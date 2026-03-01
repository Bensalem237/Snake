#pragma once

class Application {
private :
    // 20 x 35 array to store the grid
    char grid[20][35];
    char head = 'O'; // Snake's head
    char body = 'o'; // Snake's body

    int score; // Player's actual score
    bool gameOver = false; // whether the game is running or not
    bool hasEaten = false; // Whether or not the snake has eaten

    // Snake's position (initialy at the center of the grid)
    int hX = 17, hY = 9;

    // Food position
    int fX, fY;

    // Arrays store the trajectory of the snake at each iteration in order to implement the snake's displacement
    int bX[100] = {15, 16};
    int bY[100] = {9, 9};

    // The number of characters of the body
    int nb = 2;

    // Stores the direction in which the snake is moving
    int dX = 1;
    int dY = 0;

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
     * @brief Runs the game
     */
    void run();

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

    /**
     * @brief spawns food at a random position
     */
    void spawnFood();

    /**
     * @brief Updates the snake's position
     */
    void update();

};