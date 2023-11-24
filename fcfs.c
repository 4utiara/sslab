//FCFS//
#include <stdio.h>

int main() {
    // Write C code here
    int i,n,sum=0,totalTAT=0,totalWT=0;
    printf("enter the number of processess");
    scanf("%d",&n);
    int at[n],wt[n],tat[n],ct[n],bt[n];
    printf("enter the burst timeand arrival time of processes");
    for( i=0;i<n;i++){
        scanf("%d%d",&bt[i],&at[i]);
        sum+=bt[i];
        ct[i]=sum;
    }
    float avgTAT,avgWT;
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
    totalTAT+=tat[i];
    }
    avgTAT=(float)(totalTAT/n);
    for(i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        totalWT+=wt[i];
    }
    avgWT=(float)(totalWT/n);
    
    for(i=0;i<n;i++){
    printf("%d %d %d %d %d",i+1,at[i],bt[i],tat[i],ct[i],wt[i]);
    }
printf("average waiting time =%f,and average turnaroundtime = %f",avgWT,avgTAT);
    return 0;
}