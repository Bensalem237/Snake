#include <windows.h>
#include <iostream>
#include "snake.hpp"

int main() {
    SetConsoleOutputCP(65001);
    Application app;
    app.hideCursor();
    app.run();
    return 0;
}