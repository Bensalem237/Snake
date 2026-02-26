#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time
#include <windows.h>
#include "snake.hpp"

Application::Application() {
    score = 0;

    // Initializing the grid with empty spaces
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            grid[i][j] = ' ';
        }
    }
}

void Application::resetCursor(int x, int y) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

void Application::hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void Application::draw() {
    // Clear screen
    resetCursor(0, 0);

    std::cout << "===================================" << std::endl;
    std::cout << "*    Snake Game by Ben-salem ❤️  *" << std::endl;
    std::cout << "===================================" << std::endl;

    std::cout << "SCORE : " << score << std::endl;
    std::cout << "╔════════════════════╗" << std::endl;
    
    for (int i = 0; i < 20; i++) {
        std::cout << "║"; // Left border
        for (int j = 0; j < 20; j++) {
            std::cout << grid[i][j];
        }
        std::cout << "║" << std::endl; // Right border
    }

    std::cout << "╚════════════════════╝" << std::endl;
}

void Application::update() {

    bool gameOver = true;

    do {
        
    } while (!gameOver);
}