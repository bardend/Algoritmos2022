#include <bits/stdc++.h>
#define pb push_back 

using namespace std;
vector<int>a,b;
vector<int>c;
int main() {
	a.pb(1);
	a.pb(1);
	b.pb(2);
	b.pb(2);
	for(auto ele:a)
		c.pb(ele);
	for(auto ele:b)
		c.pb(ele);
	for(auto ele:c)
			cout<<ele<<endl;
}
