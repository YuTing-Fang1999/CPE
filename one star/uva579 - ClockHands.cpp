#include <iostream>
using namespace std;
//�ɰw (360/12)/60 = 0.5��(�C����)
//���w (360/60) = 6 �רC����  
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
