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
const int N =104;
const int R =1e6+5;
const int mod = 1e9+7;
int dp[R] , a[N];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	dp[0] = 1;
	for(int i=0;i<n;i++){
		
		for(int j=R-1;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			dp[j]%=mod;
		}
	}
	vi v;
	for(int i=1;i<R;i++)
		if(dp[i]) v.pb(i);
	cout<<(int)v.size()<<endl;
	for(auto ele:v)cout<<ele<<" ";
}
