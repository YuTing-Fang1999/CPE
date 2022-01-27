#include <iostream>
#include <string>
using namespace std;

int T;
string str;
char c;
int main(){
	cin>>T;
	for(int CASE=1;CASE<=T;++CASE){
		printf("Case %d: ",CASE);
		cin>>str;
		for(int i=0;i<str.size();++i){
			if('A'<=str[i] &&str[i]<='Z'){
				int num = 0; c=str[i];
				while('0'<=str[i+1] && str[i+1]<='9'){
					++i;
					int num2 = str[i]-'0';
					num = 10*num + num2;
				}
				while(num--){
					cout<<c;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
