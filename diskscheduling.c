#include <stdio.h>
#include <stdlib.h>
int x,max,ip,nr;
int req[100];
int temp[100];
int fcfs();
int sstf();
int scan();
int cscan();
int clook();
int look();

void restore(){
    for(int i=0;i<nr;i++){
        temp[i]=req[i];
    }
}
int main(){
    
    scanf("%d",&x);
    scanf("%d",&max);
    scanf("%d",&ip);
    scanf("%d",&nr);
    
    for(int i=0;i<nr;i++){
        scanf("%d",&req[i]);
    }
    int ans;
    switch(x){
        case 1: {
                ans=fcfs();
                break;
    }
        case 2:{
            ans=sstf();
            break;
        }
        case 3:{
            ans=scan();
            break;
        }
        case 4:{
            ans=look();
            break;
        }
        case 5:{
            ans=cscan();
            break;
        }
        case 6:{
            ans=clook();
            break;
        }
    }
    printf("%d",ans);
    

return 0;
}
    int fcfs(){
        int curpos=ip;
        
        int curseek,totalseek=0;
        for(int i=0;i<nr;i++){
        curseek=abs(req[i]-curpos);
        curpos=req[i];
        totalseek+=curseek;
        }
        return totalseek;
    }
    
    int sstf(){
        int count=0;
        int total=0;
        int curpos=ip;
        while(count!=nr){
            int min=1000,d,index;
            for(int i=0;i<nr;i++){
                d=abs(req[i]-curpos);
                if(min>d){
                    min=d;
                    index=i;
                }
            }
            total=total+min;
            curpos=req[index];
            req[index]=1000;
            count++;
        }
        return total;
        
    }

    int scan(){
        for(int i=0;i<nr;i++)
    {
        for(int j=0;j<nr-i-1;j++)
        {
            if(req[j]>req[j+1])
            {
                int temp;
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }

        }
    }

    int index;
    for(int i=0;i<nr;i++)
    {
        if(ip<req[i])
        {
            index=i;
            break;
        }
    }


int total=0;
    int i;
    for(i=index-1;i>=0;i--)
        {
            total=total+abs(req[i]-ip);
            ip=req[i];
        }

        total=total+abs(req[i+1]-0);
        ip =0;
        for(i=index;i<nr;i++)
        {
             total=total+abs(req[i]-ip);
             ip=req[i];
            
        }
    return total;
    }
                    

int cscan(){
    for(int i=0;i<nr;i++)
    {
        for( int j=0;j<nr-i-1;j++)
        {
            if(req[j]>req[j+1])
            {
                int temp;
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }

    }
    int index;
    for(int i=0;i<nr;i++)
    {
        if(ip<req[i])
        {
            index=i;
            break;
        }
    }
    int total=0;
    int i;
     for(i=index-1;i>=0;i--)
        {
            total=total+abs(req[i]-ip);
            ip=req[i];
        }
        total=total+abs(req[i+1]-0);
        total=total+abs(max-1-0);
        ip =max-1;
        for(i=nr-1;i>=index;i--)
        {
             total=total+abs(req[i]-ip);
             ip=req[i];
            
        }
   return total;
    }

int clook(){
for(int i=0;i<nr;i++)
    {
        for( int j=0;j<nr-i-1;j++)
        {
            if(req[j]>req[j+1])
            {
                int temp;
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }

    }
    int index;
    int total=0;
    for(int i=0;i<nr;i++)
    {
        if(ip<req[i])
        {
            index=i;
            break;
        }
    }    
    for(int i=index-1;i>=0;i--)
        {
            total=total+abs(req[i]-ip);
            ip=req[i];
        }
        
        for(int i=nr-1;i>=index;i--)
        {
             total=total+abs(req[i]-ip);
             ip=req[i];
            
        }
return total;

}

int look(){
int seek=0;
        int temp;
        int tmp[100];
        int temp1=0,temp2=0;
        int q1[100],q2[100];

        for(int i=0;i<nr;i++){
            if(req[i]>=ip){
                q1[temp1]=req[i];
                temp1++;
                        }
            else{
                q2[temp2]=req[i];
                temp2++;
                        }}


 for(int i=0;i<temp2;i++)
    {
        for(int l=0;l<temp2-1;l++)
        {
            if(q2[l]<q2[l+1])
            {
                temp=q2[l];
                q2[l]=q2[l+1];
                q2[l+1]=temp;
            }
        }
    }
 for(int i=0;i<=temp1;i++)
    {
        for(int l=0;l<temp1-1;l++)
        {
            if(q1[l]>q1[l+1])
            {
                temp=q1[l];
                q1[l]=q1[l+1];
                q1[l+1]=temp;
            }
        
    }
    }
int m=0;
 for(int i=0;i<temp2;i++)
            {   tmp[m]=q2[i];   
                m++;           
            }
for(int i=0;i<temp1;i++)
            {    tmp[m]=q1[i];
                m++;               
            }
seek=seek+abs(ip-tmp[0]);
    for(int i=1;i<m;i++)
    {
        seek=seek+abs(tmp[i]-tmp[i-1]);

}
return seek;
}
    
  
