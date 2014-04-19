#include<stdio.h>
#include<string.h>

const int MAX_N=105;
int dp_f(int r,int c);
int data [MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int R,C;

int main(void)
{
    int maxn=0;
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&R,&C);
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            scanf("%d",&data[i][j]);

    for(int i=0;i<R;i++)
        for(int j=0;j<R;j++)
            dp_f(i,j);
    for(int i=0;i<R;i++)
            //printf("\n");
        for(int j=0;j<R;j++)
        if(maxn<dp[i][j]) maxn=dp[i][j];
            //{printf("%d ",dp[i][j]);}
    printf("%d\n",maxn+1);

}


int dp_f(int r,int c)
{
    if(dp[r][c]) return dp[r][c];
    else
    {
        for(int i=0;i<4;i++)
            if(r+dy[i]>=0 && r+dy[i]<R && c+dx[i]>=0 && c+dx[i]<C)
            {
                if(data[r][c]>data[r+dy[i]][c+dx[i]])
                {
                    if(dp[r][c]<dp_f(r+dy[i],c+dx[i])+1)
                        dp[r][c]=dp_f(r+dy[i],c+dx[i])+1;
                }
            }
    }
    return dp[r][c];
}
