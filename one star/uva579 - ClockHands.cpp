#include <iostream>
using namespace std;
//時針 (360/12)/60 = 0.5度(每分鐘)
//分針 (360/60) = 6 度每分鐘  
int main(){
	double H,M,ans;  
	char c;
	while(cin>>H>>c>>M && (H || M)){
		H = H*5*6 + M*0.5;
		M = M*6;
		
		if(H>M) ans = H - M;
		else ans = M - H;
		
		if(ans>=180) ans=360-ans;
		
		printf("%.3f\n",ans);
	}
	return 0;
}
