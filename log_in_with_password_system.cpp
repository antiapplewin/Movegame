#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char name[100], password[100], guesspass[100], login[100];
	
	scanf("%s", name);
	strcpy(login,name);
	strcat(login,".txt");
    
    FILE* fp = fopen(login, "r");
    
    fscanf(fp, "%s", password);
    scanf("%s", guesspass);
    
    int res = strcmp(password, guesspass);
    
    if (res == 0) {
    	printf("succed");
	} else {
		printf("wrong pass");
	}
}
