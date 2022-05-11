#include <bits/stdc++.h>
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
//#define dbg(x) do {} while (false)
#define raya do {cerr << "===========================" << endl; } while (false)
//#define raya do {} while (false)

using namespace std;


class Solution{
	public:
	int longestSubsequence(int n,int a[]){
		
		int dp[n];
		for(int i=0;i<n;i++)dp[i] = 1;
		
		int ret = 1;
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				
				if(a[i]>a[j]){
					dp[i] = max(dp[i],dp[j]+1);
			
					ret =  max(dp[i],ret);
				}
			}
		}
		return ret;
		
	}
};


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,t;t=1;
	while(t--){
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
	Solution ob;
	cout<<ob.longestSubsequence(n,a)<<endl;
	}
}
