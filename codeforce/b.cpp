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
vi dep[N],adj[N];
int vis[N];

vector<vector<int>> ans;
vi walk;
void clear(int n){
	
	for(int i=0;i<=n;i++){
		dep[i].clear() , adj[i].clear();
		vis[i] = 0;
	}
	ans.clear();
}
void dfs1(int node,int h){
	dep[h].pb(node);
	for(auto to:adj[node])
		dfs1(to,h+1);	
}
void dfs2(int node){
	vis[node] = 1;
	walk.pb(node);
	for(auto to:adj[node]){
		if(!vis[to]){
			dfs2(to);
			break;
		}
	}
}	
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,root;
		cin>>n;
		clear(n);
		for(int i=1;i<=n;i++){
			int pi;cin>>pi;
			if(pi==i) root = i;
			else {
				adj[pi].pb(i); 
			}
		}
		dfs1(root,0);
		for(int h=0;h<n;h++){
	//		raya;
			for(auto ele:dep[h]){
		//		dbg(ele);
				if(!vis[ele]){
					walk.clear();
					dfs2(ele);
		//			for(auto tt:walk)cout<<tt<<" ";
					ans.pb(walk);
				}
			}
		}
		int len = (int)ans.size();
		cout<<len<<endl;
		for(int i=0;i<len;i++){
			int nn = (int)ans[i].size();
			cout<<nn<<endl;
			for(auto ele:ans[i])
				cout<<ele<<" ";
			cout<<endl;	
		}
		cout<<endl;
		
	}
}
