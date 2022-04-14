// 100 - The 3n + 1 problem

#include <stdio.h>
#include <iostream>
using namespace std;

int cycle_len(int n);
int max_cycle_len(int n1, int n2);

int main(){
	int n1,n2,max;
	while(cin >> n1){
		cin >> n2;
		if(n1<n2){
			max = max_cycle_len(n1, n2);
		}else{
			max = max_cycle_len(n2, n1);
		}
		
//		printf("%d \n",max);
		
		cout << n1 << " " << n2;
   		cout << " " << max << endl;
	}
	
	return 0;
}
int max_cycle_len(int n1, int n2){
	
	int max_len=0,new_len=0;
	for(int i=n1;i<=n2;++i){		
		new_len = cycle_len(i);
		if( new_len > max_len) max_len = new_len;
	}
	return max_len;
	
}

int cycle_len(int n){
	
	int count=1;
	while(n!=1){
		++count;
		if(n%2) n=3*n+1;
		else n=n/2;
	}
	
	return count;
	
}
