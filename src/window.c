#include "window.h"
#include "Core/Engine.h"

void windowCreate(Application *app, WindowProperties windowProperties) {
    PANIC(!glfwInit(), "Failed to initialize GLFW!")
    app->window.windowProperties = windowProperties;
    app->window.renderer = malloc(sizeof(Renderer));
    PANIC(app->window.renderer == 0, "Failed to allocate memory for Renderer!")
    app->window.handle = glfwCreateWindow(windowProperties.width,
                                          windowProperties.height,
                                          windowProperties.title,
                                          NULL,
                                          NULL);
    PANIC(app->window.handle == 0, "Failed to create Window!")
}

Application *applicationCreate() {
    Application *app = (Application*) malloc(sizeof(Application));
    PANIC(app == 0, "Failed to allocate memory for application!")
    return app;
}

Application* create_application(WindowProperties windowProperties) {
    setupErrorHandling();
    Application *app = applicationCreate();
    windowCreate(app, windowProperties);
    glfwMakeContextCurrent(app->window.handle);
    gladLoadGL();
    engineLoop(app);
}

void cleanup_application(Application* application) {

}