#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char str[110] = "abcdefghijklmnopqrst";
	printf("%d - %d - %d - %d -%d -%d\n", atoi("  - 5"), atoi(" --5"), atoi("-+5"), atoi("+-5"), atoi("+5"), atoi("-5"));
	
	printf("%p -- %p\n", str, strchr(str, '0'));
}
