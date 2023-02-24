#include <stdio.h>

int cal(int num1, int num2, char type) {
	int result;
	if (type=='p') {
		result = num1+num2;
	} else if (type == 'm') {
		result = num1-num2;
	} else if (type == 't') {
		result = num1*num2;
	} else if (type == 'd') {
		result = num1/num2;
	} else if (type == 'l') {
		result = num1%num2;
	}
	return result;
}
