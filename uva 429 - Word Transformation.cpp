///another BFS problem.
///if two word similar in length and differ by one letter just connect them.
///and BFS on the graph to calculate the levels.  :XD
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
map<string,vector<string> >g;
string a,b;
map<string,ll>level;

ll BFS(string x, string y)
{
    queue<string>q;
    q.push(x);
    level[x]=0;
    while(!q.empty())
    {
        string r=q.front();
        q.pop();
        if(r==y)
            return level[r];
        ll sz=g[r].size();
        for(i=0; i<sz; i++)
        {
            if(!level.count(g[r][i]))
            {
                level[g[r][i]]=level[r]+1;
                q.push(g[r][i]);
                if(g[r][i]==y)
                    return level[g[r][i]];
            }
        }
    }
}

int main()
{
    scanf("%lld",&n);
    while(n--)
    {
        g.clear();
        cin>>a;
        while(a!="*")
        {
            g[a];
            map<string,vector<string> >::const_iterator itr;
            for(itr=g.begin(); itr!=g.end(); itr++)
            {
                b=(*itr).first;
                ll dif=0;
                if(a.size()==b.size())
                {
                    for(i=0; i<b.size() && dif<2; i++ )
                    {
                        if(b[i]!=a[i])
                            dif++;
                    }
                    if(dif==1)
                    {
                        g[a].pb(b);
                        g[b].pb(a);
                    }
                }
            }
            cin>>a;
        }
        string line;
        ///we need to ignore first enter. and than take next line as input.
        getline(cin,line); /// or cin.ignore();
        while(getline(cin,line) && line!="")
        {
            stringstream ss(line);
            string x,y;
            ss>>x>>y;
            level.clear();
            printf("%s %s %lld\n",x.c_str(),y.c_str(),BFS(x,y));
        }
        if(n!=0)
            printf("\n");
    }
    return 0;
}

