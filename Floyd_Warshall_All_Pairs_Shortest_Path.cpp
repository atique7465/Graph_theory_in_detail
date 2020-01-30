/// resource 01: https://www.youtube.com/watch?v=oNI0rf2P9gE&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=49
/// resource 02: http://www.shafaetsplanet.com/?p=1927
/// resource 03: https://www.techiedelight.com/pairs-shortest-paths-floyd-warshall-algorithm/
/// Floyd–Warshall algorithm is an algorithm for finding shortest paths in a weighted graph
/// with positive or negative edge weights (but with no negative cycles).
/// Time Complexity O( v^3 );
/// also used for finding transitive closure of graph and detecting negative weight cycle of graph.

#include<bits./stdc++.h>
using namespace std;
int A[101][101],nxt[101][101],n,e,u,v,w,mx=9999,ck=0;

void Initialize()
{
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
        {
            if(i==j)
                A[i][j] = 0;
            else
                A[i][j] = mx;
            nxt[i][j]=j;
        }
}

void floyed_warshal()
{
    for(int k = 1; k<=n; k++)
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
                if(A[i][k] + A[k][j] < A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j] ;
                    nxt[i][j]=nxt[i][k]; /// for path.
                }
            if(A[i][i]<0)
            {
                cout<<"Negative Weight Cycle Found ! "<<endl;
                ck=1;
            }
        }
}

void find_path(int i, int j)
{
    while(i!=j)
    {
        cout<<i<<" ";
        i = nxt[i][j];
    }
    cout<<j<<endl;
}


int main()
{
    cout<<"Numbers of Nodes : ";
    cin>>n;
    Initialize();
    cout<<"Numbers of edges : ";
    cin>>e;
    while(e--)
    {
        cin>>u>>v>>w;
        A[u][v]=w;
    }

    floyed_warshal();

    cout<<"shortest path Matrix : "<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }

    if(ck==0)
    {
        while(1)
        {
            cout<<"Find shortest distance and path between two nodes : ";
            cin>>u>>v;
            cout<<"Shortest distance is : "<<A[u][v]<<endl;
            cout<<"Shortest path is :";
            find_path(u,v);
        }
    }
    return 0;
}

/*
INPUT: 01 with positive edges
4
7
1 2 3
1 4 7
2 1 8
2 3 2
3 1 5
3 4 1
4 1 2
OUTPUT:
shortest path Matrix :
0 3 5 6
5 0 2 3
3 6 0 1
2 5 7 0
Find shortest distance and path between two nodes : 1 4
Shortest distance is : 6
Shortest path is :1 2 3 4
Find shortest distance and path between two nodes : 1 3
Shortest distance is : 5
Shortest path is :1 2 3
Find shortest distance and path between two nodes : 3 1
Shortest distance is : 3
Shortest path is :3 4 1
Find shortest distance and path between two nodes :

INPUT: 02 with negative edges & weight cycle
4
7
1 2 3
1 4 -9
2 1 8
2 3 2
3 1 5
3 4 1
4 1 2
OUTPUT:
Negative Weight Cycle Found !
Negative Weight Cycle Found !
Negative Weight Cycle Found !
Negative Weight Cycle Found !
Negative Weight Cycle Found !
shortest path Matrix :
-7 -4 -2 -16
0 0 2 -9
-2 1 0 -11
-5 -2 0 -14

INPUT: 03 with negative edges & no negative weight cycle
4
5
1 3 -2
2 1 4
2 3 3
3 4 2
4 2 1
OUTPUT:
shortest path Matrix :
0 1 -2 0
4 0 2 4
7 3 0 2
5 1 3 0
Find shortest distance and path between two nodes : 1 2
Shortest distance is : 1
Shortest path is :1 3 4 2
Find shortest distance and path between two nodes : 1 3
Shortest distance is : -2
Shortest path is :1 3
Find shortest distance and path between two nodes : 1 4
Shortest distance is : 0
Shortest path is :1 3 4
Find shortest distance and path between two nodes : 2 1
Shortest distance is : 4
Shortest path is :2 1
Find shortest distance and path between two nodes : 2 3
Shortest distance is : 2
Shortest path is :2 1 3
Find shortest distance and path between two nodes : 2 4
Shortest distance is : 4
Shortest path is :2 1 3 4
Find shortest distance and path between two nodes :
*/
