#pragma once

class Application {
private :
    // Defining a 20 x 20 array to store the board
    char grid[20][20];
    int score;

    // Snake's position (initialy at the center of the grid)
    int sX = 9, sY = 9;
    char head = 'O';
    char body = 'o';

    // Food position
    int fX, fY;

public :
    /**
     * @brief Application class constructor
     */
    Application();

    /**
     * @brief Resets the console's cursor before drawing the board
     * @param x the x coordinate where to reset the cursor (recomended to put 0)
     * @param y the y coordinate where to reset the cursor (recomended to put 0)
     */
    void resetCursor(int x, int y);

    /**
     * @brief Hides the console's cursor when drawing.
     * @brief If not called, the cursor will be seen flying over the console everytime the board is been redrawn
     */
    void hideCursor();

    /**
     * @brief Updates the position of the snake and the food
     */
    void update();

    /**
     * @brief Draws the game board
     */
    void draw();

    /**
     * @brief Gets player's input
     */
    void input();

    /**
     * @brief Checks if there is any collision with the boundaries or with the snake itself at every iteration
     */
    void checkCollision();
};