#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ndigit(int n);
int nthDigit(int num, int digit);

int main() {

	int one = 1;
	int ten = 1;
	int hundred = ndigit(100);
	int thousand = ndigit(1000);
	int tenthou = ndigit(10000);
	int hundredthou = ndigit(100000);
	int million = ndigit(1000000);
	int result = one*ten*hundred*thousand*tenthou*hundredthou*million;

	printf("Answer is %d\n",result);
	return 0;
}

int ndigit(int n) {

	int limit = 9;
	int numDigits = 2;

	if (n < 10) return n;

	while (1) {
		limit += 9*pow(10.0,numDigits-1)*numDigits;
		if (n <= limit) { 
			limit -= 9*pow(10.0,numDigits-1)*numDigits;
			break;
		}
		numDigits++;
	}

	int theNum = (n - limit)/numDigits+pow(10.0,numDigits-1)-1;
	int remain = (n - limit)%numDigits;

	if (remain == 0) {
		return (theNum%10);
	} else {
		return nthDigit(theNum+1,remain);
	}
}

int nthDigit(int num, int digit) {

	int i;
	int n = num;
	int count;
	int *got = malloc(25);
	int idx = 0;
	int res;	

	while (n > 0) {
		got[idx++] = n%10;
		n /= 10;
	}

	for (i = idx-1, count = 0; i >= 0 && count < digit; i--,count++) {
		res = got[i];
	}
	return res;
}
