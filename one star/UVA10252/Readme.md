### 題目講得文周周
題目是說x**經由排列**可以成為a,b的子序列，所以與找子序列不同，只要共同擁有就行  
反正就是找有哪些字元是共同擁有的，然後由小排到大輸出  

### 善用erase
```cpp
// Deletes all characters 
str.erase(); 

// 刪除“pos”之後的所有字符
// Deletes all characters except first one 
str.erase(1);

// Deletes 4 characters from index number 1 
str.erase(1, 4); 

// Deletes character at position 4 
str.erase(str.begin() + 4); 


// Deletes all characters between 0th index and  str.end() - 6 
str.erase(str.begin() + 0, str.end() - 6);
```

### 注意字串也包含空字串!要用getline!

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string ans,s1,s2;
int main(){
	while(getline(cin,s1) && getline(cin,s2)){
		ans="";
		for(int i=0;i<s1.size();++i){
			for(int j=0;j<s2.size();++j){
				if(s1[i]==s2[j]){
					ans+=s1[i];
					s2.erase(j,1);
					break;
				}
			}
		}
		sort(ans.begin(),ans.end());
		cout<<ans<<endl;
	}
	return 0;
}
```

### O(n)的解法
```cpp
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string s1,s2;
int map1[26]={0},map2[26]={0};
int main(){
	while(getline(cin,s1) && getline(cin,s2)){
		memset(map1,0,sizeof(map1));
		memset(map2,0,sizeof(map2));
		
		for(int i=0;i<s1.size();++i) map1[s1[i]-'a']++;
		for(int i=0;i<s2.size();++i) map2[s2[i]-'a']++;
		for(int i=0;i<26;++i){
			int mn = min(map1[i],map2[i]);
			while(mn--) printf("%c",i+'a');
		}
		cout<<endl;
	}
	return 0;
}
```

