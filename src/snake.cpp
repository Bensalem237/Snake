#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time
#include <chrono>
#include <conio.h>
#include <thread>
#include <windows.h>
#include "snake.hpp"

Application::Application() {
    score = 0;

    // Initializing the grid with empty spaces
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 35; j++) {
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
    grid[sY][sX] = head;

    std::cout << "=====================================" << std::endl;
    std::cout << "*    Snake Game by Ben-salem ❤️    *" << std::endl;
    std::cout << "=====================================" << std::endl;

    std::cout << "SCORE : " << score << std::endl;
    std::cout << "╔═══════════════════════════════════╗" << std::endl;
    
    for (int i = 0; i < 20; i++) {
        std::cout << "║"; // Left border
        for (int j = 0; j < 35; j++) {
            std::cout << grid[i][j];
        }
        std::cout << "║" << std::endl; // Right border
    }

    std::cout << "╚═══════════════════════════════════╝" << std::endl;
}

void Application::run() {

    spawnFood();

    do {
        input();
        update();
        draw();
        checkCollision();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    } while (!gameOver);

    std::cout << "\n\n GAME OVER! 💔"  << std::endl;
    std::cin.ignore();
}

void Application::spawnFood() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    fX = std::rand() % 35;
    fY = std::rand() % 20;

    grid[fY][fX] = 'F';
}

void Application::checkCollision() {
    if (sX == -1 || sX == 35 || sY == -1 || sY == 20) gameOver = true;

    if (fX == sX && fY == sY) {
        score++;
        spawnFood();
    }
}

void Application::input() {
    if (_kbhit()) {
        char key = _getch();
    
        switch (key) {
            case 'w' :
            if ((dX == -1 || dX == 1) && dY != 1) {
                dX = 0;
                dY = -1;
            }
            break;

            case 'z' :
            if ((dX == -1 || dX == 1) && dY != 1) {
                dX = 0;
                dY = -1;
            }
            break;

            case 's' :
            if ((dX == -1 || dX == 1) && dY != -1) {
                dX = 0;
                dY = 1;
            }
            break;

            case 'a' :
            if ((dY == -1 || dY == 1) && dX != 1) {
                dX = -1;
                dY = 0;
            }
            break;

            case 'q' :
            if ((dY == -1 || dY == 1) && dX != 1) {
                dX = -1;
                dY = 0;
            }
            break;

            case 'd' :
            if ((dY == -1 || dY == 1) && dX != -1) {
                dX = 1;
                dY = 0;
            }
            break;
        }
    }
}

void Application::update() {
    grid[sY][sX] = ' ';
    sX += dX;
    sY += dY;
}