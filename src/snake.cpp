#include <iostream> // For std::cout and std::cin
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time
#include <chrono> // For chrono::milliseconds
#include <conio.h> // For _kbhit() and _getch()
#include <thread> // For sleep_for()

// Provides Windows API which permits to manipulate directly the command prompt window
// It permits us to hideCursor, resetCursor, modify output mode to UTF-8 mode 
#include <windows.h>

#include "snake.hpp" // Our header file

Application::Application() {
    // Initializing score to Zero
    score = 0;

    // Initializing the grid with empty spaces
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 35; j++) {
            grid[i][j] = ' ';
        }
    }
}

void Application::resetCursor(int x, int y) {

    // Defining a handle and assigning it the output window
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // Defining a special structure that stores the window's coordinate
    COORD coord = { (SHORT)x, (SHORT)y };

    // The function uses the handle we creted to set the cursor to the coordinate (x, y)
    SetConsoleCursorPosition(hOut, coord);

}

void Application::hideCursor() {

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Defining a special structure that stores the informations of the cursor (size and visibility)
    CONSOLE_CURSOR_INFO info;

    // We set the size to 100 (space occupied by a character)
    info.dwSize = 100;

    // We set the visibility to false
    info.bVisible = FALSE;

    // We use the handle we declared to modify the console info with the structure we created
    SetConsoleCursorInfo(consoleHandle, &info);
}

void Application::draw() {
    // Clear screen
    resetCursor(0, 0);

    std::cout << "=====================================" << std::endl;
    std::cout << "*               Snake               *" << std::endl;
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
        checkCollision();

        if (!gameOver) {
            update();
            draw();
        }

        // We delay the program for 0.3 seconds at every iteration to have a reasonable speed
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    } while (!gameOver);

    std::cout << "\n\n GAME OVER! 💔"  << std::endl;
    std::cin.ignore();
}

void Application::spawnFood() {
    // Note: It's better to call std::srand(...) just ONCE in your Application() constructor, 
    // but if you must put it here, do not put it inside the while loop!
    
    bool validPosition = false;

    while (!validPosition) {
        fX = std::rand() % 35;
        fY = std::rand() % 20;

        validPosition = true; // Assume the spot is safe, then try to prove it wrong

        // 1. Check if the food spawned on top of the snake's head
        if (fX == hX && fY == hY) {
            validPosition = false;
            continue; // Skip checking the body, loop back and roll new coordinates
        }

        // 2. Check if the food spawned on top of ANY body part
        for (int i = 0; i < nb; i++) { // Use 'nb', not 'nb - 1'
            if (fX == bX[i] && fY == bY[i]) {
                validPosition = false;
                break; // We found a collision, no need to check the rest of the body
            }
        }
    }

    // Once the while loop finishes, we know we have safe coordinates
    grid[fY][fX] = 'F';
}

void Application::checkCollision() {
    int nextX = hX + dX;
    int nextY = hY + dY;

    if (nextX < 0 || nextX >= 35 || nextY < 0 || nextY >= 20) {
        gameOver = true;
        return;
    }

    for (int i = 0; i < nb; i++) {
        if (bX[i] == nextX && bY[i] == nextY) {
            gameOver = true;
            return;
        }
    }

    if (fX == hX && fY == hY) {
        hasEaten = true;
        nb++;
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

    if (hasEaten) {
        bX[nb - 1] = hX;
        bY[nb - 1] = hY;
    
        hX += dX;
        hY += dY;

        hasEaten = false;
    } else {
        grid[bY[0]][bX[0]] = ' ';

        for (int i = 0; i < nb - 1; i++) {
            bX[i] = bX[i + 1];
            bY[i] = bY[i + 1];
        }
        bX[nb - 1] = hX;
        bY[nb - 1] = hY;
        
        hX += dX;
        hY += dY;
    }

    grid[hY][hX] = head;

    for (int i = 0; i < nb; i++) {
        grid[bY[i]][bX[i]] = body;
    }
}