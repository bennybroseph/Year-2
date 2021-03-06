#ifndef _SHADERUTILITY_H_
#define _SHADERUTILITY_H_
#pragma once

#include <gl_core_4_4.h>

#include "ShaderVariable.h"

#include "MasterHeader.h"

enum class ShaderType
{
	Vertex,
	Fragment,
	Geometry,
};

class Shader;

typedef unique_ptr<Shader> ShaderPtrU;
typedef shared_ptr<Shader> ShaderPtrS;
typedef weak_ptr<Shader> ShaderPtrW;

class Shader
{

	const static string EDITABLE_IDENTIFIER;

public:

	static int init();
	static int quit();

	Shader();

	int addShader(const char *path, ShaderType type) const;

	const GLchar * getName() const;
	void setName(const GLchar *newName);

	static const Shader * standard();
	static const Shader * basic();
	static const Shader * texture();
	static const Shader * positional();
	static const Shader * phong();
	static const Shader * perlin();
	static const Shader * time();

	static const vector<Shader *> * getShaders();

	vectorPtrU<ShaderVariablePtrU> getVariables() const;

	GLuint programID() const;

	~Shader();

private:

	static ShaderPtrU s_standard;
	static ShaderPtrU s_basic;
	static ShaderPtrU s_texture;
	static ShaderPtrU s_positional;
	static ShaderPtrU s_phong;
	static ShaderPtrU s_perlin;
	static ShaderPtrU s_time;

	static vectorPtrU<Shader *> s_shaders;

	GLuint m_programID = 0;
	unique_ptr<GLchar> m_name = unique_ptr<GLchar>(new GLchar[255]);
	vectorPtrU<unique_ptr<string>> m_shaderPaths = make_unique<vector<unique_ptr<string>>>();
};

#endif // _SHADERUTILITY_H_
