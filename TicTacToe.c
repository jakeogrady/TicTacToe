#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int turn = 1;
// mark represents the X or O currently being used by player
char mark;
int gridNum;

bool winner = false;

// player board
char markPos[3][3] = {
	{ ' ' , ' ' , ' ' } ,
	{ ' ' , ' ' , ' ' } ,
	{ ' ' , ' ' , ' ' }
};
// contains empty spaces for the grid

void createGrid();
void takingTurns();
void checkForWinner(int gridNum, char mark);


void main() {
	while (turn < 10 && winner == false) {
		takingTurns();
		createGrid();
		checkForWinner(gridNum, mark);
	}
}
void createGrid() {
	for (int i = 0; i < 3; i++) {
		printf("\n\t|");
		for (int j = 0; j < 3; j++) {
			printf("%c|", markPos[i][j]);
		}
	}
}
void takingTurns() {

	(turn % 2 == 0) ? (mark = 'X') : (mark = 'O');
	
	printf("\nTurn %d. Place a %c\n", turn, mark);
	printf("\n\nEnter a number between 1 - 9 (1 being top left square)\n> ");
	scanf_s("%d", &gridNum);
	gridNum--;
	turn++;
	
	// division gets the x-coordinate using player input, modulus gets y-coordinate
	if (markPos[gridNum / 3][gridNum % 3] == ' ') {
		markPos[gridNum / 3][gridNum % 3] = mark;
	}
	else {
		printf("\nIncorrect Input. Square contains symbol already");
		turn--;
	}
}
void checkForWinner(int gridNum, char mark) {
	int xCoordinate = gridNum / 3;
	int yCoordinate = gridNum % 3;
	if (markPos[xCoordinate][0] == mark && markPos[xCoordinate][1] == mark && markPos[xCoordinate][2] == mark) {
		winner = true;
	}
	else if (markPos[0][yCoordinate] == mark && markPos[1][yCoordinate] == mark && markPos[2][yCoordinate] == mark) {
		winner = true;
	}
	else if (markPos[0][0] == mark && markPos[1][1] == mark && markPos[2][2] == mark) {
		winner = true;
	}
	else if (markPos[2][0] == mark && markPos[1][1] == mark && markPos[0][2] == mark) {
		winner = true;
	}
}