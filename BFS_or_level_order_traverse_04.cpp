///Applications
///1. How to determine the level of each node in the given tree?
///the level of a node indicates the shortest path from source to the node.
///nodes and edges are integer.
///The time complexity of BFS is O(V + E), where V is the number of nodes and E is the number of edges.
/*
input:
8 10
0 1
0 2
0 3
0 4
1 5
2 5
3 6
4 6
5 7
6 7
output:
Node 0 at level 0
Node 1 at level 1
Node 2 at level 1
Node 3 at level 1
Node 4 at level 1
Node 5 at level 2
Node 6 at level 2
Node 7 at level 3
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i,n,e,j;
ll a,b;
vector<vector<ll> >edges; ///map for edges.
vector< ll >visited; /// either we can use an array.
ll level[1000];

void BFS_travers(ll root) /// just travers the graph and print the nodes in order of level.
{
    memset(level,-1,sizeof(level)); /// set all nodes level as -1.
    queue<ll>q;
    q.push(root);
    level[root]=0;   ///set root node level as zero.
    while(!q.empty())
    {
        ll r=q.front();
        cout<<"Node "<<r<<" at level "<<level[r]<<endl;
        for(j=0; j<edges[r].size(); j++)
        {
            if(level[edges[r][j]]==-1)
            {
                q.push(edges[r][j]);
                level[edges[r][j]]=level[r]+1; /// mark as visited.
            }
        }
        q.pop();
    }
}

int main()
{
    scanf("%lld %lld",&n,&e);  /// enter number of nodes.
    visited.assign(n, 0);      /// assigning vector size to n and value as 0.
    edges.assign(n, vector<ll>() ); /// assigning vector size to n and value as another vector.

    /// enter number of edges.
    for(i=1; i<=e; i++)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    BFS_travers(0); /// bfs by setting first node as root.
    return 0;
}

