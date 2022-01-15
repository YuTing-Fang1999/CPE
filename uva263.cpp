#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

string str;
set< int > mySet;
stringstream ss;
int n1,n2,n3;

int main(){
	while(cin>>str && str!="0"){
		ss.clear(); mySet.clear();
		printf("Original number was %s\n",str.c_str());

		while(true){
			sort(str.begin(),str.end());
			int n1=stoi(str);
			reverse(str.begin(),str.end());
			int n2=stoi(str);
			int n3=n2-n1;
			
			printf("%d - %d = %d\n",n2,n1,n3);
			if(mySet.find(n3) != mySet.end()) break;
			mySet.insert(n3);
			ss.clear();
			ss<<n3;
			ss>>str;
		}
		printf("Chain length %d\n\n",mySet.size()+1);
	}
	return 0;
}
