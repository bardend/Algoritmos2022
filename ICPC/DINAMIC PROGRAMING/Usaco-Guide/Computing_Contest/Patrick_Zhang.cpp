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

class Solution{
	public:
		long long Flower(int n,int m){
			const int N = 505;
			ll dp[N][2][N];
			memset(dp,0,sizeof(dp));
			dp[0][0][0] = dp[0][1][0] = 1;
			for(int i=1;i<=n;i++){
				raya;
				for(int col=0;col<2;col++){
					
					for(int ele =1;ele<=min(m,i);ele++){
						
						if(ele==1){
							ll aux = 0;
					 		for(int j = 0;j<=min(m,i-1);j++)
								aux += dp[i-1][col^1][j];
							dp[i][col][ele] = aux;	
						}
						else {
							dp[i][col][ele]+=dp[i-1][col][ele-1];
						}
						
			/*		dbg(i);
					dbg(col);
					dbg(ele);
					dbg(dp[i][col][ele]);
			*/
					}
				}
			}			
			long long ret = 0;
			for(int ele=1;ele<=m;ele++){
				ret += dp[n][0][ele];
				ret += dp[n][1][ele];
			}
			return ret;
		}
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	Solution Obj;
	cout<<Obj.Flower(n,m)<<endl;

}
