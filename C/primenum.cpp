#include <stdio.h>

int isPrime(int x){
	int flag = 0;
	if (x != 0 || x != 1){
		for (int i = 2; i <= x/2; i++){
			if (x % i == 0){
				flag = 1;
				break;
			}
		}
	}
	else flag = 1;
	
	return flag;
}

int main(){
	int repeat, num;
	unsigned int status;
	
	scanf("%d", &repeat);
	for (int i = 1; i <= repeat; i++){
		scanf("%d", &num);
		status = isPrime(num);
		if(status != 1){
			printf("Case #%d: Prime Number\n", i);
		}
		else printf("Case #%d: Not Prime Number\n", i);
	}
	return 0;
}
