#include "main.h"

int main() {
	system("mode con cols=90 lines=30");
	system("title 스카이캐슬 the 패러디");
	CursorView(1);

	while (while_) {

		arrow();
		printf("@");
	}
}

void arrow() {
	int key;

	key = _getch();
	printf(" ");
	if (key == 224)
		key = _getch();
		

	switch (key)
	{
	case UP:
		y -= 1;
		break;
	case DOWN:
		y += 1;
		break;
	case LEFT:
		x -= 1;
		break;
	case RIGHT:
		x += 1;
		break;
	}
	gotoxy(x, y);
}