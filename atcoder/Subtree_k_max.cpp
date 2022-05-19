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
const int N =1e5+5;
int x[N];
vector<vi>maxi;
vi adj[N];
void dfs(int v,int pa =-1){
	vi ret(20,0);
	vi here;
	for(auto to:adj[v]){
		if(to==pa)continue;
		dfs(to,v);
		for(auto ele:maxi[to])
			ret.pb(ele);
	}
	ret.pb(x[v]);
	sort(rall(ret));
	for(int i=0;i<20;i++)
		here.pb(ret[i]);
	maxi[v] =here;
}
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>x[i];
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	maxi.resize(n,vector<int>(20,0));
	dfs(0);
	while(q--){
		int v, k;
		cin>>v>>k;;
		v--;k--;
		cout<<maxi[v][k]<<endl;
		
	}
	return 0;
}
