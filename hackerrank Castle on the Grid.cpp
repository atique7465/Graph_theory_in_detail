#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;

int ans;

void BFS(int n,string s[110], int sx, int sy, int ex, int ey)
{
    int level[n+1][n+1];
    memset(level,-1,sizeof(level));
    level[sx][sy]=0;
    queue<pii>q;
    q.push(mp(sx,sy));
    pii r;
    while(!q.empty())
    {
        r=q.front();
        q.pop();
        int i=r.first+1,j=r.second;
        while(i<n && s[i][j]!='X')
        {
            if(level[i][j]==-1)
            {
                q.push(mp(i,j));
                level[i][j]=level[r.first][r.second]+1;
                if(i==ex && j==ey)
                {
                    ans=level[i][j];
                    return;
                }
            }
            i++;
        }
        i=r.first-1,j=r.second;
        while(i>=0 && s[i][j]!='X')
        {
            if(level[i][j]==-1)
            {
                q.push(mp(i,j));
                level[i][j]=level[r.first][r.second]+1;
                if(i==ex && j==ey)
                {
                    ans=level[i][j];
                    return;
                }
            }
            i--;
        }
        i=r.first,j=r.second+1;
        while(j<n && s[i][j]!='X')
        {
            if(level[i][j]==-1)
            {
                q.push(mp(i,j));
                level[i][j]=level[r.first][r.second]+1;
                if(i==ex && j==ey)
                {
                    ans=level[i][j];
                    return;
                }
            }
            j++;
        }
        i=r.first,j=r.second-1;
        while(j>=0 && s[i][j]!='X')
        {
            if(level[i][j]==-1)
            {
                q.push(mp(i,j));
                level[i][j]=level[r.first][r.second]+1;
                if(i==ex && j==ey)
                {
                    ans=level[i][j];
                    return;
                }
            }
            j--;
        }
    }
}

int main()
{
    int n,i,sx,sy,ex,ey;
    scanf("%d",&n);
    string s[110];
    for(i=0; i<n; i++)
        cin>>s[i];
    scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
    BFS(n,s,sx,sy,ex,ey);
    printf("%d",ans);
    return 0;
}

