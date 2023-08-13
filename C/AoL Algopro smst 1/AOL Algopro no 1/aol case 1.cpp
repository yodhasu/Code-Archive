#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COLUMNS 10000

struct ValueCount {
    char value[100];
    int count;
} valueCount[MAX_COLUMNS];


//function to print maximum value with frequencies
void printMaxValueCount(int valueCountSize) {
    int maxCount = -1;
    int maxIndex = -1;
    for (int i = 0; i < valueCountSize; i++) {
        if (valueCount[i].count > maxCount) {
            maxCount = valueCount[i].count;
            maxIndex = i;
        }
    }

    if (maxIndex != -1) {
        printf("Maximum value: %s with frequencies: %d\n", valueCount[maxIndex].value, maxCount);
    } else {
        printf("No max value found\n");
    }
}

//function to print minimum value with frequencies
void printMinValueCount(int valueCountSize) {
    int minCount = valueCount[0].count;
    int minIndex = -1;
    for (int i = 0; i < valueCountSize; i++) {
        if (valueCount[i].count <= minCount) {
            minCount = valueCount[i].count;
            minIndex = i;
        }
    }

    if (minIndex != -1) {
        printf("Minimum value: %s with frequencies: %d\n", valueCount[minIndex].value, minCount);
    } else {
        printf("No min value found\n");
    }
}


//Function for price and area
void priceFunction(int valueCountSize)
{
	double tot = 0;
	int ifYouDeleteThisArrayItWillBecomeErrorIDontKnowWhy[MAX_COLUMNS];
	double sum = 0;
	int valuePrice[101];
	int values[101];
	
	//count average
	for (int i = 0; i < valueCountSize; i++)
	{
		valuePrice[i] = atoi(valueCount[i].value)*valueCount[i].count;
		tot = tot + valuePrice[i];
		sum = sum + valueCount[i].count;
	}
	double avg = tot/sum;
	
	//convert price value to int to search max and min
	for (int i = 0; i < valueCountSize; i++)
	{
		values[i] = atoi(valueCount[i].value);
	}
	
	//search max
	int maximum = values[0];
	
    for (int c = 1; c < valueCountSize; c++)
    {
        if (values[c] > maximum)
        {
                maximum  = values[c];
        }
    }
    
    //search min
    int minimum = values[0];
	
    for (int c = 1; c < valueCountSize; c++)
    {
        if (values[c] < minimum)
        {
                minimum  = values[c];
        }
    }
	
	printf("Maximum value: %d\n", maximum);
	printf("Minimum value: %d\n", minimum);
	printf("Average value: %.2lf\n", avg);
}

void showMenu()
{
	printf("Column list\n");
	printf("1. Location 1\n");
	printf("2. Location 2\n");
	printf("3. Price\n");
	printf("4. Rooms\n");
	printf("5. Bathrooms\n");
	printf("6. Car Parks\n");
	printf("7. Type\n");
	printf("8. Area\n");
	printf("9. Furnish\n");
}

int main() {
    FILE *file;
    char line[1000], loc[1000];
    //char loc1[] = "Location 1", loc2[] = "Location 2";
    int valueCountIndex = 0;
    int choice;
    showMenu();
    printf("Input choice: ");
    scanf("%d", &choice); getchar();
    
    /*if (strcmp(loc, "loc1") == 0)
    {
    	strcpy(loc, "Location 1");
	}
	else if (strcmp(loc, "loc2") == 0)
	{
		strcpy(loc, "Location 2");
	}*/
	
	switch(choice)
	{
		case 1:
			system("cls");
			strcpy(loc, "Location 1");
			break;
		case 2:
			system("cls");
			strcpy(loc, "Location 2");
			break;
		case 3:
			system("cls");
			strcpy(loc, "Price");
			break;
		case 4:
			system("cls");
			strcpy(loc, "Rooms");
			break;
		case 5:
			system("cls");
			strcpy(loc, "Bathrooms");
			break;
		case 6:
			system("cls");
			strcpy(loc, "CarParks");
			break;
		case 7:
			system("cls");
			strcpy(loc, "Type");
			break;
		case 8:
			system("cls");
			strcpy(loc, "Area");
			break;
		case 9:
			system("cls");
			strcpy(loc, "Furnish");
			break;
			
		default:
			system("cls");
			printf("Choice doesn't exist\n");
			return 0;
		
	}

    file = fopen("file.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    // Read header row
    fgets(line, sizeof(line), file);
    line[strcspn(line, "\n")] = '\0';

    // Get index of specified column
    char *token = strtok(line, ",");
    int columnIndex = -1;
    for (int i = 0; token != NULL; i++) {
        if (strcmp(token, loc) == 0) {
            columnIndex = i;
            break;
        }
        token = strtok(NULL, ",");
    }

    if (columnIndex == -1) {
        printf("Column not found\n");
        return 0;
    }

    // Read file contents
    while (fgets(line, sizeof(line), file)) {
    	line[strcspn(line, "\n")] = '\0';
        token = strtok(line, ",");
        int col = 0;
        while (token != NULL) {
            if (col == columnIndex) {
                // Check if value already exists
                bool found = false;
                for (int i = 0; i < valueCountIndex; i++) {
                    if (strcmp(token, valueCount[i].value) == 0) {
                        valueCount[i].count++;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    // Add new value
                    strcpy(valueCount[valueCountIndex].value, token);
                    valueCount[valueCountIndex].count = 1;
                    valueCountIndex++;
                }
            }
            token = strtok(NULL, ",");
            col++;
        }
    }
	
	//Print value, max value, and min value
	if (columnIndex == 2 || columnIndex == 7) 
	{
		//for price and area only print max, min, and average
		priceFunction(valueCountIndex);
	}
	else
	{
		for (int i = 0; i < valueCountIndex; i++) {
	        printf("%s : %d\n", valueCount[i].value, valueCount[i].count);
	    }
		printMaxValueCount(valueCountIndex);
	 
		printMinValueCount(valueCountIndex);
	}
	getchar();
    fclose(file);
    return 0;
}
