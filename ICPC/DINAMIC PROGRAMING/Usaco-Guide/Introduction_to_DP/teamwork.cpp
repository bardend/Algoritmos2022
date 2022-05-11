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

const int N = 1e4+5;
const int K = 1e3+5;
const int inf = 1e9+7;

int  dp[N][K] , a[N],good[N],mx[N];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ifstream in;
    ofstream out;

    in.open("teamwork.in");
    out.open("teamwork.out");
	int n,k;
	in>>n>>k;
	for(int i=1;i<=n;i++)in>>a[i];
	for(int i=1;i<=n;i++)mx[i] = a[i];
	memset(dp,-inf,sizeof(dp));
	memset(good,-inf,sizeof(good));
	good[0] = 0;
	for(int i=1;i<=n;i++){
		for(int fol=1;fol<=min(i,k);fol++){
			mx[i] = max(mx[i],a[i-fol+1]);
			dp[i][fol] = max(dp[i][fol],good[i-fol]+fol*(mx[i]));
			good[i] = max(good[i],dp[i][fol]);
		}
	}
	out<<good[n]<<endl;
}
