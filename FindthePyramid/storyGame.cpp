#include "storyGame.h"
#include "HowToGame.h"

int main() {
	system("mode con cols=119 lines=35");
	system("title 콘솔c캐슬");
	CursorView(0);

	int wh = 1;
	int next = 0;

	while (wh) {
		
		system("cls");
		First();

		system("cls");
		next = way();
		if (next == 1) {
			next = 0;
			if (x == 1) {
				system("cls");
				story1();
			}
			else if (x == 2) {
				system("cls");
				story2();
			}
			else if (x == 3) {
				system("cls");
				story3();
			}
		}
		next = _getch();
	}
}

///////////////////////////////////////////////////////////////////////////

int First() {
	x = 1;
	first_1();
	first_2();
	first_cursor();

	return 0;
}

int first_1() {
	CursorView(0);
	int x, y;
	for (y = 0; y < MAZE_BOARD_HEIGHT; y++)
	{
		for (x = 0; x < MAZE_BOARD_WIDTH; x++)
		{
			if (maze[y][x] == '1')
				printf("----");
			if (maze[y][x] == '0')
				printf("    ");
			if (maze[y][x] == '2')
				printf("+");
			if (maze[y][x] == '3')
				printf("|");
			if (maze[y][x] == '9')
				printf("  ");
		}
		printf("\n");
	}

	gotoxy(20, 24);
	printf("+----------------+");
	gotoxy(20, 25);
	printf("|");
	gotoxy(20, 26);
	printf("|");
	gotoxy(20, 27);
	printf("|");
	gotoxy(20, 28);
	printf("|");
	gotoxy(20, 29);
	printf("|");
	gotoxy(20, 30);

	gotoxy(37, 25);
	printf("|");
	gotoxy(37, 26);
	printf("|");
	gotoxy(37, 27);
	printf("|");
	gotoxy(37, 28);
	printf("|");
	gotoxy(37, 29);
	printf("|");
	gotoxy(20, 30);
	printf("+----------------+");

	return 0;
}

int first_2() {
	CursorView(0);
	gotoxy(56, 11);
	printf("콘솔c캐슬");
	gotoxy(27, 27);
	printf("기준");
	gotoxy(57, 27);
	printf("예서");
	gotoxy(87, 27);
	printf("우주");

	return 0;
}

int first_cursor() {
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
		}
		else if (chr == 13 || chr == 32) {
			next = true;
			end = 0;
		}
		if (x == 1) {
			gotoxy(20, 24);
			printf("+----------------+");
			gotoxy(20, 25);
			printf("|");
			gotoxy(20, 26);
			printf("|");
			gotoxy(20, 27);
			printf("|");
			gotoxy(20, 28);
			printf("|");
			gotoxy(20, 29);
			printf("|");
			gotoxy(20, 30);

			gotoxy(37, 25);
			printf("|");
			gotoxy(37, 26);
			printf("|");
			gotoxy(37, 27);
			printf("|");
			gotoxy(37, 28);
			printf("|");
			gotoxy(37, 29);
			printf("|");
			gotoxy(20, 30);
			printf("+----------------+");

			gotoxy(50, 24);
			printf("                  ");
			gotoxy(50, 25);
			printf(" ");
			gotoxy(50, 26);
			printf(" ");
			gotoxy(50, 27);
			printf(" ");
			gotoxy(50, 28);
			printf(" ");
			gotoxy(50, 29);
			printf(" ");
			gotoxy(50, 30);

			gotoxy(67, 25);
			printf(" ");
			gotoxy(67, 26);
			printf(" ");
			gotoxy(67, 27);
			printf(" ");
			gotoxy(67, 28);
			printf(" ");
			gotoxy(67, 29);
			printf(" ");
			gotoxy(50, 30);
			printf("                  ");

			gotoxy(80, 24);
			printf("                  ");
			gotoxy(80, 25);
			printf(" ");
			gotoxy(80, 26);
			printf(" ");
			gotoxy(80, 27);
			printf(" ");
			gotoxy(80, 28);
			printf(" ");
			gotoxy(80, 29);
			printf(" ");
			gotoxy(80, 30);

			gotoxy(97, 25);
			printf(" ");
			gotoxy(97, 26);
			printf(" ");
			gotoxy(97, 27);
			printf(" ");
			gotoxy(97, 28);
			printf(" ");
			gotoxy(97, 29);
			printf(" ");
			gotoxy(80, 30);
			printf("                  ");
		}
		else if (x == 2) {
			gotoxy(20, 24);
			printf("                  ");
			gotoxy(20, 25);
			printf(" ");
			gotoxy(20, 26);
			printf(" ");
			gotoxy(20, 27);
			printf(" ");
			gotoxy(20, 28);
			printf(" ");
			gotoxy(20, 29);
			printf(" ");
			gotoxy(20, 30);

			gotoxy(37, 25);
			printf(" ");
			gotoxy(37, 26);
			printf(" ");
			gotoxy(37, 27);
			printf(" ");
			gotoxy(37, 28);
			printf(" ");
			gotoxy(37, 29);
			printf(" ");
			gotoxy(20, 30);
			printf("                  ");

			gotoxy(50, 24);
			printf("+----------------+");
			gotoxy(50, 25);
			printf("|");
			gotoxy(50, 26);
			printf("|");
			gotoxy(50, 27);
			printf("|");
			gotoxy(50, 28);
			printf("|");
			gotoxy(50, 29);
			printf("|");
			gotoxy(50, 30);

			gotoxy(67, 25);
			printf("|");
			gotoxy(67, 26);
			printf("|");
			gotoxy(67, 27);
			printf("|");
			gotoxy(67, 28);
			printf("|");
			gotoxy(67, 29);
			printf("|");
			gotoxy(50, 30);
			printf("+----------------+");

			gotoxy(80, 24);
			printf("                  ");
			gotoxy(80, 25);
			printf(" ");
			gotoxy(80, 26);
			printf(" ");
			gotoxy(80, 27);
			printf(" ");
			gotoxy(80, 28);
			printf(" ");
			gotoxy(80, 29);
			printf(" ");
			gotoxy(80, 30);

			gotoxy(97, 25);
			printf(" ");
			gotoxy(97, 26);
			printf(" ");
			gotoxy(97, 27);
			printf(" ");
			gotoxy(97, 28);
			printf(" ");
			gotoxy(97, 29);
			printf(" ");
			gotoxy(80, 30);
			printf("                  ");
		}
		else if (x == 3) {
			gotoxy(20, 24);
			printf("                  ");
			gotoxy(20, 25);
			printf(" ");
			gotoxy(20, 26);
			printf(" ");
			gotoxy(20, 27);
			printf(" ");
			gotoxy(20, 28);
			printf(" ");
			gotoxy(20, 29);
			printf(" ");
			gotoxy(20, 30);

			gotoxy(37, 25);
			printf(" ");
			gotoxy(37, 26);
			printf(" ");
			gotoxy(37, 27);
			printf(" ");
			gotoxy(37, 28);
			printf(" ");
			gotoxy(37, 29);
			printf(" ");
			gotoxy(20, 30);
			printf("                  ");

			gotoxy(50, 24);
			printf("                  ");
			gotoxy(50, 25);
			printf(" ");
			gotoxy(50, 26);
			printf(" ");
			gotoxy(50, 27);
			printf(" ");
			gotoxy(50, 28);
			printf(" ");
			gotoxy(50, 29);
			printf(" ");
			gotoxy(50, 30);

			gotoxy(67, 25);
			printf(" ");
			gotoxy(67, 26);
			printf(" ");
			gotoxy(67, 27);
			printf(" ");
			gotoxy(67, 28);
			printf(" ");
			gotoxy(67, 29);
			printf(" ");
			gotoxy(50, 30);
			printf("                  ");

			gotoxy(80, 24);
			printf("+----------------+");
			gotoxy(80, 25);
			printf("|");
			gotoxy(80, 26);
			printf("|");
			gotoxy(80, 27);
			printf("|");
			gotoxy(80, 28);
			printf("|");
			gotoxy(80, 29);
			printf("|");
			gotoxy(80, 30);

			gotoxy(97, 25);
			printf("|");
			gotoxy(97, 26);
			printf("|");
			gotoxy(97, 27);
			printf("|");
			gotoxy(97, 28);
			printf("|");
			gotoxy(97, 29);
			printf("|");
			gotoxy(80, 30);
			printf("+----------------+");
		}

	}

	return 0;
}

int view() {
	CursorView(0);
	int x, y;
	gotoxy(0, 34);
	for (y = 0; y < MAZE_BOARD_HEIGHT2; y++)
	{
		for (x = 0; x < MAZE_BOARD_WIDTH2; x++)
		{
			if (meze[y][x] == '1')
				printf("----");
			if (meze[y][x] == '0')
				printf("    ");
			if (meze[y][x] == '2')
				printf("+");
			if (meze[y][x] == '3')
				printf("|");
			if (meze[y][x] == '9')
				printf("  ");
		}
		printf("\n");
	}

	return 0;
}

///////////////////////////////////////////////////////////////////////////

int mainView2() {
	int x, y;
	for (y = 0; y < MAZE_BOARD_HEIGHT3; y++)
	{
		for (x = 0; x < MAZE_BOARD_WIDTH3; x++)
		{
			if (maze2[y][x] == '1')
				printf("----");
			if (maze2[y][x] == '0')
				printf("    ");
			if (maze2[y][x] == '2')
				printf("+");
			if (maze2[y][x] == '3')
				printf("|");
			if (maze2[y][x] == '9')
				printf("  ");
		}
		printf("\n");
	}
	return 0;
}

int way() {
	mainView2();
	
	int end = 1;
	while (end) {
		gotoxy(10, 4);
		printf("게임 설명 *** \n");
		gotoxy(13, 7);
		printf("위 게임은 작년 tvN에서 방영된 드라마 \'스카이캐슬\'를 패러디한 게임으로 각 집안의 주요사건들을");
		gotoxy(13, 9);
		printf("조금씩 각색해 사용자가 선택을 하여 각각의 엔딩을 보는 게임입니다. 네 명의 등장인물들을 중심으로");
		gotoxy(13, 11);
		printf("이루어진 이야기로 주로 게임 캐릭터들과의 대화를 통해 문제를 해결해 나갑니다.");
		gotoxy(13, 13);
		printf("기준이와 서준이, 예서 그리고 우주가 해피엔딩을 맞을 수 있도록 도와주세요 !");

		gotoxy(10, 18);
		printf("게임 방법 ***");
		gotoxy(13, 20);
		printf("대화 도중에 나타나는 선택지들 중에서 알맞는 선택지를 선택합니다.");
		gotoxy(13, 22);
		printf("↑(위 방향키),↓(아래 방향키)를 이용하여 여러가지 선택지 중에서 고릅니다.");
		gotoxy(13, 24);
		printf("다음으로 넘어가기 위해서는 ENTER 키를 누릅니다.");
		gotoxy(13, 26);
		printf("* 우주의 이야기 중 미로게임의 경우 →, ←, ↑, ↓ 키 4가지를 이용하여 이동합니다.");
		gotoxy(13, 28);
		printf("올바른 선택을 할 경우 해피엔딩을 맞고 틀린 선택을 할 경우 배드엔딩을 겪게 됩니다.");

		gotoxy(101, 31);
		printf("+-------------+");
		gotoxy(101, 32);
		printf("|             |");
		gotoxy(101, 33);
		printf("+-------------+");
		gotoxy(103, 32); printf("홈 화면 (H)");

		chr = _getch();

		if (chr == 72 || chr == 104) {
			return 0;
		}
		else if (chr == 13 || chr == 32) {
			next = true;
			end = 0;
			return 1;
		}

	}
}

int story1() {  //기준
	view();
	gotoxy(50, 28);
	printf("피라미드를 깨버려라 !");
	return 0;
}

int story2() {  //예서
	view();
	gotoxy(48, 28);
	printf("우주의 마음을 얻어라 !");
	return 0;
}

int story3() {  //우주
	view();
	gotoxy(40, 28);
	printf("정말 우주가 혜나 살인사건의 범인일까 ?");
	return 0;
}


/*
- 기준서준이네 : 피라미드를 깨버려라 !

- 예서네 : 우주의 마음을 얻어라 !



- 우주네 : 정말 우주가 혜나 살인사건의 범인일까 ?
*/