/// this is another classical MST problem.
/// just calculate the euclidean distance between all possible city pairs.
/// and than kruskal or prims. i used kruskal here.
/// if distance<=r , it should be road
/// else its a rail way and state should increase by one  :XD
#include<bits/stdc++.h>
#define ll long long int
#define rep0(i,k) for(i=0; i<(int)k; i++)
#define rep1(i,k) for(i=1; i<=(int)k; i++)
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
int i,j,t,state;
double road,train;
double a,b;
int parent[1010];
int sz[1010];
struct edge
{
    int u,v;
    double w;
    bool operator<(const edge& p)const
    {
        return w<p.w;
    }

};

int find_root(int v)
{
    if(v==parent[v])
        return v;
    else
        return parent[v]=find_root(parent[v]);
}

void union_by_size(int p, int q)
{
    int pr=find_root(p);
    int qr=find_root(q);
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

void kruskal(vector<edge>e,int n, int r)
{
    state=1;
    road=train=0.0;
    for(i=0; i<=n+1; i++)
    {
        parent[i]=i;
        sz[i]=1;
    }
    sort(e.begin(),e.end());
    for(i=0; i<e.size(); i++)
    {
        int pr=find_root(e[i].u);
        int qr=find_root(e[i].v);
        if(pr!=qr)
        {
            if(e[i].w<=r)
                road+=e[i].w;
            else
            {
                state++;
                train+=e[i].w;
            }
            union_by_size(pr,qr);
        }
    }
    road=round(road);
    train=round(train);
}

int main()
{
    scanf("%d",&t);
    int cas=1;
    while(cas<=t)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        map<int,pdd>nodes;
        vector<edge>e;
        rep1(i,n)
        {
            scanf("%lf %lf",&a,&b);
            nodes[i]=make_pair(a,b);
        }
        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                double dis;
                dis=((nodes[j].first-nodes[i].first)*(nodes[j].first-nodes[i].first))+((nodes[j].second-nodes[i].second)*(nodes[j].second-nodes[i].second));
                dis=sqrt(dis);
                edge get;
                get.u=i;
                get.v=j;
                get.w=dis;
                e.pb(get);
            }
        }
        kruskal(e,n,r);
        printf("Case #%d: %d %.lf %.lf\n",cas,state,road,train);
        cas++;
    }
    return 0;
}

