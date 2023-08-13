#include <stdio.h>
#include <string.h>

struct something
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
};
	
int main()
{
	struct something data[4000];
	FILE *fp;
	fp = fopen("file.csv", "r");
	int i=0;
	char remove[101];
	fscanf(fp, "%[^\n]\n", &remove);
	while(!feof(fp))
	{
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", &data[i].loc1, &data[i].loc2, &data[i].price, &data[i].room, &data[i].bathroom, &data[i].carpark, &data[i].type, &data[i].area, &data[i].furnish);
		//printf("%-28s | %-15s | %-8s | %-3s | %-3s | %-3s | %-10s | %-7s | %-10s\n", data[i].loc1, data[i].loc2, data[i].price, data[i].room, data[i].bathroom, data[i].carpark, data[i].type, data[i].area, data[i].furnish);
		i++;
	}
//	fclose(fp);
	for(int j=0; j<3939-1; j++)
	{
		for(int k=0; k<3939-j-1; k++)
		{
			if(strcmpi(data[k].loc1, data[k+1].loc1) > 0)
			{
				struct something arr = data[k];
				data[k] = data[k+1];
				data[k+1] = arr; 
			}
		}
	}
	for(int j=0; j<3939; j++)
	{
		printf("%-28s | %-15s | %-8s | %-3s | %-3s | %-3s | %-10s | %-7s | %-10s\n", data[j].loc1, data[j].loc2, data[j].price, data[j].room, data[j].bathroom, data[j].carpark, data[j].type, data[j].area, data[j].furnish);
	}
	puts("Press enter to continue...");
	getchar();
	fclose(fp);
	return 0;
}
