#ifndef OPENENGINE_WINDOW_H
#define OPENENGINE_WINDOW_H

#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include "utils.h"

typedef struct WindowProperties {
    char *title;
    int width, minWidth, maxWidth, height, minHeight, maxHeight;
    bool windowResizable;
} WindowProperties;
typedef struct Renderer {

} Renderer;
typedef struct Window {
    GLFWwindow *handle;
    Renderer *renderer;
    WindowProperties windowProperties;
} Window;
typedef struct Application {
    Window window;
} Application;

Application* create_application(WindowProperties windowProperties);
void cleanup_application(Application* application);

#endif //OPENENGINE_WINDOW_H
