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
	const int N =300+5;
	const ll inf =1e18+9;
	int ed[N][N],mid[N][N],arista[N][N];
	long long dp[N][N];

	void pat(int a,int b){
		if(mid[a][b]==-1 ){
			ed[a][b] = 1;
			ed[b][a] = 1;
			dbg(a);dbg(b);
			raya;

			return;
		}
		int x = mid[a][b];
		pat(a,x);
		pat(x,b);
	}					  
	int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int n,m;
		cin>>n>>m;
		
		memset(ed,-1,sizeof(ed));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dp[i][j] = inf ;
		
		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			a--;b--;
			dp[a][b] = dp[b][a] = c;
			ed[a][b] = ed[b][a] = 0;
			mid[a][b] = mid[b][a] = -1;
		}
		
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if (dp[i][k] < inf && dp[k][j] < inf){
						ll op = dp[i][k] + dp[k][j];
						if(op<dp[i][j]){
							dp[i][j] = op;
							mid[i][j] = k;
						}
					}
				}
			}
		}
		
		for(int i=0;i<n;i++){
			raya;
			for(int j=0;j<n;j++){
				if(i==j)continue;
	
	 			dbg(i);dbg(j);
				dbg(mid[i][j]);
				dbg(dp[i][j]);
	
				pat(i,j);
			}
		}
		
		int ans  =0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				if(ed[i][j]==0)ans++;
			}
		}
		cout<<ans/2<<endl;
	}
