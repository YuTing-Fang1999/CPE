#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// The given numbers can contain up to 1000 digits.=>using string
// 11计 = abs(计-案计)%11==0 (琌11计)
string str;
int even,odd;
int main(){
	while(cin>>str && str!="0"){
		even=odd=0;
		for(int i=0;i<str.size();++i){
			if(i%2) odd+=str[i]-'0';
			else even+=str[i]-'0';
		}
		if(abs(even-odd) %11) printf("%s is not a multiple of 11.\n",str.c_str());
		else printf("%s is a multiple of 11.\n",str.c_str());
	}
	return 0;
}

