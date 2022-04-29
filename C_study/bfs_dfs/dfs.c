#include<stdio.h>
#include<string.h>

const int N=15,sx[8]={-1,-1,-1,0,0,1,1,1},sy[8]={-1,0,1,-1,1,-1,0,1};//八个方向标记做好
int n,sum=0;
int s[N][N], a[N][N];//是否访问过标记
void dfs(int x,int y)
{
    if(x==0&&y==n-1)
    {
        sum++;
        return ;
    }
    for(int i=0;i<8;i++)//依次访问该点周围八个方向
    {
        int nx=x+sx[i];
        int ny=y+sy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<n&&s[nx][ny]==0&&a[nx][ny]==0)//前四个为判断是否在迷宫中  最后一个是判断该点是否被访问过
        {
            a[nx][ny]=1;
            dfs(nx,ny);//是没访问过的点并且是可行点，就继续搜索
            a[nx][ny]=0;//回溯，重新置为0，方便下次访问
        }
    }
    return ;
}
 
int main()
{
    while(scanf("%d",&n))
    {
        sum=0;
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&s[i][j]);
        a[0][0]=1;//左上角访问过，置为1；
        dfs(0,0);
        printf("%d\n",sum);
    }
    return 0;
}