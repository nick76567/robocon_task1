#include <stdio.h>

#define FALSE 0
#define TRUE  1


unsigned short is_prime(const unsigned short TEST_NUM)
{
	unsigned short i;

	if (TEST_NUM % 2 == 0) return FALSE;

	for (i = 3; i <= TEST_NUM / i; i += 2)
	{
		if (TEST_NUM % i == 0 && TEST_NUM != i) return FALSE;
	}

	return TRUE;
}

void print_prime_nums(const unsigned short INPUT)
{
	unsigned short i;
	printf("2\n");

	for (i = 3; i <= INPUT; i += 2)
	{
		if (is_prime(i)) printf("%hu\n", i);
	}
}

void get_prime_nums()
{
	unsigned short input;

	scanf_s("%hu", &input);
	print_prime_nums(input);
}

int main() {
	get_prime_nums();


	return 0;
}