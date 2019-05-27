///MST_prim's using priority queue.
///Time Complexity:
///The time complexity of the Prim’s Algorithm is O((V+E)logV)
///because each vertex is inserted in the priority queue only once
///and insertion in priority queue take logarithmic time.
#include<bits/stdc++.h>
#include <functional>
#define ll long long int
using namespace std;

ll nodes,edges,a,b,i,j,weight,minimum_cost;
const ll mx=1e5+5;
typedef pair<ll,ll>pii;
bool visited[mx];
vector<pii>adj_edges[mx];
vector<pii>mst;

ll prim(ll root)
{
    priority_queue< pii,vector<pii>,greater<pii> >pq; ///creating min heap.
    ll min_cost=0;                                    ///sorting descending order.
    pii r;
    ll x;
    pq.push((make_pair(0,root)));
    while(!pq.empty())
    {
        ///select the edge with minimum cost.
        r=pq.top();
        pq.pop();
        x=r.second;
        ///checking for cycle.
        if(visited[x]== true)
            continue;
        min_cost+=r.first;       /// for minimum cost.
        mst.push_back(make_pair(r.second,r.first)); /// for showing the MS tree.
        visited[x]=true;
        for(i=0; i<adj_edges[x].size(); i++)
        {
            ll y=adj_edges[x][i].second;
            if(visited[y]==false) /// if w,b is visited than w,a is also visited.
                pq.push(adj_edges[x][i]);
        }
    }
    return min_cost;
}

int main()
{
    scanf("%lld %lld",&nodes,&edges);
    /// taking input.
    for(i=1; i<=edges; i++)
    {
        scanf("%lld %lld %lld",&a,&b,&weight);
        adj_edges[a].push_back(make_pair(weight,b));
        adj_edges[b].push_back(make_pair(weight,a));
    }
    /// selecting 1 as the starting node.
    minimum_cost=prim(1);
    printf("Minimum cost is: %lld\n",minimum_cost);
    printf("Minimum Spanning Tree is:\n");
    for(i=0; i<mst.size(); i++)
    {
        printf("(%lld)%lld",mst[i].second,mst[i].first);
        if(i!=mst.size()-1)
            printf("->");
    }
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
output:
34
*/
