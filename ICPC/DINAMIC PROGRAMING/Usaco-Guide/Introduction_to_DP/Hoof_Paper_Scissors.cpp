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

const int N = 100005;
const int K = 22;
const int C = 3;
int dp[N][K][C] ;
int v[N];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ifstream in;
    ofstream out;

    in.open("hps.in");
    out.open("hps.out");	
	int n,k;
	in>>n>>k;
	for(int i=1;i<=n;i++){
		char ch;in>>ch;
		if(ch =='P')v[i] = 0;
		else if(ch=='S') v[i] = 1;
		else v[i] = 2;
	}
		
	dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 0;
	for(int i=1;i<=n;i++){
		
		for(int j=0;j<=min(i,k);j++){
			
			for(int col=0;col<C;col++){
				if(j==0){
					dp[i][j][col] = dp[i-1][j][col]; 		
				}
				else {
					int op1,op2,op3;
					if(col==0){
						 op1 = dp[i-1][j][col];
						 op2 = dp[i-1][j-1][1]; 
						 op3 = dp[i-1][j-1][2]; 
					}
					else if(col==1){
						 op1 = dp[i-1][j][col];
						 op2 = dp[i-1][j-1][0]; 
						 op3 = dp[i-1][j-1][2]; 
					}
					else{
						 op1 = dp[i-1][j][col];
						 op2 = dp[i-1][j-1][0]; 
						 op3 = dp[i-1][j-1][1]; 
					
					}
					dp[i][j][col] = max(op1,max(op2,op3));
				}
				if(col==0 && v[i]==2) dp[i][j][col]++;
				else if(col==1 && v[i]==0) dp[i][j][col]++;
				else if(col==2 && v[i]==1) dp[i][j][col]++;
			}
		}
	}
	int ans = 0;
	for(int col=0;col<C;col++)
		ans = max(ans,dp[n][min(k,n)][col]);
	out<<ans;	
}
