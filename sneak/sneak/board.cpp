#include "board.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <conio.h>

//////////////////////class Board;
void Screen::clearScreen()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

void Screen::updatePix(COORD coords, char sign)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount = 1;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    coords.Y = y_size - coords.Y - 1;
    FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)sign,
        cellCount,
        coords,
        &count
    );
}

Screen::Screen(short x, short y) : x_size(x), y_size(y) {
    matrix.resize(x_size);
    for (short i = 0; i < x_size; i++)
        matrix[i].resize(y_size);
    for (short i = 0; i < x_size; ++i) {
        for (short j = 0; j < y_size; ++j)
            insertToMatrix({ i, j }, ' ');
    }
}

void Screen::show()  {
    clearScreen();
    for (short j = y_size - 1; j >= 0; --j) {
        for (short i = 0; i < x_size; ++i) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void Screen::insertToMatrix(COORD cord, char sign) {
    matrix[cord.X][cord.Y] = sign;
}

void Screen::clearMatrix() {
    for (short i = 0; i < x_size; ++i) {
        for (short j = 0; j < y_size; ++j)
            matrix[i][j] = ' ';
    }
}

//////////////////////class Board;

Board::Board(short x, short y) : Screen::Screen(x, y) {
    boards.push_back({ 0,0 });
    insertToMatrix(boards.back(), 200);
    boards.push_back({ x_size - 1,0 });
    insertToMatrix(boards.back(), 188);
    boards.push_back({ x_size - 1,y_size - 1 });
    insertToMatrix(boards.back(), 187);
    boards.push_back({ 0,y_size - 1 });
    insertToMatrix(boards.back(), 201);
    for (short i = 1; i < x_size - 1; ++i) {
        boards.push_back({ i, 0 });
        insertToMatrix(boards.back(), 205);
        boards.push_back({ i, y_size - 1 });
        insertToMatrix(boards.back(), 205);
    }
    for (short j = 1; j < y_size - 1; ++j) {
        boards.push_back({ 0, j });
        insertToMatrix(boards.back(), 186);
        boards.push_back({ x_size - 1, j });
        insertToMatrix(boards.back(), 186);
    }
}

bool Board::checkCordInBoard(COORD cord) {
    for (auto el : boards) {
        if (el.X == cord.X && el.Y == cord.Y)
            return 1;
    }
    return 0;
}

//////////////////////class Worm;

Worm::Worm(short x, short y) : Screen::Screen(x, y) {
    srand(time(NULL));
    short rX, rY;
    rX = rand() % (x_size - 2) + 1;
    rY = rand() % (y_size - 2) + 1;
    worm = { rX, rY };
    insertToMatrix(worm, 248);
}

void Worm::deleteWorm() {
    insertToMatrix(worm, ' ');
    updatePix(worm, ' ');
}

void Worm::newWorm() {
    COORD cord;
    cord.X = (rand() % (x_size - 2)) + 1;
    cord.Y = (rand() % (y_size - 2)) + 1;
    worm = cord;
    insertToMatrix(worm, 248);
    updatePix(worm, 248);
}

//////////////////////class Worm;

void Sneak::deleteSneak() {
    direction = STOP;
    while (!sneak.empty())
        sneak.pop();
}

Sneak::Sneak(short x, short y) : Screen::Screen(x, y) {
    srand(time(NULL));
}

void Sneak::addCell(COORD cord) {
    sneak.push(cord);
    insertToMatrix(cord, 178);
    updatePix(cord, 178);
}

void Sneak::removeCell() {
    insertToMatrix(sneak.front(), ' ');
    updatePix(sneak.front(), ' ');
    sneak.pop();
}

void Sneak::initFirstCell() {
    if (sneak.empty()) {
        COORD cord;
        cord.X = (rand() % (x_size - 2)) + 1;
        cord.Y = (rand() % (y_size - 2)) + 1;
        sneak.push(cord);
        insertToMatrix(cord, 178);
        updatePix(cord, 178);
    }
}

void Sneak::initDirection() {
    direction = allDirections(rand()%4);
}

COORD Sneak::nextCOORD(allDirections dir) {
    COORD cord = sneak.back();
    switch (dir) {
        case Sneak::UP:
            ++cord.Y;
            break;
        case Sneak::DOWN:
            --cord.Y;
            break;
        case Sneak::LEFT:
            --cord.X;
            break;
        case Sneak::RIGHT:
            ++cord.X;
            break;
    }
    return cord;
}

bool Sneak::checkCordInSneak(COORD cord) {
    std::queue<COORD> temp_sneak = Sneak::sneak;
    while (!temp_sneak.empty()) {
        if (temp_sneak.front().X == cord.X && temp_sneak.front().Y == cord.Y)
            return 1;
        temp_sneak.pop();
    }
    return 0;
}


//////////////////////class Game;

Game::Game(short x, short y) : Screen::Screen(x, y), Board::Board(x, y), Worm::Worm(x, y), Sneak::Sneak(x, y) {}

bool Game::moveSnake(COORD nextCord) {
    if (nextCord.X == worm.X && nextCord.Y == worm.Y) {
        addCell(nextCord);
        newWorm();
    }
    else if (checkCordInBoard(nextCord)) {
        addCell(nextCord);
        return 0;
    }
    else if (checkCordInSneak(nextCord)) {
        return 0;
    }
    else {
        addCell(nextCord);
        removeCell();
    }

    return 1;
}

void getKeyDirection(Sneak& sneak, bool waitForDir) {
    char ch, rightCh = 100;
    while (_kbhit() || waitForDir) {
        ch = _getch();
        switch (ch) {
            case 72:
                    waitForDir = 0;     
                    rightCh = ch;
                    break;
            case 80:
                    waitForDir = 0;
                    rightCh = ch;
                    break;
            case 75:
                    waitForDir = 0;
                    rightCh = ch;
                    break;
            case 77:
                    waitForDir = 0;
                    rightCh = ch;
                    break;
        }
    }
    switch (rightCh) {
        case 72:
            if (sneak.direction != Sneak::DOWN)
                sneak.direction = Sneak::UP;
            break;
        case 80:
            if (sneak.direction != Sneak::UP)
                sneak.direction = Sneak::DOWN;
            break;
        case 75:
            if (sneak.direction != Sneak::RIGHT)
                sneak.direction = Sneak::LEFT;
            break;
        case 77:
            if (sneak.direction != Sneak::LEFT)
                sneak.direction = Sneak::RIGHT;
            break;
    }
}

void Game::startGame() {
    int speed = 400;
    show();
    newWorm();
    initFirstCell();
    //initDirection();
    getKeyDirection(dynamic_cast<Sneak&>(*this), 1);
    do {
        Sleep(speed);
        getKeyDirection(dynamic_cast<Sneak&>(*this));
    } while ( moveSnake(nextCOORD(direction)) );

}