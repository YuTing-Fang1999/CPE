#include <iostream>
using namespace std;

int f(int num){
	if(num<10) return num;
	int num2=0;
	while(num){
		num2+=num%10;
		num/=10;
	}
	return f(num2);
}
int main(){
	int n;
	while(cin>>n && n!=0){
		cout<<f(n)<<endl;
	}
	return 0;
}
