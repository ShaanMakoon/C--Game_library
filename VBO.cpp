#include"VBO.h"

// Constructor that generates a Vertex Buffer Object and links it to vertices
VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	//opengl works as a state machine, meaning al
	//opengl objects need a value(and integer)

	//generates value
	glGenBuffers(1, &ID);
	//binding means to activate it
	//so this VBO is now tha active one
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	//feed data to the current VBO
	//we just specified theVBO
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

// Binds the VBO
void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

// Unbinds the VBO
void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Deletes the VBO
void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}