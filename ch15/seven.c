#include <stdio.h>

char line[100];
int seven_count;
int data[5];
int three_count;
int index;
void get_data();

int main(){
	seven_count = 0;
	three_count = 0;
	get_data();

	for(index = 1; index <= 5; ++index){
		if(data[index] == 3)
			++three_count;

		if(data[index] == 7)
			++seven_count;
	}

	printf("Threes %d Sevens %d\n",
		three_count, seven_count);
	return(0);
}

void get_data()
{
	printf("Enter 5 numbers\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d %d %d %d %d",
		&data[1], &data[2], &data[3], 
		&data[4], &data[5]);
}
