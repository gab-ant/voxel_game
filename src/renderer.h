#pragma once
#include <string>

using std::string;

class Renderer
{    
    public:
	Renderer();
	void draw();
	void clean();

    private:
	static const string vertexFilePath;
	static const string fragmentFilePath;

	string vertexShaderSource;
	string fragmentShaderSource;

	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;

	unsigned int texture;

	unsigned int shaderProgram;

	string loadShaderFile(string path);
};

