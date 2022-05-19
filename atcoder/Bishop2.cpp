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
int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,1,-1};
const int N =1500+5;
const int R =4;
const int inf = 1e9+7;
int x_0,y_0,x_1,y_1,n;
char s[N][N];	
int dp[N][N];

bool valid(int x,int y){
	return x>=0 && x<n && y>=0 && y<n && s[x][y]=='.';
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>x_0>>y_0>>x_1>>y_1;
	x_0--;x_1--;y_0--;y_1--;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>s[i][j];	
	
	queue<pair<int,int>>q;
	
	q.push({x_0,y_0});
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) dp[i][j] = inf;
		
	dp[x_0][y_0] = 0;
	while(!q.empty()){
		auto node = q.front();
		q.pop();
		int aux = dp[node.first][node.second];
		for(int i=0;i<R;i++){
			
			for(int d=1;d<=n;d++){
				int x,y;
				x = node.first+d*dx[i] , y = node.second+d*dy[i];
				if(!valid(x,y))break;
				if(aux+1>dp[x][y])break;
				dp[x][y] = min(dp[x][y],aux+1);
				q.push({x,y});
			}
		}
	}
	if(dp[x_1][y_1]==inf)cout<<"-1\n";
	else cout<<dp[x_1][y_1]<<endl;	
}
