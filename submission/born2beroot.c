#include "sub.h"

int convert(long long n) {

  int dec = 0, i = 0, rem;

  while (n != 0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    i++;
  }

  return dec;
}

void born2beroot(){
    char str[] = "0010 01 11 111 001 000 11 01 10 1 0000 01 1 1010 111 11 0 000 011 00 1 0000 1 0000 0 01 0100 1 0 010 10 01 1 0 0001 0 010 000 00 111 10 111 0010 001100 001100 001100";
    int init_size = strlen(str);
    char delim[] = " ";

    char *ptr = strtok(str, delim);

	while(ptr != NULL)
	{
		printf("%d\n", convert(ptr));
		ptr = strtok(NULL, delim);
	}
}
