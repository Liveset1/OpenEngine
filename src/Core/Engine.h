//
// Created by yousi on 8/15/2023.
//

#ifndef OPENENGINE_ENGINE_H
#define OPENENGINE_ENGINE_H

#include "../window.h"

void engineUpdate(Application *app) {

}

void engineRender(Application *app) {

}

void engineLoop(Application *app) {
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(app->window.handle))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1, 1, 1, 1);
        /* Swap front and back buffers */
        glfwSwapBuffers(app->window.handle);

        engineUpdate(app);
        engineRender(app);

        /* Poll for and process events */
        glfwPollEvents();
    }
}

#endif //OPENENGINE_ENGINE_H
