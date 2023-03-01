#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "calculator.c"

int Monster(int Lvl, int A1, int d1, int A2, int d2, int A3, int d3, int A4, int d4) {
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
		
		printf("Which attack will you do?\n");
		if (A1==1) { // A1 starter
			printf("1. Slash\n");
		}
		if (A2==1) { // A2 starter
			printf("2. You don\' have a attack\n");
		}
		if (A3==1) { // A3 starter
			printf("3. You don\' have a attack\n");
		}
		if (A4==1) { // A4 starter
			printf("4. You don\' have a attack\n");
		}
		
		scanf("%d", &attack);
		
		if (attack==1) { //atype = 1
			Hp -= d1*Lvl*2;
		}else if (attack==2) { 
			Hp -= d2*Lvl*2;
		} else if (attack==3) {
			Hp -= d3*Lvl*2;
		} else if (attack==4) {
			Hp -= d4*Lvl*2;
		}
		
		printf("You dealed %d DMG!\n", attack*Lvl*2);
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
		} else if (MT == 2) {
			switch (rand()%2) {
				case 0:
					printf("Skeleton use trick aim shot!\n");
					Dmg = 5;
				case 1:
					printf("Slime use bone trow!\n");
					Dmg = 1;
					Hp -= 1;
			}
		} else if (MT == 3) {
			switch (rand()%2) {
				case 0:
					printf("Golem use ground shake!\n");
					Dmg = 7;
				case 1:
					printf("Golem use roar!\n");
					Dmg = 3;
			}
		}
		printf("It had dealed %d dmg!", Dmg*lvl/2);
		PHp -= Dmg*lvl/2;
		Sleep(1000);
		system("cls");
		if (esc==1) {
			break;
		}
		if (PHp <= 0 || Hp <=0) {
			esc = 1;
			if (Hp<=0) {
				return 10*MT*lvl;
			} else {
				return 0;
			}
		}
	}
	
}
