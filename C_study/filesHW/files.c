#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Cut(FILE *src, FILE *dst);

int main()
{
    char sname[1024], dname[1024];
    FILE *sfile, *dfile;

    gets(sname);
    gets(dname);

    sfile = fopen(sname, "rb");
    if (!sfile)
    {
        printf("%s 无法打开!\n", sfile);
    }
    dfile = fopen(dname, "wb");
    if (!dfile)
    {
        printf("%s 无法打开!\n", dfile);
    }

    if (sfile && dfile)
    {
        printf("正在整理...");
        Cut(sfile, dfile);
        puts("整理完成!");
    }

    if (sfile)
    {
        fclose(sfile);
    }
    if (dfile)
    {
        fclose(dfile);
    }
    return 0;
}


void Cut(FILE *src, FILE *dst){
    char s[10001] = {0};
    int pos, f = 0;
    while (fgets(s, 10001, src)){
        pos = strlen(s);
        pos--;
        while (s[pos] == ' ' || s[pos] == '\t' || s[pos] == '\n' || s[pos] == '\r') {
            pos--;
        }
        s[pos + 1] = '\0';
        fputs(s, dst);
        fputc('\n', dst);
    }
}






// void Cut(FILE *src, FILE *dst){
//     char s_temp, s_pre = 0, ans[1000001] = {0};
//     int cnt = 0, f = 0, pos = 0, pos_now = 0, k = 0, judge = 1;
//     s_pre = fgetc(src);
//     while (!feof(src)){
//         s_temp = fgetc(src);
//         if(f == 0){
//             if ((s_pre == ';' || s_pre == '{' || s_pre == '}' || s_pre == '(' || s_pre == ')' || s_pre == '>')){
//                 if(s_temp != ' ' && s_temp != '\t'){
//                     f = 0;
//                 }else{
//                     f = 1;
//                     ans[k] = s_pre;
//                     k++;
//                 }
//             }
//             else f = 0;
//         }
//         if(f == 0) {
//             ans[k] = s_pre;
//             k++;
//         }
//         else if(f == 0 && cnt == 0){
//             ans[k++] = '\r';
//             ans[k++] = '\n';
//             cnt = 1;
//         }
//         s_pre = s_temp;
//         if(s_temp == '\n') {
//             f = 0;
//             cnt = 0;    
//         }
//     }
//     k--;
//     while (ans[k] == ' ' || ans[k] == '\t' || ans[k] == '\n' || ans[k] == '\r') {
//         k--;
//     }
//     pos = k;
//     int pos_end = 0, pos_st = 0;
//     for(int i = 0; i < pos; i++){
//         if(ans[i] == '\n' && pos_end <= pos_st) pos_st = i + 1;
//         if(ans[i] == '\r') pos_end = i - 1;
//         if(pos_st < pos_end){
//             for(int j = pos_st; j <= pos_end; j++){
//                 if(ans[j] == ' ' || ans[j] == '\t'){
//                     judge = 0;
//                 }
//                 else{
//                     judge = 1;
//                     break;
//                 }
//             }
//             if(judge == 0){
//                 for(int j = pos_st; j < pos; j++){
//                     ans[j] = ans[j + pos_end - pos_st + 1];
//                 }
//                 pos -= pos_end - pos_st +1;
//                 judge = 1;
//                 i = pos_st + 2;
//                 pos_st = 0;
//                 pos_end = 0;
//             }
//         }
//     }
//     pos_now = 0;
//     while (pos_now <= pos){
//         fputc(ans[pos_now], dst);
//         pos_now++;
//     }
// }





// void Cut(FILE *src, FILE *dst){
//     char s_temp, s_pre = 0;
//     FILE *temp;
//     temp = fopen("trial.c", "wb+");
//     int cnt = 0, f = 0, pos = 0, pos_now = 0;
//     s_pre = fgetc(src);
//     while (!feof(src)){
//         s_temp = fgetc(src);
//         if(f == 0){
//             if ((s_pre == ';' || s_pre == '{' || s_pre == '}' || s_pre == '(' || s_pre == ')' || s_pre == '>')){
//                 if(s_temp != ' ' && s_temp != '\t'){
//                     f = 0;
//                 }else{
//                     f = 1;
//                     fputc(s_pre, temp);
//                 }
//             }
//             else f = 0;
//         }
//         if(f == 0) fputc(s_pre, temp);
//         else if(f == 0 && cnt == 0){
//             fputc('\r', temp);
//             fputc('\n', temp);
//             cnt = 1;
//         }
//         s_pre = s_temp;
//         if(s_temp == '\n') {
//             f = 0;
//             cnt = 0;    
//         }
//     }
//     char ct;
//     fseek(temp, -1, SEEK_END);
//     //printf("%d",ftell(temp));
//     ct = fgetc(temp);
//     fseek(temp, -1, SEEK_CUR);
//     //printf("%c",ct);
//     while (ct == ' ' || ct == '\t' || ct == '\n' || ct == '\r') {
//         fseek(temp, -1, SEEK_CUR);
//         ct = fgetc(temp);
//         fseek(temp, -2, SEEK_CUR);
//     }
//     pos = ftell(temp);
//     printf("%d",pos);
//     char exch;
//     fseek(dst, 0, SEEK_SET);
//     fseek(temp, 0, SEEK_SET);
//     pos_now = ftell(dst);
//     fseek(temp, 0, SEEK_SET);
//     while (pos_now <= pos){
//         pos_now = ftell(dst);
//         exch = fgetc(temp);
//         fputc(exch, temp);
//         //printf("%d\n",pos_now);
//     }
//     fclose(temp);
// }

