#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
//#define dbg(x) do {} while (false)
//#define raya do {cerr << "===========================" << endl; } while (false)
#define raya do {} while (false)
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll 
#define max_bit(A) 31-__builtin_clz(A)
typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;
typedef vector<ii> vii;
const int N =2e5+5;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		string cad;cin>>cad;
		int n = (int)cad.size();
		if(n==1){
			cout<<"Bob "<<cad[0]-'a'+1<<endl;
			continue;
		}
		
		int sum = 0;
		for(auto ele:cad){
			int val = ele-'a'+1;
			sum+=val;
		}
		if(!(n%2)){
			cout<<"Alice "<<sum<<endl;
		}
		else {
			int op1 = cad[0]-'a'+1;
			int op2 = cad[n-1]-'a'+1;
			cout<<"Alice "<<sum-2*min(op1,op2)<<endl;
		}
	}
}
