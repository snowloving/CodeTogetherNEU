#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000002

const int s=1000000;

int vis[MAX];

int main (void)
{
	int N;
	int sel;
	int sum=0;
	while(scanf("%d",&N)!=EOF)
	{
		memset (vis,0,sizeof(vis));
		for(int i=0;i<N;i++)
		{
			scanf("%d",&sel);
			vis[sel]=1;
			sum+=(sel-1);
		}
		int tmpsum=0;
		int cnt=0;
		int pta=1,ptb=s;
		while(pta<ptb)
		{
			if(vis[pta])
			{
				if(!vis[ptb])
				{
					if(cnt!=0) printf(" ");
					printf("%d",ptb);
					vis[ptb]=1;
					cnt++;
				}
				else if(vis[ptb])
				{
					for(int i=1;i<=s;i++)
					{
						if((vis[i] && vis[s+1-i])==0)
						{
							vis[i]=vis[s+1-i]=1;
							if(cnt!=0) printf(" ");
							printf("%d",i);
							cnt++;
							printf(" %d",s+1-i);
							cnt++;
							break;
						}
					}
				}
			}
			else if(vis[ptb])
			{
				if(!vis[pta])
				{
					if(cnt!=0) printf(" ");
					printf("%d",pta);
					vis[pta]=1;
					cnt++;
				}
				else if(vis[pta])
				{
					for(int i=1;i<=s;i++)
					{
						if((vis[i] && vis[s+1-i])==0)
						{
							vis[i]=vis[s+1-i]=1;
							if(cnt!=0) printf(" ");
							printf("%d",i);
							cnt++;
							printf(" %d",s+1-i);
							cnt++;
							break;
						}
					}
				}
			}
			if(cnt==N) break;
			pta++;
			ptb--;
		}
	}
}
