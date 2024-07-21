#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

char board[3][3];
bool exit_flag;
char winner;
int x, y, k, i;

void init_board() {
	// 보드를 초기화한다. 
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++) board[x][y] = ' ';
}

void print_board() {
	printf("---|---|---\n");
	for (i = 0; i < 3; i++) {
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
	}
	printf("---|---|---\n");
	system("pause");
	system("cls");
}

void user_turn() {
	puts("당신의 턴입니다. 가로, 세로 번호를 0, 1, 2 중 선택하세요.");
	scanf(" %d %d", &x, &y);
	board[x][y] = 'o';
	system("cls");
}

void comp_turn() {
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++) if (board[x][y] == ' ') {
			board[x][y] = 'x';
			return;
		}
}

bool is_going() {
	exit_flag = true;
	for (x = 0; x < 3 && exit_flag; x++) {
		for (y = 1; y < 3 && exit_flag; y++) if (board[x][y] != ' ' || board[x][y] != board[x][y - 1]) {
			exit_flag = false;
			winner = board[x][y];
		}
	}
	if (exit_flag) return false;
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		winner = board[0][0];
		return false;
	}
	else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		winner = board[0][2];
		return false;
	}
	else return true;
}

int main(void) {
	init_board();
	int i = 0;
	do {
		if (i % 2 == 0) {
			user_turn();
			print_board();
		}
		else {
			comp_turn();
			print_board();
		}
		i++;
	} while (is_going() && i < 9);
	if (i < 9) {
		printf("승자는 ");
		printf(winner == 'o' ? "플레이어입니다!" : "컴퓨터입니다!");
	}
	else {
		printf("무승부입니다!");
	}
	return 0;
}
