#include <iostream>
#include <map>
#include <string>
using namespace std;

int T;
map< string, int >::iterator iter;
string str;
int main(){
	cin>>T; 
	getchar();
	getchar();
	while(T--){
		double tot=0;
		map< string, int > species;
		while(getline(cin,str) && str!=""){
			//cout<<str<<endl;
			species[str]++;
			tot++;
		}
		
		for(iter=species.begin();iter!=species.end();++iter){
			printf("%s %.4f\n",iter->first.c_str(),iter->second/tot*100);
		}
		//注意最後一行不能換行 
		if(T>0) cout<<endl;
	}
	return 0;
}
