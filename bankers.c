/*Write a program in C/C++/Java to simulate the Banker’s algorithm for
deadlock avoidance. Consider at least 3 processes in the system, with 4
resource classes having at least one resource instance for each class.
Assume the values for Available, Allocation, MAX, and request from
a particular process from your side. Program must reflect two cases,
where a safe sequence exists for one and safe sequence does not exist
for another.*/
#include <stdio.h>
 int available[4];
struct process{
    int pid;
    int allocation[4];
    int max[4];
    int need[4];
    int completed;
}p[5];

int isPossible(int a){
    int flag = 1;
    for(int i = 0 ; i < 4 ; i++){
        if(p[a].need[i]>available[i]){
            flag=0;
        }
    }
    return flag;
}
void addResources(int a){
    for(int i = 0 ; i<4 ; i++){
        available[i]+=p[a].allocation[i];
    }
    p[a].completed=1;
    printf("Process with pid->%d has been completed\n"  , a);
}
void main(){
   
    for(int i = 0 ; i < 4 ; i++){
        printf("Enter available resources of type%d\n" , i+1);
        scanf("%d" , &available[i]);
    }
    for(int i = 0 ; i < 5 ; i++){
        p[i].completed=0;
        printf("For process with pid->%d\n" , i);
        p[i].pid=i;
        printf("Enter allocation array\n");
        for(int j = 0 ; j < 4 ; j++){
             scanf("%d" , &p[i].allocation[j]);
        }
        printf("Enter max array\n");
        for(int j = 0 ; j < 4 ; j++){
             scanf("%d" , &p[i].max[j]);
        }
        for(int j = 0 ; j < 4 ; j++){
             p[i].need[j]=p[i].max[j]-p[i].allocation[j];
        }
        
    }
    while(1){
        int safeState=0;
        int count = 0;
        for(int i = 0 ; i < 5 ; i++){
            if(p[i].completed){
                count++;
            }
        }
        if(count==5)break;
        for(int i = 0; i<5;i++){
            if(p[i].completed)continue;
            else if(!isPossible(i))continue;
            else{
                safeState=1;
                addResources(i);
            }
        }
        if(!safeState){
            printf("NO SAFE STATE FOUND");
            break;
        }

    }


}

/*
INPUT CASE
3 3 2 1
P0
Allocation: 0 1 0 3
Max:        7 5 3 5

P1
Allocation: 2 0 0 1
Max:        3 2 2 2

P2
Allocation: 3 0 2 1
Max:        9 0 2 2

P3
Allocation: 2 1 1 0
Max:        4 2 2 1

P4
Allocation: 0 0 2 0
Max:        5 3 3 1

*/