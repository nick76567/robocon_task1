#include <stdio.h>

#define NUMERATOR 	0
#define DENOMINATOR 1

unsigned int get_gcd(unsigned int numerator, unsigned int denominator){
	unsigned int remainder, divisor = numerator, dividend = denominator;

	do{
		remainder = dividend % divisor;
		dividend = divisor;
		divisor = remainder;
	}while(remainder != 0);

	return dividend;
}


void add_fractions(const unsigned int INPUT[2][2], unsigned int *result){
	unsigned int gcd;
	result[NUMERATOR] = INPUT[0][NUMERATOR] * INPUT[1][DENOMINATOR] + INPUT[1][NUMERATOR] * INPUT[0][DENOMINATOR];
	result[DENOMINATOR] = INPUT[0][DENOMINATOR] * INPUT[1][DENOMINATOR];

	gcd = get_gcd(result[NUMERATOR], result[DENOMINATOR]);
	result[NUMERATOR] /= gcd;
	result[DENOMINATOR] /= gcd;
}

void get_add_fractions(){
	unsigned int input[2][2], result[2];

	scanf_s("%u %u %u %u", &input[0][NUMERATOR], &input[0][DENOMINATOR], &input[1][NUMERATOR], &input[1][DENOMINATOR]);

	add_fractions(input, result);

	printf("%u %u\n", result[NUMERATOR], result[DENOMINATOR]);

}

int main(){
	get_add_fractions();

	return 0;
}