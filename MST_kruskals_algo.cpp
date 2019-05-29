///time complexity O(ElogE).
///most time consuming operation is sorting than we
///loop over edges.

///http://www.shafaetsplanet.com/?p=825
///https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i,j,n,nodes,edges,a,b,wt;
struct edge
{
    ll u,v,w;
    bool operator<(const edge& p) const
    {
        return w<p.w;
    }
};
vector<edge>e;
ll parent[100000];
ll sz[100000];

ll find_root(ll v)
{
    if(v==parent[v])
        return v;
    else
        return parent[v]=find_root(parent[v]);
}

void union_by_size(ll u,ll v)
{
    ll root_u=find_root(u);
    ll root_v=find_root(v);
    if(root_u!=root_v)
    {
        if(sz[root_u]<sz[root_v])
        {
            parent[root_u]=parent[root_v];
            sz[root_v]+=sz[root_u];
        }
        else
        {
            parent[root_v]=parent[root_u];
            sz[root_u]+=sz[root_v];
        }
    }
}

ll MST_kruskal(ll n)
{
    for(i=0; i<=n; i++) ///initialize paarent and size.
    {
        parent[i]=i;
        sz[i]=1;
    }
    ll min_cost=0;
    sort(e.begin(),e.end());
    //ll count=0;
    for(i=0; i<e.size(); i++)
    {
        ll ur=find_root(e[i].u);
        ll vr=find_root(e[i].v);
        if(ur!=vr)
        {
            min_cost+=e[i].w;
            union_by_size(ur,vr);
            //count++;
           // if(count==n-1)
           //     break;
        }
    }
    return min_cost;
}

int main()
{
    scanf("%lld %lld",&nodes,&edges);
    for(i=0; i<edges; i++)
    {
        scanf("%lld %lld %lld",&a,&b,&wt);
        edge newedge;
        newedge.u=a;
        newedge.v=b;
        newedge.w=wt;
        e.push_back(newedge);
    }
    printf("Minimun cost is: %lld\n",MST_kruskal(nodes));
    return 0;
}
/*
input:
7 11
1 3 5
1 2 7
2 3 9
2 5 7
2 6 8
3 5 15
3 4 6
4 5 8
4 7 11
5 7 9
5 6 5
output:
Minimun cost is: 39
*/

