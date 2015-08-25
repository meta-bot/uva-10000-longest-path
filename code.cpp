//user : AnAnDo
//from : university of dhaka 20th batch


//headers start here

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include <climits>
using namespace std;

//headers end


//short cuts from here

#define si(x)               scanf("%d",&x)
#define sd(x)               scanf("%lf",&x)
#define sI(x)               scanf("%lld",&x)
#define sii(x,y)            scanf("%d %d",&x,&y)
#define sdd(x,y)            scanf("%lf %lf",&x,&y)
#define sII(x,y)            scanf("%lld %lld",&x,&y)
#define sddd(x,y,z)         scanf("%lf %lf %lf",&x,&y,&z)
#define sIII(x,y,z)         scanf("%lld %lld %lld",&x,&y,&z)
#define siii(x,y,z)         scanf("%d %d %d",&x,&y,&z)
#define su(x)               scanf("%u",&x)
#define suI(x)              scanf("%llu",&x)
#define suu(x,y)            scanf("%u %u",&x,&y)
#define suuu(x,y,z)         scanf("%u %u %u",&x,&y,&z)
#define MAX                 1<<29
#define MIN                 -MAX
#define READ                freopen("in.txt","r",stdin)
#define WRITE               freopen("out.txt","w",stdout)
#define pf                  printf
#define deb_s               puts("debug start")
#define deb_in(x)           printf("number here for debug %d",x)
#define mem(x,y)            memset(x,y,sizeof(x))
#define dp_mem(x)           memset(x,-1,sizeof(x))
#define ff                  first
#define ss                  second
#define pb                  push_back
#define max3(a,b,c)         max(a,max(b,c))
#define min3(a,b,c)         min(a,min(b,c))


typedef long long int ll;
typedef long long unsigned int lu;

#define pi                  pair<int ,int >
#define MP(x,y)             make_pair(x,y)

//inline void inp(int &a){register int c;a = 0;do c = getchar_unlocked(); while(c < '0');do{a = (a << 1) + (a << 3) + c - '0';c = getchar_unlocked();}while(c >= '0');}
//inline void print(int a){char s[11];int t = -1;do{s[++t] = a % 10 + '0';a /= 10;}while(a > 0);while(t >= 0)putchar_unlocked(s[t--]);putchar_unlocked('\n');}

int dp[105],child[105],n;
vector < int > vec[105];
int longest(int node)
{
    if(dp[node]!=-1)return dp[node];
    if(vec[node].size()==0)
    {
        child[node]=node;
    }
    int mx = 0;
    for(int i=0;i<vec[node].size();i++)
    {
        int a = longest(vec[node][i]);
        if(mx<a)
        {
            mx=a;
            child[node] = child[vec[node][i]];
        }
        else if(mx==a)
            child[node]=child[node]==-1?child[vec[node][i]]:min(child[node],child[vec[node][i]]);
    }
    return dp[node] = mx+1;
}
int main()
{
    
    int cas=0;
    while(si(n)==1)
    {
        if(n==0)return 0;
                int start; si(start);
        int u,v;
        dp_mem(dp);
        dp_mem(child);
        while(sii(u,v))
        {
            if(u==0 or v == 0)break;
            vec[u].pb(v);
        }
        int a = longest(start) - 1;
        pf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++cas,start,a,child[start]);
        for(int i=1;i<=n;i++)vec[i].clear();
    }
    return 0;
}
