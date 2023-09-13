#include <stdio.h>

int sum(int arr[], int len){
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum+=arr[i];
    }
    return sum;
}

void copy(int *arra, int *arrb, int len){
	
	for(int i = 0; i < len; i++){
		arrb[i] = arra[i];
	}
}

void newArr(int *arr, int *arrb, int len){
    for(int i = 0; i < len; i++){
        if(arr[i] == 1) arrb[i] = arr[i] + 1;
        else arrb[i] = arr[i] - 1;
    }
}

void remakeArr(int *arra, int *arrb, int delta, int len){
	for(int i = 0; i < len; i++){
		if(arrb[i] + delta == arra[i] || arrb[i] + delta < 1) continue;
		else{
			arrb[i] += delta;
			break;
		}
	}
}

int checker(int *arra, int *arrb, int len){
	int status = 0;
	for(int i = 0; i < len; i++){
		if(arra[i] == arrb[i]) return status = 1;
	}
	return status;
}

int main()
{
    int cases, len;
    
    
    //printf("Input case ");
    scanf("%d", &cases);
    
    for(int i = 1; i <= cases; i++){
        scanf("%d", &len);
        
        int arra[len], arrb[len];
        
        for(int j = 0; j < len; j++){
            scanf("%d", &arra[j]);  
        }
        int errarr = 0;
        for(int x = 0; x < len; x++){
        	if(arra[x] < 1) errarr = 1;
		}
		if(errarr == 1){
			puts("No");
			continue;
		}
        //arrb = newArr(arra, len);
        newArr(arra, arrb, len);
//        printf("Case %d:\n", i);
//        printf("Array A: ");
//        for(int j = 0; j < len; j++){
//            printf("%d ", arra[j]);
//        }
//        puts("");
//        printf("Sum of array A: %d\n", sum(arra, len));
//        puts("");
//        printf("Array B: ");
//        for(int j = 0; j < len; j++){
//            printf("%d ", arrb[j]);
//        }
//        puts("");
//        printf("Sum of array B: %d\n", sum(arrb, len));
//        puts("");
        
        int delta = sum(arra, len) - sum(arrb, len);
        remakeArr(arra, arrb, delta, len);
//        printf("Remake Array B: ");
//        for(int j = 0; j < len; j++){
//            printf("%d ", arrb[j]);
//        }
//        puts("");
//        printf("Sum of array B remake: %d\n", sum(arrb, len));
//        puts("");
//        printf("Check for good arrays\n");
        int goodarr = checker(arra, arrb, len);
        if(goodarr != 1 && sum(arra, len) == sum(arrb, len)) puts("Yes");
        else puts("No");
    }

    return 0;
}
