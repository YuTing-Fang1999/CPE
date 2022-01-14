#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int x;
string str;
stringstream ss;
vector< int > a;

int main(){
	while(cin>>x){
		cin.ignore();
    	ss.clear();
    	a.clear();
    	
		getline(cin,str); 
		ss<<str;
		int tmp;
		while(ss>>tmp){
			a.push_back(tmp);
		}
		int n=a.size()-1;
		int num=0;
		int mul =1;
		for(int i=n-1;i>=0;--i){
			num+=a[i]*(n-i)*mul;
			mul*=x;
		}
		cout<<num<<endl;
	}
	return 0;
}
