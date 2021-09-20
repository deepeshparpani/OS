#include <stdio.h>
#define max 1000
int main(){
int n;
scanf("%d",&n);
int at[n],bt[n+1],tmp[n],t,ct,x,c;
for(int i=0;i<n;i++){
scanf("%d",&at[i]);
}
for(int i=0;i<n;i++){
scanf("%d",&bt[i]);
tmp[i]=bt[i];
}
int i;
float wt=0;
bt[n+1]=max;
for(t=0;c!=n;t++){
x=n+1;
for(i=0;i<n;i++){
    if(at[i]<=t && bt[i]<bt[x]&&bt[i]>0){
        x=i;
    }
}

bt[x]--;
if(bt[x]==0){
    c++;
    ct=t+1;
    wt=wt+ct-at[x]-tmp[x];
}
}
float avgwt=wt/n;
printf("%.2f",avgwt);
return 0;

}
