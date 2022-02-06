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
	while(getline(cin,str)){
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

### 結果一直WA
後來看別人的程式碼發現後面要補空格=>直接用二維陣列反轉
```cpp
#include <iostream>
#include <string>
using namespace std;

string sen[101];
int main(){
	int n=0,jmax=0;
	while(getline(cin,sen[n])){
		if(jmax<sen[n].size()) jmax=sen[n].size();
		n++;
	}
	for(int j=0;j<jmax;++j){
		for(int i=n-1;i>=0;--i){
			//注意如果長度小於jmax後面要補空格 
			if(j>=sen[i].size()) cout<<" ";
			else cout<<sen[i][j];
		}
		cout<<endl;	
	}
	
	return 0;
}
```
