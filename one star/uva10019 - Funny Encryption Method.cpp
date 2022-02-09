#include <iostream>
using namespace std;

int N,M,b1,b2;
int pow2[14];
int main(){
	pow2[0]=1;
	for(int i=1;i<14;++i){
		pow2[i]=pow2[i-1]*2;
	}
//	cout<<pow2[13];//8192
	cin>>N;
	while(N--){
		cin>>M;
		//copy M
		int M2=M;
		//init
		b1=b2=0;
		
		for(int i=13;i>=0;--i){
			if(M-pow2[i]>=0){
				b1++;
				M-=pow2[i];
			}
		}
		
		while(M2){
			//get the digit
			int m=M2%10;
			M2/=10;
			//分別轉成二進位 
			for(int i=13;i>=0;--i){
				if(m-pow2[i]>=0){
					b2++;
					m-=pow2[i];
				}
			}
		}
		
		printf("%d %d\n",b1,b2);
	}
	return 0;
} 

//受到上一題費氏數列的影響，所以寫成這種解法 
//也可以使用%2判斷是否為1，再/2的方法 
