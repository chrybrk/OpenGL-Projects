#include "Graphic.h"

int GetElementCount(ShaderElementKind kind)
{
    switch (kind)
    {
        case i1:
        case ui1:
        case f1:
            return 1;

        case i2:
        case ui2:
        case f2:
            return 2;

        case i3:
        case ui3:
        case f3:
            return 3;

        case i4:
        case ui4:
        case f4:
            return 4;
        
        default:
            return -1;
    }
}

size_t GetElementSize(ShaderElementKind kind)
{
    switch (kind)
    {
        case i1:
        case i2:
        case i3:
        case i4:
            return sizeof(int);

        case ui1:
        case ui2:
        case ui3:
        case ui4:
            return sizeof(unsigned int);

        case f1:
        case f2:
        case f3:
        case f4:
            return sizeof(float);
        
        default:
            return 0;
    }
}

ShaderElement InitShaderElement(ShaderElementKind *kinds, size_t kind_size, unsigned int openGLType, bool normalized)
{
    ShaderElement se = {
        kinds,
        kind_size,
        openGLType,
        normalized,
        0
    };

    for (size_t i = 0; i < kind_size; ++i)
        se.totalElements += GetElementCount(kinds[i]);

    return se;
}

VertexBuffer CreateVertexBuffer(float *vertices, size_t size, DrawKind drawKind)
{
    VertexBuffer vb;
    vb.elements = NULL;

    glGenBuffers(1, &vb.ID);

    glBindBuffer(GL_ARRAY_BUFFER, vb.ID);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, drawKind == STATIC ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);

    return vb;
}

void VertexBufferBind(VertexBuffer *vb)
{
    glBindBuffer(GL_ARRAY_BUFFER, vb->ID);
}

void VertexBufferSetLayout(VertexBuffer *vb, ShaderElement *elements)
{
    vb->elements = elements;
}

ElementBuffer CreateElementBuffer(unsigned int *indices, size_t size, DrawKind drawKind)
{
    ElementBuffer eb;

    glGenBuffers(1, &eb.ID);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb.ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, drawKind == STATIC ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);

    return eb;
}

void ElementBufferBind(ElementBuffer *eb)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb->ID);
}

VertexArray CreateVertexArray()
{
    VertexArray va;

    glGenVertexArrays(1, &va.ID);

    return va;
}

void VertexArrayBind(VertexArray *va)
{
    glBindVertexArray(va->ID);
}

void VertexArrayUnbind(VertexArray *va)
{
    glBindVertexArray(0);
}

void VertexArrayPointers(VertexArray *va, VertexBuffer *vb)
{
    if (!vb->elements) {
        printf("Error :: cannot find shader elements in Vertex Buffer.\n");
        return;
    }

    VertexBufferBind(vb);

    int prevOffset = 0;
    for (size_t i = 0; i < vb->elements->size; ++i)
    {
        glVertexAttribPointer(
            i,
            GetElementCount(vb->elements->kinds[i]),
            vb->elements->openGLType,
            vb->elements->normalized,
            vb->elements->totalElements * GetElementSize(vb->elements->kinds[i]),
            (void*)(prevOffset * GetElementSize(vb->elements->kinds[i])));
        glEnableVertexAttribArray(i);

        prevOffset += GetElementCount(vb->elements->kinds[i]);
    }
}