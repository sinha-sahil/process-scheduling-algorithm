#include<stdio.h>

struct job{
	int pid;
	int at;
	int bt;
	int tat; int wt;
}f[100], s[100], m[100];

int n, fc=0, sc=0, mc=0;

void merger(){
	int min= fc, i, flag=1, r=0, maxr=0;
	if( fc>0 && sc>0){
		if(min>sc){ flag=2; min=sc;	}
		while(r != min){
			if(flag==1){
				if(f[r].at == s[maxr].at){
					m[mc]= f[r]; r++; mc++;
					m[mc]= s[maxr]; mc++; maxr++;
				}
				else if(f[r].at < s[maxr].at){
					m[mc]= f[r]; r++; mc++;
				}
				else{
					m[mc]= s[maxr]; maxr++; mc++;
				}		
			}
			else{
				if(s[r].at== f[maxr].at){
					m[mc]= f[maxr]; mc++; maxr++;
					m[mc]= s[r]; mc++; r++;
				}
				else if(s[r].at < f[maxr].at){
					m[mc]= s[r]; mc++; r++;
				}
				else{
					m[mc] = f[maxr]; mc++; maxr++;
				}
			
			}
		}
		if(min!=sc){
			while(maxr!=sc){
				m[mc]= s[maxr]; mc++; maxr++;
			}	
		}
		else{
			while(maxr!=fc){
				m[mc]= f[maxr]; mc++; maxr++;
			}
		}
	}	
	else if(sc==0){
		while(r!=fc){
			m[mc]= f[r]; mc++; r++;
		}
	}
	else if(fc==0){
		while(r!=sc){
			m[mc]= s[r]; mc++; r++;
		}
	}
	else {
		printf("\n No Jobs to be done"); exit(0);
	}
}

void printer(){
	int i=0; 
	for(i; i<mc; i++){
		printf("\n\nId: %d Atime: %d", m[i].pid, m[i].at);
	}
}

void input(){
	int map,  i, t;
	printf("Enter total no of queries: "); scanf("%d", &n);
	if(n==0) { printf("\n No queries\n"); exit(0);}
	else{
		printf("\nEnter 1 for faculty and 2 for student\n");
		for(i=0; i<n; i++){
			printf("\nJob Type (1/2): "); scanf("%d", &map);
			if(map==1){
				printf("Query Id: "); scanf("%d", &f[fc].pid);
				printf("Arrival Time: "); scanf("%d", &t); f[fc].at= t-1000;
				printf("Resolving Time: "); scanf("%d", &f[fc].bt);
				fc++;
			} else{
				printf("Query Id: "); scanf("%d", &s[sc].pid);
				printf("Arrival Time: "); scanf("%d", &t); s[sc].at= t-1000;
				printf("Resolving Time: "); scanf("%d", &s[sc].bt);	
				sc++;
			}
		}
	}
}

void main(){
	input();
	merger();
	printer();
}
