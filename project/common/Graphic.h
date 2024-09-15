#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include "common.h"

typedef enum {
	// integer
	i1, i2, i3, i4,

	// unsigned integer
	ui1, ui2, ui3, ui4,

	// float
	f1, f2, f3, f4
} ShaderElementKind;

typedef struct ShaderElement {
	ShaderElementKind *kinds;
	size_t size;
	unsigned int openGLType;
	bool normalized;
	size_t totalElements;
} ShaderElement;

ShaderElement InitShaderElement(ShaderElementKind *kinds, size_t kind_size, unsigned int openGLType, bool normalized);

typedef enum {
	STATIC,
	DYNAMIC
} DrawKind;

typedef struct VertexBuffer {
	unsigned int ID;
	ShaderElement *elements;
} VertexBuffer;

VertexBuffer CreateVertexBuffer(float *vertices, size_t size, DrawKind drawKind);
void VertexBufferBind(VertexBuffer *vb);
void VertexBufferSetLayout(VertexBuffer *vb, ShaderElement *elements);

typedef struct ElementBuffer {
	unsigned int ID;
} ElementBuffer;

ElementBuffer CreateElementBuffer(unsigned int *indices, size_t size, DrawKind drawKind);
void ElementBufferBind(ElementBuffer *eb);

typedef struct VertexArray {
	unsigned int ID;
} VertexArray;

VertexArray CreateVertexArray();
void VertexArrayBind(VertexArray *va);
void VertexArrayUnbind(VertexArray *va);
void VertexArrayPointers(VertexArray *va, VertexBuffer *vb);

#endif // __GRAPHIC_H__