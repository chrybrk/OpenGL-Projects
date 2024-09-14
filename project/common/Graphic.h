#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include "common.h"

/*
 * {
 * 	{ Sf3, (Vec3) { 0.5f, 0.5f, 0.5f } },
 * 	{ Sf3, (Vec3) { 0.5f, 0.5f, 0.5f } }
 * }
*/

typedef struct VertexBuffer {
	unsigned int ID;
} VertexBuffer;

VertexBuffer CreateVetexBuffer();
void VertexBufferBind(VertexBuffer *vb);
void VertexBufferUnbind(VertexBuffer *vb);
void VertexBufferSet(VertexBuffer *vb, float *vertices, size_t size);

typedef struct ElementBuffer {
	unsigned int ID;
} ElementBuffer;

ElementBuffer CreateElementBuffer();
void ElementBufferBind(ElementBuffer *vb);
void ElementBufferUnbind(ElementBuffer *vb);
void ElementBufferSet(ElementBuffer *vb, float *vertices, size_t size);

enum ShaderDataType {
	Float,
	Float2,
	Float3,
	Float4
};

typedef struct VertexArrayElement {
	ShaderDataType sdt;
	void *value;
} VertexArrayElement;

void VertexArraySet(VertexArrayElement *elements);

#endif // __GRAPHIC_H__
