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
const int N =403;
const int R = 2;
int dp[N+R][N+R][N+R];//R B G

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	string s;
	cin>>n>>s;
	int r,b,g;
	r = b = g = 0;
	for(auto ele:s){
		if(ele=='R') r++;
		else if(ele=='B')b++;
		else g++;
	}
	dp[r][b][g] = 1;
	int ctn = r+b+g;
	int t=2;
	while(t--){
	for(int i=ctn;i>=0;i--){
		for(int j=ctn;j>=0;j--){
			for(int k=ctn;k>=0;k--){
				
				if(i>=1) dp[i][j][k] |= dp[i-1][j+1][k+1],dp[i][j][k] |= dp[i+1][j][k];
				if(j>=1) dp[i][j][k] |= dp[i+1][j-1][k+1],dp[i][j][k] |= dp[i][j+1][k];	
				if(k>=1) dp[i][j][k] |= dp[i+1][j+1][k-1],dp[i][j][k] |= dp[i][j][k+1];
				
				
		/*		raya;
				dbg(i);
				dbg(j);
				dbg(k);
				dbg(dp[i][j][k]);
		*/		
			}
		}
	}
	}
	if(dp[0][1][0])cout<<"B";
	if(dp[0][0][1])cout<<"G";
	if(dp[1][0][0])cout<<"R";
	cout<<endl;
}
