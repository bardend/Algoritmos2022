#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
//#define dbg(x) do {} while (false)
#define raya do {cerr << "===========================" << endl; } while (false)
//#define raya do {} while (false)
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll 
#define max_bit(A) 31-__builtin_clz(A)
typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;
typedef vector<ii> vii;
const int N =2e5+5;
int vis[N];
vi adj[N];
void dfs(int v){
	vis[v] = 1;
	for(auto to:adj[v]){
		if(!vis[to])
			dfs(to);
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b+1);
		adj[b+1].pb(a); 
	}
	dfs(1);
	if(vis[n+1])cout<<"Yes\n";
	else cout<<"No\n";
}
