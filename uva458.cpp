#include <iostream>
#include <string>
using namespace std;

string str;
int main(){
	while(cin>>str){
		for(int i=0;i<str.size();++i){
			printf("%c",str[i]-7);
		}
		cout<<endl;
	}
	return 0;
}
