#include <stdio.h>
#include <string.h>

int searchIndex(char names[100][30], char comp[30], int list){
	for (int i = 0; i < list; i++){
		if (strcmp(names[i], comp) == 0) return i + 1;
	}
	return 0;
}

int main(){
	FILE* inputFile = fopen("testdata.in", "r");
	int list, flag = 1, cases;
	char names[100][30], comp[30];
	
	if(inputFile == NULL) puts("File not found...");
	else{
		fscanf(inputFile, "%d", &cases);
		
		for(int i = 1; i <= cases; i++){
			fscanf(inputFile, "%d", &list);
		
			for (int j = 0; j < list; j++){
				fscanf(inputFile, "%s", names[j]);
			}
			fscanf(inputFile, "%s", comp);
			
			if (searchIndex(names, comp, list) != 0) printf("Case #%d: %d\n", i, searchIndex(names, comp, list));
			else printf("Case #%d: Not found\n", i);
		}
	}
	return 0;
}
