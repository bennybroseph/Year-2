#include "Mesh.h"

#include "Camera.h"


void Mesh::drawMesh(
	const mat4 &matrix,
	const vec4 &colour,
	GLboolean drawMesh,
	GLboolean drawWireFrame,
	GLuint drawType) const
{
	glUseProgram(Shader::basic()->programID());

	GLuint matUniform = glGetUniformLocation(Shader::basic()->programID(), "ProjectionViewModel");
	if (matUniform != -1)
		glUniformMatrix4fv(
			matUniform,
			1,
			false,
			value_ptr(Camera::mainCamera()->getProjectionView() * matrix));

	if (drawMesh)
	{
		// bind colour
		GLuint materialUniform = glGetUniformLocation(Shader::basic()->programID(), "MaterialAmbient");
		if (materialUniform != -1)
			glUniform4fv(materialUniform, 1, &colour[0]);

		glBindVertexArray(m_vao);
		glDrawElements(drawType, m_indexes->size(), GL_UNSIGNED_INT, nullptr);
	}
	if (drawWireFrame)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		{
			// bind colour
			GLuint materialUniform = glGetUniformLocation(Shader::basic()->programID(), "MaterialAmbient");
			if (materialUniform != -1)
				glUniform4fv(materialUniform, 1, &vec4(1.f, 1.f, 1.f, 1.f)[0]);

			glBindVertexArray(m_vao);
			glDrawElements(drawType, m_indexes->size(), GL_UNSIGNED_INT, nullptr);
		}
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	glBindVertexArray(0);
}

void Mesh::genBuffers()
{
	//gen VBO, IBO
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	//bind and pop VBO
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, m_vertexes->size() * sizeof(Vertex), m_vertexes->data(), GL_STATIC_DRAW);

	//bind and pop IBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexes->size() * sizeof(GLuint), m_indexes->data(), GL_STATIC_DRAW);

	//setup vertex descriptors
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(sizeof(vec4)));

	// normals
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(sizeof(vec4) * 2));

	// tangents
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(sizeof(vec4) * 3));

	// textureUV
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(sizeof(vec4) * 4));

	//teardown unbind all handles
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ibo);

	glDeleteVertexArrays(1, &m_vao);
}