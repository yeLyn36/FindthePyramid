#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<windows.h>
#include <conio.h>

#define MAZE_BOARD_HEIGHT 14 //��� ��ȭâ ����
#define MAZE_BOARD_WIDTH 20 //��� ��ȭâ �ʺ�
#define UP 72 //����Ű ��
#define DOWN 80 //����Ű �Ʒ� 

int key, choose, answer;
int diningroom = 0;
int bedroom = 0;
int password = 0; //��ȣŰ
int deskKey = 0; //����
int roop = 1;
int pyramid = 0;

int maze[MAZE_BOARD_HEIGHT][MAZE_BOARD_WIDTH] = {
	{ '9' },
{ '9' },
{ '9','2','1','1','1','1','1','1','1','1','1','1','1','1','1','2' },
{ '9','3','7','0','0','0','0','0','0','0','0','0','0','0','0','3' },
{ '9','3','0','0','0','0','0','0','0','0','0','0','0','0','0','3' },
{ '9','3','0','0','0','0','0','0','0','0','0','0','0','0','0','3' },
{ '9','3','0','0','0','0','0','0','0','0','0','0','0','0','0','3' },
{ '9','3','0','0','0','0','0','0','0','0','0','0','0','0','0','3' },
{ '9','3','0','0','0','0','0','0','0','0','0','0','0','0','0','3' },
{ '9','3','0','0','0','0','0','0','0','0','0','0','0','0','0','3' },
{ '9','3','0','0','0','0','0','0','0','0','0','0','0','6','5','3' },
{ '9','3','0','0','0','0','0','0','0','0','0','0','0','0','0','3' },
{ '9','3','0','0','0','0','0','0','0','0','0','0','0','0','0','3' },
{ '9','2','1','1','1','1','1','1','1','1','1','1','1','1','1','2' }
};

void mainView(); //��ȭâ �׸���
void CursorView(char); //Ŀ�� ����ǥ��
int keyControl(); //ȭ��ǥ �̵�
void next(); //��ȭ â ���� ���� ȭ������ �Ѿ�� : ��Ʈ�ο� �������� ���
void nextScene(); //��ȭâ ����鼭 ���� ȭ������ �Ѿ�� : ��ȭ Ȥ�� ���ÿ��� ���
void gotoxy(int, int); //��ǥ �̵�

void mainView() {
	int x, y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for (y = 0; y < MAZE_BOARD_HEIGHT; y++) {
		for (x = 0; x < MAZE_BOARD_WIDTH; x++) {
			if (maze[y][x] == '1')
				printf("--------");
			if (maze[y][x] == '0')
				printf("        ");
			if (maze[y][x] == '2')
				printf("+");
			if (maze[y][x] == '3')
				printf("|");
			if (maze[y][x] == '9')
				printf("      ");
			if (maze[y][x] == '5')
				printf("<��      ");
			if (maze[y][x] == '6')
				printf("(ENTER) ");
			if (maze[y][x] == '7')
				printf("  ������");
		}
		printf("\n");
	}
}// mainView();

int keyControl() {
	answer = 1;
	int x = 20, y = 5, end = 1;
	gotoxy(x, y);
	printf("��");
	while(end){
		key = _getch();
		if (key == UP) { //��
			y -= 4;
			if (y < 5) y = 5;
			gotoxy(x, y+4);
			printf(" ");
			gotoxy(x, y);
			printf("��");
			answer--;
		} //UP if
		else if (key == DOWN) { //�Ʒ�
			y += 4;
			if (y > 14) y = 13;
			gotoxy(x, y - 4);
			printf(" ");
			gotoxy(x, y);
			printf("��");
			answer++;
		} //DOWN if
		else if (key == 13) {
			//next = true;
			end = 0;
			return answer;
		} //else if
	} //while
} // keyControl()

void textColor(int i) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void CursorView(char show){
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
} //CursorView

void gotoxy(int x, int y) {
	COORD Pos = { x, y + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
} //gotoxy

void next() { //��ȭ â ���� ���� ȭ������ �Ѿ�� : ��Ʈ�ο� �������� ���
	key = _getch();
	if (key == 13)
		system("cls");
} //next()

void nextScene() { //���� ȭ������ �Ѿ�� : ��ȭ�� ������ �� ���
	key = _getch();
	if (key == 13) 
		system("cls");
		gotoxy(0, 17); 
		mainView();
} //nextScene()

void main() {
	system("mode con cols=120 lines=35");
	system("title CPUĳ��");
	CursorView(0);

	gotoxy(20, 13);
	textColor(8); //text color = gray
	//text color (������ 12, ����� 13, ���� 14, ?? 11, ������ 7, ������ 10, ���� �ؽ�Ʈ 8), ��Ʈ�ο����� �۾�ü ����, ���� �����ϸ� ����, ���� �Ͼ��
	printf("- 20XX�� 6�� �� ��ī�� ĳ�� ������ �����̳�");
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(12); //text color = red
	gotoxy(20, 13);	printf("\"������!!!!!! ������!!!!!! ���� �� �ϰ� �� �ϰ� �־�!!!!!!!!\"");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(7);
	gotoxy(20, 13);	printf("\"��.. ���� 7�ùۿ� �� ���ݾƿ�.\"");
	textColor(10);
	gotoxy(20, 16);	printf("\"���� ������ 3�ÿ� ��µ�..\"");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(12); //text color = red
	gotoxy(20, 13);	printf("\"��ħ���� ������ ���� ������ �Ƕ�̵� ����⿡ ���� �� ����, �׷��ϱ� ..\"");

	textColor(7);
	gotoxy(20, 18);	printf("(�� �Ƕ�̵�.. ���� ���ֹ����� �ȵǳ� ..)");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(7);
	gotoxy(20, 13);	printf("\"��, ���ؾ�.");
	gotoxy(20, 15);	printf("�츮, �� �Ƕ�̵� ���ٱ� ?\"");
	textColor(10);
	gotoxy(25, 18);	printf("\"�� ? �ƺ��� ���� ���������ϴ� ���� ?\"");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(7);
	gotoxy(20, 13);	printf("\"����, �� �� �տ� ������ ������ ���ϰ���.\"\n");
	textColor(8);
	gotoxy(40, 25); printf("(���ѷαװ� �������ϴ�. Enter Ű�� ���� ���� ȭ������ �Ѿ �ּ���.)");
	// Finished intro

	nextScene();
	textColor(8); //change text color
	gotoxy(20, 8);	printf("-���� 2��, �����̳� ���� ��ΰ� �ῡ ���� �� ���߿� �����̿� �������� �濡�� ����");
	gotoxy(20, 10);	printf("�Һ��� ����Դ�.");
	nextScene();

	textColor(7);
	gotoxy(20, 8);	printf("\"���ؾ�, �Ͼ\"");

	key = _getch();
	if (key == 13) {
		gotoxy(15, 22);	printf("\"� ��ø�\"");
	} //enter if
	nextScene();

	gotoxy(15, 22);
	printf("\"�� �� ì�ܾ��ؼ�, �� .. �̰Ÿ� �ǰ��� ?\"");
	gotoxy(28, 5);	printf("- ��ο� ���� ���� �ڵ���");
	gotoxy(28, 9);	printf("- �Ƕ�̵带 ��ĥ �ָӴ�");
	gotoxy(28, 13);	printf("- �̲����� ���� �尩");

	nextScene();
	gotoxy(15, 22);	printf("\"����.\"");

	nextScene();
	gotoxy(15, 22);	printf("\"�ٵ�, ���� ������ ����?\"");

	while (roop) {
		nextScene();
		gotoxy(28, 5);	printf("�ƺ��� �Ƴ��� �͵鸸 �ִ� �ƺ��� ����");
		gotoxy(28, 9);	printf("���������� �ص� ���Ŀ��� �Ƕ�̵带 �ڶ��ϴ� �Ž�"); //�� ���� ������ diningroom = 0 -> 1;
		gotoxy(28, 13);	printf("�ƺ� ������ ���� �ڰ� ��ô� ħ��");// �� ���� ���� �� bedroom = 0 -> 1;

		choose = keyControl();
		system("cls");
		gotoxy(0, 17);
		mainView();

		gotoxy(20, 8);	printf("\"��� ���ܳ����� �� ���� ?\"");

		key = _getch();
		if (key == 13) {
			switch (choose) {
			case 1: 
				gotoxy(15, 22);	printf("\"�ƺ� ����� ����.\"");
				nextScene();

				gotoxy(20, 8);	printf("\"���ؾ�, �츮 �������� ..?\"");

				key = _getch();
				if (key == 13) {
					gotoxy(15, 22);	printf("\"���ڱ� ���� �Ҹ���? ���� ��\"");
				} //enter if


				key = _getch();
				if (key == 13) {
					if (password == 1 && deskKey == 1) {
						roop = 0;

						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);	printf("\"��.. �Ʊ� ã�� ���踻�̾�, ���� ���� ���谰����?\"");

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"��, �ѹ� �����.\"");
						} //enter if

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("                                          ");
							gotoxy(20, 8);	printf("\'�ٵ� �� ���� �� �ϴ� �� ����...?\'");
						} //enter if

						nextScene();
						gotoxy(20, 8);	printf("- ö��");

						nextScene();
						gotoxy(20, 8);	printf("\"���ȴ�.\"");

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"�ȿ� �� �־�?\"");
						} //enter if

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("                                          ");
							gotoxy(20, 8);	printf("\"�� ���,\"'");
						} //enter if

						nextScene();
						gotoxy(28, 5);	printf("�� ����");//�� ������ ��� : �Ƕ�̵带 ���ܳ��Ҵٰ� ǥ�õ� ���� ����, �ɸ��� ��
						gotoxy(28, 9);	printf("�Ƕ�̵� å"); //�Ƕ�̵� å�� ��� : ������� ���� ���� ����
						gotoxy(28, 13);	printf("�ϱ���"); //������ �ϱ��� �� ��� : �Ǿ� �忡 �� ��ȣŰ : �ڵ��� �޸� 1�� �� �̶�� �ۼ��Ǿ� ����->�ݰ� ã��

						//�� ���� ������ ����� �� ��쿣 �ϱ��� ��� ����

						choose = keyControl();

						switch (choose) {
						case 1:
							system("cls");
							gotoxy(0, 17);
							mainView();

							gotoxy(15, 22);	printf("\"�� ���󵵰��� �͵� �־� �츮?\"");
							
							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"�׷��ϱ�, �ű⿡ ���� �־�?\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"�� .. �Ƕ�̵� �ִ� �� �������. �� ���� ��¥ ������.\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"����.. �峭�ƴϴ�. ���� ���� ������ ��¥.\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("                                       ");
								gotoxy(15, 22);	printf("\"�׷�. ���� ��¥ ����.\"");
							} //enter if

							nextScene();
							textColor(8);
							gotoxy(20, 5);	printf("�� ���󵵿� ���� �Ƕ�̵� ��ġ�� ������ ��� �� �� ���󵵴� ��¥�����ϴ� !!!");
							gotoxy(20, 7);	printf("��¥ �Ƕ�̵� ��ġ�� �� �����̿� �����̴� �ٽ� ����� �޷��ͼ� �ٸ� ���Ÿ�");
							gotoxy(20, 9);	printf("ã���� ������, �̹� ��ħ 7�� ���ð��� �ٰ����� ��¿ �� ���� �����ϰ� �������� �̷�ϴ�.");

							key = _getch();
							if (key == 13) {
								roop = 0;
								system("cls");
							} //enter if
							break;
						case 2:
							system("cls");
							gotoxy(0, 17);
							mainView();

							gotoxy(15, 22);	printf("\".. �̰� �� ����, ��¥ ¡�׷��� ����.\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"�� .. �� ��¦ �Ҹ����Ҵµ� ����.\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"�̰� ������, ���� �������̳� �����.\"");
							} //enter if
						case 3:
							system("cls");
							gotoxy(0, 17);
							mainView();

							gotoxy(15, 22);	printf("\".. �츮 �ƺ� �ϱ⵵ ��?\"");
							

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"��.. ���ó� ����, �� ���� �־� ??\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"2016�� 3�� 1��, ������ ������ �� �༮�� ���� �⿴��. �Ƕ�̵� ����, ���� �̰ŵ� �Ƕ�̵��?\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"����.. �ϱ��忡�� �׷� �� ���ó�.      \"");
							} //enter if

							nextScene();
							gotoxy(15, 22);	printf("\"��, �� �ƺ� �ڵ��� �����Ծ��� �츮,\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"����, �ٵ� �� ?\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"�ƴ�, �ű� �޸��� ���� ù��°�� ��ȣŰ��� ǥ���� �����ִµ�..?\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"��? ����, ��ø� ..\"");
							} //enter if

							next();
							gotoxy(25, 10);	printf("------------------");
							gotoxy(25, 11);	printf("|                 |");
							gotoxy(25, 12);	printf("|  ������ ����    |");
							gotoxy(25, 13);	printf("|    0102         |");
							gotoxy(25, 14);	printf("|                 |");
							gotoxy(25, 15);	printf("------------------");

							nextScene();
							gotoxy(15, 22);	printf("\"����, ���� �����̳ס�\"");

							key = _getch();
							if (key == 13) {
								gotoxy(15, 24);	printf("\"�Է��غ� ����,\"");
							} //enter if
							
							nextScene();
							gotoxy(15, 8); printf("- ��");

							key = _getch();
							if (key == 13) {
								gotoxy(15, 10); printf("- ��");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 12); printf("- ��");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 14); printf("- ��");
							} //enter if
							

							nextScene();
								gotoxy(20, 8);	printf("\"����? ���� ������ ��\"");

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"��, �Ƕ�̵� ���� �ִ� !!!!\"");
								pyramid = 1;
							} //enter if
							
							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"��, �ָӴϿ� ���ܼ� ������.\"");
								pyramid = 1;
							} //enter if
							break;
						}

					} //enter if
					else {
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);
						printf("\"���� .. �� �ݰ� ã����.. �� ���� �� ����\"");

						nextScene();
							gotoxy(15, 22);
							printf("\"�� ����, ��ȣŰ �־�� �ϴµ� ? \"");
						
						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);
							printf("\"���⵵ ���� �־�� �� �� ����, �� ����\"");
						} //enter if

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);
							printf("                                           ");
							gotoxy(15, 22);
							printf("\"..�ٸ��� ���� ã��\"");
						} //enter if
					} //else (��ȣŰ�� ���谡 ���� ��쿡 ���縦 ������ �ٸ� ���� ���� ã�� ����)
				} //if (���縦 ã������ ��)
				break;
			case 2:
				if (diningroom == 1) {
					gotoxy(15, 22);	printf("���� �þ����ϱ� �ٸ� �� ����.");
					nextScene();
				} //if (�̹� �Ž��� �湮��)
				else {
					gotoxy(15, 22);
					printf("�Žǿ� ���� �� ���� �ʳ� ?");
					nextScene();
					gotoxy(15, 22);	printf("\"���� ���� ? ������, ���� �ڿ� �� ã�ƺ�.\"");
					gotoxy(20, 8);	printf("- ����");

					nextScene();
					gotoxy(20, 8);	printf("\"�� ��¥\"");

					key = _getch();
					if (key == 13) {
					textColor(11);
					gotoxy(20, 8);	printf("\"�ű� ������ ? \"");
					} //enter if

					key = _getch();
					if (key == 13) {
						textColor(7);
						gotoxy(15, 22);	printf(" ... ��� ���� ?");
					} //enter if

					nextScene();
					gotoxy(28, 5);	printf("������ ô�ϸ鼭 �� ������ Ƣ�����.");
					gotoxy(28, 9);	printf("�� ���÷� ���� ô�ϸ鼭 �������� ���ƺ���.");
					gotoxy(28, 13);	printf("���� ��Ǵ�� ���ϰ� �뼭�� ���Ѵ�.");

					choose = keyControl();

					switch (choose) {
					case 1: system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 22);	printf("��, �𸣰ڴ� Ƣ�� !!!");

						nextScene();
						textColor(8);
						gotoxy(20, 5);	printf("������ �����̿� �����̴� �� ������ �پ���� �� ���÷� ���� ������ ���� ");
						gotoxy(20, 7);	printf("������ �Ű��ϰ�, �����̿� �����̴� �ᱹ ���Ѽ� �ƺ����� ��û ȥ���� ���θ�");
						gotoxy(20, 9);	printf("�׾�� �ϰ� �Ǿ����ϴ�.");
						// (�̼� ����)

						key = _getch();
						if (key == 13) {
							roop = 0;
							system("cls");
						} //enter if
						break; // �������� ��Ʈ�� �������� ���
					case 2:
						system("cls");
						gotoxy(0, 17);
						mainView();
						textColor(7);
						gotoxy(15, 22);	printf("\"����, ������ ? �츮 �� ���÷� ������ ~");

						key = _getch();
						if (key == 13) {
							textColor(14);
							gotoxy(20, 8);	printf("\"�ʳ� ���� ���� �� ������ ..���� ���� ��\"");
						} //enter if

						key = _getch();
						if (key == 13) {
							textColor(7);
							gotoxy(20, 12);	printf("\"�˾Ҿ�, ���� ����\"");
						} //enter if

						nextScene();
						gotoxy(15, 22);
						printf("\"... ���� ?\"");
						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("\"����, ���� ���� �̰�\"");
						} //enter if

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"����, ���� �ϰ� ����.\"");
						} //enter if

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"���, ������, �� ������ ���� �� ���� ? \"");
						} // enter if

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("                        ");
							gotoxy(20, 8);	printf("\"���, \"");
						}//enter if

						nextScene();
						gotoxy(28, 5);	printf("��ο� ���� ���� �ڵ���"); //�ڵ����� ����� ��Ŵ
						gotoxy(28, 9);	printf("�Ƕ�̵带 ��ĥ �ָӴ�"); //���� �ɸ��� ������ ���� ����
						gotoxy(28, 13);	printf("�̲����� ���� �尩"); //����

						choose = keyControl();

						switch (choose) {
						case 1:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(20, 8);	printf("\"�� ��� ..!\"");

							key = _getch();
							if (key == 13) {
								textColor(8);
								gotoxy(20, 12);	printf("- ����������������");
							} //enter if

							nextScene();
							textColor(12);
							gotoxy(20, 8);	printf("\"�� �� �߿� ������ !!!\"");

							nextScene();
							textColor(8);
							gotoxy(20, 8);	printf("�ڵ����� Ű�ٰ� �Ǽ��� �˶��� �������� �������� �Ǽ� ������ �ῡ�� ������ �ƺ����� �ɷ���");
							gotoxy(20, 10);	printf("�Ƕ�̵� Ż�� ����� ���з� ���ư��� �Ǿ����ϴ�.");
							
							key = _getch();
							if (key == 13) {
								roop = 0;
								system("cls");
							} //enter if (�̼� ����)
							break;
						case 2: 
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"�ָӴϴ� �ʿ����..\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"�׳� ������ �� �׷�.\"");
							}// enter if
						case 3:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);
							printf("\"������.\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"������ �ؾ���, �˰��� ? \"");
							} //enter if
								
							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"�翬����, �� ������ ��\"");
								}// enter if
							nextScene();
							gotoxy(15, 22);	printf("\"��, ���ִ�.\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"����, ��¥ �� �־� ?\"");
							}// enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"��, �����.");
							}// enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 24);	printf("\"���谡 �� ���� ���� ? \"");
								deskKey = 1;
							}// enter if

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("                          ");
								gotoxy(20, 8);	printf("\"�켱 ì�ܺ���. ��.\"");
							}// enter if
						
							nextScene();
							gotoxy(15, 24);	printf("\"�̰� ����� ���� ���� ���� ...\"");
						
							nextScene();
							gotoxy(20, 8);	printf("\"�׷� ���� �ٸ� �� ������.\"");
							break; // ���� �ùٸ� ��Ʈ�� ������
						} // switch (���踦 ã�� ���ؼ� ������ ����)
						break;
					case 3: 
						system("cls");
						gotoxy(0, 17);
						mainView();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"�˼��ؿ�, ���� �ƹ��͵� �� �߾�� !\"");
						}// enter if

						key = _getch();
						if (key == 13) {
							textColor(13);
							gotoxy(20, 8);	printf("\"��..? ����\"");	
						}// enter if

						key = _getch();
						if (key == 13) {
							textColor(7);
							gotoxy(20, 10);		printf("\"���...\"");
						}// enter if

						nextScene();
						textColor(8);
						gotoxy(20, 5);printf("���� ���÷� ���� �������� ��� ���� ��Ǵ�� �о���� �����̿� ������, ");
						gotoxy(20, 7);	printf("������ ��� ���� ��� ��� ������ �ϴ��� ���� �����شٰ� ���մϴ�. ������ ");
						gotoxy(20, 9);	printf("�ٽô� �̷� ���� ���� ����� ȥ�� �� �����̿� �����̴� ������ ���������ϴ�.");				

						key = _getch();
						if (key == 13) {
							roop = 0;
							system("cls");
						} //enter if (�̼� ����)
						break;
					} //switch (�������� ��ų ���� ���� ��Ʈ�� �����ϴ� switch)
					diningroom = 1;
				}//else (�Ž��� �ѹ��� �湮���� ����)
				break;
			case 3:
				if (bedroom == 1) {
					gotoxy(15, 22);	printf("���� �þ����ϱ� �ٸ� �� ����.");
					nextScene();
				} //if (�̹� ħ���� �湮��)
				else {
		
					gotoxy(15, 22);	printf("\"�����ƺ� ħ�� ������ ?\"");
					nextScene();
					gotoxy(20, 8);	printf("\"�ڰ� �ִ� �� ���� ?\"");

					key = _getch();
					if (key == 13) {
						gotoxy(15, 22);	printf("\"�´ٴϱ� �׷���. ���� ���� ã�⳪ ��.\"");
					}

					key = _getch();
					if (key == 13) {
						gotoxy(20, 8);	printf("\"�� �ٵ� �� ����..�� �� �� ���� ?\"");
					}

					nextScene();
					gotoxy(28, 5);	printf("��ο� ���� ���� �ڵ���"); //����
					gotoxy(28, 9);	printf("�Ƕ�̵带 ��ĥ �ָӴ�"); //(����߷��� �������� ��Ŵ)
					gotoxy(28, 13);	printf("�̲����� ���� �尩"); //�Ǽ��� �̲������� ū �Ҹ��� ���� �ƺ����� ���Ѽ� ��

					choose = keyControl();

					switch (choose) {
					case 1:
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);	printf("\"��.. ���� ���忡 ���� �� ���� �ʾ�?\"");
						
						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"��� ���� �ϴ°ž�.\"");
						}

						nextScene();
						gotoxy(28, 5);	printf("������ �� ������"); 
						gotoxy(28, 9);	printf("������ ��� ������");
						gotoxy(28, 13);	printf("������ �Ʒ� ������"); //����

						choose = keyControl();

						switch (choose) {
						case 1:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"�� �ʹ� ��ο�.. \"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"�� ��� �Һ�..!\"");
							}// enter if

							next();
							textColor(12);
							gotoxy(20, 10);	printf("\"����... ������, ������. �� �� �ڰ� �ű⼭ ���ϴ� �ž�.\"");

							nextScene();
							textColor(8);
							gotoxy(20, 5);	printf("������ Ž���Ϸ��ٰ� ������ ���� �ſ￡ ��ģ �ڵ��� �Һ��� �׸� �������� ");
							gotoxy(20, 7);	printf("���� ������ �������� �ῡ�� ������ϴ� !!! ");
							gotoxy(20, 9);	printf("�׷��� �����̿� �����̴� �� �� �߿� �������� �ܼҸ��� ȭ�� 3�ð� ���� ������ϴ�.");

							key = _getch();
							if (key == 13) {
								roop = 0;
								system("cls");
							} //enter if (�̼� ����)
							break;
						case 2:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"�ƹ� �͵� ���µ�?\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"����, �׷� �Ʒ��� �����\"");
							}// enter if

							key = _getch();
							if (key == 13) {

							}
						case 3:
							//�Ʒ��� : �ƺ� �ڵ����� �����־ ��
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"���� �ֱ� �Ѱž� �� ������..?\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"���ؾ�, ���� �ƺ� �ڵ��� �ƴϾ�? �� ���� ����.\"");
							}// enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"�� ��¥��..                        ");
							}// enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"Ȥ�� ���� ����� �ƺ� ���� ū���̴ϱ� �ۿ� ��������.\"");
							}// enter if

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("                                                        ");
								gotoxy(20, 8);	printf("\"�׷�.\"");
							}// enter if
							break;
						}//switch ���� ���Ʒ� ����
						break;
					case 2:
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);	printf("\"�ʹ� ��ο��� �� �� ���� ..\"");

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"�ƴ�, ���� �� ��.\"");
						}

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("\"����, ã�Ҵµ� ����߷Ⱦ�...\"");
						}

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("                       ");
							gotoxy(15, 22);	printf("\"��� .. \"");
						}

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("                       ");
							gotoxy(15, 22);	printf("\"�� !!!!\"");
						}

						nextScene();	textColor(12);
						gotoxy(20, 10);	printf("\"���� !!!! ����, ���� ������ !!!\"");
						nextScene();
						textColor(8);
						gotoxy(20, 5);	printf("����߸� �ָӴϸ� ��� �Ѿ��� ���� �������� ���� �� �Ҹ��� �׸� �������� �����ȴ�.");
						gotoxy(20, 7);	printf("���� ������ �������� ȭ�� �Ӹ� ������ ���� �����̿� �����̸� �������� ���� �Ծ���,");
						gotoxy(20, 9);	printf("�׷��� �����̿� �����̴� �� �� �߿� �������� �ܼҸ��� ȭ�� 3�ð� ���� ���� �ߴ�.");

						key = _getch();
						if (key == 13) {
							roop = 0;
							system("cls");
						} //enter if (�̼� ����)
						break;
					case 3:
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 22);	printf("\"�ʹ� ��ο��� �� �� ���� ..\"");

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("\"�ƴ�, ���� �� ��.\"");
						}

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"��, ã�Ҵµ� ����߷ȴ�.\"");
						}

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("                       ");
							gotoxy(20, 8);	printf("\"�װ� ��ġ�� ... \"");
						}

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("                       ");
							gotoxy(20, 8);	printf("\"�� !!!!\"");
						}

						nextScene();
						gotoxy(20, 10);
						textColor(12);
						printf("\"���� ... ������, ������. ���ϴ� �ž� ���� !!!\"");
						nextScene();
						textColor(8);
						gotoxy(20, 5);	printf("����߸� �尩�� �ʹ� �̲����� ��� �Ѿ��� ���� �������� ���� �� �Ҹ��� �׸� �������� �����Ƚ��ϴ�.");
						gotoxy(20, 7);	printf("�尩�� �������� ���� �׸��� ���� ������ ���� �Ӽ��� �˾����� �������� ȭ�� ���� ���ϰ�,");
						gotoxy(20, 9);	printf("�׷��� �����̿� �����̴� �� �� �߿� �������� �ܼҸ��� ȭ�� 3�ð� ���� ���� �߽��ϴ�.");

						key = _getch();
						if (key == 13) {
							roop = 0;
							system("cls");
						} //enter if (�̼� ����)
						break;
					}//switch ���� Ž�� ������ ����
					password = 1;
					bedroom = 1;
				}//else (ħ���� �ѹ��� �湮���� �ʾ��� ���)
				break;
			}// switch (��� ���� �湮���� ������)
		} // enter if ( ù ������)
	}//while (�Ƕ�̵� Ž���� �ݺ���)

	if (pyramid == 1) {
		next();
		gotoxy(20, 10);	printf("- �� ���� ����");

		key = _getch();
		if (key == 13) {
			gotoxy(20, 10);	printf("\"������, ���� �̰�\"");
		}//enter if

		system("cls");
		key = _getch();
		if (key == 13) {
			gotoxy(20, 8);	printf("- ��                 ");
		}//enter if
		key = _getch();
		if (key == 13) {
			gotoxy(20, 10);	printf("- ��");	
		}//enter if
		key = _getch();
		if (key == 13) {
			gotoxy(20, 12);	printf("- ��");
		}//enter if

		nextScene();
		textColor(7);
		gotoxy(20, 10);	printf("������ !!");
		textColor(10);
		gotoxy(20, 12);	printf("������ !!");

		next();
		gotoxy(20, 10);	printf("���ϵ帳�ϴ� !! �Ƕ�̵带 ã�Ƴ��� �����Ƚ��ϴ�!");
		gotoxy(20, 12);	printf("ENTER Ű�� �����ø� ĳ�� ���� �������� ���ư��ϴ� _");
	}//���� �Ƕ�̵带 ã�Ҵٸ�
		system("pause>null");
}