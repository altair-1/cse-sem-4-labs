#include <stdio.h>

void main(){
	int n1, n2, x, i, gcd, opCount=0;
	printf("enter two numbers: \n");
	scanf("%d %d", &n1, &n2);
	x = n1 < n2 ? n1 : n2;
	for (i = x; i >= 1; i--){
		opCount++;
		if (n1%i == 0 && n2 % i == 0){
			gcd = i;
			break;
		}
	}
	printf("GCD of %d and %d is %d\nopCount is %d\n", n1, n2, gcd, opCount);
}