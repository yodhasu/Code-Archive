#include <stdio.h>
#include <string.h>

void sortAlgo(char arr[100][100], int n, int usrint[]){
	char temp[100];
	int temp2;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n-1-i; j++){
			if (usrint[j] > usrint[j+1]){
				//swap()
				temp2 = usrint[j];
				usrint[j] = usrint[j+1];
				usrint[j+1] = temp2;
				
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j+1]);
				strcpy(arr[j+1], temp);
			}
		}
	}
}

void printAll(char arr[100][100], int size, int num[]){
	for (int i = 0; i < size; i++){
		//printf("%d. %s index = %d\n", num[i], arr[i], i);
		printf("%d. %s\n", num[i], arr[i]);
	}
}

int main(){
	FILE* inputfile = fopen("testdata.in", "r");
	int loop, arrlen;
	char usrinpt[100][100];
	int usrint[100];
	
	fscanf(inputfile, "%d", &loop);
	
	for (int i = 0; i < loop; i++){
		fscanf(inputfile, "%d", &arrlen);
		for (int j = 0; j < arrlen; j++){
			fscanf(inputfile, "%d. %s", &usrint[j] ,usrinpt[j]);
			//fgets(usrinpt[j], 4, stdin);
		}
		sortAlgo(usrinpt, arrlen, usrint);
		printf("Case #%d:\n", i+1);
		printAll(usrinpt, arrlen, usrint);
		memset(usrinpt, '\0', sizeof(usrinpt));
	}
	
	return 0;
}
