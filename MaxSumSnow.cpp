#include <stdio.h>
#include <string.h>

int main()
{
    int n,a;
    scanf("%d",&n);
    for(a=0;a<n;a++)
    {
        int m,i,j,b[100005],c[100005],max,min,k,h,l=0;
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
            if(i==0)c[i]=b[i];
            else c[i]=c[i-1]+b[i];
        }
        max=c[0];
        for(i=0;i<m;i++)
        {
            if(i==0)
            {
                min=0;
                max-=min;
                k=1;
                h=1;
                continue;
            }
            if(min>c[i-1])
            {
                min=c[i-1];
                l=i+1;
            }
            if(max<(c[i]-min))
            {
                max=c[i]-min;
                if(l!=0)h=l;
                k=i+1;
            }
        }
        printf("Case %d:\n%d %d %d\n",a+1,max,h,k);
        if(a!=n-1)printf("\n");
    }
    return 0;
}
//这个是当初的AC代码~没有用dp
//小宇讲这叫前缀数组
