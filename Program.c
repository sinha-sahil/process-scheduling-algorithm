#include<stdio.h>

struct jobDetails{
	int processId;
	int arrivalTime;
	int burstTime;	
	int complete;
	int turnAroundTime;
	int waitTime;
}student[100], faculty[100];

void enqueue(int a[], int rear);
void dequeue(int a[], int front);

void getStats(int findex, int sindex);

void Scheduler();

int timeQuanta= 2;

void Scheduler(){
	int fpointer=0, spointer=0;
	int time= 120, i;
	for(i=0; i<=time; i++){
		if(student[spointer].arrivalTime == i || faculty[fpointer] == i){
			if(faculty[fpointer]== i){
				
			}
			else{
				
			}
		}	
		else{
			continue;
		}	
	}
}

void main(){
	int total_query, map, i;
	int facultyJobCount=0, studentJobCount=0;
	printf("Welcome, Mr. Sudhesh\n");
	printf("\nEnter the total number of process to handle: ");
	scanf("%d", &total_query);
	for(i=0; i<total_query; i++){
		printf("\nQuery Type (1 for faculty || 2 for Student): ");
		scanf("%d", &map);
		if(map==1){
			printf("Faculty's query\n");
			printf("QueryId: "); scanf("%d", &faculty[facultyJobCount].processId);
			printf("Arrival Time (mins from 10:00 am): "); scanf("%d", &faculty[facultyJobCount].arrivalTime);
			printf("Query Resolving duration (mins): "); scanf("%d", &faculty[facultyJobCount].burstTime);
			faculty[facultyJobCount].complete= 0;
			facultyJobCount++;
		} 
		else{
			printf("\nStudent's query\n");
			printf("QueryId: "); scanf("%d", &student[studentJobCount].processId);
			printf("Arrival Time (mins from 10:00 am) : "); scanf("%d", &student[studentJobCount].arrivalTime);
			printf("Query Resolving Time (mins): "); scanf("%d", &student[studentJobCount].burstTime);
			student[studentJobCount].complete = 0;
			studentJobCount++;
		}
	}
	getStats(facultyJobCount, studentJobCount);
}

void getStats(int findex, int sindex){
	int i;
	printf("\nDeatails of all Jobs Done:");
	printf("\nFaculty's QueriesDetails\n");
	printf("\nQuery Id \t Arrival Time \t Resolving Time\n");
	for (i = 0; i < findex; i++) {
		printf("%d \t\t %d \t\t %d\n", faculty[i].processId, faculty[i].arrivalTime, faculty[i].burstTime );
	}
}


