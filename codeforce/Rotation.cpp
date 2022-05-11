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
int a[N],b[N],fb[N],fa[N],cnt[N];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;		
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)cin>>b[i];
		for(int i=1;i<=n;i++) cnt[i] = 0;
		a[n] = b[n] = 0;
		for(int i=n-1;i>=0;i--){
			if(a[i] == a[i+1])
				fa[i] = fa[i+1]+1;
			else fa[i] = 1;
			if(b[i] ==b[i+1])
				fb[i] = fb[i+1]+1;
			else fb[i] = 1;
		}
		int i,j,add,jump;
		i = j = 0 ;
		while(i<n && j<n ){
			if(a[i]==b[j]){
				if(fa[i]>=fb[j]){
					add = fb[j];
					i+=add , j+=add;
				}
				else {
					add = fa[i];
					i+=add , j+=add;
					jump = min(fb[j],cnt[b[j]]);
					cnt[b[j]]-=jump; j+=jump;
				}
			}
			else{
				cnt[a[i]]++;
				i++;
			}
		}
		bool yea = 1; 
		for(i=1;i<=n;i++) if(cnt[i]) yea = 0;
		if(yea && i>=n && j>=n)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
