#include<stdio.h>
#include<stdlib.h>
//二分答案
int judge(int ans);
int cmp(const void *a,const void *b){
    return *(long int *)a-*(long int *)b;
}

int n,c;
long int stall_number[100001];

int main (){
    int ans;
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++) scanf("%ld",&stall_number[i]);
    qsort(stall_number,n,sizeof(long int),cmp);
    int l=stall_number[0],r=stall_number[n-1],mid=(l+r)/2;
    while(l<=r){
        if(judge(mid)==1){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
        mid=(l+r)/2;
    }
    printf("%d",ans);
}

int judge(int ans){
    int count=1,pre=0;
    for(int i=1;i<n;i++){
        if(stall_number[i]-stall_number[pre]>=ans){
            count++;
            pre=i;
        }
    }
    if(count>=c) return 1;
    else return 0;
}