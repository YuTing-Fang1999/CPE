#include <iostream>
#include <string>
using namespace std;

string str1, str2;
int main(){
	while(cin>>str1>>str2){
		int j=0;
		for(int i=0;i<str2.size();++i){
			if(str2[i] == str1[j]) ++j;		
		}
		if(j==str1.size()) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
} 
