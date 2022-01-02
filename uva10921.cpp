#include <iostream>
#include <string>
using namespace std;

int PHONE_MAP[] = {2,2,2,
					3,3,3,
					4,4,4,
					5,5,5,
					6,6,6,
					7,7,7,7,
					8,8,8,
					9,9,9,9};
//註解掉的為CPE題目的要求 
int main(){
	string str;
	while(cin>>str){
//		int captial=0, hyphen=0;
		for(int i=0;i<str.size();++i){
			if('A'<=str[i] && str[i] <= 'Z'){
//				++ captial;
				cout<<PHONE_MAP[str[i]-'A'];
			}else {
//				if(str[i]=='-') ++hyphen;
				cout<<str[i];
			}
		}
		printf("\n");
//		printf(" %d %d\n",captial,hyphen);
	}
	return 0;
}
