#include<stdio.h>
#include<conio.h>

struct process {
		int processId ;
		int priority ;
		int arrivalTime ;
		int burstTime ;
		int responseTime ;
		int processed ;
};

struct process queue1[100], queue2[100], queue3[100] ;

int rear1 = -1 ;
int front1 = -1 ;
int rear2 = -1 ;
int front2 = -1 ;
int rear3 = -1 ;
int front3 = -1 ;

void queue1Push(struct process proc) {
	if(front1 == -1) {
		front1 = 0 ;
	}
	rear1 = rear1 + 1 ;
	queue1[rear1] = proc ;
}


void queue1Pop() {
	front1 = front1 + 1 ;
}


struct process queue1Front() {
	return queue1[front1] ;
}


void queue2Push(struct process proc) {
	if(front2 == -1) {
		front2 = 0 ;
	}
	rear2 = rear2 + 1 ;
	queue2[rear2] = proc ;
}


void queue2Pop() {
	front2 = front2 + 1 ;
}


struct process queue2Front() {
	return queue2[front2] ;
}


void queue3Push(struct process proc) {
	if(front3 == -1) {
		front3 = 0 ;
	}
	rear3 = rear3 + 1 ;
	queue3[rear3] = proc ;
}


void queue3Pop() {
	front3 = front3 + 1 ;
}


struct process queue3Front() {
	return queue3[front3] ;
}


void createProcess(int n, struct process proc[]) {	
	int i ;
	for(i=0; i<n; i++) {
		printf("Enter Process Id") ;
		scanf("%d",&proc[i].processId) ;
		printf("Enter Process Arrival Time") ;
		scanf("%d",&proc[i].arrivalTime) ;
		printf("Enter Process Burst Time") ;
		scanf("%d",&proc[i].burstTime) ;
		printf("Enter Processes Priority") ;
		scanf("%d",&proc[i].priority) ;
		proc[i].responseTime = proc[i].burstTime ;
	}
}

int main() {
	int n ;
	printf("How many process - ") ;
	scanf("%d",&n) ;
	struct process proc[n] ;
	createProcess(n, proc) ;
}