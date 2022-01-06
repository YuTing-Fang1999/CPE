#include <iostream>
using namespace std;

int T;
int e,f,c;

int main(){
	cin>>T;
	while(T--){
		cin>>e>>f>>c;
		int remain=e+f;
		int n1=remain/c;
		int n2=remain%c;
		
		int count=n1;
		while(n1+n2>=c){
			remain=n1+n2;
			n1=remain/c;
			n2=remain%c;
			count+=n1;
		}
		cout<<count<<endl;
	}
	return 0;
}
