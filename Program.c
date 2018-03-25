#include<stdio.h>

struct jobDetails{
	int processId;
	int arrivalTime;
	int burstTime;	
	int complete;
	int turnAroundTime;
	int waitTime;
}student[100], faculty[100], ready[100];

int facultyJobCount=0;
int studentJobCount=0;
int rpointer=0;

void readyGen(){
	int i;
	int s=0, f=0;
	int r=0;
	for(i=0; i<=120; i++){
		if(i== student[s].arrivalTime && i == faculty[f].arrivalTime){
			ready[r] = faculty[f]; r++; f++;
			while(i== faculty[f].arrivalTime){
				ready[r]= faculty[f]; r++; f++;
			}
			ready[r]= student[s]; r++; s++;	
			while(i== student[s].arrivalTime){
				ready[r]= student[s]; r++; s++; 
			}		
		}
		else if(i == student[s].arrivalTime){
			ready[r] = student[s];
			r++;
			s++; 
			while(i== student[s].arrivalTime){
				ready[r]= student[s];
				r++; s++;
			}
		}
		else if(i == faculty[f].arrivalTime){
			ready[r]= faculty[f];
			r++;
			f++; 
			while(i == faculty[f].arrivalTime){
				ready[r]= faculty[f];
				r++; f++;
			}
		}
		else continue; 
	} 
	rpointer= r;
}

void printer(){
	int i=0, j=0;
	printf("\nPrinter\n");
	printf("Faculty Jobs: \n");
	for(i=0; i<facultyJobCount; i++){
		printf("Id: %d, Atime: %d, Btime: %d\n", faculty[i].processId, faculty[i].arrivalTime, faculty[i].burstTime);
	}
	printf("Student Jobs: \n");
	for(i=0; i<studentJobCount; i++){
		printf("Id: %d, Atime: %d, Btime: %d\n", student[i].processId, student[i].arrivalTime, student[i].burstTime);
	}
	printf("\nReady Jobs: \n");
	for(i=0; i<rpointer; i++){
		printf("Id: %d, Atime: %d, Btime: %d\n", ready[i].processId, ready[i].arrivalTime, ready[i].burstTime);
	}
}


void summary(int findex, int sindex);

void main(){
	int total_query, map, i;
	printf("Welcome\n");
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
	readyGen();
	printer();
	summary(facultyJobCount, studentJobCount);
}

void summary(int findex, int sindex){
	int i;
	printf("\nSummary:");
	printf("\nFaculty's QueriesDetails\n");
	printf("\nQuery Id \t Arrival Time \t Resolving Time\n");
	for (i = 0; i < findex; i++) {
		printf("%d \t\t %d \t\t %d\n", faculty[i].processId, faculty[i].arrivalTime, faculty[i].burstTime );
	}
}


