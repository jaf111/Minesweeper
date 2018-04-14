#pragma once
#include <vector>
using namespace std;


class Minesweeper {
private:
	struct Tile {
		bool open;
		bool mine;
		bool flag;
	};
	vector <vector<Tile>> brett;
	int width;
	int height;
	int mines;
	bool gameOver = false;
	int opend = 0;
	
	
public:
    Minesweeper(int width, int height, int mines);
    ~Minesweeper();

    bool isGameOver() const;
	bool win() const;

    bool isTileOpen(int row, int col) const;
    bool isTileMine(int row, int col) const;

    void openTile(int row, int col);

    int numAdjacentMines(int row, int col) const;
	void mark(int row, int col);
	bool isTileFlag(int row, int col) const;
    	
    Minesweeper(const Minesweeper &) = delete;
    Minesweeper &operator=(const Minesweeper &) = delete;
};
