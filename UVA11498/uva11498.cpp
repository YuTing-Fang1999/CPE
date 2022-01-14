#include <iostream>
using namespace std;

int N;
int px,py;
int x,y;

int main(){
	while(cin>>N &&N){
		cin>>px>>py;
		while(N--){
			cin>>x>>y;
			if(x==px || y==py) cout<<"divisa";
			else if(x>px){
				if(y>py) cout<<"NE";
				else cout<<"SE";
			}
			else{
				if(y>py) cout<<"NO";
				else cout<<"SO";
			}
			cout<<endl;
		}
	
	}
	return 0;
}
