///nodes and edges are string. worst one. next implementation is better.
///The time complexity of BFS is O(V + E), where V is the number of nodes and E is the number of edges.
/*
input:
5
a b c d e
7
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
map<string,ll>m;
string nd[100]; /// strings of nodes.
vector<ll>v[100]; /// vector for edges as nodes indexes.
ll visited[100]; /// for indicating a node visited or not.

void BFS_travers(string root) /// just travers the graph and print the nodes in order of level.
{
    queue<string>q;
    q.push(root);
    visited[m[root]]=1;  ///set root node visited;
    while(!q.empty())
    {
        string r=q.front();
        cout<<r<<" ";
        i=m[r];
        for(j=0; j<v[i].size(); j++)
        {
            if(visited[v[i][j]]==0)
            {
                q.push(nd[v[i][j]]);
                visited[v[i][j]]=1;
            }
        }
        q.pop();
    }
}

int main()
{
    scanf("%lld",&n);  /// enter number of nodes.
    for(i=0; i<n; i++) /// storing nodes as integer index.
    {
        cin>>nd[i];
        m[nd[i]]=i;
    }

    scanf("%lld",&e); /// enter number of edges.
    for(i=1; i<=e; i++)
    {
        cin>>a>>b;
        v[m[a]].push_back(m[b]);
        v[m[b]].push_back(m[a]);
    }

    BFS_travers(nd[0]); /// bfs by setting first node as root.

    return 0;
}
