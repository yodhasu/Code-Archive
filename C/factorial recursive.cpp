#include <stdio.h>

int fact(int n){
	if(n == 1 || n == 0) return 1;
	else return n*fact(n-1);
}

int count(int x){
	if(x != 0) return x + count(x - 1);
	else return 0;
}

int main(){
	int usrInpt;
	//printf("%d", fact(31));
	printf("Input number: ");
	scanf("%d", &usrInpt);
	
	printf("Factorial of %d is %d", usrInpt, fact(usrInpt));
	
	return 0;
}
