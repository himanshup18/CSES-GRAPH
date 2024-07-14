#include <bits/stdc++.h>
#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long 
#define pb push_back
#define umap unordered_map
#define mii map<int, int>
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vpii vector<pii>
#define mp make_pair
#define ff first
#define ss second
#define loop(i,x,y) for(int i=x; i<y; i++)
#define lloop(i,x,y) for(int i=x; i>=y; i--)
#define srt(x) sort((x).begin(), (x).end())
#define rsrt(x) sort((x).rbegin(), (x).rend())
#define setbits(x) __builtin_popcountll(x)
#define lzeroes(x)  __builtin_clzll(x)
#define tzeroes(x)  __builtin_ctzll(x)
#define yn(f) f?cout<<"YES\n":cout<<"NO\n"
#define syn(f) f?cout<<"Yes\n":cout<<"No\n"
 
int M=1000000007;
//int M=998244353;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //sorted set with extra functions
// initialize-> pbds name
// can change int to any other datatype, can change less to greater for descending order 
// find_by_order ->gives iterator of the element at given index, order_of_key ->gives no. of elements less than given value
 
int bpow(int x,int n){  //binary exponentiation only for integers
  if(n==0){
     return 1;
  }
  return x*bpow(x,n-1);
}
 
int bpowm(int x,int n,int m){   //binary exponentiation with mod m
  if(n==0){
    return  1;
  }
   if(n%2==0)
  {
    return bpowm(((x%m)*(x%m))%m,n/2,m);
  }
  return ((x%m)*bpowm(((x%m)*(x%m))%m,n/2,m))%m;
}
 
/* 
 
sieve code -->
 
vector<int> isprime(1e6+1,1);
void sieve(int n){isprime[1]=0;for(int i=2;i*i<1000001;i++)
if(isprime[i]!=0)for(int j=i*i;j<1000001;j+=i)isprime[j]=0;}
 
*/
 
// n & (1ll << i) -> ith bit is on or off
// n |= (1LL<<i) -> ith bit on
//  n & ( n ^ ( 1LL << i ) ) -> turn off
 
//priority_queue <int, vector<int>, greater<int>> pq;  --> min heap that means
//smallest element at the top
 
//pi=3.14159265358979323846264338327950288419716939937510582097494   upto 60 decimal places
 
int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b,a%b);
}
 
int lcm(int a, int b){
    int ans=(a/gcd(a,b))*b;
    return ans;
}
 
bool cmp(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}
bool powerof2(int n) {
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}
 
bool prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return 0;
    }   
    return 1;
} 
 
/*-------------------------------------------------------------------------------------------------------------------------------------*/
 
 
int32_t main(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> vec(n+1);
	vector<vector<pair<int,int>>> vec2(n+1);
	vector<pair<pair<int,int> ,int>> e;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		e.pb({{a,b},c});
		vec[a].pb({b,c});
		vec2[b].pb({a,c});
	}
	vector<int> dist(n+1,1e18);
	vector<int> vis(n+1,0);
	dist[1]=0;
	priority_queue<pii, vector<pii> ,greater<pii> > pq;
	pq.push({dist[1],1});
	while(!pq.empty()){
		int u=pq.top().second;
		int x=pq.top().first;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto it : vec[u]){
			int v = it.first;
			int w = it.second;
			if(x+w<dist[v] && !vis[v]){
				dist[v]=x+w;
				pq.push({dist[v],v});
			}
		}
	}
	
	vector<int> dist2(n+1,1e18);
	vector<int> vis2(n+1,0);
	dist2[n]=0;
	priority_queue<pii, vector<pii> ,greater<pii> > pq2;
	pq2.push({dist2[n],n});
	while(!pq2.empty()){
		int u=pq2.top().second;
		int x=pq2.top().first;
		pq2.pop();
		if(vis2[u])continue;
		vis2[u]=1;
		for(auto it : vec2[u]){
			int v = it.first;
			int w = it.second;
			if(x+w<dist2[v] && !vis2[v]){
				dist2[v]=x+w;
				pq2.push({dist2[v],v});
			}
		}
	}
	int ans=1e18;
	for(auto it : e){
		ans=min(ans,dist[it.ff.ff]+ dist2[it.ff.ss] + it.ss/2); 
	}
	cout<<ans<<endl;
	
	
}
 