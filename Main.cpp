//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"


const unsigned int width = 800;
const unsigned int height = 800;


// Vertices coordinates
float vertices[] = {
	// format position, tex coords
	// front
	-2.6,   0.2,  1.1, 0, 0,-2.0f, -0.2f, 2.0f, // 0
	-2.4,   0.2,  1.1, 1, 0, 2.0f, -0.2f, 2.0f, // 1
	-2.4,   0.3,  1.1, 1, 1, 2.0f, 0.2f, 2.0f, // 2
	-2.6,   0.3,  1.1, 0, 1,-2.0f, 0.2f, 2.0f, // 3

	// right
	-2.4,   0.2,  1.1, 0, 0, 2.0f, -0.2f, -2.0f, // 4
	-2.4,   0.2,  0.9, 1, 0, 2.0f, 0.2f, -2.0f, // 5
	-2.4,   0.3,  0.9, 1, 1, 2.0f, 0.2f, 2.0f, // 6
	-2.4,   0.3,  1.1, 0, 1, 2.0f, -0.2f, 2.0f, // 7

	// back
	-2.6,   0.2,  0.9, 0, 0,  -2.0f, -0.2f, -2.0f, // 8 
	-2.4,   0.2,  0.9, 1, 0,  -2.0f, 0.2f, -2.0f, // 9
	-2.4,   0.3,  0.9, 1, 1, 2.0f, 0.2f, -2.0f, // 10
	-2.6,   0.3,  0.9, 0, 1, 2.0f, -0.2f, -2.0f, // 11

	// left   4
	-2.6,   0.2,  0.9, 0, 0, -2.0f, -0.2f, -2.0f, // 12
	-2.6,   0.2,  1.1, 1, 0, -2.0f, -0.2f, 2.0f, // 13
	-2.6,   0.3,  1.1, 1, 1, -2.0f, 0.2f, 2.0f, // 14
	-2.6,   0.3,  0.9, 0, 1, -2.0f, 0.2f, -2.0f, // 15 

	// top				  
	-2.6,   0.3,  1.1, 0, 0, 2.0f, 0.2f, 2.0f, // 16
	-2.4,   0.3,  1.1, 1, 0, -2.0f, 0.2f, 2.0f, // 17
	-2.4,   0.3,  0.9, 1, 1, -2.0f, 0.2f, -2.0f, // 18
	-2.6,   0.3,  0.9, 0, 1, 2.0f, 0.2f, -2.0f, // 19

	// bottom
	-2.6,   0.3,  1.1, 0, 0, 2.0f, -0.2f, 2.0f, // 16
	-2.4,   0.3,  1.1, 1, 0, -2.0f, -0.2f, 2.0f, // 17
	-2.4,   0.3,  0.9, 1, 1, -2.0f, -0.2f, -2.0f, // 18
	-2.6,   0.3,  0.9, 0, 1, 2.0f,-0.2f, -2.0f, // 19

//back leg
		// front
	-2.6,   0.2,  1.1, 0, 0, 1.8f, -0.2f, -1.2f, // 0
	-2.4,   0.2,  1.1, 1, 0, 1.4f, -0.2f, -1.2f, // 1
	-2.4,   0.3,  1.1, 1, 1, 1.4f, -3.0f, -1.2f, // 2
	-2.6,   0.3,  1.1, 0, 1, 1.8f, -3.0f, -1.2f, // 3

	// right
	-2.4,   0.2,  1.1, 0, 0, 1.8f, -0.2f, -1.6f, // 4
	-2.4,   0.2,  0.9, 1, 0, 1.4f, -0.2f, -1.2f, // 5
	-2.4,   0.3,  0.9, 1, 1, 1.4f, -3.0f, -1.2f, // 6
	-2.4,   0.3,  1.1, 0, 1, 1.8f, -3.0f, -1.6f, // 7

	// back
	-2.6,   0.2,  0.9, 0, 0, 1.8f, -0.2f, -1.6f, // 8 
	-2.4,   0.2,  0.9, 1, 0, 1.4f, -0.2f, -1.6f, // 9
	-2.4,   0.3,  0.9, 1, 1, 1.4f, -3.0f, -1.6f, // 10
	-2.6,   0.3,  0.9, 0, 1, 1.8f, -3.0f, -1.6f, // 11

	// left   4
	-2.6,   0.2,  0.9, 0, 0, 1.4f, -0.2f, -1.6f, // 12
	-2.6,   0.2,  1.1, 1, 0, 1.4f, -0.2f, -1.2f, // 13
	-2.6,   0.3,  1.1, 1, 1, 1.4f, -3.0f, -1.2f, // 14
	-2.6,   0.3,  0.9, 0, 1, 1.4f, -3.0f, -1.6f, // 15 

	// leg left
	// front
- 2.6,   0.2,  1.1, 0, 0, -1.8f, -0.2f, 1.6f, // 0
-2.4,   0.2,  1.1, 1, 0, -1.4f, -0.2f, 1.6f, // 1
-2.4,   0.3,  1.1, 1, 1, -1.4f, -3.0f, 1.6f, // 2
-2.6,   0.3,  1.1, 0, 1, -1.8f, -3.0f, 1.6f, // 3

// right
-2.4,   0.2,  1.1, 0, 0, -1.8f, -0.2f, 1.6f, // 4
-2.4,   0.2,  0.9, 1, 0, -1.8f, -0.2f, 1.2f, // 5
-2.4,   0.3,  0.9, 1, 1, -1.8f, -3.0f, 1.2f, // 6
-2.4,   0.3,  1.1, 0, 1, -1.8f, -3.0f, 1.6f, // 7

// back
-2.6,   0.2,  0.9, 0, 0, -1.8f, -0.2f, 1.2f, // 8 
-2.4,   0.2,  0.9, 1, 0, -1.4f, -0.2f, 1.2f, // 9
-2.4,   0.3,  0.9, 1, 1, -1.4f, -3.0f, 1.2f, // 10
-2.6,   0.3,  0.9, 0, 1, -1.8f, -3.0f, 1.2f, // 11

// left   4
-2.6,   0.2,  0.9, 0, 0, -1.4f, -0.2f, 1.6f, // 12
-2.6,   0.2,  1.1, 1, 0, -1.4f, -0.2f, 1.2f, // 13
-2.6,   0.3,  1.1, 1, 1, -1.4f, -3.0f, 1.2f, // 14
-2.6,   0.3,  0.9, 0, 1, -1.4f, -3.0f, 1.6f, // 15 

	// leg bck 
	// front
-2.6,   0.2,  1.1, 0, 0, -1.8f, -0.2f, -1.2f, // 0
-2.4,   0.2,  1.1, 1, 0, -1.4f, -0.2f, -1.2f, // 1
-2.4,   0.3,  1.1, 1, 1, -1.4f, -3.0f, -1.2f, // 2
-2.6,   0.3,  1.1, 0, 1, -1.8f, -3.0f, -1.2f, // 3

// right
-2.4,   0.2,  1.1, 0, 0, -1.8f, -0.2f, -1.6f, // 4
-2.4,   0.2,  0.9, 1, 0, -1.8f, -0.2f, -1.2f, // 5
-2.4,   0.3,  0.9, 1, 1, -1.8f, -3.0f, -1.2f, // 6
-2.4,   0.3,  1.1, 0, 1, -1.8f, -3.0f, -1.6f, // 7

// back
-2.6,   0.2,  0.9, 0, 0, -1.8f, -0.2f, -1.6f, // 8 
-2.4,   0.2,  0.9, 1, 0, -1.8f, -0.2f, -1.6f, // 9
-2.4,   0.3,  0.9, 1, 1, -1.8f, -3.0f, -1.6f, // 10
-2.6,   0.3,  0.9, 0, 1, -1.8f, -3.0f, -1.6f, // 11

// left   4
-2.6,   0.2,  0.9, 0, 0, -1.4f, -0.2f, -1.6f, // 12
-2.6,   0.2,  1.1, 1, 0, -1.4f, -0.2f, -1.2f, // 13
-2.6,   0.3,  1.1, 1, 1, -1.4f, -3.0f, -1.2f, // 14
-2.6,   0.3,  0.9, 0, 1, -1.4f, -3.0f, -1.6f, // 15 

// chair bck 
	// front
		-2.6, 0.2, 1.1, 0, 0, -1.8f, 0.2f, -1.8f, // 0
		-2.4, 0.2, 1.1, 1, 0, 1.8f, 0.2f, -1.8f,// 1
		-2.4, 0.3, 1.1, 1, 1, 1.8f, 3.5f, -1.8f, // 2
		-2.6, 0.3, 1.1, 0, 1, -1.8f, 3.5f, -1.8f, // 3

		
		// back
		-2.6, 0.2, 1.1, 0, 0, -1.8f, 0.2f, -2.0f, // 0
		-2.4, 0.2, 1.1, 1, 0, 1.8f, 0.2f, -2.0f,// 1
		-2.4, 0.3, 1.1, 1, 1, 1.8f, 3.5f, -2.0f, // 2
		-2.6, 0.3, 1.1, 0, 1, -1.8f, 3.5f, -2.0f, // 3

};



unsigned int indices[] = {
	0,  1,  2,  0,  2,  3,   // front
	4,  5,  6,  4,  6, 7,   // right
	8,  9,  10, 8,  10, 11,  // back
	12, 14, 13, 12, 15, 14,  // left
	16, 18, 17, 16, 19, 18,  // upper
	20, 22, 21, 20, 23, 22,   // bottom
	0,  1,  2,  0,  2,  3,   // front
	4,  5,  6,  4,  6, 7,   // right
	8,  9,  10, 8,  10, 11,  // back
	12, 14, 13, 12, 15, 14,  // left
	16, 18, 17, 16, 19, 18,  // upper
	20, 22, 21, 20, 23, 22,   // bottom
	0,  1,  2,  0,  2,  3,   // front
	4,  5,  6,  4,  6, 7,   // right
	8,  9,  10, 8,  10, 11,  // back
	12, 14, 13, 12, 15, 14,  // left
	16, 18, 17, 16, 19, 18,  // upper
	20, 22, 21, 20, 23, 22,
	0,  1,  2,  0,  2,  3,   // front
	4,  5,  6,  4,  6, 7,   // rightm
};


int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow 
	GLFWwindow* window = glfwCreateWindow(width, height, "objek3D", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);



	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("VertexShader.vert", "fragmentShader.frag");



	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath = "/Resources/YoutubeOpenGL 7 - Going 3D/";

	// Texture
	Texture brickTex((parentDir + texPath + "brick.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);

	// Original code from the tutorial
	/*Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);*/


	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();

		// Initializes matrices so they are not the null matrix
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		// Assigns different transformations to each matrix
		model = glm::translate(model, glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
		proj = glm::perspective(glm::radians(5.0f), (float)width / height, 0.1f, 100.0f);

		// Outputs the matrices into the Vertex Shader
		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		// Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
		glUniform1f(uniID, 0.5f);
		// Binds texture so that is appears in rendering
		brickTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	brickTex.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}