///another BFS problem.
#include<bits/stdc++.h>
#define ll long long int
#define rep0(i,n) for(i=0; i<(ll)n; i++)
#define rep1(i,n) for(i=1; i<=(ll)n; i++)
#define pb(x) push_back(x)
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<ll,ll>
#define mp make_pair
#define uu first
#define vv second
#define read(f) freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdin)
using namespace std;
ll i,j,n;
map<string,vector<string> >e;
map<string,string>parent;
map<string,bool>visited;

bool BFS(string x,string y)
{
    queue<string>q;
    q.push(x);
    visited[x]=true;
    while(!q.empty())
    {
        string r=q.front();
        if(r==y)
            return true;
        q.pop();
        ll sz=e[r].size();
        for(i=0; i<sz; i++)
        {
            if(!visited.count(e[r][i]))
            {
                visited[e[r][i]]=1;
                q.push(e[r][i]);
                parent[e[r][i]]=r;
                if(e[r][i]==y)
                    return true;
            }
        }
    }
    return false;
}

void path(string f,string x)
{
    if(f==x)
        return;
    path(parent[f],x);
    printf("%s %s\n",parent[f].c_str(),f.c_str());
}

int main()
{
    bool nw=false;
    while(scanf("%lld",&n)!=EOF)
    {
        string a,b,x,y;
        while(n--)
        {
            cin>>a>>b;
            e[a].pb(b);
            e[b].pb(a);
        }
        cin>>x>>y;
        if(nw)
            printf("\n");
        nw=true;
        if(BFS(x,y))
        {
            path(y,x);
        }
        else
        {
            printf("No route\n");
        }
        e.clear();
        parent.clear();
        visited.clear();
    }
    return 0;
}

