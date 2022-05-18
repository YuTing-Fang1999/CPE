#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	while(cin>>n && n){
		printf("%d : ",n);
		int maxP = int(sqrt(n - 1e-9))+1;
		int count=0;
		for(int p=2;p<=maxP;++p){
			if(n%p==0){
				++count;
				while(n%p==0) n/=p;
			}
		}
		//璝n﹟ゼ跑1ボ﹟腹n借计ㄤ计盢借计计
		if(n!=1) ++count;
		printf("%d\n",count);
	}
}
