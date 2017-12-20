#include <stdio.h>

unsigned short is_prime(const unsigned short NUM, const unsigned short * const PRIME_NUM, const unsigned short SIZE)
{
	unsigned short i;

	for (i = 2; i < SIZE; i++)
	{
		if (NUM % PRIME_NUM[i] == 0) return 0;
	}

	return 1;
}

void print_prime_nums(const unsigned short INPUT) {
	const unsigned short PRIME_NUM[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	const unsigned short SIZE = 11, MAX_ITERATION = 166;
	unsigned short test_num, i, j;

	for (i = 0; i < SIZE; i++) {
		if (INPUT < PRIME_NUM[i]) break;

		printf("%hu\n", PRIME_NUM[i]);
	}
	

	for (j = 6; j < MAX_ITERATION + 1; j++)
	{
		test_num = 6 * j - 1;
		if (test_num > INPUT) return;
		if (is_prime(test_num, PRIME_NUM, SIZE)) printf("%hu\n", test_num);

		test_num = 6 * j + 1;
		if (test_num > INPUT) return;
		if (is_prime(test_num, PRIME_NUM, SIZE)) printf("%hu\n", test_num);
	}

}

void get_prime_nums() {
	unsigned short input;

	scanf_s("%hu", &input);
	print_prime_nums(input);
}



int main() {
	
	get_prime_nums();
	return 0;
}