#include <stdio.h>
#include <windows.h>
//#include "Attack.c"

int TU(int level) {
	int hp = 50;
	int attack;
	while (1) {
		printf("Dummy : lvl 0 HP = %d\n", hp);
		printf("Which attack will you do?\n");
		printf("1. Slash\n");
		scanf("%d", &attack);
		hp -= attack + level*2;
		printf("You dealed %d DMG!\n", attack + level*2);
		if (hp<=0) {
			return 10;
		}
		system("cls");
	}
	
}
