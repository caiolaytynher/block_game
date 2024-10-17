#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/struct.h>
#include "core.h"
#include <stdio.h>

static void error_callback(i32 error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, i32 key, i32 scan_code, i32 action, i32 mods) {
    if (action == GLFW_PRESS) {
        switch (key) {

        case GLFW_KEY_ESCAPE: {
            glfwSetWindowShouldClose(window, true);
        } break;

        case GLFW_KEY_F11: {
            GLFWmonitor* monitor = glfwGetWindowMonitor(window);
            if (monitor == NULL) {
                monitor = glfwGetPrimaryMonitor();
                const GLFWvidmode* mode = glfwGetVideoMode(monitor);
                glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
            } else {
                glfwSetWindowMonitor(window, NULL, 100, 100, 1280, 720, GLFW_DONT_CARE);
            }
        } break;

        }
    }
}

static void mouse_button_callback(GLFWwindow* window, i32 button, i32 action, i32 mods) {
    if (action == GLFW_PRESS) {
        switch (button) {

        case GLFW_MOUSE_BUTTON_LEFT: {
            printf("Left click\n");
        } break;

        case GLFW_MOUSE_BUTTON_RIGHT: {
            printf("Right click\n");
        } break;

        case GLFW_MOUSE_BUTTON_MIDDLE: {
            printf("Middle click\n");
        } break;

        case GLFW_MOUSE_BUTTON_4: {
            printf("Side back click\n");
        } break;

        case GLFW_MOUSE_BUTTON_5: {
            printf("Side front click\n");
        } break;

        }
    }
}

void scroll_callback(GLFWwindow* window, f64 xoffset, f64 yoffset) {
    printf("Scroll offset: (%.2f, %.2f)\n", xoffset, yoffset);
}

static void framebuffer_size_callback(GLFWwindow* window, i32 width, i32 height) {
    glViewport(0, 0, width, height);
}

i32 main(void) {
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        return -1;
    }

    // OpenGL 4.6 core
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWmonitor* window_monitor = NULL;
    i32 window_width = 1280;
    i32 window_height = 720;
    GLFWwindow* window = glfwCreateWindow(window_width, window_height, "Block Game", window_monitor, NULL);
    if (window == NULL) {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return -1;
    }

    glViewport(0, 0, window_width, window_height);
    f64 last_time = glfwGetTime();
    while (!glfwWindowShouldClose(window))
    {
        f64 current_time = glfwGetTime();
        f64 dt = current_time - last_time;
        last_time = current_time;
        f64 fps = 1.0 / dt;

        // Sky blue
        glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}