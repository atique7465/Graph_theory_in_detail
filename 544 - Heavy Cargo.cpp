/// this is an modified djkstrs.
/// always track the biggest weight in a priority queue
/// and result will be the minimum of them.
/// there may be multiple level 1 connection between two different cities.
/// and there is a blank line between two output.  :XD
#include<bits/stdc++.h>
#define ll long long int
#define rep0(i,n) for(i=0; i<(ll)n; i++)
#define rep1(i,n) for(i=1; i<=(ll)n; i++)
#define pb(x) push_back(x)
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<ll,ll>
#define pls pair<ll,string>
#define mp make_pair
#define uu first
#define vv second
#define read(f) freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdin)
using namespace std;
ll i,j,n,r,w;
string a,b;

ll find_weight(map<string,vector<pls> >g,string x, string y)
{
    map<string,ll>mx_weight;
    map<string,ll>level;
    priority_queue<pls>pq;
    pq.push(mp(0,x));
    mx_weight[x]=99999999;
    level[x]=0;
    while(!pq.empty())
    {
        pls r=pq.top();
        pq.pop();
        string s=r.second;
        if(s==y)
            return mx_weight[s];
        rep0(i,g[s].size())
        {
            if(mx_weight.count(g[s][i].second))
            {
                if(mx_weight[g[s][i].second]<min(mx_weight[s],g[s][i].first))
                {
                    mx_weight[g[s][i].second]=min(mx_weight[s],g[s][i].first);
                    pq.push(g[s][i]);
                }
            }
            else
            {
                mx_weight[g[s][i].second]=min(mx_weight[s],g[s][i].first);
                pq.push(g[s][i]);
            }
        }
    }
}

int main()
{
    ll cas=1;
    scanf("%lld %lld",&n,&r);
    while(n!=0 || r!=0)
    {
        map<string,vector<pls> >g;
        while(r--)
        {
            cin>>a>>b;
            scanf("%lld",&w);
            g[a].pb(mp(w,b));
            g[b].pb(mp(w,a));
        }

        string x,y;
        cin>>x>>y;
        printf("Scenario #%lld\n%lld tons\n",cas,find_weight(g,x,y));
        cas++;
        printf("\n");
        scanf("%lld %lld",&n,&r);
    }
    return 0;
}
