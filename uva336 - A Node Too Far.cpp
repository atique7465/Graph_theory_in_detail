///This is a BFS problem. Calculate the costs by BFS traversal. Then count the vertices with costs less than TTL.
///Remember source can be reachable even with 0 cost.
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i,j,edges,a,b,cas,start,ttl;
map<ll,ll>level;
map<ll,vector<ll> >e;

ll BFS(ll root)
{
    queue<ll>q;
    q.push(root);
    level[root]=0;
    ll reachable=1; ///as root can be reachable with 0 cost.
    while(!q.empty())
    {
        ll r=q.front();
        q.pop();
        for(i=0; i<e[r].size(); i++)
        {
            ll n = e[r][i];
            if(!level.count(n))
            {
                level[n]=level[r]+1;
                if(level[n]<=ttl)
                {
                    reachable++;
                }
                q.push(n);
            }
        }
    }
    return reachable;
}

int main()
{
    cas=1;
    scanf("%lld",&edges);
    while(edges!=0)
    {
        e.clear();
        for(i=1; i<=edges; i++)
        {
            scanf("%lld %lld",&a,&b);
            e[a].push_back(b);
            e[b].push_back(a);
        }
        scanf("%lld %lld",&start,&ttl);
        while(start!=0 || ttl!=0)
        {
            level.clear();
            ll ans=BFS(start);
            ans=e.size()-ans; ///total node minus reachable.
            printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n",cas,ans,start,ttl);
            scanf("%lld %lld",&start,&ttl);
            cas++;
        }
        scanf("%lld",&edges);
    }
    return 0;
}

