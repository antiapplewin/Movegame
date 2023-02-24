#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "calculator.c"

void Monster(int Lvl) {
	srand(time(NULL));
	int lvl, MT, Hp, esc = 0, PHp = 100;
	MT = rand()%(3-1+1)+1;
	lvl = rand()%(10-1+1)+1;
	if (MT == 1){
		printf("Slime ");
	} else if (MT == 2) {
		printf("Skeleton ");
	} else {
		printf("Golem ");
	}
	printf("lvl : %d\n\n", lvl);
	
	Hp = cal(lvl, 2, 't') + 100;
	Hp = cal(Hp, MT, 't');
	
	while (1) {
		int attack;
		printf("Your Hp : %d / Enemy\'s Hp : %d\n\n", PHp, Hp);
		
		printf("Which attack will you do? \n1 >>> Slash!\n");
		scanf("%d", &attack);
		Hp -= attack + Lvl*2;
		printf("You dealed %d DMG!\n", attack + Lvl*2);
		int Dmg;
		if (MT == 1) {
			switch (rand()%2) {
				case 0:
					printf("Slime use sticky pit!\n");
					Dmg = 3;
				case 1:
					printf("Slime use body slam!\n");
					Dmg = 1;
			}
		}
		printf("It had dealed %d dmg!", Dmg*lvl);
		PHp -= Dmg*lvl;
		esc = 1;
		if (esc==1) {
			break;
		}
	}
	
}
