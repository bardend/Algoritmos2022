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

const int N =2e5+5;
const int inf = 1e9+7;
int dp[N][2];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		vi a(n+1);
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n==1){
			cout<<a[1]<<endl;
			continue;
		}	
		dp[1][0] = inf ,dp[1][1] = a[1];
		dp[2][0] = dp[1][1] , dp[2][1] = dp[1][1]+a[2];
		for(int i=3;i<=n;i++){	
			dp[i][0] = min(dp[i-1][1],dp[i-2][1]);
			dp[i][1] = min(dp[i-2][0]+a[i-1]+a[i],dp[i-1][0]+a[i]);
		}
		cout<<min(dp[n][0],dp[n][1])<<endl;
	}
}
