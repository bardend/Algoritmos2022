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

struct obj{
	int w,h,type;
	};
bool cmp(const obj &t1,const obj &t2){
	if(t1.w==t2.w)
		return t1.type>t2.type;
	return t1.w>t2.w;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<obj>v;
	v.resize(n+m);
	for(int i=0;i<n;i++) cin>>v[i].h , v[i].type = 0;
	for(int i=0;i<n;i++) cin>>v[i].w;
	for(int i=n;i<(n+m);i++)cin>>v[i].h , v[i].type = 1;
	for(int i=n;i<(n+m);i++)cin>>v[i].w;
	sort(all(v),cmp);
	multiset<int>mst;
	bool ok = 0;
	for(int i=0;i<(n+m);i++){
		if(v[i].type){
			mst.insert(v[i].h);
		}
		else {
			auto itr = mst.lower_bound(v[i].h);
			if(itr ==mst.end()){
				ok = 1;
				break;
			}
			mst.erase(itr);
		}
	}
	if(ok)cout<<"No\n";
	else cout<<"Yes\n";
}	
