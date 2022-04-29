#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int *tmp;
    tmp=a;
    a=b;
    b=tmp;
    return;
}

int cmp(const void *a,const void *b){
    return (*(int*) a-*(int*) b);
}

void arrangement(char *s,int p){
    int n=strlen(s);
    if(p==n){
        for(int i=0;i<n;i++){
            printf("%c",s[i]);
        }
        printf("\n");
    }else{
        for(int i=p;i<n;i++){
            swap((s+i),(s+p));
            arrangement(s,p);
            swap((s+i),(s+p));
        }
    }
}

int main (){
    char s_in[1001];
    int n;
    scanf("%s",s_in);
    qsort(s_in,strlen(s_in),sizeof(char),cmp);
    arrangement(s_in,0);
}