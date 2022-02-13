### 一直WA
後來看別人的程式碼發現後面要補空格
```cpp
#include <iostream>
#include <string>
using namespace std;

string sen[105];
int idx=0;
int jmax=0;
int main(){
	while(getline(cin,sen[idx])){
		if(sen[idx].size()>jmax) jmax=sen[idx].size();
		idx++;
	}
	for(int j=0;j<jmax;++j){
		for(int i=idx-1;i>=0;--i){
			if(sen[i].size()<=j) cout<<" ";
			else cout<<sen[i][j];
		}
		cout<<endl;
	}
	return 0;
}
```
