#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
//#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
#define dbg(x) do {} while (false)
//#define raya do {cerr << "===========================" << endl; } while (false)
#define raya do {} while (false)
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll 
#define max_bit(A) 31-__builtin_clz(A)
typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;
typedef vector<ii> vii;
const int N =2000+5;
const int R = 2;
const int mod = 998244353;
vi adj[N];
int dp[N][N][R];

int sum(int x,int y ){
	return (x+y)%mod;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k,s,t,x;
	cin>>n>>m>>k>>s>>t>>x;
	s--;t--;x--;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(dp,0,sizeof(dp));
	dp[s][0][0] = 1;
	for(int lon = 0;lon<=k;lon++){
		
		for(int v=0;v<n;v++){
			if(dp[v][lon][0]!=0){
				for(auto ele:adj[v]){
					if(ele==x) dp[ele][lon+1][1]+=dp[v][lon][0] ,dp[ele][lon+1][1]%=mod;
					else 	dp[ele][lon+1][0] +=dp[v][lon][0] , dp[ele][lon+1][0]%=mod;
				}
			}
			if(dp[v][lon][1]!=0){
				for(auto ele:adj[v]){
					if(ele==x) dp[ele][lon+1][0]+=dp[v][lon][1], dp[ele][lon+1][0]%=mod;
					else 	dp[ele][lon+1][1] +=dp[v][lon][1] , dp[ele][lon+1][1]%=mod;					
				}
			}
		}
	}
	cout<<dp[t][k][0]<<endl;
}
