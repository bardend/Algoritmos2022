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
const int N =50005;
int p[N],k[N],w[N];

struct lab{
	int p,w,ind;
};

vector<lab>v;
bool cmp1(const lab &l1,const lab &l2){
	return l1.p*l2.w<l2.p*l1.w;
}

struct classes{
	ll s,w,x;
	vi ind;
};
bool cmp2(const classes &c1,const classes &c2){
	return c1.s*c2.w<c2.s*c1.w;
}
	
vector<classes>a;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ifstream in;
    ofstream out;

    in.open("student.in");
    out.open("student.out");	
    int n;
	in>>n;
	int  T = 0;
	for(int i=0;i<n;i++) in>>k[i] , T+=k[i];
	for(int i=0;i<T;i++) in>>p[i];
	for(int i=0;i<T;i++) in>>w[i];
	v.resize(T);	
	for(int i=0;i<T;i++)
		v[i].p = p[i] , v[i].w = w[i] ,v[i].ind = i;
	
	int init = 0;
	for(int i=0;i<n;i++){
		sort(v.begin()+init,v.begin()+k[i]+init,cmp1);
		init+=k[i];
	}

	a.resize(n);
	init = 0;
	for(int i=0;i<n;i++){
		ll S,W,X;
		S = W = X = 0LL;
		vi help;
		for(int j=init;j<init+k[i];j++){
			S+=v[j].p , W+=v[j].w;
			X+=S*v[j].w;
			help.pb(v[j].ind);
		}
		a[i].s = S ,a[i].w = W, a[i].x = X ;
		a[i].ind = help;
		init+=k[i];
	}
	sort(all(a),cmp2);
	ll pres[N];
	pres[0] = a[0].s;
	
	for(int i=1;i<n;i++)
		pres[i] = pres[i-1] + a[i].s;
	
	ll ans = a[0].x;
	for(int i=1;i<n;i++)
		ans += (a[i].x+pres[i-1]*a[i].w);
	out<<ans<<endl;
	
	for(int i=0;i<n;i++){
		for(auto ele:a[i].ind)
			out<<ele+1<<" ";
	}
}
