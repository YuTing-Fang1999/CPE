#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int T;
stringstream ss;
string str;
int main(){
	cin>>T;
	getchar(); //�`�N�n�Y�����'\n' 
	getchar();
	for(int CASE=1;CASE<=T;++CASE){
		if(CASE>1) cout<<endl; //�̫ᤣ�঳�Ů� 
		printf("Case #%d:\n",CASE);
		while(getline(cin,str) && str!=""){ //�`�N������󬰪Ŧr�� 
			//cout<<str<<endl;
			ss.clear(); //�`�N�n�M��ss 
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
