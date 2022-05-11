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
const int N = 105;
const int R = 12;
const int mod = 1e8;
int dp[N][N][2];
int sum(int x,int y){
	return (((x+y)%mod)+mod)%mod;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	
	dp[0][0][0] = dp[0][0][1] = 1;
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			
			for(int r1=1;r1<=min(i,k1);r1++){
				dp[i][j][0] = sum(dp[i][j][0],dp[i-r1][j][1]);
			}
			for(int r2=1;r2<=min(j,k2);r2++){
				dp[i][j][1] = sum(dp[i][j][1],dp[i][j-r2][0]);
			}
		}
	}
	int ans = 0;
	for(int i=0;i<2;i++) ans = sum(ans,dp[n1][n2][i]);
	cout<<ans<<endl;
	return 0;
}
