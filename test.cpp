#include<bits/stdc++.h>
#define ll long long int
#define rep0(i,n) for(i=0; i<(ll)n; i++)
#define rep1(i,n) for(i=1; i<=(ll)n; i++)
#define pb(x) push_back(x)
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<ll,ll>
#define mp make_pair
#define uu.first
#define vv.second
#define read(f) freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdin)
using namespace std;
ll i,j;
int main()
{
    //mem(a,-1);
    ll a[10][10]={0};
    rep0(i,10)
    {
        rep0(j,10){
          printf("%lld ",a[i][i]);}
          printf("\n");
    }
    return 0;
}
