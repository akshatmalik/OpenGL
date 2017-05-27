#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
#include <GL/glew.h>// Include glew to get all the required OpenGL

class Shader
{
public:
	// The program ID
	GLuint Program;
	// Constructor reads and builds the shader
	Shader(const GLchar* vertexSourcePath, const GLchar* fragmentSourcePath
		);
	// Use the program
	void Use();
};
