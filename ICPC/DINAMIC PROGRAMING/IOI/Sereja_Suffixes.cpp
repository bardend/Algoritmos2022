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
const int N =1e5+5;
int frec[N],a[N],dp[N];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	dp[n] = 0;
	for(int i=n-1;i>=0;i--){
		if(frec[a[i]]==0)
			dp[i] =  dp[i+1] + 1;
		else dp[i]  = dp[i+1];
		frec[a[i]] = 1;
	}
	while(m--){
		int x;cin>>x;x--;
		cout<<dp[x]<<"\n";
	}
	
}
