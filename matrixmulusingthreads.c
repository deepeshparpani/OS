#include <stdio.h>
#include <pthread.h>

int MAT1[10][10],MAT2[10][10],MAT3[10][10];

int r1,c1,r2,c2;

void *thread_multiply_matrix(void *);
int main(){
    
    pthread_t tid;
    int i,j,k;
    
    scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&MAT1[i][j]);
        }
    }
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            scanf("%d",&MAT2[i][j]);
        }
    }
    pthread_create(&tid,NULL,thread_multiply_matrix,NULL);
    for(i=0;i<r1;i=i+2){
    for(j=0;j<c2;j++){
        for(k=0;k<c1;k++){
            MAT3[i][j]+=MAT1[i][k]*MAT2[k][j];
            
        }
    }}
    
    pthread_join(tid,NULL);
    
    
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            printf("%d ",MAT3[i][j]);
        }
    }
    return 0;
    }
    
    void *thread_multiply_matrix(void *para){
        int i,j,k;
        for(i=1;i<r1;i=i+2){
            for(j=0;j<c2;j++){
                for(k=0;k<c1;k++){
                    MAT3[i][j]+=MAT1[i][k]*MAT2[k][j];
                }
            }
        }
        pthread_exit(NULL);
    }
        
        
        
    
