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

const int R = 19;
int cnt[R];
int main(){
	int t;
	cin>>t;
	while(t--){
		ll l,r;
		cin>>l>>r;
		vi a(r-l+1);
		for(int i=0;i<(r-l+1);i++)cin>>a[i];
		for(int bit=0;bit<R;bit++)cnt[bit] = 0;
		
		for(int i=l;i<=r;i++){
			for(int bit =0;bit<R;bit++){
				cnt[bit]+=((i>>bit)&1);	
			}
		}	
		
		
		int ans =0 ;
		for(int bit =0;bit<R;bit++){
			int fb = 0;
			for(int i=0;i<(r-l+1);i++){
				fb+=((a[i]>>bit)&1);
			}
			if(fb != cnt[bit])ans|=(1<<bit);
		}
		cout<<ans<<endl;
	}
	return 0;
}
