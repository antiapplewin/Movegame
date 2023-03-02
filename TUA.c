#include <stdio.h>
#include <windows.h>

int TU(int level, int A1, int d1, int A2, int d2, int A3, int d3, int A4, int d4) {
	int hp = 50;
	int attack;
	while (1) {
		printf("Dummy : lvl 0 HP = %d\n", hp);
		printf("Which attack will you do?\n");
		if (A1==1) { //A1 starter
			printf("1. Slash\n");
		} 
		if (A2==0) { //A2 starter
			printf("2. You don\' have a attack\n");
		} else if (A2==2) {
			printf("2. Fire magic\n");
		} else if (A2==3) {
			printf("2. Assassin magic\n");
		} else if (A2==4) {
			printf("2. heal magic\n");
		} else if (A2==2) {
			printf("2. Fire magic\n");
		} else if (A2==3) {
			printf("2. Assassin magic\n");
		} else if (A2==4) {
			printf("2. heal magic\n");
		}
		if (A3==0) { //A3 starter
			printf("3. You don\' have a attack\n");
		} else if (A3==2) {
			printf("3. Fire magic\n");
		} else if (A3==3) {
			printf("3. Assassin magic\n");
		} else if (A3==4) {
			printf("3. heal magic\n");
		}
		if (A4==0) { //A3 starter
			printf("4. You don\' have a attack\n");
		} else if (A4==2) {
			printf("4. Fire magic\n");
		} else if (A4==3) {
			printf("4. Assassin magic\n");
		} else if (A4==4) {
			printf("4. heal magic\n");
		}
		
		scanf("%d", &attack);
		
		if (attack==1) { //atype = 1
			hp -= d1*level*2;
		}else if (attack==2) { 
			hp -= d2*level*2;
		} else if (attack==3) {
			hp -= d3*level*2;
		} else if (attack==4) {
			hp -= d4*level*2;
		}
		
		printf("You dealed %d DMG!\n", attack*level*2);
		Sleep(1000);
		if (hp<=0) {
			return 10;
		}
		system("cls");
	}
	
}
