#include <iostream>
#include <string>
using namespace std;

string str;
char dic[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char mirr[] = {'A','n','n','n','3','n','n','H','I','L','n','J','M','n','O','n','n','n',
				'2','T','U','V','W','X','Y','5','0','1','S','E','n','Z','n','n','8','n'};
				
int char2idx(char c){
	for(int i=0;i<36;++i)
		if(dic[i] == c)
			return i;
}
int main(){
	while(cin>>str){
		printf("%s -- ",str.c_str());
		bool isMirr = true;
		bool isPalin = true;
		int len = str.size();
		
		//notice AAEAA is not mirrored
		for(int i=0;i<len/2+1;++i){
			char c1=str[i], c2=str[len-i-1];
			if(isPalin){
				if(c1!=c2)
					isPalin = false;
			}
			if(isMirr){
				if(mirr[char2idx(c1)]!=c2)
					isMirr = false;
			}
		}
		if(!isMirr && !isPalin) printf("is not a palindrome.\n");
		else if(isPalin && isMirr) printf("is a mirrored palindrome.\n");
		else if(isPalin) printf("is a regular palindrome.\n");
		else if(isMirr) printf("is a mirrored string.\n");
		printf("\n");
	}
	return 0;
} 
