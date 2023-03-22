#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char *str = "       -45";
	int res = atoi(str);
	printf("%d", res);
	return 0;
}