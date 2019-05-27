///Time Complexity of Dijkstra's Algorithm is O(v^2)
///but with min-priority queue it drops down to O(V+E log V).
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
                pq.push(e[s][i]);
            }
        }
    }
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
        dijkstrs(1);
    cout<<"Dijkstrs found min cost for nodes:"<<endl;
    ll min_dist=0;
    for(i=1; i<=nodes; i++)
    {
        cout<<"node "<<i<<" : "<<distence[i]<<endl;
        min_dist+=distence[i]; ///minimum dist from node 1 to every ith node.
    }
    cout<<"Summation of minimum costs "<<min_dist<<endl;
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
Output:
Dijkstrs found min cost for nodes:
node 1 : 0
node 2 : 4
node 3 : 18
node 4 : 7
node 5 : 2
node 6 : 18
node 7 : 18
node 8 : 16
Summation of minimum costs 83
*/
