#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i,j,nodes,edges,a,b,weight;
const ll mx=1000005;
struct edge
{
    ll w,v;
    bool operator<(const edge& p)const
    {
        return w>p.w;
    }
};
vector<edge>e[mx];
ll distence[mx];

ll dijkstrs(ll root)
{
    memset(distence,63,sizeof(distence));
    priority_queue<edge>pq;
    edge get;
    get.v=root;
    get.w=0;
    pq.push(get);
    edge r;
    distence[root]=0;
    ll min_dis=0;
    while(!pq.empty())
    {
        r=pq.top();
        pq.pop();
        ll s=r.v;
        for(i=0; i<e[s].size(); i++)
        {
            ll k=e[s][i].v;
            if(distence[k]>distence[s]+e[s][i].w)
            {
                distence[k]=distence[s]+e[s][i].w;
                min_dis+=e[s][i].w;
                pq.push(e[s][i]);
            }
        }
    }
    return min_dis;
}

int main()
{
    scanf("%lld %lld",&nodes,&edges);
    for(i=1; i<=edges; i++)
    {
        scanf("%lld %lld %lld",&a,&b,&weight);
        edge get;
        get.v=b;
        get.w=weight;
        e[a].push_back(get);
        get.v=a;
        get.w=weight;
        e[b].push_back(get);
    }
    cout<<dijkstrs(1)<<endl;
    return 0;
}
/*
input:
8 11
1 5 2
1 2 4
1 4 10
5 4 5
2 4 8
2 3 18
4 3 11
4 7 11
4 8 9
7 6 1
8 6 2
