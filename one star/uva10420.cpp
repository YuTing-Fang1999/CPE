#include <iostream>
#include <map>
#include <string>
using namespace std;

map< string, int > myLove;
map< string, int >::iterator iter;
int N;
string str;
int main(){
	cin>>N;
	while(N--){
		cin>>str;
		cin.ignore(1024,'\n');
		myLove[str]++;
	}
	//map會依照ASCII排序
	for(iter=myLove.begin();iter!=myLove.end();++iter){
		printf("%s %d\n",iter->first.c_str(), iter->second);
	}
	return 0;
} 
