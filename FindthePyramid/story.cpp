#include "story.h"

int main() {
	system("mode con cols=190 lines=50");
	system("title 콘솔c캐슬");
	CursorView(0);

	first_1();
	first_2();
	first_cursor();
}

void first_1() {
	CursorView(0);
	int x, y;
	for (y = 0; y < MAZE_BOARD_HEIGHT; y++)
	{
		for (x = 0; x < MAZE_BOARD_WIDTH; x++)
		{
			if (maze[y][x] == '1')
				printf("---------");
			if (maze[y][x] == '0')
				printf("         ");
			if (maze[y][x] == '2')
				printf("+");
			if (maze[y][x] == '3')
				printf("|");
			if (maze[y][x] == '9')
				printf("     ");
		}
		printf("\n");
	}
	gotoxy(47, 27);
	printf("+----------------+");
	gotoxy(47, 28); printf("|");
	gotoxy(47, 29); printf("|");
	gotoxy(47, 30); printf("|");
	gotoxy(47, 31); printf("|");
	gotoxy(47, 32); printf("|");
	gotoxy(47, 33); printf("|");
	gotoxy(47, 34); printf("|");
	gotoxy(47, 35); printf("|");
	gotoxy(64, 28); printf("|");
	gotoxy(64, 29); printf("|");
	gotoxy(64, 30); printf("|");
	gotoxy(64, 31); printf("|");
	gotoxy(64, 32); printf("|");
	gotoxy(64, 33); printf("|");
	gotoxy(64, 34); printf("|");
	gotoxy(64, 35); printf("|");
	gotoxy(47, 36);
	printf("+----------------+");
}
void first_2() {
	CursorView(0);
	gotoxy(53, 30);
	printf("기준집");
	gotoxy(53, 33);
	printf("스토리");
	gotoxy(93, 30);
	printf("예서집");
	gotoxy(93, 33);
	printf("스토리");
	gotoxy(133, 30);
	printf("우주집");
	gotoxy(133, 33);
	printf("스토리");
}

void first_cursor() {
	CursorView(0);
	int end = 1;
	while (end) {
		chr = _getch();
		if (chr == 0 || chr == 0xe0) {
			chr = _getch();
			if (chr == 75) { //좌
				x--;
				if (x < 1)x = 3;

			}
			else if (chr == 77) { //우
				x++;
				if (x > 3)x = 1;
			}
			else if (chr == 13 || chr == 32) {
				next = true;
				end = 0;
			}
		}
		if (x == 1) {
			gotoxy(47, 27);
			printf("+----------------+");
			gotoxy(47, 28); printf("|");
			gotoxy(47, 29); printf("|");
			gotoxy(47, 30); printf("|");
			gotoxy(47, 31); printf("|");
			gotoxy(47, 32); printf("|");
			gotoxy(47, 33); printf("|");
			gotoxy(47, 34); printf("|");
			gotoxy(47, 35); printf("|");
			gotoxy(64, 28); printf("|");
			gotoxy(64, 29); printf("|");
			gotoxy(64, 30); printf("|");
			gotoxy(64, 31); printf("|");
			gotoxy(64, 32); printf("|");
			gotoxy(64, 33); printf("|");
			gotoxy(64, 34); printf("|");
			gotoxy(64, 35); printf("|");
			gotoxy(47, 36);
			printf("+----------------+");

			gotoxy(87, 27);
			printf("                  ");
			gotoxy(87, 28); printf(" ");
			gotoxy(87, 29); printf(" ");
			gotoxy(87, 30); printf(" ");
			gotoxy(87, 31); printf(" ");
			gotoxy(87, 32); printf(" ");
			gotoxy(87, 33); printf(" ");
			gotoxy(87, 34); printf(" ");
			gotoxy(87, 35); printf(" ");
			gotoxy(104, 28); printf(" ");
			gotoxy(104, 29); printf(" ");
			gotoxy(104, 30); printf(" ");
			gotoxy(104, 31); printf(" ");
			gotoxy(104, 32); printf(" ");
			gotoxy(104, 33); printf(" ");
			gotoxy(104, 34); printf(" ");
			gotoxy(104, 35); printf(" ");
			gotoxy(87, 36);
			printf("                  ");

			gotoxy(127, 27);
			printf("                  ");
			gotoxy(127, 28); printf(" ");
			gotoxy(127, 29); printf(" ");
			gotoxy(127, 30); printf(" ");
			gotoxy(127, 31); printf(" ");
			gotoxy(127, 32); printf(" ");
			gotoxy(127, 33); printf(" ");
			gotoxy(127, 34); printf(" ");
			gotoxy(127, 35); printf(" ");
			gotoxy(144, 28); printf(" ");
			gotoxy(144, 29); printf(" ");
			gotoxy(144, 30); printf(" ");
			gotoxy(144, 31); printf(" ");
			gotoxy(144, 32); printf(" ");
			gotoxy(144, 33); printf(" ");
			gotoxy(144, 34); printf(" ");
			gotoxy(144, 35); printf(" ");
			gotoxy(127, 36);
			printf("                  ");
		}
		else if (x == 2) {
			gotoxy(47, 27);
			printf("                  ");
			gotoxy(47, 28); printf(" ");
			gotoxy(47, 29); printf(" ");
			gotoxy(47, 30); printf(" ");
			gotoxy(47, 31); printf(" ");
			gotoxy(47, 32); printf(" ");
			gotoxy(47, 33); printf(" ");
			gotoxy(47, 34); printf(" ");
			gotoxy(47, 35); printf(" ");
			gotoxy(64, 28); printf(" ");
			gotoxy(64, 29); printf(" ");
			gotoxy(64, 30); printf(" ");
			gotoxy(64, 31); printf(" ");
			gotoxy(64, 32); printf(" ");
			gotoxy(64, 33); printf(" ");
			gotoxy(64, 34); printf(" ");
			gotoxy(64, 35); printf(" ");
			gotoxy(47, 36);
			printf("                  ");

			gotoxy(87, 27);
			printf("+----------------+");
			gotoxy(87, 28); printf("|");
			gotoxy(87, 29); printf("|");
			gotoxy(87, 30); printf("|");
			gotoxy(87, 31); printf("|");
			gotoxy(87, 32); printf("|");
			gotoxy(87, 33); printf("|");
			gotoxy(87, 34); printf("|");
			gotoxy(87, 35); printf("|");
			gotoxy(104, 28); printf("|");
			gotoxy(104, 29); printf("|");
			gotoxy(104, 30); printf("|");
			gotoxy(104, 31); printf("|");
			gotoxy(104, 32); printf("|");
			gotoxy(104, 33); printf("|");
			gotoxy(104, 34); printf("|");
			gotoxy(104, 35); printf
		}
	}