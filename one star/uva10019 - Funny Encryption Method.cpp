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
			//���O�ন�G�i�� 
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

//����W�@�D�O��ƦC���v�T�A�ҥH�g���o�ظѪk 
//�]�i�H�ϥ�%2�P�_�O�_��1�A�A/2����k 
