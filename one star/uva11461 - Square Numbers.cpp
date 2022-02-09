#include <iostream>
#include <cmath>
using namespace std;

double a,b;
int main(){
	while(cin>>a>>b && a && b){
		int cnt=0;
		//注意要使用0.5而不要用1/2 
		int n1=pow(a,0.5);
		int n2=pow(b,0.5);
		if(n1*n1<a) ++n1;
		cout<<n2-n1+1<<endl;
	}
	return 0;
} 
