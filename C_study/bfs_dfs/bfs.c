#include<stdio.h>
//迷宫
struct note//队列
{
    int x;//横坐标
    int y;//纵坐标
    int f;//父节点（上一个结点）
    int s;//步数
};
int main()
{
    struct note que[2501];//定义队列
    int a[51][51]={0},book[51][51]={0};//定义迷宫数组，book用于记录哪些点已遍历过
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//分别代表向右，向下，向左，向上
    int head,tail;//head表示正扩展的结点，tail位于队尾最后一个元素的后面随时将head扩展出来的结点入队
    int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
    scanf("%d %d",&n,&m);//迷宫规格
    for(i = 1;i <= n;i++)
        for(j = 1;j <= m;j++)
        scanf("%d",&a[i][j]);
    scanf("%d %d %d %d",&startx,&starty,&p,&q);//起点，终点
    head = 1;
    tail = 1;
    //将初始入口入队
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].f = 0;
    que[tail].s = 0;
    tail++;//每执行一次入队就后移一位
    book[startx][starty] = 1;//起点已到达过
    flag = 0;//如找到终点即flag=1，现在表示未找到终点
    while(head < tail)//队列不为空
    {
        for(k = 0;k < 4;k++)//枚举4个方向
        {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            if(tx < 1||tx > n||ty < 1||ty > m)//判断是否越界
                continue;
            if(a[tx][ty] == 0 && book[tx][ty] == 0)//判断是否为障碍，是否已经走过
            {
                book[tx][ty] = 1;//记录当前节点已走过，广搜每个节点只搜索一次，所以之后不需要再次置零
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].f = head;
                que[tail].s = que[head].s + 1;
                tail++;//每入队一次tail++
            }
            if(tx==p && ty==q)//是否找到出口
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
        head++;//当前节点的扩展未有找到出口，搜索下一个节点
    }
    printf("%d\n",que[tail - 1].s);//因为tail指向队尾最后一个元素的后一位
    //system("pause");//程序运行完毕，暂停检查数据
    return 0;
}
