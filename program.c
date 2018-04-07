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


void assignProcessInQueue(int n, struct process proc[]) {
	int i ;
	for(i=0; i<n; i++) {
		if((proc[i].priority)>=0 && (proc[i].priority)<100) {
			queue1Push(proc[i]) ;
		} else if ((proc[i].priority)>=100 && (proc[i].priority)<200) {
			queue2Push(proc[i]) ;
		} else if ((proc[i].priority)>=200 && (proc[i].priority)<300) {
			queue3Push(proc[i]) ;
		} 
	}	
}


void printQueueFront() {
//	printf("Queue 1 1st -> P%d\n",queue1Front().processId) ;
//	printf("Queue 2 1st -> P%d\n",queue2Front().processId) ;
//	printf("Queue 3 1st -> P%d\n",queue3Front().processId) ;
	int i ;
	printf("Process in Queue 1 - ") ;
	for(i=0;i<=rear1;i++) {
		printf("P%d  ",queue1[i].processId) ;
	}
	printf("\nProcess in Queue 2 - ") ;
	for(i=0;i<=rear2;i++) {
		printf("P%d  ",queue2[i].processId) ;
	}
	printf("\nProcess in Queue 3 - ") ;
	for(i=0;i<=rear3;i++) {
		printf("P%d  ",queue3[i].processId) ;
	}
	printf("\n") ;
}


void roundRobin(int n, struct process proc[]) {
	int i,j,time,remain=n,flag=0,timeQuantum = 4,waitTime=0,turnAroundTime=0 ;
	
	printf("\n\nProcess\t\tWaiting Time    Turnaround Time\n\n"); 
  	for(time=0,i=0;remain!=0;) {  	 
	    if((proc[i].responseTime<=timeQuantum) && (proc[i].responseTime)>0) { 
			time+=(proc[i].responseTime); 
	      	(proc[i].responseTime)=0; 
	      	flag=1; 
	    } else if((proc[i].responseTime)>0) { 
			(proc[i].responseTime)-=timeQuantum; 
			time+=timeQuantum; 
	    } if((proc[i].responseTime)==0 && flag==1) { 
		    remain--; 
			printf("Process[%d]\t\t%d\t\t%d\n",proc[i].processId,time-((proc[i].arrivalTime)-(proc[i].burstTime)),time-(proc[i].arrivalTime)); 
		    waitTime+=time-(proc[i].arrivalTime)-(proc[i].burstTime); 
			turnAroundTime+=time-(proc[i].arrivalTime); 
		    flag=0; 
	    } if(i==n-1) 
	    	i=0; 
	    else if((proc[i+1].arrivalTime)<=time) 
	    	i++; 
	    else 
	    	i=0; 
	} 
	//printf("\nAverage Waiting Time= %f\n",waitTime*1.0/n); 
	//printf("Avg Turnaround Time = %f",turnAroundTime*1.0/n); 
}


void fcfs(int n, struct process proc[]) {
	float abTime[500],wTime[500],tat_time[500];
	int i = 0 ;
    float aw_time = 0, atat_time = 0;
    wTime[0] = 0;
    tat_time[0] = queue3[front3].burstTime;
    abTime[0] = queue3[front3].burstTime+queue3[front3].arrivalTime;
    for( i = 1 ; i < n ; i++){
        abTime[i] = abTime[i-1] + proc[i].burstTime;
        tat_time[i] = abTime[i] - proc[i].arrivalTime;
        wTime[i] = tat_time[i] - proc[i].burstTime;
    }
    for(i = 0 ; i < n ; i++){
        aw_time = aw_time + wTime[i];
        atat_time = atat_time + tat_time[i];
    }
    printf("\n\t\tWaiting Time    Turnaround Time\n");
    for(i = 0 ; i < n ; i++){
        printf("\nProcess[%d]\t\t%0.2f\t\t%0.2f\n",proc[i].processId,wTime[i],tat_time[i]);
    }
    //printf("\nAverage waiting time : %0.2f",aw_time/n);
    //printf("\nAverage turn around time : %0.2f",atat_time/n);       
}


void priorityScheduling(int n, struct process proc[]) {
	int time = 0,largest ;
	struct process temp;
int i,j,sum_bt;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
if(proc[i].arrivalTime>proc[j].arrivalTime)
{
temp=proc[i];
proc[i]=proc[j];
proc[j]=temp;
}
}
for(i=0;i<n;i++)
 {
 	proc[i].processed=0;
 sum_bt+=proc[i].burstTime;
 }
 proc[rear2+1].priority=-9999;
printf("\nProcess\t\tPriority\t\tWaiting Time\t\tTurnaround Time ");
  for(time=queue2[front2].arrivalTime;time<sum_bt;)
  {
    largest=rear2+1;
    for(i=0;i<n;i++)
    {
      if(proc[i].arrivalTime<=time && proc[i].processed!=1 && proc[i].priority>proc[largest].priority)
        largest=i;
    }
      time+=proc[largest].burstTime;
      int ct[100],wt[100],tt[100] ;
  ct[largest]=time;
          wt[largest]=ct[largest]-proc[largest].arrivalTime-proc[largest].burstTime;
    tt[largest]=ct[largest]-proc[largest].arrivalTime;
    proc[largest].processed=1;
    //avgwt+=p[largest].wt;4
printf("\nProcess[%d]\t\t%d\t\t\t%d\t\t\t%d\t",proc[largest].processId,proc[largest].priority,wt[largest],tt[largest]);
}
//printf("\nAverage waiting time:%f\n",avgwt/n);
printf("\n") ;
}


void queueScheduling1() {
	roundRobin(rear1+1, queue1) ;
}
void queueScheduling2() {
	priorityScheduling(rear2+1, queue2) ;
}
void queueScheduling3() {
	fcfs(rear3+1, queue3) ;
}

int main() {
	int n ;
	printf("How many process - ") ;
	scanf("%d",&n) ;
	struct process proc[n] ;
	createProcess(n, proc) ;
	assignProcessInQueue(n, proc) ;
	printQueueFront() ;
	queueScheduling1() ;
	queueScheduling2() ;
	queueScheduling3() ;
//	int i ;
//	for(i = 0; i<n;i++) {
//		
//		printf("%d %d %d %d\n",proc[i].processId,proc[i].arrivalTime,proc[i].burstTime,proc[i].priority) ;
//	}
}




// main_scheduling() {
//    RoundRobin - 10sec
//          q1 / q2 / q3
// }

// queue1() - round robin 4 secs
// queue2() - priority scheduling
// queue3() - FCFS