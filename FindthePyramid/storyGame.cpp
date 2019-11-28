#include "storyGame.h"
#include "HowToGame.h"

int main() {
	system("mode con cols=119 lines=35");
	system("title �ܼ�cĳ��");
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
	printf("�ܼ�cĳ��");
	gotoxy(27, 27);
	printf("����");
	gotoxy(57, 27);
	printf("����");
	gotoxy(87, 27);
	printf("����");

	return 0;
}

int first_cursor() {
	CursorView(0);
	int end = 1;
	while (end) {
		chr = _getch();

		if (chr == 0 || chr == 0xe0) {
			chr = _getch();
			if (chr == 75) { //��
				x--;
				if (x < 1)x = 3;

			}
			else if (chr == 77) { //��
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
		printf("���� ���� *** \n");
		gotoxy(13, 7);
		printf("�� ������ �۳� tvN���� �濵�� ��� \'��ī��ĳ��\'�� �з����� �������� �� ������ �ֿ��ǵ���");
		gotoxy(13, 9);
		printf("���ݾ� ������ ����ڰ� ������ �Ͽ� ������ ������ ���� �����Դϴ�. �� ���� �����ι����� �߽�����");
		gotoxy(13, 11);
		printf("�̷���� �̾߱�� �ַ� ���� ĳ���͵���� ��ȭ�� ���� ������ �ذ��� �����ϴ�.");
		gotoxy(13, 13);
		printf("�����̿� ������, ���� �׸��� ���ְ� ���ǿ����� ���� �� �ֵ��� �����ּ��� !");

		gotoxy(10, 18);
		printf("���� ��� ***");
		gotoxy(13, 20);
		printf("��ȭ ���߿� ��Ÿ���� �������� �߿��� �˸´� �������� �����մϴ�.");
		gotoxy(13, 22);
		printf("��(�� ����Ű),��(�Ʒ� ����Ű)�� �̿��Ͽ� �������� ������ �߿��� ���ϴ�.");
		gotoxy(13, 24);
		printf("�������� �Ѿ�� ���ؼ��� ENTER Ű�� �����ϴ�.");
		gotoxy(13, 26);
		printf("* ������ �̾߱� �� �̷ΰ����� ��� ��, ��, ��, �� Ű 4������ �̿��Ͽ� �̵��մϴ�.");
		gotoxy(13, 28);
		printf("�ùٸ� ������ �� ��� ���ǿ����� �°� Ʋ�� ������ �� ��� ��忣���� �ް� �˴ϴ�.");

		gotoxy(101, 31);
		printf("+-------------+");
		gotoxy(101, 32);
		printf("|             |");
		gotoxy(101, 33);
		printf("+-------------+");
		gotoxy(103, 32); printf("Ȩ ȭ�� (H)");

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

int story1() {  //����
	view();
	gotoxy(50, 28);
	printf("�Ƕ�̵带 �������� !");
	return 0;
}

int story2() {  //����
	view();
	gotoxy(48, 28);
	printf("������ ������ ���� !");
	return 0;
}

int story3() {  //����
	view();
	gotoxy(40, 28);
	printf("���� ���ְ� ���� ���λ���� �����ϱ� ?");
	return 0;
}


/*
- ���ؼ����̳� : �Ƕ�̵带 �������� !

- ������ : ������ ������ ���� !



- ���ֳ� : ���� ���ְ� ���� ���λ���� �����ϱ� ?
*/