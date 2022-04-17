#include <iostream>
#include <cmath> 
using namespace std;
//狦2计碞絘羭计(0~9)キよ p  
//狦pだㄢ单k杠碞才 
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
				cout.fill('0');//砞竚恶才
				cout.width(N);//砞竚办糴 
				cout<<p<<endl;
			}
				
		}
	}
	
	return 0;
}
