#include<stdio.h>
#include<string.h>
#include<math.h>
int pos=0;
void erase_blank(char *s,char *p);
int factor(char *s);
int expression(char *s);

int main (){
    char s_in[1001][1001],s_after[1001][1001];
    int ans[100]={0},k=0;
    int test_ans;
    for(k=1;k<=20;k++){
        gets(s_in[k]);
        if(s_in[k][0]=='\0'||s_in[k][0]=='\n'){
            k--;
            break;
        }
        erase_blank(s_in[k],s_after[k]);
        ans[k]=expression(s_after[k]);
        pos=0;
    }
    for(int i=1;i<=k;i++){
        printf("Expression %d: ",i);
        if(ans[i]==1) printf("V");
        else if(ans[i]==0) printf("F");
        printf("\n");
    }
}


void erase_blank(char *s,char *p){
    int i=0,j=0;
    while(*(s+i)!='\0'){
        if(*(s+i)!=' '){
            *(p+j)=*(s+i);
            j++;
        }
        i++;
    }
    *(p+j+1)='\0';
    return;
}

int factor(char *s){
    int ans=0;
    char c=*(s+pos);
    if(c=='!'){
        pos++;
        c=*(s+pos);
        while(c=='(') {
            pos++;
            c=*(s+pos);
        }
        ans=1-(expression(s+pos));
        while(c==')') {
            pos++;
            c=*(s+pos);
        }
    }else if(c=='('){
        while(c=='(') {
            pos++;
            c=*(s+pos);
        }
        ans=expression(s+pos);
        while(c==')') {
            pos++;
            c=*(s+pos);
        }
    }
    else if(c=='V'){
        pos++;
        ans=1;
    }else if(c=='F'){
        pos++;
        ans=0;
    }
    return ans;
}


int expression(char *s){
    int ans=factor(s+pos);
    int f=1;//表达式是否有后续计算
    while(f){
        char op=*(s+pos);
        if( op == '&' || op == '|' ){
            pos++;
            int value=factor(s+pos);
            if(op=='&') ans=ans&value;
            else if(op=='|') ans=ans|value;
        }else{
            f=0;
            pos++;
        }
    }
    return ans;
}//表达式的值