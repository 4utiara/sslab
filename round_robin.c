PROGRAM
#include<stdio.h>
int at[10],bt[10],rt[10],TQ,id[10],wt[10],tat[10];
// declaration of the ready queue
int queue[100];
int front=-1;
int rear=-1;
void insert(int n)
{
if(front==-1)
front=0;
rear=rear+1;
queue[rear]=n;
}
int delete()
{
int n;
n=queue[front];
front=front+1;
return n;
}
int main()
{
int n,TQ,p,TIME=0;
int temp[10],exist[10]={0};
float total_wt=0,total_tat=0,Avg_WT,Avg_TAT;
printf("Enter the number of the process\n");
scanf("%d",&n);
printf("Enter the arrival time and burst time of the process\n");
printf("AT BT\n");
for(int i=0;i<n;i++)
{
scanf("%d%d",&at[i],&bt[i]);
id[i]=i;
rt[i]=bt[i];
}
printf("Enter the time quantum\n");
scanf("%d",&TQ);
insert(0);
exist[0]=1;
while(front<=rear)
{
p=delete();
if(rt[p]>=TQ)
{
rt[p]-=TQ;
TIME=TIME+TQ;
}
else
{
TIME=TIME+rt[p];
rt[p]=0;
}
for(int i=0;i<n;i++)
{
if(exist[i]==0 && at[i]<=TIME)
{
insert(i);
exist[i]=1;
}
}
if(rt[p]==0)
{
tat[p]=TIME-at[p];
wt[p]=tat[p]-bt[p];
total_tat=total_tat+tat[p];
total_wt=total_wt+wt[p];
}
else
{
insert(p);
}
}
Avg_TAT=total_tat/n;
Avg_WT=total_wt/n;
printf("ID BT AT WT TAT\n");
for(int i=0;i<n;i++)
{
printf("%d %d %d %d %d\n",id[i],bt[i],at[i],wt[i],tat[i]);
}
printf("Average waiting time of the processes is : %f\n",Avg_WT);
printf("Average turn around time of the processes is : %f\n",Avg_TAT);
return 0;
}
