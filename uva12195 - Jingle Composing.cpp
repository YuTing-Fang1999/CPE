#include <iostream>
#include <map>
#include <string>
using namespace std;

map< char, double > dur;
string str;
int main(){
	dur['W']=1;
	dur['H']=1.0/2;
	dur['Q']=1.0/4;
	dur['E']=1.0/8;
	dur['S']=1.0/16;
	dur['T']=1.0/32;
	dur['X']=1.0/64;
	while(cin>>str && str!="*"){
		int cnt=0;
		double d=0;
		for(int i=0;i<str.size();++i){
			if(str[i]=='/'){
				if(d==1) cnt++;
				d=0;
			}else{
				d+=dur[str[i]];
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
