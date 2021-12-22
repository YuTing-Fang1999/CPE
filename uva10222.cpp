#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	string key = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";
	getline(cin,str);
	for(int i=0;i<str.length();++i){
		if(str[i] == ' ') {
			cout<<' ';
			continue;
		}
		str[i] = tolower(str[i]);
		int pos = 0;
		for(;pos<key.length();++pos){
			if(str[i]==key[pos]) break;
		}
		pos -= 2;
		cout<<key[pos];
	}
	cout<<endl;
	return 0;
}
