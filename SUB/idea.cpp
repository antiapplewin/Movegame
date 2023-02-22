#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	
	int X = 1, Y = 5;
	int map[10][10] = {0};
	
	for (int i = 1; i<= 12; i++) {
		int x = rand()%10;
		int y = rand()%10;
		if (map[x][y] != 0) {
			for (int escape = 0;escape!=1;) {
				x = rand()%10;
				y = rand()%10;
				if (map[x][y] == 0) {
					escape = 1;
				}
			}
		}
		map[x][y] = -1;
	}
	
	for (int i = 1; i<= 16; i++) {
		int x = rand()%10;
		int y = rand()%10;
		if (map[x][y] != 0) {
			for (int escape = 0;escape!=1;) {
				x = rand()%10;
				y = rand()%10;
				if (map[x][y] == 0) {
					escape = 1;
				}
			}
		}
		map[x][y] = 2;
	}
	
	for (;;) {
		X = rand()%10;
		Y = rand()%10;
		if (map[Y][X] != 0) {
			for (int escape = 0;escape!=1;) {
				X = rand()%10;
				X = rand()%10;
				if (map[Y][X] == 0) {
					escape = 1;
				}
			}
		}
		map[Y][X] = 1;
		break;
	}
	
	for (int i = 0; i<=9; i++) {
		for (int j = 0; j<=9; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	
	char way;
	
	while (1) {
		printf("pick a way (WASD) : ");
		scanf("%c", &way);
		int BX = X, BY = Y;
		map[Y][X] = 0;
		if (way == 'W') {
			Y -= 1;
			if (Y<0) {
				Y += 1;
			}
		} else if (way=='S') {
			Y += 1;
			if (Y>9) {
				Y -= 1;
			}
		} else if (way=='A') {
			X -= 1;
			if (X<0) {
				X += 1;
			}
		} else if (way == 'D') {
			X += 1;
			if (X>9) {
				X -= 1;
			}
		}
		
		if (map[Y][X] == -1) {
			system("cls");
			printf("GAME OVER!\nbeware of -1 next time");
			break;
		}
		
		map[Y][X] = 1;
		
		system("cls");
		
		for (int i = 0; i<=9; i++) {
			for (int j = 0; j<=9; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
	}
}

