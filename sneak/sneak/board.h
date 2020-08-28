#ifndef board__
#define board__
#include <windows.h>
#include <vector>
#include <queue>

class Screen {
private:
	std::vector< std::vector<char>> matrix;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
protected:
	short x_size, y_size;
public:
	Screen() {};
	Screen(short x, short y);
	void clearScreen();
	void updatePix(COORD cord, char sign);
	void show();
	int xSize() const { return x_size; }
	int ySize() const { return y_size; }
	void insertToMatrix(COORD coords, char sign);
	virtual ~Screen() {};
	void clearMatrix();
};

class Board : virtual public Screen {
protected:
	std::vector<COORD> boards;
public:
	Board(short x, short y);
	bool checkCordInBoard(COORD cord);
};


class Worm : virtual public Screen {
protected:
	COORD worm;
public:
	Worm(short x, short y);
	void deleteWorm();
	void newWorm();
};

class Sneak : virtual public Screen {
protected:
	std::queue<COORD> sneak;
	enum allDirections { UP = 0, DOWN, RIGHT, LEFT, STOP };
	allDirections direction = STOP;
public:
	Sneak(short x, short y);
	void addCell(COORD cord);
	void removeCell();
	void initFirstCell();
	void initDirection();
	void deleteSneak();
	bool checkCordInSneak(COORD cord);
	friend void getKeyDirection(Sneak& sneak, bool waitForDir = 0);
	COORD nextCOORD(allDirections dir);	
};

class Game : public Board, public Worm, public Sneak {
public:
	Game(short x, short y);
	bool moveSnake(COORD nextCord);
	void startGame();
};





#endif // !board__