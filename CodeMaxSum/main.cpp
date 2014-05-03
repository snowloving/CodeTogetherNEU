#include<stdio.h>
#include<string.h>

#define MAX 100001
#define INF 99999

int cases;

int max(int a,int b)
{
	return a>b?a:b;
}


int main(void)
{
	int N;
	int dp[MAX];
	int s[MAX];
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		memset(dp,0,sizeof(dp));		//所有数都是负的怎么办
		int n;
		scanf("%d",&n);
		for(int oo=1;oo<=n;oo++)
		{
			scanf("%d",&s[oo]);
		}
		for(int oo=1;oo<=n;oo++)
		{
			if(dp[oo-1]<0)
				dp[oo]=s[oo];
			else
				dp[oo]=max(dp[oo-1],dp[oo-1]+s[oo]);
		}
		for(int j=1;j<=n;j++) printf("%d ",dp[j]);
		printf("\n");
		printf("Case %d:\n%d",i,dp[n]);
	}
	return 0;
}
