#include <bits/stdc++.h>

using namespace std;


class Solution{
	public:
		long long matrixMultiplication(int N,int arr[]){
			const long long inf = 1e9+7;
			vector<pair<int,int>>v;
			for(int i=0;i<(N-1);i++)
				v.push_back({arr[i],arr[i+1]});
					
			int len = (int)v.size();
			long long dp[len][len];
			
			memset(dp,inf,sizeof(dp));
			for(int i=0;i<len;i++)dp[i][i]= 0;
			for(int num=2;num<=len;num++){
				
				for(int i=0;i<=len-num;i++){
					
					int end = i+num-1;
					
					for(int cut = i;cut<end;cut++){
						long long aux = dp[i][cut]+dp[cut+1][end]+(1LL*v[i].first*v[cut].second*v[end].second);
						if(aux<dp[i][end]){
							dp[i][end] = aux ;
							
						}
					}
					
				}
			}	
		
			return dp[0][len-1];
		}
};
	
		
		
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; t = 1;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)cin>>arr[i];
		Solution ob;
		cout<<ob.matrixMultiplication(n,arr)<<endl;
		
	}
}
