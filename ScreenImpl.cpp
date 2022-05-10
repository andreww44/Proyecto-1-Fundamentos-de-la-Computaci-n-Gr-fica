#include "Screen.h"
#define TITLE_PREFIX "Proyecto 1 Fundamentos de la Computació G"

Screen::~Screen(){

}

 
Screen::Screen()
{
    figura = Rectangle();
    controllador = KeyController();
    
}

void Screen::InitializeScreen()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    

    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, TITLE_PREFIX, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        //return -1;
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    glfwSetKeyCallback(window, glfw_onKey);

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    /*
    float vertices[] = {
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f   // top 
    };*/
    float vertices[] = {
        figura.getVertex(0).getPos()[0], figura.getVertex(0).getPos()[1], figura.getVertex(0).getPos()[2],  // bottom right
        figura.getVertex(1).getPos()[0], figura.getVertex(1).getPos()[1], figura.getVertex(1).getPos()[2],  // bottom left
        figura.getVertex(2).getPos()[0], figura.getVertex(2).getPos()[1], figura.getVertex(2).getPos()[2],  // top right
        figura.getVertex(1).getPos()[0], figura.getVertex(1).getPos()[1], figura.getVertex(1).getPos()[2],  // bottom right
        figura.getVertex(3).getPos()[0], figura.getVertex(3).getPos()[1], figura.getVertex(3).getPos()[2],  // bottom left
        figura.getVertex(2).getPos()[0], figura.getVertex(2).getPos()[1], figura.getVertex(2).getPos()[2]
    };

    //unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0);


    // bind the VAO (it was already bound, but just to demonstrate): seeing as we only have a single VAO we can 
    // just bind it beforehand before rendering the respective triangle; this is another approach.
    

}

void Screen::Loop()
{
    bool pr1 = false;
    bool pr2 = false;
    bool pr3 = false;
    bool pr4 = false;
    bool pr5 = false;
    bool pr6 = false;
    //bool pr1 = false;
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        int bt1 = glfwGetKey (window, GLFW_KEY_1);
        int bt2 = glfwGetKey (window, GLFW_KEY_2);
        int bt3 = glfwGetKey (window, GLFW_KEY_3);
        int bt4 = glfwGetKey (window, GLFW_KEY_4);
        int bt5 = glfwGetKey (window, GLFW_KEY_5);
        int bt6 = glfwGetKey (window, GLFW_KEY_6);
        //int bta = glfwGetKey (window, GLFW_KEY_1);

        if(bt1 == GLFW_PRESS && pr1 != true){figura.changeColor(1,0,0,1);pr1 = true;}
        if(bt1 == GLFW_RELEASE && pr1 == true){ pr1 = false;}

        if(bt2 == GLFW_PRESS && pr2 != true){figura.changeColor(0,1,0,1);pr2 = true;}
        if(bt2 == GLFW_RELEASE && pr2 == true){ pr2 = false;}

        if(bt3 == GLFW_PRESS && pr3 != true){figura.changeColor(0,0,1,1);pr3 = true;}
        if(bt3 == GLFW_RELEASE && pr3 == true){ pr3 = false;}

        if(bt4 == GLFW_PRESS && pr4 != true){figura.changeColor(1,0,0,0);pr4 = true;}
        if(bt4 == GLFW_RELEASE && pr4 == true){ pr4 = false;}

        if(bt5 == GLFW_PRESS && pr5 != true){figura.changeColor(0,1,0,0);pr5 = true;}
        if(bt5 == GLFW_RELEASE && pr5 == true){ pr5 = false;}

        if(bt6 == GLFW_PRESS && pr6 != true){figura.changeColor(0,0,1,0);pr6 = true;}
        if(bt6 == GLFW_RELEASE && pr6 == true){ pr6 = false;}

    	glfwSetKeyCallback(window, eventosTeclado);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // be sure to activate the shader before any calls to glUniform
        glUseProgram(shaderProgram);

        // update shader uniform
        
        double  timeValue = glfwGetTime();
        //float greenValue = static_cast<float>(sin(timeValue) / 2.0 + 0.5);
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        glUniform4f(vertexColorLocation, figura.getVertex(0).getColor()[0], figura.getVertex(0).getColor()[1], figura.getVertex(0).getColor()[2], figura.getVertex(0).getColor()[3]);
        
        // render the triangle
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Screen::FinishScreen()
{
    glBindVertexArray(VAO);

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return;

}



void Screen::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void Screen::glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key == GLFW_KEY_1 && action == GLFW_RELEASE)
    {
        //figura.plusRed();
    }
        //colorTriangle();
}

/*
void Screen::colorTriangle(){
    double  timeValue = glfwGetTime();
    float greenValue = static_cast<float>(sin(timeValue) / 2.0 + 0.5);
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
}*/

void Screen::eventosTeclado(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
		
    if (key == GLFW_KEY_1 && action == GLFW_RELEASE)
    {
        //figura.plusRed();
    }
}


