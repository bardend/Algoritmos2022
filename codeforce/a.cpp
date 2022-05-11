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
const int R= 50;
int a[N];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		if(n==1){cout<<"0"<<endl;continue;}
		bool flag = 0;
		int ans = 0;
		for(int i=n-2;i>=0;i--){
			int cnt = 0;
			
			while(a[i]>=a[i+1] && cnt<R){
				a[i]/=2;
				cnt++;
				ans++;
			}
			if(cnt==R){
				flag = 1;
				break;
			}
	//		dbg(a[i]);
		}
		if(flag)cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
}
