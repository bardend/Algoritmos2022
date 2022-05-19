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
const int N =4e5+5;

map<int,int> f;
void change(const vi &a,const vi &b){
	set<int>ret;
	for(auto ele:a)	ret.insert(ele);
	for(auto ele:b) ret.insert(ele);
	int i = 1;
	for(auto ele:ret){
		f[ele] = i;
		i++;
	}
}
int vis[N],lo[N],hi[N];
const int inf = -1;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vi a(n),b(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	change(a,b);
	for(int i=0;i<n;i++)a[i] = f[a[i]];
	for(int i=0;i<n;i++)b[i] = f[b[i]];
	
	
	set<int>st;
	int j = 0;
	memset(lo,N,sizeof(lo));
	memset(hi,-1,sizeof(hi));
	memset(vis,0 ,sizeof(vis));
	for(int i=0;i<n;i++){
		
		if(vis[a[i]])
			hi[i] =hi[i-1] , lo[i] = lo[i-1];
		
		else {
			st.insert(a[i]);
			bool good = 0;
			int pri = 1;
			while(j<n){
				if(!vis[b[j]]){
					if(st.count(b[j])){
						st.erase(b[j]);
						vis[b[j]] = 1;
						if((int)st.size()==0){
							good = 1;
							if(pri) lo[i] = j ,pri = 0;
						}
					}
					else break;
				}
				j++;
			}

			if(good)hi[i] = j-1;
		}
	}
	for(int i=0;i<n;i++){
		raya;
		dbg(lo[i]);
		dbg(hi[i]);
	}
	int q;cin>>q;
	while(q--){
		int x,y;cin>>x>>y;
		x--;y--;
		if(y<=hi[x] && y>=lo[x])cout<<"Yes\n";
		else cout<<"No\n";
	}
}
