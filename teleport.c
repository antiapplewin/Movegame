#include <stdio.h>

int Tp() {
	int where;
	printf("Where do you want to go?\n");
	printf("1. tutorial\n");
	printf("2. world 1\n");
	printf("Where to go? : ");
	scanf("%d", &where);
	return where-1;
}
