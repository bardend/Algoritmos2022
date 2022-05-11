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
const int N =100+5;
const int R = 3;
const int inf =1e9+7;
int a[N];
int dp[N][R];
//0 any 
//1 progra
//2 gym
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(dp,inf,sizeof(dp));
	
	for(int i=0;i<R;i++)
		dp[0][i] = 0 ;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
	
		}
		else if(a[i]==2){
			dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
	
		}
		else if(a[i]==3){
			dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
			dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
	
		}
		dp[i][0] = min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
	
	}
	int ans = inf;
	for(int i=0;i<R;i++)
		ans = min(ans,dp[n][i]);
	cout<<ans<<endl;
}
