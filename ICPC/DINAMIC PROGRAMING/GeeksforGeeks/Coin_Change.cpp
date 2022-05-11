#include <bits/stdc++.h>
using namespace std;


class Solution{
	public:
		long long count(int S[],int m,int n){
			long long dp[n+1];
			memset(dp,0,sizeof(dp));
			dp[0] = 1;
			
			for(int i=0;i<m;i++){
				
				for(int sum = 1;sum<=n;sum++){
					if(sum>=S[i]){
						dp[sum]+=dp[sum-S[i]];
					}
				}
			}
			return dp[n];
		}
	};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)cin>>arr[i];
		Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
}
