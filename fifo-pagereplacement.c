#include <stdio.h>

int main() {
    int n,f,k,count=0,i,pf=0,j;
    printf("enter the number of reference string elements");
    scanf("%d",&n);
    printf("enter the number of frames");
    scanf("%d",&f);
    int m[10],rs[25];
    printf("enter the reference string ");
    for(i=0;i<n;i++){
    scanf("%d",&rs[i]);
        
    }
    for(i=0;i<f;i++){
    m[i]=-1;
    }
    printf("the page replacement process is \n");
    
    //implimentation of fcfs//
    for(i=0;i<n;i++){
        
        for(k=0;k<f;k++){
            if(m[k]==rs[i])
            break;
            //means a page hit has occoured//
        }
        if(k==f){
            m[count++]=rs[i];
           pf++;
        }
        for(j=0;j<f;j++){
            printf("\t%d",m[j]);
        }
        if(k==f){
            printf("PF NO. %d",pf);
            printf("\n");
        }
        if(count==f){
            count=0;
        }
        printf("the number of page faults using FIFO is %d ",pf);
        
    }

    return 0;
}