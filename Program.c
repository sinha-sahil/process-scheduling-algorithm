#include<stdio.h>

struct jobDetails{
	char processName[20];
	int processId;
	int arrivalTime;
	int burstTime;	
};

void main(){
	int total_query, map;
	struct jodDetails student[100], faculty[100];
	printf("Welcome, Mr. Sudhesh\n");
	printf("Enter the total number of process to handle: ");
	scanf("%d", &total_query);
	for(int i=0; i<total_query; i++){
		printf("Query Type (1 for faculty || 2 for Student): ");
		scanf("%d", &map);
		if(map==1){
			
		} 
		else{

		}
	}
}