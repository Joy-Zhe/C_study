#include<stdio.h>

void func2_n(int n){
    int tmp=n,p=1,floor=0;
    if(n==1){ 
        printf("2(0)");
        return;
    }
    else if(n==2) {
        printf("2");
        return;
    }
    while(tmp-p>=0){
        p*=2;
        floor++;
    }
    if(floor>=1)
    {
        p/=2;
        floor--;
    }
    if(floor==1){
        printf("2");
    }else if(floor==0){
        printf("2(0)");
    }else{
        printf("2(");
        func2_n(floor);
        printf(")");
    }
    if(tmp-p>0){
        printf("+");
        func2_n(tmp-p);
    }
}

int main (){
    int n;
    scanf("%d",&n);
    func2_n(n);
}