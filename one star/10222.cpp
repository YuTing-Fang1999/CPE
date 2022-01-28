#include <iostream>
#include <string>
using namespace std;


int main(){
	//記得特殊符號\前面要加'\'
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
	//沒加換行會WA== 
	cout<<endl;
	return 0;
}
