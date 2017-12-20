//Q1
#include <stdio.h>
 
int main(void) {
	// your code goes here
	printf("kcwongay\n");
	return 0;
}

//Q2
#include <stdio.h>
 
int main(void) {
	// your code goes here
	int ID= 20316340;
	printf("My student ID is %d", ID);
	return 0;
}

//Q3
#include <stdio.h>
 
int main(void) {
	// your code goes here
	int num = 1;
 
	if(num > 0){
		printf("num is positive number.");
	}else if(num < 0){
		printf("num is negative number.");
	}else{
		printf("num is zero.");
	}
	return 0;
}

//Q4
#include <stdio.h>
 
int main(void) {
	// your code goes here
	int i, sum = 0;
 
	for(i = 1; i <= 100; i++){
		sum += i;
	}
 
	printf("Sum is %d", sum);
 
	return 0;
}

//Q5
#include <stdio.h>



int main(void) {
	// your code goes here
	int i, j, k;
	
	for(i = 0; i < 10; i++){
		for(j = 9; j > 0; j--){
			if(j - i >= 0) printf(" ");
			else printf("*");
		}
		for(k = i; k > 0; k--){
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}


//Q6
#include <stdio.h>
 
int factoria(int n){
	if(n < 0) return -1;
	if(n == 0) return 1;
 
	return n * factoria(n - 1);
}
 
int main(void) {
	// your code goes here
	printf("Result from factoria(5) is %d", factoria(5));
 
 
	return 0;
}

//Q7
#include <stdio.h>

int is_prime(int n){
	int i, check_num[] = {2, 3, 5, 7, 11, 13, 
					   17, 19, 23, 29, 31,
					   37, 41, 43, 47, 53,
					   59, 61, 67, 71, 73,
					   79, 83, 89, 97
					  };
	
	if(n <= 1) return -1;
	for(i = 0; i < 25; i++){
		if(n % check_num[i] == 0 && n / check_num[i] != 1) return 0;
	}
	
	return 1;
}

int main(void) {
	// your code goes here
	printf("The result is %d.", is_prime(2));
	
	return 0;
}

//Q8
#include <stdio.h>
 
int mean(int arr[], int size){
	int i, sum = 0;
	for(i = 0; i < size; i++){
		sum += arr[i];
	}
	return sum / size;
}
 
int main(void) {
	// your code goes here
	int arr[] = {1, 2, 3};
 
	printf("The mean is %d", mean(arr, 3));
	return 0;
}

//Q9
#include <stdio.h>
#include <math.h>

void dec_to_hex_helper(int dec, int i, char *result){
	int remainders = dec % 16, quotient = dec / 16;
	char tmp;
	
	if(remainders > 0 && remainders < 10){
		sprintf(&tmp, "%d", remainders);
		
		result[i] = tmp;
	}else if(remainders == 10){
		result[i] = 'A';
	}else if(remainders == 11){
		result[i] = 'B';
	}else if(remainders == 12){
		result[i] = 'C';
	}else if(remainders == 13){
		result[i] = 'D';
	}else if(remainders == 14){
		result[i] = 'E';
	}else if(remainders == 15){
		result[i] = 'F';
	}
	
	if(dec < 16) return;

	dec_to_hex_helper(quotient, i - 1, result);
}

dec_to_hex(int dec, char *result){
	dec_to_hex_helper(dec, log(dec)/log(16), result);
}

int main(void) {
	// your code goes here
	char result[4] = {'/0'};
	int dec = 33;

	dec_to_hex(dec, result);

	printf("Result is %s", result);

	return 0;
}

