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

class Solution{
	public:
		int editDistance(string s,string t){
			int l1 = (int)s.size();
			int l2 = (int)t.size();
			int dp[l1+1][l2+1];
			
			for(int i=0;i<=l1;i++) dp[i][0] = i;
			for(int i=0;i<=l2;i++) dp[0][i] = i;
			for(int i=1;i<=l1;i++){
				
				for(int j=1;j<=l2;j++){
					
					if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] ;
					else{
						int op1 = dp[i-1][j-1] + 1;
						int op2 = dp[i-1][j] + 1;
						int op3 = dp[i][j-1] + 1;
						dp[i][j] = min(op1,min(op2,op3));
					}
				}
			}
			return dp[l1][l2];
		}
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		string s,t;
		cin>>s>>t;
		Solution ob;
		cout<<ob.editDistance(s,t)<<endl;
	}
	return 0;
}
