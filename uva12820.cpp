#include <iostream>
#include <map>
#include <set>
using namespace std;

map< char, int > myMap;
map< char, int > ::iterator iter;
set< int > mySet;
int N,T,count;
char c;
//���D�u�a�}�C�]�i���A�u�O�Q�m�@�USTL���Ϊk 
int main(){
	while(cin>>N){
		getchar();
		count=0;
		while(N--){
			myMap.clear(); mySet.clear();
			while((c=getchar())!='\n'){
				myMap[c]++;
			}
			if(myMap.size()!=1){
				for(iter=myMap.begin(); iter!=myMap.end();iter++){
					if(mySet.find(iter->second) != mySet.end()) break;
					mySet.insert(iter->second);
				}
				if(iter == myMap.end()) count++;
			}
		}
		printf("Case %d: ",++T);
		cout<<count<<endl;
	}
	return 0;
}
