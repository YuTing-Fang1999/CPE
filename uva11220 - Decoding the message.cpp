#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int T;
stringstream ss;
string str;
int main(){
	cin>>T;
	getchar(); //注意要吃掉兩個'\n' 
	getchar();
	for(int CASE=1;CASE<=T;++CASE){
		if(CASE>1) cout<<endl; //最後不能有空格 
		printf("Case #%d:\n",CASE);
		while(getline(cin,str) && str!=""){ //注意停止條件為空字串 
			//cout<<str<<endl;
			ss.clear(); //注意要清空ss 
			ss<<str;
			int idx=0;
			while(ss>>str){
				if(str.size()>idx){
					cout<<str[idx];
					++idx;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
