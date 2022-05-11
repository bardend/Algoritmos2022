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

const ll inf = 1e18;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	vi t(n+1) , y(n+1);
	for(int i=1;i<=n;i++)
			cin>>t[i]>>y[i];
	t[0] = 1 , y[0] = 0;
	
	ll ans = -inf;
	ll sum = 0;
	priority_queue<int>q;
	for(int i=n;i>=0;i--){
		if(t[i]==1){
			ans = max(ans ,sum+y[i]);
			k--;
			if(k<0)break;
		}
		else {
			if(y[i]>=0)sum+=y[i];
			else q.push(y[i]);
		}
		if((int)q.size()>k){
			sum+=q.top();
			q.pop();
		}
	}
	cout<<ans<<endl;
}
