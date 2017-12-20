#include <stdio.h>

void print_prime_num(const unsigned short * const PRIME_NUM, const unsigned short POSITION) {
	int i;

	for (i = 0; i <= POSITION; i++) {
		printf("%hu\n", PRIME_NUM[i]);
	}
}

unsigned short find_position(const unsigned short INPUT, const unsigned short *const PRIME_NUM, const unsigned short SIZE) {
	unsigned short position, upper_boundary = SIZE - 1, lower_boundary = 0;

	do {
		position = (upper_boundary + lower_boundary) / 2;

		if (INPUT == PRIME_NUM[position]) return position;
		if (INPUT < PRIME_NUM[position]) {
			upper_boundary = position--;
		}
		else {
			lower_boundary = position + 1;
		}

	} while (upper_boundary > lower_boundary);

	return position;
}

void get_prime_num() {
	const unsigned short PRIME_NUM[] = {
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
		31, 37, 41, 43, 47, 53, 59, 61, 67,
		71, 73, 79, 83, 89, 97, 101, 103, 107,
		109, 113, 127, 131, 137, 139, 149, 151,
		157, 163, 167, 173, 179, 181, 191, 193,
		197, 199, 211, 223, 227, 229, 233, 239,
		241, 251, 257, 263, 269, 271, 277, 281,
		283, 293, 307, 311, 313, 317, 331, 337,
		347, 349, 353, 359, 367, 373, 379, 383,
		389, 397, 401, 409, 419, 421, 431, 433,
		439, 443, 449, 457, 461, 463, 467, 479,
		487, 491, 499, 503, 509, 521, 523, 541,
		547, 557, 563, 569, 571, 577, 587, 593,
		599, 601, 607, 613, 617, 619, 631, 641,
		643, 647, 653, 659, 661, 673, 677, 683,
		691, 701, 709, 719, 727, 733, 739, 743,
		751, 757, 761, 769, 773, 787, 797, 809,
		811, 821, 823, 827, 829, 839, 853, 857,
		859, 863, 877, 881, 883, 887, 907, 911,
		919, 929, 937, 941, 947, 953, 967, 971,
		977, 983, 991, 997
	};

	unsigned short input;
	scanf_s("%hu", &input);

	if (input <= 1 || input > 1000) return;

	const unsigned short POSITION = find_position(input, PRIME_NUM, 168);
	print_prime_num(PRIME_NUM, POSITION);
}

int main() {
	get_prime_num();

	return 0;
}