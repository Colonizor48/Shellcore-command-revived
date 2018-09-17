#pragma once

#include <GL/glew.h>

class Vertex
{
	public:
		Vertex(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
	protected:
	private:
		float x;
		float y;
		float z;
};

class Mesh
{
	public:
		Mesh(Vertex* vertices, unsigned int numVertices);
		
		void Draw();

		virtual ~Mesh();
	protected:
	private:
		Mesh(const Mesh& other);
		void operator=(const Mesh& other);

		enum
		{
			POSITION_VB,
			NUM_BUFFERS
		};

		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];
		unsigned int m_drawCount;
};