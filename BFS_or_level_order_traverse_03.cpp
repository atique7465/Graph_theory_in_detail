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
0 1 2 3 4 5 6 7
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i,n,e,j;
ll a,b;
vector<vector<ll> >edges; ///map for edges.
vector< ll >visited; /// either we can use an array.

void BFS_travers(ll root) /// just travers the graph and print the nodes in order of level.
{
    queue<ll>q;
    q.push(root);
    visited[root]=1;  ///set root node visited;
    while(!q.empty())
    {
        ll r=q.front();
        cout<<r<<" ";
        for(j=0; j<edges[r].size(); j++)
        {
            if(visited[edges[r][j]]==0)
            {
                q.push(edges[r][j]);
                visited[edges[r][j]]=1; /// mark as visited.
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

