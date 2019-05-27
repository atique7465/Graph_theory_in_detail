/// Time complexity O(V+E) when implemented using the adjacency list.
/// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/
/// http://www.shafaetsplanet.com/?p=973
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll MX = 1000000;
bool visited[MX];
vector <ll> adj[MX];
ll i,j,nodes,edges,x,y;

void DFS(ll root)
{
    visited[root]=true;
    for(int j=0; j<adj[root].size(); j++)
    {
        if(visited[adj[root][j]]==false)
        {
            DFS(adj[root][j]);
            printf("%lld ",adj[root][j]);
        }
    }
}

int main()
{
    scanf("%lld %lld",&nodes,&edges);
    for(i = 0; i < edges; i++)
    {
        scanf("%lld %lld",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll connected_components=0;
    for(i=1; i<=nodes; i++)
    {
        if(visited[i]==false)
        {
            DFS(i);
            connected_components++;
            printf("%lld ",i);
            printf("\n");
        }
    }
    printf("Number of connected components: %lld\n",connected_components);
    return 0;
}

/*
input 01:
5 5
1 2
1 5
2 4
2 3
5 4
output:
5 4 3 2 1
Number of connected components: 1

input 02:
6
4
1 2
2 3
1 3
4 5
output:
3 2 1
5 4
6
Number of connected components: 3
*/
