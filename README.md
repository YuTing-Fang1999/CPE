12959
# CPE
## 需複習的
11728(如果正著推很難算就用逆推的!)   
437(要懂得是演算法的精華而不是直接套用!)  
12911(完全不會寫QQ)  
725(能用暴力解救用暴力解!)  
12218(next_permutation,  質數篩)  

## 基本用法
### 位移
```
i << n //將i左移n位 (左移一位代表乘2)
i >> n //將i右移n位 (右移一位代表除2)
```
### stringstream
```
#include <sstream>

stringstream ss;
getline(cin,line); cin.ignore();
ss<<line;
while(ss>>num){
	...
}
```
宣告stringstream類別的時候其實蠻消耗CPU的時間，在解題目以及應用的時候不太建議重複宣告  
cin.ignore()的詳細介紹:   
http://justimchung.blogspot.com/2016/11/c-cin-getline.html
### string to int
```
atoi(str.c_str)
```
```
int num = stoi(str); //<cmath>
直接用arr[stoi(str)] 會出錯，要先放到num再使用
```
或是直接輸入就行了!
```
int src; cin>>src;
```
### 去掉字串空格的方法
要#include \<algorithm\>  //remove  reverse
* 補充 - reverse可以將順序倒轉  
 `reverse(v.begin(), v.end());`  

str = "  Arbitrary   str ing with lots of spaces to be removed   .";
```
remove(str.begin(), str.end(), ' '); //remove可以指定任何要刪除的元素
//Arbitrarystringwithlotsofspacestoberemoved.o be removed   . 
```
因為remove後陣列的長度還是不變，尾部沒換成'\0'，還是會將舊有的資料印出  
所以要用erase指定頭尾範圍把尾部的東西去掉  
remove會回傳尾部的位置，可直接使用  
```
str.erase(remove(str.begin(), str.end(), ' '), str.end()); //erase是大多數STL的內建函數
//Arbitrarystringwithlotsofspacestoberemoved.
```
### struct
```
//建構
struct Call{
	int from;
	int to;
	int tar;
	Call(int a,int b,int c){
		from=a; to=b; tar=c;
	}
};
//創立物件
Call c(a,b,c);
```
### set
```
set<int> mySet;
mySet.insert(n);
mySet.find(n);
mySet.count(n);
```
### map iterator
```
map< long long, int > myMap;
map< long long, int >::iterator iter;
for (iter=myMap.begin();iter!=myMap.end();++iter){
	iter->first //key
	iter->second //value
}
```
記得判斷是用iter`!=`myMap.end()
### map count
```
myMap.count(key k)
```
如果存在就回傳1(因為key只會有唯一一個)，否則回傳0

### multimap
```
//引入
#include <map>
//建構
multimap<string,Call> callMap;
//輸入
callMap.insert({src, c});
//查詢
multimap<string,Call>::iterator iter;
iter = callMap.find("1111");
int count = callMap.count("1111");
for(int i=0;i<count;++iter,++i){
  printf("%s %s\n",iter->first.c_str(),iter->second.tar.c_str());	
}
```
