#include <iostream>
#include <cmath> 
using namespace std;
//�p�G��2��ƴN�a�|�@���(0~9)������ p  
//�p�Gp����b�A�ۥ[����k���ܴN�ŦX 
int sum(int p, int num){
	return (p/num) + (p%num); 
}

int N;
int main(){
	while(cin>>N){
		int num = pow(10.0, N/2);
		
		for(int k=0;k<num;++k){
			int p = pow(k, 2);
			if(sum(p, num) == k){
				cout.fill('0');//�]�m��R�r��
				cout.width(N);//�]�m��e 
				cout<<p<<endl;
			}
				
		}
	}
	
	return 0;
}
