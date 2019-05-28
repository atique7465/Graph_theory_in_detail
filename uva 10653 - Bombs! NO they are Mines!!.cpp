/// its a bfs problem in 2d grid.
///calculate the level of grids can be visit.
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
typedef pair<ll,ll>pii;
ll i,j,row,column,r,c,br,hm,p,sx,sy,ex,ey;
ll bomb_cel[1005][1005]; ///is their a bomb or not.
ll level[1005][1005]; /// distance measure.

void BFS()
{
    ll dx[] = {1,-1,0,0}; ///direction array for x coordinate.
    ll dy[] = {0,0,1,-1}; ///direction array for y coordinate.
    level[sx][sy]=0;
    queue<pii>q;
    q.push(make_pair(sx,sy));
    while(!q.empty())
    {
        pii root=q.front();
        q.pop();
        for(i=0; i<4; i++) ///checking the 4 direction coordinate as neighbor.
        {
            ll tx=root.first+dx[i];
            ll ty=root.second+dy[i];
            if((tx>=0 && tx<row) && (ty>=0 && ty<column) && bomb_cel[tx][ty]==0 && level[tx][ty]==-1)
            {
                    q.push(make_pair(tx,ty));
                    level[tx][ty]=level[root.first][root.second]+1;
            }
        }
    }
}

int main()
{
    while(scanf("%lld %lld",&row,&column))
    {
        if(row==0 && column==0)
            break;
        memset(bomb_cel,0,sizeof(bomb_cel));
        memset(level,-1,sizeof(level));
        scanf("%lld",&br);
        while(br--)
        {
            scanf("%lld %lld",&r,&hm);
            while(hm--)
            {
                scanf("%lld",&p);
                bomb_cel[r][p]=-1;
            }
        }
        scanf("%lld %lld %lld %lld",&sx,&sy,&ex,&ey);
        BFS();
        printf("%lld\n",level[ex][ey]);
    }
    return 0;
}

