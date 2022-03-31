#include <iostream>
using namespace std;

int T,A,F;
int main(){
	cin>>T;
	while(T--){
		cin>>A>>F;
		while(F--){
			for(int i=1; i<=A;++i){
				for(int j=1;j<=i;++j){
					cout<<i;
				}
				cout<<endl;
			}
			for(int i=A-1; i>=1;--i){
				for(int j=1;j<=i;++j){
					cout<<i;
				}
				cout<<endl;
			}
			if(F>=1) cout<<endl;
		}
		if(T>=1) cout<<endl;
	}
	return 0;
}
