#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "mesh.h"
#include "shader.h"

int main()
{
	GLFWwindow *window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Initialize glew */
	GLenum err = glewInit();
	if (err != GLEW_OK) std::cout << ("Error: %s\n", glewGetErrorString(err)) << std::endl;

	Vertex vertices[] = { 
		Vertex(-0.5, -0.5, 0),
		Vertex(0, 0.5, 0),
		Vertex(0.5, -0.5, 0)
	};
	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

	Shader shader("./shaders/basicShader");

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		shader.Bind();
		mesh.Draw();

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}