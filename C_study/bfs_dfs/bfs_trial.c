#include<stdio.h>

struct note
{
    int x;
    int y;
    int pre;
    int step;
};

int main (){
    struct note que[1000001];
    int a[101][101] = {0}, flag[101][101] = {0};
    int direction[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};/*每行的第一个存行变换，第二个存列变换*/
    int n, m, start_x, start_y, end_x, end_y, tx, ty;
    int head, tail, out = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
    head = 0;
    tail = 0;
    /*将起点加入队列*/
    que[tail].x = start_x;
    que[tail].y = start_y;
    que[tail].pre = 0;
    que[tail].step = 0;
    tail++;/*移动至新的队尾*/
    flag[start_x][start_y] = 1;
    out = 0;
    while (head < tail){
        for (int i = 0; i < 4; i++){
            tx = que[head].x + direction[i][0];
            ty = que[head].x + direction[i][1];
            if (tx < 1 || tx > n || ty < 1 || ty > m) continue; /*越界跳过*/
            if (a[tx][ty] == 0 && flag[tx][ty] == 0){ /*可以通过，入队*/
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].pre = 0;
                que[tail].step++;
                tail++;/*移动至新的队尾*/
                flag[tx][ty] = 1;
            }
            if (tx == end_x && ty == end_y) {
                out = 1;
                break;
            }
            
        }
        if(flag == 1) break;
        head++;
    }
    printf("%d\n",que[tail - 1].step);
    return 0;
}
