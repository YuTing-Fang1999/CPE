#include <iostream> 
#include <string>
using namespace std;
//Word���w�q�O�s�򪺦r���]letter: A~Z a~z�^�Ҳզ����r�C
bool isLetter(char c){
	if( 'a' <= c && c <= 'z') return true;
	if( 'A' <= c && c <= 'Z') return true;
	return false;
}
string str;
int main(){
	while(getline(cin, str)){
		int n=0;
		bool flag=false;
		for(int i=0;i<str.size();++i){
			if(isLetter(str[i])){
				if(!flag) {
					++n;
					flag=true;
				}
			}
			else{
				flag = false;
			}
		}
		cout<<n<<endl;
	}
	return 0;
}
