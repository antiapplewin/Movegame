#include <stdio.h>
#include <windows.h>

int TU(int level, int A1, int dmg1) {
	int hp = 50;
	int attack;
	while (1) {
		printf("Dummy : lvl 0 HP = %d\n", hp);
		printf("Which attack will you do?\n");
		if (A1==1) {
			printf("1. Slash\n");
		}
		scanf("%d", &attack);
		if (attack==1) {
			hp -= dmg1 + level*2;
		}
		
		printf("You dealed %d DMG!\n", attack + level*2);
		if (hp<=0) {
			return 10;
		}
		system("cls");
	}
	
}
