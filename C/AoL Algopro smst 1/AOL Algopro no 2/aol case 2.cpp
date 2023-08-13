#include <stdio.h>
#include <string.h>

struct wow
{
	char loc1[50];
	char loc2[50];
	char price[50];
	char room[50];
	char bathroom[50];
	char carpark[50];
	char type[50];
	char area[50];
	char furnish[50];
}typedef wow;

void search(wow arr[], char search[], char col[])
{
	printf("%-25s | %-15s | %-8s | %-3s | %-3s | %-3s | %-10s | %-7s | %-10s\n", "Location 1", "Location 2", "Price", "Rooms", "Bathrooms", "Car Parks", "Type", "Area", "Furnish");
	if(strcmpi(col, "loc1") == 0)
	{
		for(int i=0; i<3940; i++)
		{
			if(strstr(arr[i].loc1, search))
			{
				printf("%-25s | %-15s | %-8s | %-5s | %-9s | %-9s | %-10s | %-7s | %-10s\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].area, arr[i].furnish);
			}
		}
	}
	else if(strcmpi(col, "loc2") == 0)
	{
		for(int i=0; i<3940; i++)
		{
			if(strstr(arr[i].loc2, search))
			{
				printf("%-25s | %-15s | %-8s | %-5s | %-9s | %-9s | %-10s | %-7s | %-10s\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].area, arr[i].furnish);
			}
		}
	}
	else if(strcmpi(col, "room") == 0)
	{
		for(int i=0; i<3940; i++)
		{
			if(strstr(arr[i].room, search))
			{
				printf("%-25s | %-15s | %-8s | %-5s | %-9s | %-9s | %-10s | %-7s | %-10s\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].area, arr[i].furnish);
			}
		}
	}
	else if(strcmpi(col, "bathroom") == 0)
	{
		for(int i=0; i<3940; i++)
		{
			if(strstr(arr[i].bathroom, search))
			{
				printf("%-25s | %-15s | %-8s | %-5s | %-9s | %-9s | %-10s | %-7s | %-10s\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].area, arr[i].furnish);
			}
		}
	}
	else if(strcmpi(col, "carpark") == 0)
	{
		for(int i=0; i<3940; i++)
		{
			if(strstr(arr[i].carpark, search))
			{
				printf("%-25s | %-15s | %-8s | %-5s | %-9s | %-9s | %-10s | %-7s | %-10s\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].area, arr[i].furnish);
			}
		}
	}
	else if(strcmpi(col, "type") == 0)
	{
		for(int i=0; i<3940; i++)
		{
			if(strstr(arr[i].type, search))
			{
				printf("%-25s | %-15s | %-8s | %-5s | %-9s | %-9s | %-10s | %-7s | %-10s\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].area, arr[i].furnish);
			}
		}
	}
	else if(strcmpi(col, "furnish") == 0)
	{
		for(int i=0; i<3940; i++)
		{
			if(strstr(arr[i].furnish, search))
			{
				printf("%-25s | %-15s | %-8s | %-5s | %-9s | %-9s | %-10s | %-7s | %-10s\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].area, arr[i].furnish);
			}
		}
	}
}

int main()
{
	struct wow data[4000];
	FILE *fp;
	fp = fopen("file.csv", "r");
	char line[101], a[101], str[101];
	int i=0;
	fscanf(fp, "%[^\n]\n", &a);
	while(!feof(fp))
	{
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", &data[i].loc1, &data[i].loc2, &data[i].price, &data[i].room, &data[i].bathroom, &data[i].carpark, &data[i].type, &data[i].area, &data[i].furnish);
		i++;
	}
	printf("notice: for the first line input random word and the third line you can input\n	[loc1, loc2, price, room, bathroom, carpark, type, area, furnish]\n");
	printf("NOTE: use uppercase letter in the line of the word that you are searching! (example: Kuala in loc2)\n");
	printf("Input here: ");
	scanf("%s in %s", line, str); getchar();
	
	search(data, line, str);
	puts("Press enter key to continue...");
	getchar();
	fclose(fp);
	return 0;
}
