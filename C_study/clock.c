#include<stdio.h>
void clk(int *a,int op){
    switch (op){
        case 1:{
            a[op-1]=(a[op-1]+1)%4;
            a[op+2]=(a[op+2]+1)%4;
            a[op]=(a[op]+1)%4;
            a[op+3]=(a[op+3]+1)%4;
        }break;
        case 2: case 8:{
            a[op-1]=(a[op-1]+1)%4;
            a[op-2]=(a[op-2]+1)%4;
            a[op]=(a[op]+1)%4;
        }break;
        case 3:{
            a[op-1]=(a[op-1]+1)%4;
            a[op+2]=(a[op+2]+1)%4;
            a[op-2]=(a[op-2]+1)%4;
            a[op+1]=(a[op+1]+1)%4;
        }break;
        case 4: case 6:{
            a[op-1]=(a[op-1]+1)%4;
            a[op+2]=(a[op+2]+1)%4;
            a[op-4]=(a[op-4]+1)%4;
        }break;
        case 5:{
            a[op-1]=(a[op-1]+1)%4;
            a[op+2]=(a[op+2]+1)%4;
            a[op-4]=(a[op-4]+1)%4;
            a[op-2]=(a[op-2]+1)%4;
            a[op]=(a[op]+1)%4;
        }break;
        case 7:{
            a[op-1]=(a[op-1]+1)%4;
            a[op]=(a[op]+1)%4;
            a[op-4]=(a[op-4]+1)%4;
            a[op-3]=(a[op-3]+1)%4;
        }break;
        case 9:{
            a[op-1]=(a[op-1]+1)%4;
            a[op-4]=(a[op-4]+1)%4;
            a[op-2]=(a[op-2]+1)%4;
            a[op-5]=(a[op-5]+1)%4;
        }break;
        default: break;
    }
}
struct member{
    int p[10];
    int pre;
    int n;
};
// int judge(int *a,int *clk0,int n){
//     int *tmp;
//     tmp=clk0;
//     for(int i=0;i<n;i++){
//         clk(tmp,a[i]);
//     }
//     for(int i=0;i<n;i++){
//         if(tmp[i]) return 0;
//     }
//     return 1;
// }
int f[10]={0};

int bfs(struct member *q,int head,int tail){
    int flag=0;
    for(int i=0;i<9;i++){
        if(q[tail].p[i]!=0){
            flag=1;
            break;
        }
    }
    if(flag==0) return tail;
    for(int i=1;i<=9&&head<tail;i++){
        if(f[i]==0){
            clk(q[tail].p,i);
            f[i]=1;
            q[tail].n=i;
            q[tail].pre=head;
            for(int i=0;i<9;i++){
                if(q[tail].p[i]!=0){
                    flag=1;
                    break;
                }
            }
            if(flag) head++;
            tail=bfs(q,head,tail);
        }
    }
}
int main (){
    int a[11],ans[101]={0};
    struct member queue[11];
    int head=1,tail=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i*3+j]);
            queue[head].p[i*3+j]=a[i*3+j];
        }
    }
    queue[head].pre=0;
    queue[head].n=0;
    tail++;
    tail=bfs(queue,head,tail);
    while(queue[tail].pre){
        printf("%d ",queue[tail].n);
        tail=queue[tail].pre;
    }
}