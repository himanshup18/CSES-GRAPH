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
const int MAX=1e5+1;
int par[MAX];
int rnk[MAX];
void make_set(int n){
	for(int i=1;i<=n;i++){
		par[i]=i;
		rnk[i]=1;
	}
}
int find_set(int x){
	if(par[x]==x){
		return x;
	}
	par[x]=find_set(par[x]);
	return par[x];
}
int mx=1;
void merge(int a,int b){
	int p1=find_set(a);
	int p2=find_set(b);
	if(p1==p2){
		return;
	}
	if(rnk[p1]>rnk[p2]){
		par[p2]=p1;
		rnk[p1]=rnk[p2]+rnk[p1];
		mx=max(mx,rnk[p1]);
	}
	else{
		par[p1]=p2;
		rnk[p2]=rnk[p2]+rnk[p1];
		mx=max(mx,rnk[p2]);
	}
}
 
void Himanshu_Patel(){
	int n,m;
	cin>>n>>m;
	int cnt=0;
	int sum=0;
	vector<pair<int,pair<int,int>>> v;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({c,{a,b}});
	}
	srt(v);
	make_set(n+1);
	for(auto it:v){
		int w=it.first;
		int x=it.ss.ff;
		int y=it.ss.ss;
		if(find_set(x)==find_set(y)){
			continue;
		}
		merge(x,y);
		cnt++;
		sum+=w;
	}
	if(cnt==n-1){
		cout<<sum<<endl;
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
	
}
 
int32_t main(){
	int t=1;
	//cin>>t;
	while(t--){
		Himanshu_Patel();
	}
	return 0;
}
