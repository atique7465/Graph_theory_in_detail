#include<bits/stdc++.h>
#include<fstream>
#define ll long long int
#define rep0(i,n) for(i=0; i<(ll)n; i++)
#define rep1(i,n) for(i=1; i<=(ll)n; i++)
#define pb(x) push_back(x)
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define ff first
#define ss second
#define mp make_pair
#define mx 100000
#define pi 3.1415926535897932384626433832795
using namespace std;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
ll i,j;

int countWords(string str) 
{ 
                          // breaking input into word using string stream 
    stringstream s(str); // Used for breaking words 
    string word;          // to store individual words 
  
    int count = 0; 
    while (s >> word) 
        count++; 
    return count; 
} 
  

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //ifstream fin("in.txt");
    //ofstream fout("out.txt");
    
    string word;
    getline(cin,word);
    
    return 0;
}
