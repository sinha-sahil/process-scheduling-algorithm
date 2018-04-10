#include<stdio.h>
#include<iostream>
using namespace std;

struct job{
	int pid;
	int at;
	int bt;
	int tat;
	int wt;
	int cmpt;
	int rbt;
}f[100], s[100], m[100];

int n, fc=0, sc=0, mc=0;
int quanta;

void roundRobin(){

}

void merger(){
	int isc=0, ifc= 0, min, flag;
	if( fc!=0  && sc!=0){
		while(isc<sc && ifc<fc){
			if(f[ifc].at == s[isc].at){
				m[mc] = f[ifc];
				mc++;
				ifc++;
				m[mc]= s[isc];
				mc++;
				isc++;
			}
			else if(f[ifc].at < s[isc].at){
				m[mc]= f[ifc];
				mc++;
				ifc++;
			}
			else if(f[ifc].at > s[isc].at){
				m[mc]= s[isc];
				mc++;
				isc++;
			}
			else;
		}
		if(mc != (fc+sc)){
			if(fc!=ifc){
				while(ifc!=fc){
					m[mc]= f[ifc];
					mc++;
					ifc++;
				}
			}
			else if(sc!=isc){
				while(isc!=sc){
					m[mc]= s[isc];
					mc++;
					isc++;
				}
			}
		}
	}
	else if(fc==0){
		while(isc!=sc){
			m[mc]= s[isc];
			mc++;
			isc++;
		}
		
	}
	else if(sc==0){
		while(ifc!=fc){
			m[mc]= f[ifc];
			mc++;
			ifc++;
		}
	}
	else {
		cout<<"No valid jobs"<<endl;
	}
}

void printer(){
	int i=0; 
	for(i; i<mc; i++){
		printf("\n\nId: %d Atime: %d, RBT: %d, CMPT: %d", m[i].pid, m[i].at, m[i].rbt, m[i].cmpt);
	}
}

void input(){
	int map,  i, t;
	printf("Enter total no of queries: "); scanf("%d", &n);
	if(n==0) { printf("\n No queries\n"); }
	else{
		printf("\nEnter Quanta for each Process: "); scanf("%d", &quanta);
		printf("\nEnter 1 for faculty and 2 for student\n");
		for(i=0; i<n; i++){
			printf("\nJob Type (1/2): "); scanf("%d", &map);
			if(map==1){
				printf("Query Id: "); scanf("%d", &f[fc].pid);
				printf("Arrival Time: "); scanf("%d", &t); f[fc].at= t-1000;
				printf("Resolving Time: "); scanf("%d", &f[fc].bt); f[fc].rbt= f[fc].bt; 
				fc++;
			} else{
				printf("Query Id: "); scanf("%d", &s[sc].pid);
				printf("Arrival Time: "); scanf("%d", &t); s[sc].at= t-1000;
				printf("Resolving Time: "); scanf("%d", &s[sc].bt);	 s[sc].rbt= s[sc].bt;
				sc++;
			}
		}
	}
}

 main(){
	input();
	merger();
	roundRobin();
	printer();
}
