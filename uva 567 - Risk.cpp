///a bfs problem. just calculate the level up to y.
/// and print the level value.
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i,j,t,n,a,b,cas,node,edges,x,y;
ll level[25];

ll BFS(vector<ll>e[25],ll x,ll y)
{
    memset(level,-1,sizeof(level));
    queue<ll>q;
    q.push(x);
    level[x]=0;
    while(!q.empty())
    {
        ll r=q.front();
        q.pop();
        for(i=0; i<e[r].size(); i++)
        {
            if(level[e[r][i]]==-1)
            {
                level[e[r][i]]=level[r]+1;
                q.push(e[r][i]);
                if(e[r][i]==y)
                    return level[e[r][i]];
            }
        }
    }
}

int main()
{
    cas=1;
    while(scanf("%lld",&n)!=EOF)
    {
        vector<ll>e[25];
        while(n--)
        {
            scanf("%lld",&b);
            e[1].push_back(b);
            e[b].push_back(1);
        }
        for(i=2; i<=19; i++)
        {
            scanf("%lld",&n);
            while(n--)
            {
                scanf("%lld",&b);
                e[i].push_back(b);
                e[b].push_back(i);
            }
        }
        printf("Test Set #%lld\n",cas);
        scanf("%lld",&t);
        while(t--)
        {
            scanf("%lld %lld",&x,&y);
            ll ans=BFS(e,x,y);
            if(x<10)
                printf(" ");
            printf("%lld",x);
            printf(" to ");
            if(y<10)
                printf(" ");
            printf("%lld",y);
            printf(": ");
            printf("%lld\n",ans);
        }
        printf("\n");
        cas++;
    }
    return 0;
}

