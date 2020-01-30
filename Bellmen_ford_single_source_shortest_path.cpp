/// resource 01: https://www.youtube.com/watch?v=FtN3BYH2Zes&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=53
/// resource 02: http://www.shafaetsplanet.com/planetcoding/?p=2044#bellman
/// time complexity O( v*e ) or O( n^2 ).
/// same work may be done by dijkstra but dijkstra dont work on negative edge and negative weighted cycle.
/// Bellmen ford can handle negative edge but cant work with negative weighted cycle.
/// can be used to detect negative cycle in graph

#include<bits/stdc++.h>
using namespace std;
int v,e,x,y,z,source,inf = 999999,ck = 0,dest;
int dist[101],previous[101];

struct edge
{
    int u,v,w;
    edge(int a=0, int b=0, int c=0)
    {
        u=a;
        v=b;
        w=c;
    }
};

void initialize()
{
    for(int i=0; i<=v; i++)
    {
        dist[i]=inf;
        previous[i]=inf;
    }
}

void Bellmen_Ford(edge E[])
{
    dist[source] = 0;
    for(int i=1; i<=v-1; i++)
        for(int j=1; j<=e; j++)
            if( dist[E[j].u] + E[j].w < dist[E[j].v])
            {
                dist[E[j].v] = dist[E[j].u] + E[j].w;
                previous[E[j].v] = E[j].u;
            }

    /// relax once again to detect negative weighted cycle
    for(int j=1; j<=e; j++)
        if( dist[E[j].u] + E[j].w < dist[E[j].v])
        {
            cout<<"Negative Weighted Cycle Detected!"<<endl;
            ck = 1;
        }
}

void find_path(int j)
{
    if(j==source)
    {
        cout<<j<<" ";
        return;
    }
    find_path(previous[j]);
    cout<<j<<" ";
}

int main()
{
    cout<<"Number of nodes : ";
    cin>>v;
    cout<<"Number of edges : ";
    cin>>e;
    edge E[e+1];
    cout<<"Enter the edges with source destination and weight :"<<endl;
    for(int i=1; i<=e; i++)
    {
        cin>>x>>y>>z;
        edge ob(x,y,z);
        E[i] = ob;
    }
    cout<<"Source : " ;
    cin>>source;
    initialize();
    Bellmen_Ford(E);

    if(ck==0)
    {
        cout<<"Shortest Distances from "<<source<<" to every node are : "<<endl;
        for(int i = 1; i<=v; i++)
            cout<<"Node "<<i<<" Distance : "<<dist[i]<<endl;

        while(1)
        {
            cout<<"Shortest Path from "<<source<<" to : ";
            cin>>dest;
            find_path(dest);
            cout<<endl;
        }
    }
    return 0;
}

/*
INPUT 01: negative edges but no negative weighted cycle
Number of nodes : 7
Number of edges : 10
Enter the edges with source destination and weight :
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3
Source : 1
OUTPUT:
Shortest Distances from 1 to every node are :
Node 1 Distance : 0
Node 2 Distance : 1
Node 3 Distance : 3
Node 4 Distance : 5
Node 5 Distance : 0
Node 6 Distance : 4
Node 7 Distance : 3
Shortest Path from 1 to : 7
1 4 3 2 5 7
Shortest Path from 1 to : 5
1 4 3 2 5
Shortest Path from 1 to : 2
1 4 3 2
Shortest Path from 1 to : 3
1 4 3
Shortest Path from 1 to :

INPUT 02: negative edges and negative weighted cycle
Number of nodes : 4
Number of edges : 5
Enter the edges with source destination and weight :
1 2 4
1 4 5
2 4 5
3 2 -10
4 3 3
Source : 1
OUTPUT:
Negative Weighted Cycle Detected!
*/

