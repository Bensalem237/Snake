#include <windows.h>
#include <iostream>
#include "snake.hpp"

int main() {
    SetConsoleOutputCP(65001);
    Application app;
    app.hideCursor();
    app.draw();
    std::cin.ignore();
    return 0;
}