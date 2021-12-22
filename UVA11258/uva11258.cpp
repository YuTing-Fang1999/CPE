#include <iostream>
#include <string>
using namespace std;

string str;
long long int dp[205];

long long int find_max(int i){
	if(dp[i]!=-1) return dp[i];
	
	long long int nowMax=0,sum=0;
	for(int j=i;j<str.size();++j){
		sum = sum*10 + (str[j] - '0');
		if(sum>INT_MAX) break;
		nowMax = max(nowMax, sum+find_max(j+1));
	}
	dp[i] = nowMax;
	return dp[i];
}
void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>str;
	cout<<find_max(0)<<endl;
}
int main(){
	int n; cin>>n;
	while(n--){
		solve();
	}
	return 0;
}
