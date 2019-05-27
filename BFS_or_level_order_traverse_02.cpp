///nodes and edges are string. better implementation than first one.
///The time complexity of BFS is O(V + E), where V is the number of nodes and E is the number of edges.
/*
input:
5 7
a b c d e
a b
a e
a c
b c
b d
d c
e c
output:
a b e c d
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i,n,e,j;
string s,a,b;
map<string,ll>nodes;///first one is strings of nodes. second for indicating a node visited or not.
map< string,vector<string> >edges; ///map for edges.

void BFS_travers(string root) /// just travers the graph and print the nodes in order of level.
{
    queue<string>q;
    q.push(root);
    nodes[root]=1;  ///set root node visited;
    while(!q.empty())
    {
        string r=q.front();
        cout<<r<<" ";
        for(j=0; j<edges[r].size(); j++)
        {
            if(nodes[edges[r][j]]==0)
            {
                q.push(edges[r][j]);
                nodes[edges[r][j]]=1; /// mark as visited.
            }
        }
        q.pop();
    }
}

int main()
{
    scanf("%lld %lld",&n,&e);  /// enter number of nodes.
    for(i=0; i<n; i++) /// storing nodes as integer index.
    {
        cin>>s;
        nodes[s]=0;
    }

    /// enter number of edges.
    for(i=1; i<=e; i++)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    BFS_travers("a"); /// bfs by setting first node as root.

    return 0;
}
