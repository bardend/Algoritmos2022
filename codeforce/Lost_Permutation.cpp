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
const int N =2e5+5;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi v(n),a(n);
		int j;
		for(int i=0;i<n;i++){
			cin>>v[i];
			if(v[i]==1) j = i;
		}
		if(count(all(v),1)!=1){
			cout<<"NO\n";
			continue;
		}
		
		for(int i=0;i<n;i++)
			a[i] = v[(i+j)%n];
		
		bool flag = 1;
		for(int i =1;i<n;i++)
			if(a[i]-a[i-1]>1)
				flag = 0;
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
