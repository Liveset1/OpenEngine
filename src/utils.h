#ifndef OPENENGINE_UTILS_H
#define OPENENGINE_UTILS_H

#include <signal.h>

#define PANIC(ERROR, FORMAT, ...) { \
    int errCode;\
    if ((errCode = ERROR)) {\
        fprintf(stderr, "%s -> %s -> %i -> Error(%i)" FORMAT "\n", __FILE_NAME__, __FUNCTION__, __LINE__, errCode, ##__VA_ARGS__); raise(SIGABRT);\
    }\
}

// Exit Callback
void exitCallback() {
    glfwTerminate();
}

// GLFW Error Callback
void glfwErrorCallback(int error_code, const char *description) {
    PANIC(error_code, "GLFW Error Callback: %s", description)
}

void setupErrorHandling() {
    glfwSetErrorCallback(glfwErrorCallback);
    atexit(exitCallback);
}

#endif //OPENENGINE_UTILS_H
