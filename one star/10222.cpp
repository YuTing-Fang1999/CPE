#include <iostream>
#include <string>
using namespace std;


int main(){
	//�O�o�S��Ÿ�\�e���n�['\'
	string str="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	
	char c;
	while((c=getchar())!='\n'){
		c=tolower(c);
		if(c==' ') printf(" ");
		else {
			int pos=str.find(c);
			printf("%c",str[pos-2]);
		}
	}
	//�S�[����|WA== 
	cout<<endl;
	return 0;
}
