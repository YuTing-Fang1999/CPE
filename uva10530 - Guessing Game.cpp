#include <iostream>
#include <string>
using namespace std;

int main(){
	int N,L=1,H=10;
	string str;
	while(cin>>N && N){
		getchar();//del '\n'
		getline(cin,str);
		if(str=="too high" && N<=H){//注意N要比目前的更低才要更新
			H=N-1;
		}
		else if(str=="too low" && N>=L){
			L=N+1;
		}
		else if(str=="right on"){
			if(L<=N && N<=H) cout<<"Stan may be honest"<<endl;
			else cout<<"Stan is dishonest"<<endl;
			L=1,H=10;
		}
	}
	return 0;
}
