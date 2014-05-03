#include<stdio.h>
#include<string.h>

#define MAX 1000005
#define INF 99999


int max(int a,int b)
{
	return a>b?a:b;
}

int dp[MAX];
int s[MAX];//有人说过，大数组不要定义在主函数中，会溢出

int main(void)
{
	int N;
	int st[MAX];
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		memset(dp,0,sizeof(dp));		//所有数都是负的怎么办
		memset(st,0,sizeof(st));
		int n;
		int maxn=-INF;
		int pst,ped;
		scanf("%d",&n);
		for(int oo=1;oo<=n;oo++)
		{
			scanf("%d",&s[oo]);
		}
		dp[1]=s[1];
		int mark=1;;
		for(int oo=2;oo<=n;oo++)
		{
			if(dp[oo-1]<0)
			{
				dp[oo]=s[oo];
				st[oo]=oo;
				mark=oo;
			}
			else
			{
				dp[oo]=dp[oo-1]+s[oo];
				st[oo]=st[mark];
			}
		}
		for(int oo=1;oo<=n;oo++)
		{
			if(maxn<dp[oo])
			{
				maxn=dp[oo];
				ped=oo;
				pst=st[oo];
			}
		}
		printf("Case %d:\n%d %d %d\n",i,maxn,!pst?1:pst,ped);
		if(i!=N) printf("\n");
	}
	return 0;
}
