#include "Minesweeper.h"
#include <vector>
#include <iostream>
using namespace std;

Minesweeper::Minesweeper(int width, int height, int mines) : width(width), height(height), mines(mines) {
	for (int i = 0; i < height; i++) {
		vector <Tile> row;
		for (int j = 0; j < width; j++) {
			Tile tile;
			tile.open = false;
			tile.mine = false;
			tile.flag = false;
			row.push_back(tile);
		}
		brett.push_back(row);
	}

	// Placing Mines 
	while (mines > 0) {
		int r = rand() % (height); 
		int c = rand() % (width);
		if (brett[r][c].mine == false) {
			brett[r][c].mine = true;
			mines--;
		}
	}

}


Minesweeper::~Minesweeper() {
}

bool Minesweeper::isGameOver() const {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (isTileOpen(i, j) && gameOver) {
				return true;
			}
		}
	}
	return false;
}

bool Minesweeper::win() const {
	if (((width*height) - mines) == opend) {
		return true;
	}
	return false;
}

bool Minesweeper::isTileOpen(int row, int col) const {
	if ((col < width && col >= 0) && (row < height && row >= 0)) {
		if (brett[row][col].open) {
			return true;
		}
	}
	return false;
}

bool Minesweeper::isTileMine(int row, int col) const {
	if (brett[row][col].mine) {
		return true;
	}
	return false;
}

void Minesweeper::openTile(int row, int col) {
	if (isTileMine(row, col)) {
		gameOver = true;
	}
	
	for (int i = row - 1; i < row + 2; i++) {
		for (int j = col - 1; j < col + 2; j++) {
			if (i >= 0 && j >= 0 && i < height && j < width) {
				if ((brett[i][j].open == false) && (isTileMine(i, j) == false)) {
					brett[i][j].open = true;
					opend++;
					if (numAdjacentMines(i, j) == 0) {
						openTile(i, j);

					}
				}
			}
		}
	}
}

int Minesweeper::numAdjacentMines(int row, int col) const {
	int numMines = 0;
	for (int i = row - 1; i < row + 2; i++) {
		for (int j = col - 1; j < col + 2; j++) {
			if (i >= 0 && j >= 0 && i< height && j< width) {
				if (isTileMine(i, j)) {
					numMines++;
				}
			}
		}
	}
	return numMines;

}

void Minesweeper::mark(int row, int col){
	if (brett[row][col].open == false && brett[row][col].flag == false) {
		brett[row][col].flag = true;
	}
	else if (brett[row][col].open == false && brett[row][col].flag == true) {
		brett[row][col].flag = false;
	}
	// brett[row][col].flag = !brett[row][col].flag
}

bool Minesweeper::isTileFlag(int row, int col) const {
	if (brett[row][col].flag) {
		return true;
	}
	return false;
}

