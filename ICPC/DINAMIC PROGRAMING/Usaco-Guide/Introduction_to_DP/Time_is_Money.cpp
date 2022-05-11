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

const int N =1005;
const int MAXT = 1005;
const int inf = 1e9+7;
int m[N],dp[N][MAXT];
vi adj[N];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	ifstream in;
	ofstream out;
	
	in.open("time.in");
    out.open("time.out");	
	
	int n,M,c;
	in>>n>>M>>c;
	for(int i=1;i<=n;i++) in>>m[i];
	for(int i=0;i<M;i++){
		int a,b;
		in>>a>>b;
		adj[a].pb(b);
	}
	memset(dp,-inf,sizeof(dp));
	dp[1][0] = 0; // node - time
	for(int time = 1;time<MAXT;time++){
		
		for(int last=1;last<=n;last++){
			if(dp[last][time-1]!=-inf){
				
				for(auto to:adj[last]){
					dp[to][time] = max(dp[to][time],dp[last][time-1]+m[to]-c*(2*time-1));
				}
			}

			
		}
	}
	int ans = 0;
	for(int i=0;i<MAXT;i++)
		ans = max(dp[1][i],ans);
	out<<ans<<endl;
}
