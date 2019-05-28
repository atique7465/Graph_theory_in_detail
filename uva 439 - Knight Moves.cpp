/// its a BFS problem in [8*8] -2d chess board grid.
///calculate the level of squares can be visit.

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<ll,ll>pii;
ll i,j,sx,sy,ex,ey;
string a,b;
ll level[10][10]; /// distance measure.

void BFS()
{
    ///defining the moves of a knight in chess board.
    ll dx[] = {-2,-2,-1,1,-1,1,2,2}; ///direction array for x coordinate.
    ll dy[] = {1,-1,2,2,-2,-2,1,-1}; ///direction array for y coordinate.
    level[sx][sy]=0;
    queue<pii>q;
    q.push(make_pair(sx,sy));
    while(!q.empty())
    {
        pii root=q.front();
        q.pop();
        for(i=0; i<8; i++) ///checking the 4 direction coordinate as neighbor.
        {
            ll tx=root.first+dx[i];
            ll ty=root.second+dy[i];
            if((tx>0 && tx<=8) && (ty>0 && ty<=8) && level[tx][ty]==-1)
            {

                    q.push(make_pair(tx,ty));
                    level[tx][ty]=level[root.first][root.second]+1;
            }
        }
    }
}

int main()
{
    while(cin>>a>>b)
    {
        memset(level,-1,sizeof(level));
        sx=(a[0]-'a')+1;
        sy=(a[1]-'0');
        ex=(b[0]-'a')+1;
        ey=(b[1]-'0');
        BFS();
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<level[ex][ey]<<" knight moves."<<endl;
    }
    return 0;
}

