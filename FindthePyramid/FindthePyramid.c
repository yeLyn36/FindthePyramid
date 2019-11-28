#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<windows.h>
#include <conio.h>

#define MAZE_BOARD_HEIGHT 14 //배경 대화창 높이
#define MAZE_BOARD_WIDTH 20 //배경 대화창 너비
#define UP 72 //방향키 위
#define DOWN 80 //방향키 아래 

int key, choose, answer;
int diningroom = 0;
int bedroom = 0;
int password = 0; //번호키
int deskKey = 0; //열쇠
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

void mainView(); //대화창 그리기
void CursorView(char); //커서 유무표시
int keyControl(); //화살표 이동
void next(); //대화 창 없이 다음 화면으로 넘어가기 : 인트로와 엔딩에서 사용
void nextScene(); //대화창 만들면서 다음 화면으로 넘어가기 : 대화 혹은 선택에서 사용
void gotoxy(int, int); //좌표 이동

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
				printf("<┘      ");
			if (maze[y][x] == '6')
				printf("(ENTER) ");
			if (maze[y][x] == '7')
				printf("  차기준");
		}
		printf("\n");
	}
}// mainView();

int keyControl() {
	answer = 1;
	int x = 20, y = 5, end = 1;
	gotoxy(x, y);
	printf("▶");
	while(end){
		key = _getch();
		if (key == UP) { //위
			y -= 4;
			if (y < 5) y = 5;
			gotoxy(x, y+4);
			printf(" ");
			gotoxy(x, y);
			printf("▶");
			answer--;
		} //UP if
		else if (key == DOWN) { //아래
			y += 4;
			if (y > 14) y = 13;
			gotoxy(x, y - 4);
			printf(" ");
			gotoxy(x, y);
			printf("▶");
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

void next() { //대화 창 없이 다음 화면으로 넘어가기 : 인트로와 엔딩에서 사용
	key = _getch();
	if (key == 13)
		system("cls");
} //next()

void nextScene() { //다음 화면으로 넘어가기 : 대화나 선택할 때 사용
	key = _getch();
	if (key == 13) 
		system("cls");
		gotoxy(0, 17); 
		mainView();
} //nextScene()

void main() {
	system("mode con cols=120 lines=35");
	system("title CPU캐슬");
	CursorView(0);

	gotoxy(20, 13);
	textColor(8); //text color = gray
	//text color (차교수 12, 노승혜 13, 세라 14, ?? 11, 기준이 7, 서준이 10, 설명 텍스트 8), 인트로에서만 글씨체 구분, 게임 시작하면 ㅅㅈ, ㄱㅈ 하얀색
	printf("- 20XX년 6월 말 스카이 캐슬 기준이 서준이네");
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(12); //text color = red
	gotoxy(20, 13);	printf("\"차기준!!!!!! 차서준!!!!!! 공부 안 하고 뭐 하고 있어!!!!!!!!\"");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(7);
	gotoxy(20, 13);	printf("\"하.. 아직 7시밖에 안 됬잖아요.\"");
	textColor(10);
	gotoxy(20, 16);	printf("\"저희 어제도 3시에 잤는데..\"");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(12); //text color = red
	gotoxy(20, 13);	printf("\"아침부터 열심히 하지 않으면 피라미드 꼭대기에 앉을 수 없어, 그러니까 ..\"");

	textColor(7);
	gotoxy(20, 18);	printf("(저 피라미드.. 누가 없애버리면 안되나 ..)");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(7);
	gotoxy(20, 13);	printf("\"야, 서준아.");
	gotoxy(20, 15);	printf("우리, 저 피라미드 없앨까 ?\"");
	textColor(10);
	gotoxy(25, 18);	printf("\"뭐 ? 아빠가 제일 애지중지하는 저걸 ?\"");
	textColor(8);
	gotoxy(85, 25); printf("(Press Enter please.)");
	next();

	textColor(7);
	gotoxy(20, 13);	printf("\"저거, 내 눈 앞에 없으면 조금은 편하겠지.\"\n");
	textColor(8);
	gotoxy(40, 25); printf("(프롤로그가 끝났습니다. Enter 키를 눌러 다음 화면으로 넘어가 주세요.)");
	// Finished intro

	nextScene();
	textColor(8); //change text color
	gotoxy(20, 8);	printf("-새벽 2시, 기준이네 가족 모두가 잠에 빠진 한 밤중에 기준이와 서준이의 방에서 작은");
	gotoxy(20, 10);	printf("불빛이 새어나왔다.");
	nextScene();

	textColor(7);
	gotoxy(20, 8);	printf("\"기준아, 일어나\"");

	key = _getch();
	if (key == 13) {
		gotoxy(15, 22);	printf("\"어… 잠시만\"");
	} //enter if
	nextScene();

	gotoxy(15, 22);
	printf("\"짐 좀 챙겨야해서, 음 .. 이거면 되겠지 ?\"");
	gotoxy(28, 5);	printf("- 어두운 집을 밝힐 핸드폰");
	gotoxy(28, 9);	printf("- 피라미드를 훔칠 주머니");
	gotoxy(28, 13);	printf("- 미끄럽고 얇은 장갑");

	nextScene();
	gotoxy(15, 22);	printf("\"가자.\"");

	nextScene();
	gotoxy(15, 22);	printf("\"근데, 먼저 어디부터 가지?\"");

	while (roop) {
		nextScene();
		gotoxy(28, 5);	printf("아빠가 아끼는 것들만 있는 아빠의 서재");
		gotoxy(28, 9);	printf("어제까지만 해도 소파에서 피라미드를 자랑하던 거실"); //한 번만 들어가야함 diningroom = 0 -> 1;
		gotoxy(28, 13);	printf("아빠 엄마가 같이 자고 계시는 침실");// 한 번만 들어가야 함 bedroom = 0 -> 1;

		choose = keyControl();
		system("cls");
		gotoxy(0, 17);
		mainView();

		gotoxy(20, 8);	printf("\"어디에 숨겨놓았을 거 같아 ?\"");

		key = _getch();
		if (key == 13) {
			switch (choose) {
			case 1: 
				gotoxy(15, 22);	printf("\"아빠 서재로 가자.\"");
				nextScene();

				gotoxy(20, 8);	printf("\"기준아, 우리 괜찮겠지 ..?\"");

				key = _getch();
				if (key == 13) {
					gotoxy(15, 22);	printf("\"갑자기 무슨 소리야? 빨리 들어가\"");
				} //enter if


				key = _getch();
				if (key == 13) {
					if (password == 1 && deskKey == 1) {
						roop = 0;

						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);	printf("\"으.. 아까 찾은 열쇠말이야, 여기 서랍 열쇠같은데?\"");

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"오, 한번 열어보자.\"");
						} //enter if

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("                                          ");
							gotoxy(20, 8);	printf("\'근데 왜 내가 다 하는 거 같지...?\'");
						} //enter if

						nextScene();
						gotoxy(20, 8);	printf("- 철컥");

						nextScene();
						gotoxy(20, 8);	printf("\"열렸다.\"");

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"안에 뭐 있어?\"");
						} //enter if

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("                                          ");
							gotoxy(20, 8);	printf("\"어 잠깐만,\"'");
						} //enter if

						nextScene();
						gotoxy(28, 5);	printf("집 구상도");//집 구상도일 경우 : 피라미드를 숨겨놓았다고 표시된 곳은 거짓, 걸리게 됨
						gotoxy(28, 9);	printf("피라미드 책"); //피라미드 책일 경우 : 쓸모없음 다음 서랍 열기
						gotoxy(28, 13);	printf("일기장"); //차교수 일기장 일 경우 : 맨앞 장에 ‘ 번호키 : 핸드폰 메모 1번 ‘ 이라고 작성되어 있음->금고 찾기

						//그 다음 서랍을 열어야 할 경우엔 일기장 들어 있음

						choose = keyControl();

						switch (choose) {
						case 1:
							system("cls");
							gotoxy(0, 17);
							mainView();

							gotoxy(15, 22);	printf("\"집 구상도같은 것도 있어 우리?\"");
							
							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"그러니까, 거기에 뭐라도 있어?\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"와 .. 피라미드 있는 곳 적어놨어. 나 이제 진짜 무서워.\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"하하.. 장난아니다. 빨리 가서 버리자 진짜.\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("                                       ");
								gotoxy(15, 22);	printf("\"그래. 이제 진짜 제발.\"");
							} //enter if

							nextScene();
							textColor(8);
							gotoxy(20, 5);	printf("집 구상도에 적힌 피라미드 위치로 갔지만 사실 그 집 구상도는 가짜였습니다 !!!");
							gotoxy(20, 7);	printf("가짜 피라미드 위치에 간 서준이와 기준이는 다시 서재로 달려와서 다른 증거를");
							gotoxy(20, 9);	printf("찾으려 하지만, 이미 아침 7시 기상시간이 다가오자 어쩔 수 없이 포기하고 다음으로 미룹니다.");

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

							gotoxy(15, 22);	printf("\".. 이건 또 뭐야, 진짜 징그럽다 이젠.\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"와 .. 나 살짝 소름돋았는데 지금.\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"이건 버리고, 다음 서랍장이나 열어보자.\"");
							} //enter if
						case 3:
							system("cls");
							gotoxy(0, 17);
							mainView();

							gotoxy(15, 22);	printf("\".. 우리 아빠 일기도 써?\"");
							

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"으.. 쓰시나 보지, 뭐 써져 있어 ??\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"2016년 3월 1일, 차기준 차서준 두 녀석이 속을 썩였다. 피라미드 꼭대, 뭐야 이거도 피라미드야?\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"하하.. 일기장에도 그런 걸 쓰시네.      \"");
							} //enter if

							nextScene();
							gotoxy(15, 22);	printf("\"어, 야 아빠 핸드폰 가져왔었지 우리,\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"그지, 근데 왜 ?\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"아니, 거기 메모장 들어가면 첫번째에 번호키라고 표지에 써져있는데..?\"");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"응? 뭐야, 잠시만 ..\"");
							} //enter if

							next();
							gotoxy(25, 10);	printf("------------------");
							gotoxy(25, 11);	printf("|                 |");
							gotoxy(25, 12);	printf("|  와이프 생일    |");
							gotoxy(25, 13);	printf("|    0102         |");
							gotoxy(25, 14);	printf("|                 |");
							gotoxy(25, 15);	printf("------------------");

							nextScene();
							gotoxy(15, 22);	printf("\"뭐야, 엄마 생일이네…\"");

							key = _getch();
							if (key == 13) {
								gotoxy(15, 24);	printf("\"입력해봐 빨리,\"");
							} //enter if
							
							nextScene();
							gotoxy(15, 8); printf("- 삑");

							key = _getch();
							if (key == 13) {
								gotoxy(15, 10); printf("- 삑");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 12); printf("- 삑");
							} //enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 14); printf("- 삑");
							} //enter if
							

							nextScene();
								gotoxy(20, 8);	printf("\"열려? 빨리 꺼내봐 좀\"");

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"어, 피라미드 여기 있다 !!!!\"");
								pyramid = 1;
							} //enter if
							
							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"쉿, 주머니에 숨겨서 나가자.\"");
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
						printf("\"어응 .. 난 금고를 찾을게.. 넌 서랍 좀 봐봐\"");

						nextScene();
							gotoxy(15, 22);
							printf("\"아 뭐야, 번호키 있어야 하는데 ? \"");
						
						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);
							printf("\"여기도 열쇠 있어야 할 거 같아, 안 열려\"");
						} //enter if

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);
							printf("                                           ");
							gotoxy(15, 22);
							printf("\"..다른데 부터 찾자\"");
						} //enter if
					} //else (번호키와 열쇠가 없을 경우에 서재를 제외한 다른 곳을 먼저 찾기 위함)
				} //if (서재를 찾으려고 함)
				break;
			case 2:
				if (diningroom == 1) {
					gotoxy(15, 22);	printf("여긴 봤었으니까 다른 데 가자.");
					nextScene();
				} //if (이미 거실을 방문함)
				else {
					gotoxy(15, 22);
					printf("거실에 있을 거 같지 않냐 ?");
					nextScene();
					gotoxy(15, 22);	printf("\"누구 없지 ? 차서준, 소파 뒤에 좀 찾아봐.\"");
					gotoxy(20, 8);	printf("- 끼익");

					nextScene();
					gotoxy(20, 8);	printf("\"으 진짜\"");

					key = _getch();
					if (key == 13) {
					textColor(11);
					gotoxy(20, 8);	printf("\"거기 누구야 ? \"");
					} //enter if

					key = _getch();
					if (key == 13) {
						textColor(7);
						gotoxy(15, 22);	printf(" ... 어떻게 하지 ?");
					} //enter if

					nextScene();
					gotoxy(28, 5);	printf("도둑인 척하면서 집 밖으로 튀어나간다.");
					gotoxy(28, 9);	printf("물 마시러 나온 척하면서 누구인지 돌아본다.");
					gotoxy(28, 13);	printf("빨리 사실대로 말하고 용서를 구한다.");

					choose = keyControl();

					switch (choose) {
					case 1: system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 22);	printf("으, 모르겠다 튀어 !!!");

						nextScene();
						textColor(8);
						gotoxy(20, 5);	printf("도망간 기준이와 서준이는 집 밖으로 뛰어나갔고 물 마시러 나온 세리는 둘을 ");
						gotoxy(20, 7);	printf("경찰에 신고하고, 기준이와 서준이는 결국 들켜서 아빠한테 엄청 혼나고 공부만");
						gotoxy(20, 9);	printf("죽어라 하게 되었습니다.");
						// (미션 실패)

						key = _getch();
						if (key == 13) {
							roop = 0;
							system("cls");
						} //enter if
						break; // 도망가는 루트를 선택했을 경우
					case 2:
						system("cls");
						gotoxy(0, 17);
						mainView();
						textColor(7);
						gotoxy(15, 22);	printf("\"뭐야, 누나야 ? 우리 물 마시러 나왔지 ~");

						key = _getch();
						if (key == 13) {
							textColor(14);
							gotoxy(20, 8);	printf("\"너네 뭐해 지금 이 새벽에 ..빨리 들어가서 자\"");
						} //enter if

						key = _getch();
						if (key == 13) {
							textColor(7);
							gotoxy(20, 12);	printf("\"알았어, 누나 잘자\"");
						} //enter if

						nextScene();
						gotoxy(15, 22);
						printf("\"... 갔지 ?\"");
						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("\"으아, 심장 떨려 이거\"");
						} //enter if

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"으으, 빨리 하고 가자.\"");
						} //enter if

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"어라, 차서준, 뭐 조용히 뒤질 거 없냐 ? \"");
						} // enter if

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("                        ");
							gotoxy(20, 8);	printf("\"잠깐만, \"");
						}//enter if

						nextScene();
						gotoxy(28, 5);	printf("어두운 집을 밝힐 핸드폰"); //핸드폰이 울려서 들킴
						gotoxy(28, 9);	printf("피라미드를 훔칠 주머니"); //딱히 걸리지 않지만 쓸모 없음
						gotoxy(28, 13);	printf("미끄럽고 얇은 장갑"); //정답

						choose = keyControl();

						switch (choose) {
						case 1:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(20, 8);	printf("\"으 잠깐만 ..!\"");

							key = _getch();
							if (key == 13) {
								textColor(8);
								gotoxy(20, 12);	printf("- 따르르르르르르르");
							} //enter if

							nextScene();
							textColor(12);
							gotoxy(20, 8);	printf("\"이 밤 중에 누구야 !!!\"");

							nextScene();
							textColor(8);
							gotoxy(20, 8);	printf("핸드폰을 키다가 실수로 알람을 눌러버린 서준이의 실수 때문에 잠에서 깨버린 아빠에게 걸려서");
							gotoxy(20, 10);	printf("피라미드 탈취 사건은 실패로 돌아가게 되었습니다.");
							
							key = _getch();
							if (key == 13) {
								roop = 0;
								system("cls");
							} //enter if (미션 실패)
							break;
						case 2: 
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"주머니는 필요없어..\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"그냥 손으로 해 그럼.\"");
							}// enter if
						case 3:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);
							printf("\"오케이.\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"조심히 해야해, 알겠지 ? \"");
							} //enter if
								
							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"당연하지, 이 정도야 뭐\"");
								}// enter if
							nextScene();
							gotoxy(15, 22);	printf("\"어, 뭐있다.\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"뭐야, 진짜 뭐 있어 ?\"");
							}// enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"엥, 열쇠네.");
							}// enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 24);	printf("\"열쇠가 왜 여기 있지 ? \"");
								deskKey = 1;
							}// enter if

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("                          ");
								gotoxy(20, 8);	printf("\"우선 챙겨보자. 줘.\"");
							}// enter if
						
							nextScene();
							gotoxy(15, 24);	printf("\"이거 빼고는 여긴 뭐가 없네 ...\"");
						
							nextScene();
							gotoxy(20, 8);	printf("\"그럼 이제 다른 데 가보자.\"");
							break; // 가장 올바른 루트를 선택함
						} // switch (열쇠를 찾기 위해서 아이템 선택)
						break;
					case 3: 
						system("cls");
						gotoxy(0, 17);
						mainView();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"죄송해요, 아직 아무것도 안 했어요 !\"");
						}// enter if

						key = _getch();
						if (key == 13) {
							textColor(13);
							gotoxy(20, 8);	printf("\"응..? 뭐가\"");	
						}// enter if

						key = _getch();
						if (key == 13) {
							textColor(7);
							gotoxy(20, 10);		printf("\"사실...\"");
						}// enter if

						nextScene();
						textColor(8);
						gotoxy(20, 5);printf("물을 마시러 나온 엄마에게 모든 것을 사실대로 털어놓은 기준이와 서준이, ");
						gotoxy(20, 7);	printf("엄마는 모든 것을 듣고 잠시 생각을 하더니 눈을 감아준다고 말합니다. 하지만 ");
						gotoxy(20, 9);	printf("다시는 이런 일을 하지 말라고 혼낸 후 서준이와 기준이는 방으로 돌려보냅니다.");				

						key = _getch();
						if (key == 13) {
							roop = 0;
							system("cls");
						} //enter if (미션 실패)
						break;
					} //switch (세라한테 들킬 것을 피할 루트를 선택하는 switch)
					diningroom = 1;
				}//else (거실을 한번도 방문하지 않음)
				break;
			case 3:
				if (bedroom == 1) {
					gotoxy(15, 22);	printf("여긴 봤었으니까 다른 데 가자.");
					nextScene();
				} //if (이미 침실을 방문함)
				else {
		
					gotoxy(15, 22);	printf("\"엄마아빠 침실 가볼까 ?\"");
					nextScene();
					gotoxy(20, 8);	printf("\"자고 있는 거 맞지 ?\"");

					key = _getch();
					if (key == 13) {
						gotoxy(15, 22);	printf("\"맞다니까 그러네. 깨기 전에 찾기나 해.\"");
					}

					key = _getch();
					if (key == 13) {
						gotoxy(20, 8);	printf("\"야 근데 안 보여..뭐 볼 거 없어 ?\"");
					}

					nextScene();
					gotoxy(28, 5);	printf("어두운 집을 밝힐 핸드폰"); //정답
					gotoxy(28, 9);	printf("피라미드를 훔칠 주머니"); //(떨어뜨려서 엄마한테 들킴)
					gotoxy(28, 13);	printf("미끄럽고 얇은 장갑"); //실수로 미끄러져서 큰 소리가 나자 아빠한테 들켜서 끝

					choose = keyControl();

					switch (choose) {
					case 1:
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);	printf("\"어.. 저기 옷장에 있을 거 같지 않아?\"");
						
						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"어딜 봐야 하는거야.\"");
						}

						nextScene();
						gotoxy(28, 5);	printf("옷장의 윗 수납장"); 
						gotoxy(28, 9);	printf("옷장의 가운데 유리장");
						gotoxy(28, 13);	printf("옷장의 아래 서랍장"); //정답

						choose = keyControl();

						switch (choose) {
						case 1:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"으 너무 어두워.. \"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"야 잠깐만 불빛..!\"");
							}// enter if

							next();
							textColor(12);
							gotoxy(20, 10);	printf("\"으음... 차기준, 차서준. 잠 안 자고 거기서 뭐하는 거야.\"");

							nextScene();
							textColor(8);
							gotoxy(20, 5);	printf("옷장을 탐색하려다가 옷장의 작은 거울에 비친 핸드폰 불빛이 그만 차교수의 ");
							gotoxy(20, 7);	printf("눈에 들어버려 차교수가 잠에서 깨어났습니다 !!! ");
							gotoxy(20, 9);	printf("그렇게 기준이와 서준이는 한 밤 중에 차교수의 잔소리와 화를 3시간 동안 들었습니다.");

							key = _getch();
							if (key == 13) {
								roop = 0;
								system("cls");
							} //enter if (미션 실패)
							break;
						case 2:
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"아무 것도 없는데?\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"뭐야, 그럼 아래나 열어보자\"");
							}// enter if

							key = _getch();
							if (key == 13) {

							}
						case 3:
							//아래층 : 아빠 핸드폰이 켜져있어서 봄
							system("cls");
							gotoxy(0, 17);
							mainView();
							gotoxy(15, 22);	printf("\"뭐가 있긴 한거야 이 옷장은..?\"");

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("\"기준아, 저거 아빠 핸드폰 아니야? 왜 저기 있지.\"");
							}// enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"엥 진짜네..                        ");
							}// enter if

							key = _getch();
							if (key == 13) {
								gotoxy(15, 22);	printf("\"혹시 저거 울려서 아빠 깨면 큰일이니까 밖에 가져가자.\"");
							}// enter if

							key = _getch();
							if (key == 13) {
								gotoxy(20, 8);	printf("                                                        ");
								gotoxy(20, 8);	printf("\"그래.\"");
							}// enter if
							break;
						}//switch 옷장 위아래 선택
						break;
					case 2:
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(20, 8);	printf("\"너무 어두워서 잘 안 보여 ..\"");

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"아니, 가방 줘 봐.\"");
						}

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("\"으에, 찾았는데 떨어뜨렸어...\"");
						}

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("                       ");
							gotoxy(15, 22);	printf("\"어디 .. \"");
						}

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("                       ");
							gotoxy(15, 22);	printf("\"악 !!!!\"");
						}

						nextScene();	textColor(12);
						gotoxy(20, 10);	printf("\"으아 !!!! 뭐야, 뭐야 누구야 !!!\"");
						nextScene();
						textColor(8);
						gotoxy(20, 5);	printf("떨어뜨린 주머니를 밟고 넘어져 버린 기준이의 비명과 쿵 소리에 그만 차교수가 깨버렸다.");
						gotoxy(20, 7);	printf("같이 놀라버린 차교수는 화가 머리 끝까지 나서 기준이와 서준이를 벌세우기로 마음 먹었고,");
						gotoxy(20, 9);	printf("그렇게 기준이와 서준이는 한 밤 중에 차교수의 잔소리와 화를 3시간 동안 들어야 했다.");

						key = _getch();
						if (key == 13) {
							roop = 0;
							system("cls");
						} //enter if (미션 실패)
						break;
					case 3:
						system("cls");
						gotoxy(0, 17);
						mainView();
						gotoxy(15, 22);	printf("\"너무 어두워서 잘 안 보여 ..\"");

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("\"아니, 가방 줘 봐.\"");
						}

						key = _getch();
						if (key == 13) {
							gotoxy(15, 22);	printf("\"아, 찾았는데 떨어뜨렸다.\"");
						}

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("                       ");
							gotoxy(20, 8);	printf("\"그걸 놓치냐 ... \"");
						}

						key = _getch();
						if (key == 13) {
							gotoxy(20, 8);	printf("                       ");
							gotoxy(20, 8);	printf("\"악 !!!!\"");
						}

						nextScene();
						gotoxy(20, 10);
						textColor(12);
						printf("\"으음 ... 차서준, 차기준. 뭐하는 거야 지금 !!!\"");
						nextScene();
						textColor(8);
						gotoxy(20, 5);	printf("떨어뜨린 장갑이 너무 미끄러워 밟고 넘어져 버린 기준이의 비명과 쿵 소리에 그만 차교수가 깨버렸습니다.");
						gotoxy(20, 7);	printf("장갑과 여러가지 짐들 그리고 열린 옷장을 보고 속셈을 알아차린 차교수는 화를 참지 못하고,");
						gotoxy(20, 9);	printf("그렇게 기준이와 서준이는 한 밤 중에 차교수의 잔소리와 화를 3시간 동안 들어야 했습니다.");

						key = _getch();
						if (key == 13) {
							roop = 0;
							system("cls");
						} //enter if (미션 실패)
						break;
					}//switch 옷장 탐색 아이템 선택
					password = 1;
					bedroom = 1;
				}//else (침실을 한번도 방문하지 않았을 경우)
				break;
			}// switch (어디를 먼저 방문할지 선택함)
		} // enter if ( 첫 선택지)
	}//while (피라미드 탐색을 반복함)

	if (pyramid == 1) {
		next();
		gotoxy(20, 10);	printf("- 집 마당 구석");

		key = _getch();
		if (key == 13) {
			gotoxy(20, 10);	printf("\"오케이, 깨자 이거\"");
		}//enter if

		system("cls");
		key = _getch();
		if (key == 13) {
			gotoxy(20, 8);	printf("- 쾅                 ");
		}//enter if
		key = _getch();
		if (key == 13) {
			gotoxy(20, 10);	printf("- 쾅");	
		}//enter if
		key = _getch();
		if (key == 13) {
			gotoxy(20, 12);	printf("- 쾅");
		}//enter if

		nextScene();
		textColor(7);
		gotoxy(20, 10);	printf("끝났다 !!");
		textColor(10);
		gotoxy(20, 12);	printf("끝났다 !!");

		next();
		gotoxy(20, 10);	printf("축하드립니다 !! 피라미드를 찾아내어 깨버렸습니다!");
		gotoxy(20, 12);	printf("ENTER 키를 누르시면 캐슬 게임 메인으로 돌아갑니다 _");
	}//만약 피라미드를 찾았다면
		system("pause>null");
}