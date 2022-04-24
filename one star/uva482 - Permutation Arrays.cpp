#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(){
	int T; cin>>T;
	while(T--){
		getchar();
		getchar();
		string str;
		getline(cin, str);
		
		vector< int > order;
		stringstream ss(str);
		while(ss>>str){
			int idx = atoi(str.c_str());
			order.push_back(idx);
		}
		
		string arr[10000];
		for(int i=0;i<order.size();++i){
			cin>>str;
			arr[order[i]] = str;
		}
		
		for(int i=1;i<=order.size();++i){
			cout<<arr[i]<<endl;
		}
		if(T) printf("\n");
	}
	return 0;
}
