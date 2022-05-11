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
const int inf =1e9+7;
const int N =405;
int s[N],a[N];
int dp[N][N] , val[N][N] , frec[N][N];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ifstream in;
    ofstream out;

    in.open("snakes.in");
    out.open("snakes.out");

	int n,k;
	in>>n>>k;
	k++;
	for(int i=1;i<=n;i++)in>>a[i];
	s[0] = 0;
	for(int i=1;i<=n;i++)s[i] = s[i-1]+a[i];
	memset(dp,inf,sizeof(dp));
	val[0][0] = frec[0][0] = dp[0][1] = 0;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
	
		for(int g=1;g<=min(i,k);g++){
		
			dp[i][g] = dp[i-1][g-1];
			frec[i][g] = 1 , val[i][g] = a[i];
			int vl , nm ;
			vl = val[i-1][g]  , nm = frec[i-1][g]; 
			if(a[i]<=vl){
				if(dp[i-1][g]+(vl-a[i])<dp[i][g]){
					dp[i][g] = dp[i-1][g]+(vl-a[i]);
					frec[i][g] = nm+1;
					val[i][g] = vl;
				}
			}	
			else {
				nm +=1;
				if(dp[i-nm][g-1]+(a[i]*nm-(s[i]-s[i-nm]))<dp[i][g]){
					dp[i][g] = dp[i-nm][g-1]+(a[i]*nm-(s[i]-s[i-nm]));
					frec[i][g] =nm;
					val[i][g] = a[i];
				}
			}
				
		}
	}
	int ans = inf;
	for(int g=1;g<=k;g++) ans = min(dp[n][g],ans);
	cout<<ans<<endl;
}
