/// this is another classical MST problem.
/// just calculate the euclidean distance between all possible pickle pairs.
/// and than kruskal or prims. i used kruskal here.  :XD
#include<bits/stdc++.h>
#define ll long long int
#define rep0(i,n) for(i=0; i<(ll)n; i++)
#define rep1(i,n) for(i=1; i<=(ll)n; i++)
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
struct edge
{
    int u,v;
    double w;
    bool operator<(const edge& p)const
    {
        return w<p.w;
    }
};
int i,j,t;
double a,b;
int parent[150];
int sz[150];
map<int,pdd>nodes;

int find_root(int z)
{
    if(z==parent[z])
        return z;
    else
        return parent[z]=find_root(parent[z]);
}

void union_by_size(int r,int s)
{
    int root_r=find_root(r);
    int root_s=find_root(s);
    if(root_r!=root_s)
    {
        if(sz[root_r]<sz[root_s])
        {
            parent[root_r]=parent[root_s];
            sz[root_s]+=sz[root_r];
        }
        else
        {
            parent[root_s]=parent[root_r];
            sz[root_r]+=sz[root_s];
        }
    }
}

double kruskal(vector<edge>e,int n)
{
    for(i=0; i<=n+5; i++)
    {
        parent[i]=i;
        sz[i]=1;
    }
    double min_cost=0;
    sort(e.begin(),e.end());
    for(i=0; i<e.size(); i++)
    {
        int ur=find_root(e[i].u);
        int vr=find_root(e[i].v);
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
    bool nw=false;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%lf %lf",&a,&b);
            nodes[i]=make_pair(a,b);
        }
        vector<edge>e;
        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                double dis;
                dis=((nodes[j].first-nodes[i].first)*(nodes[j].first-nodes[i].first))+((nodes[j].second-nodes[i].second)*(nodes[j].second-nodes[i].second));
                dis=sqrt(dis);
                edge get;
                get.u=i;
                get.v
                =j;
                get.w=dis;
                e.pb(get);
            }
        }
        if(nw)
            printf("\n");
        nw=true;
        printf("%.2lf\n",kruskal(e,n));
        nodes.clear();
    }
    return 0;
}

