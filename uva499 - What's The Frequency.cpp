#include <iostream>
#include <string>
using namespace std;

string str;
int main(){
	while(getline(cin,str)){
		int upper[26] = {0};
		int lower[26] = {0};
		int maxN = 0;
		for(int i=0;i<str.size();++i){
			if( 'A'<=str[i] && str[i]<='Z') upper[str[i]-'A']++;
			if( 'a'<=str[i] && str[i]<='z') lower[str[i]-'a']++;
		}
		for(int i=0;i<26;++i){
			if(upper[i] > maxN) maxN = upper[i];
			if(lower[i] > maxN) maxN = lower[i];
		}
		
		for(int i=0;i<26;++i){
			if(upper[i] == maxN) printf("%c",('A'+i));
		}
		for(int i=0;i<26;++i){
			if(lower[i] == maxN) printf("%c",('a'+i));
		}
		printf(" %d\n",maxN);
	}
	return 0;
}
