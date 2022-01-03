#include<iostream>
#include<string>
using namespace std;

int MtoD[] = {
	0,31,28,31,30,31,30,31,31,30,31,30,31
};
string toStr[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int T,M,D,nowDay;
int firstDay = 4;
int main(){
	cin>>T;
	while(T--){
		cin>>M>>D;
		nowDay=firstDay + D;
		for(int i=0;i<M;++i){
			nowDay+=MtoD[i];
		}
		cout<<toStr[nowDay%7]<<endl;
	}
	return 0;
}

