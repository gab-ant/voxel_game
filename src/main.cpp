#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	glfwSetWindowShouldClose(window, true);
}

int main() 
{
    if (!glfwInit()) 
    {
	std::cerr << "Failed to initialize GLFW\n";
	return -1;
    }
 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Test", NULL, NULL);

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

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback)

    while(!glfwWindowShouldClose(window)) 
    {
	processInput(window);
	
	// Set state
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	// Use state to clear
	glClear(GL_COLOR_BUFFER_BIT);

	glfwPollEvents();
	glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
