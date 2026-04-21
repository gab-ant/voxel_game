#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "renderer.h"
#include "image_loader.h"

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
    {
	glfwSetWindowShouldClose(window, true);
    }
}

int main() 
{   
    // GLFW init
    if (!glfwInit()) 
    {
	std::cerr << "Failed to initialize GLFW\n";
	return -1;
    }
 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Shader loading
    imageLoader::loadImage("textures/wall.bmp");

    // Window creation
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "MY_GAME", NULL, NULL);

    if (!window) 
    {
	std::cerr << "Failed to create GLFW window\n";
	glfwTerminate();
	return -1;
    }

    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
	std::cerr << "Failed to initialize GLAD\n";
    }
    
    // OpenGL display data relative to window size
    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    Renderer renderer;
    
    // Game-loop
    while(!glfwWindowShouldClose(window)) 
    {
	processInput(window);
	
	renderer.draw();

	glfwSwapBuffers(window);
	glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
