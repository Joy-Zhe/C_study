#include<stdio.h>

//分治
//先确定一种划分中的最大因子

int divide(int n,int max){
    if(n<1||max<1) return 0;
    else if(n==1||max==1) return 1;
    if(n<max) return divide(n,n);
    if(n==max) return (1+divide(n,max-1));//本身为一种，继续遍历下一种(max-1)
    return (divide(n-max,max)+divide(n,max-1));//某种划分法可以继续分为-其取出max-与-继续遍历(max-1)-两种情况
}

int main (){
    int n;
    scanf("%d",&n);
    printf("%d",divide(n,n));
    return 0;
}