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

const int R = 27;
int cnt[R],want[R];


bool cicle(string cd,int pos){
	int ret = 1;
	int len = pos+1;
	for(int i=pos+1;i<(int)cd.size();i++)
		if(cd[i]!=cd[i-len]) ret = 0;
	
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		string cd;
		cin>>cd;
		int n = (int)cd.size();
		for(int i=0;i<R;i++)cnt[i]=want[i]=0;
		for(auto ele:cd)want[ele-'a'] = 1;
		for(int i=0;i<n;i++){
			int val = cd[i]-'a';
			cnt[val]++;
			if(cnt[val]==2){
				cout<<"NO\n";
				break;
			}
			bool flag = 1;
			for(int j=0;j<R;j++){
				if(cnt[j]!=want[j]) flag = 0;
			}
			if(flag){
				if(cicle(cd,i))
					cout<<"YES\n";
				else cout<<"NO\n";
				break;
			}
		}
	}

}
