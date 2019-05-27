///https://codeforces.com/blog/entry/5048
///https://cp-algorithms.com/graph/bipartite-check.html
///Solved using DFS. Can be solved by using BFS also.
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i,j,t,nodes,edges,a,b;
ll bipertite=true;
ll visited[210];
ll color[210];

void IsBipertite(vector<ll>e[210],ll root, ll c)
{
    visited[root]=1;
    color[root]=c;
    for(i=0; i<e[root].size(); i++)
    {
        if(color[e[root][i]]==c)
        {
            bipertite=false;
            return;
        }
        if(!visited[e[root][i]])
                IsBipertite(e,e[root][i],c==1?0:1);
    }
}

int main()
{
    scanf("%lld",&nodes);
    while(nodes!=0)
    {
        memset(visited,0,sizeof(visited));
        memset(color,0,sizeof(color));
        ll d=0,root;
        scanf("%lld",&edges);
        vector<ll>e[210];
        for(i=1; i<=edges; i++)
        {
            scanf("%lld %lld",&a,&b);
            e[a].push_back(b);
            e[b].push_back(a);
            if(d==0)
            {
                d=1;
                root=a;
            }
        }
        bipertite=true;
        IsBipertite(e,root,0);
        if(bipertite)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
        scanf("%lld",&nodes);
    }
    return 0;
}
