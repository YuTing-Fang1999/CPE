#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string stringAdd(string s1, string s2){
//	reverse(s1.begin(), s1.end());
//	reverse(s2.begin(), s2.end());
	int len = s1.size(); //s1的長度一定比s2小 
	int i, c = 0, n=0;
	for(i=0;i<len;++i){ 
		n = (s1[i]-'0') + (s2[i]-'0') + c;
		c = n/10;
		n = n%10;
		s2[i] = (n + '0');
	}
	while(c){
		if(i==s2.size()) s2+="0";
		n = (s2[i]-'0') + c;
		c = n/10;
		n = n%10;
		s2[i++] = (n + '0');
	}
//	reverse(s2.begin(), s2.end()); 等最後輸出答案時再reverse就好 
	return s2;
}
int main(){
	string table[5005];
	table[0] = "0";
	table[1] = "1";
	for(int i=2;i<=5000;++i){
		table[i] = stringAdd(table[i-2], table[i-1]);
	}
	
	int n;
	while(cin>>n){
		string s = table[n];
		reverse(s.begin(), s.end());
		printf("The Fibonacci number for %d is %s\n", n, s.c_str());
	}
}
