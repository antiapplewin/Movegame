#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "monster.c"
#include "teleport.c"
#include "TUA.c"

void Lvl(int* lvel, int* expr);

int main() {
	int flvl = 0, fexp = 0, fcoin = 0, hon;
	int a1 = 1, a2 = 0, a3 = 0, a4 = 0;
	int d1 = 1, d2 = 0, d3 = 0, d4 = 0;
	printf("Do you have your account? type in 1 or 0 : ");
	scanf("%d", &hon);
	char name[100], password[100], guesspass[100], login[100];
	
	if (hon==1) {
		printf("type your account name : ");	
		scanf("%s", name);
		strcpy(login,name);
		strcat(login,".txt");
	    
	    FILE* fp = fopen(login, "r");
	    
	    fscanf(fp, "%s", password);
	    printf("what\'s your password? : ");
	    scanf("%s", guesspass);
	    fscanf(fp, "%d", &flvl);
	    fscanf(fp, "%d", &fexp);
	    fscanf(fp, "%d", &fcoin);
	    
	    int res = strcmp(password, guesspass);
	    
	    if (res == 0) {
	    	printf("succed");
		} else {
			return 0;
		}
		fclose(fp);
	} else {
		printf("pick your name : ");
		scanf("%s", name);
		strcpy(login,name);
		strcat(login,".txt");
		FILE* fp = fopen(login, "w");
		printf("pick your password : ");
		scanf("%s", password);
		for (int i = 0;; i++) {
			if (password[i]=='\0') {
				break;
			}
			fprintf(fp,"%c", password[i]);
		}
		fprintf(fp, " ");
		fprintf(fp, "1 ");
		fprintf(fp, "0 ");
		fprintf(fp, "0 ");
		fclose(fp);
		flvl = 1;
		fexp = 0;
		fcoin = 0;
	}
	
	system("cls");
	
	srand(time(NULL));
	
	int X = 1, Y = 5;
	int map[10][10] = {0};
	int T_map[10][10] = {0};
	int coin = fcoin, lvl = flvl, exp = fexp;
	
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
	int MAP = 0;
	MAP = 0;
	while (1) {
		
		Lvl(&lvl, &exp);
		int fexp = lvl*100;
		
		printf("\n\n");
		printf("LVL = %d exp = %d/%d coins = %d MAP%d\n==========================================\n", lvl, exp, fexp, coin, MAP);
		printf("pick a way (WASD) : ");
		scanf("%c", &way);
		
		if (MAP == 0) {
			T_map[Y][X] = 0;
		} else if (MAP == 1) {
			map[Y][X] = 0;
		}
		
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
		} else if (way == 'R') {
			if (MAP == 1) { // 1
				for (int i = 0; i<=9; i++) {
					for (int j = 0; j<=9; j++) {
						map[i][j] = 0;
					}
				}
				
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
			} else if (MAP == 0) { // 2
				for (int i = 0; i<=9; i++) {
					for (int j = 0; j<=9; j++) {
						T_map[i][j] = 0;
					}
				}
				
				for (int i = 1; i<= 12; i++) {
					int x = rand()%10;
					int y = rand()%10;
					if (T_map[x][y] != 0) {
						for (int escape = 0;escape!=1;) {
							x = rand()%10;
							y = rand()%10;
							if (T_map[x][y] == 0) {
								escape = 1;
							}
						}
					}
					T_map[x][y] = -1;
				}
				
				for (int i = 1; i<= 16; i++) {
					int x = rand()%10;
					int y = rand()%10;
					if (T_map[x][y] != 0) {
						for (int escape = 0;escape!=1;) {
							x = rand()%10;
							y = rand()%10;
							if (T_map[x][y] == 0) {
								escape = 1;
							}
						}
					}
					T_map[x][y] = 2;
				}
				
				for (;;) {
					X = rand()%10;
					Y = rand()%10;
					if (T_map[Y][X] != 0) {
						for (int escape = 0;escape!=1;) {
							X = rand()%10;
							X = rand()%10;
							if (T_map[Y][X] == 0) {
								escape = 1;
							}
						}
					}
					T_map[Y][X] = 1;
					break;
				}
			} // 3
		} else if (way=='T') {
			system("cls");
			MAP = Tp();
		} else if (way=='U') {
			FILE* fp = fopen(login, "w");
			for (int i = 0;; i++) {
				if (password[i]=='\0') {
					break;
				}
				fprintf(fp,"%c", password[i]);
			}
			fprintf(fp, " %d ", lvl);
			fprintf(fp, "%d ", exp);
			fprintf(fp, "%d ", coin);
			fclose(fp);
			system("cls");
			printf("Uploding changes...");
			Sleep(1000);
			system("cls");
		} else if (way=='K') {
			int MN;
			system("cls");
			printf("What will you learn?\n");
			printf("1 > fire magic : 10 coins\n");
			printf("2 > assassin magic : 25 coins\n");
			printf("3 > heal magic : 7 coins\n");
			printf("GIVE ME MONEY : ");
			scanf("%d", &MN);
			if (MN==1&&coin>=10) {
				if (a2==0) {
					a2 = 2;
					d2 = 5;
				} else if (a3 == 0) {
					a3 = 2;
					d3 = 5;
				} else {
					a4 = 2;
					a4 = 5;
				}
				
			} else if (MN==2&&coin>=25) {
				if (a2==0) {
					a2 = 3;
					d2 = 10;
				} else if (a3 == 0) {
					a3 = 3;
					d3 = 10;
				} else {
					a4 = 3;
					a4 = 10;
				}
			} else if (MN==3&&coin>=7) {
				if (a2==0) {
					a2 = 4;
					d2 = 0;
				} else if (a3 == 0) {
					a3 = 4;
					d3 = 0;
				} else {
					a4 = 4;
					a4 = 0;
				}
			}
		}
		
		if (MAP == 0) {
			if (T_map[Y][X] == -1) {
				system("cls");
				printf("Monster attack!");
				Sleep(1000);
				system("cls");
				exp += TU(lvl, a1, d1, a2, d2, a3, d3, a4, d4);
				Sleep(1000);
			}
			
			if (T_map[Y][X] == 2) {
				coin++;
			}
			
			T_map[Y][X] = 1;
			
			system("cls");
			
			for (int i = 0; i<=9; i++) {
				for (int j = 0; j<=9; j++) {
					printf("%d ", T_map[i][j]);
				}
				printf("\n");
			}
		} else if (MAP == 1) {
			if (map[Y][X] == -1) {
				system("cls");
				printf("Monster attack!");
				Sleep(1000);
				system("cls");
				exp += Monster(lvl, a1, d1, a2, d2, a3, d3, a4, d4);
				Sleep(1000);
			}
			
			if (map[Y][X] == 2) {
				coin++;
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
}

void Lvl(int* lvel, int* expr) {
	int fexp = *lvel*100;
	if (*expr >= fexp) {
		*expr = 0;
		*lvel += 1;
	}
}
