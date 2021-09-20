#include <stdio.h>
#include <stdlib.h>
int n,tq;
int at[100],bt[100],tmp[100],wt[100],process[100];
int time=0;
typedef struct l{
    int p;
    struct l *next;
}Q;
Q * queue=NULL;

int execremained(){
    int i;
    int x=0;
    for(i=0;i<n;i++){
        if(tmp[i]>0){
            x=1;
        }
    }
    return x;
}
void addtoq(int i){
    Q*m,*m1;
    m=(Q*)malloc(sizeof(Q));
    m->next=NULL;
    m->p=i;
    if(queue==NULL){
        queue=m;
    }
    else{
        for(m1=queue;m1->next!=NULL;m1=m1->next);
        m1->next=m;
    }
}
int nextprocess(){
    Q * m;
    int x;
    if(queue==NULL){
        return -1;
    }
    else{
        x=queue->p;
        m=queue;
        queue=queue->next;
        free(m);
        return x;
    }
}
void addarrived(){
    int i;
    for(i=0;i<n;i++){
        if(at[i]==time){
            addtoq(i);
        }
    }
}
void schedule(){
int np,torun,q,i;
q=0;
addarrived();
while(execremained()){
    np=nextprocess();
    if(np==-1){
        process[time]=-1;
        time++;
        addarrived();
    }
    else{
        q=tq;
        if(tmp[np]<q){
            q=tmp[np];
        }
        for(i=q;i>0;i--){
            process[time]=np;
            time++;
            tmp[np]--;
            addarrived();
        }
        if(tmp[np]>0){
            addtoq(np);
        }
    }
}
int x;
}
void waitingtime(){
    int i;
    int releasetime,t;
    for(i=0;i<n;i++){
        for(t=time-1;process[t]!=i;t--);
            releasetime=t+1;
            wt[i]=releasetime-at[i]-bt[i];
        
    }
}
    
    

int main(){
    scanf("%d",&n);
    scanf("%d",&tq);
    for(int i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
        tmp[i]=bt[i];
    }
  schedule();
  waitingtime();
  float avgwt;
  for(int i=0;i<n;i++){
      avgwt=avgwt+wt[i];
  }
  avgwt=avgwt/n;
  printf("%.2f",avgwt);
return 0;   
}
