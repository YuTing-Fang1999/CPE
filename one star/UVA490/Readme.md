### 善用algorithm的reverse
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector< string > sen;
string str;
int main(){
	while(getline(cin,str) && str!="0"){
		for(int i=0;i<str.size();++i){
			if(i+1>sen.size()) sen.push_back("");
			sen[i]+=str[i];
		}
	}
	for(int i=0;i<sen.size();++i){
		reverse(sen[i].begin(),sen[i].end());
		cout<<sen[i]<<endl;		
	}
	
	return 0;
}
```
