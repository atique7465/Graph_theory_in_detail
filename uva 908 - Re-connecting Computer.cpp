/// its an straight forward MST problem.
/// just run MST on T+K edges. no need to bother about m's.
/// i used kruskal here. prims also be used.
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
ll i,j,a,b,w;
struct edge
{
    ll u,v,w;
    bool operator<(const edge& p)const
    {
        return w<p.w;
    }
};

ll parent[1000050];
ll sz[1000050];

ll find_root(ll v)
{
    if(parent[v]==v)
        return v;
    else
        return parent[v]=find_root(parent[v]);
}

void union_by_size(ll u,ll v)
{
    ll root_u=find_root(u);
    ll root_v=find_root(v);
    if(root_u!=root_v)
    {
        if(sz[root_u]<sz[root_v])
        {
            parent[root_u]=parent[root_v];
            sz[root_v]+=sz[root_u];
        }
        else
        {
            parent[root_v]=parent[root_u];
            sz[root_u]+=sz[root_v];
        }
    }
}

ll kruskal(vector<edge>e,ll n)
{
    rep0(i,n+1)  /// initialize parent and size.
    {
        parent[i]=i;
        sz[i]=1;
    }
    ll min_cost=0;
    sort(e.begin(),e.end());
    rep0(i,e.size())
    {
        ll ur=find_root(e[i].u);
        ll vr=find_root(e[i].v);
        if(ur!=vr)
        {
            min_cost+=e[i].w;
            union_by_size(ur,vr);
        }
    }
    return min_cost;
}

int main()
{
    ll n,m,k;
    bool nw=false;
    while(scanf("%lld",&n)!=EOF)
    {
        ll x=0,y;
        vector<edge>e;
        ll t=n-1;
        while(t--)
        {
            scanf("%lld %lld %lld",&a,&b,&w);
            edge get;
            get.u=a;
            get.v=b;
            get.w=w;
            x+=w;
            e.push_back(get);
        }
        scanf("%lld",&k);
        n=n+k;
        while(k--)
        {
            scanf("%lld %lld %lld",&a,&b,&w);
            edge get;
            get.u=a;
            get.v=b;
            get.w=w;
            e.push_back(get);
        }
        scanf("%lld",&m);
        while(m--)
        {
            scanf("%lld %lld %lld",&a,&b,&w);
        }
        if(nw)
            printf("\n");
        nw=true;
        printf("%lld\n%lld\n",x,kruskal(e,n));
    }
    return 0;
}

