/// this is another straight forward classical MST problem.
/// i used kruskal here. :XD
#include<bits/stdc++.h>
#define ll long long int
#define pb(x) push_back(x)
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define mp make_pair
#define uu first
#define vv second
#define read(f) freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdin)
using namespace std;
ll i,j,a,b,weight,m;
ll parent[10010];
ll sz[10010];
struct edge
{
    ll u,v,w;
    bool operator<(const edge& p)const
    {
        return w<p.w;
    }
};

ll find_root(ll v)
{
    if(v==parent[v])
        return v;
    else
        return parent[v]=find_root(parent[v]);
}

void union_by_size(ll p, ll q)
{
    ll pr=find_root(p);
    ll qr=find_root(q);
    if(pr!=qr)
    {
        if(sz[pr]<sz[qr])
        {
            parent[pr]=parent[qr];
            sz[qr]+=sz[pr];
        }
        else
        {
            parent[qr]=parent[pr];
            sz[pr]+=sz[qr];
        }
    }
}

ll kruskal(vector<edge>e,ll n)
{
    for(i=0; i<=n+1; i++)
    {
        parent[i]=i;
        sz[i]=1;
    }
    ll min_cost=0;
    sort(e.begin(),e.end());
    for(i=0; i<e.size(); i++)
    {
        ll pr=find_root(e[i].u);
        ll qr=find_root(e[i].v);
        if(pr!=qr)
        {
            min_cost+=e[i].w;
            union_by_size(pr,qr);
        }
    }
    return min_cost;
}

int main()
{
    ll n,r;
    scanf("%lld %lld",&n,&m);
    vector<edge>e;
    for(i=1; i<=m; i++)
    {
        scanf("%lld %lld %lld",&a,&b,&weight);
            edge get;
            get.u=a;
            get.v=b;
            get.w=weight;
            e.pb(get);
    }
    printf("%lld",kruskal(e,n));
    return 0;
}

