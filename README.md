# 瘋狂程設
一推問題，編譯器好難找==，符合版本的都過時了  
需要Microsoft Visual Studio 10.0  
https://docs.microsoft.com/zh-tw/visualstudio/releasenotes/vs2010-sp1-vs

# CPE
## 需複習的
10268(考前再練一次)   
11728(如果正著推很難算就用逆推的!)   
437(要懂得是演算法的精華而不是直接套用!)  
12911(完全不會寫QQ)  
725(能用暴力解救用暴力解!)  
12218(next_permutation,  質數篩)  
165還是不太會解(可能我的功力還不夠...)  
13257(建表)   
255(不難但容易出bug的模擬題)   
490(善用algorithm的reverse)   


## 基本用法
### str reverse
uva11192
```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string str;
int main(){
	while(cin>>N && N){
		cin>>str;
		N = str.size()/N;
		for(int i=0;i<str.size();i+=N){
			reverse(&str[i],&str[i+N]);
		}
		cout<<str<<endl;
	}
	return 0;
}
```
### queue
`#include <queue>`
* push：把值加到尾巴  
* pop：移除頭的值
* back：回傳尾巴的值
* front：回傳頭的值
* size：回傳目前長度
* empty：回傳是否為空  

缺點: 無法取中間值  
### vector
初始化長度為N，值為0
```cpp
X.assign(N,0);
```
二維
```cpp
vector< vector<int> > vec(row, vector<int>(col,-1))
```
### sort
```cpp
#include <algorithm>
```
由小排到大
```cpp
sort(v.begin(),v.end()) 
```
由大排到小
```cpp
	//i+1	//i
bool cmp(int a, int b){
	return a>b;
}
sort(v.begin(),v.end(),cmp);
```
或是先由小排到大再reverse也行;

### 位移
```cpp
i << n //將i左移n位 (左移一位代表乘2)
i >> n //將i右移n位 (右移一位代表除2)
```
### stringstream
```cpp
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
```cpp
atoi(str.c_str)
```
```cpp
int num = stoi(str); //<cmath>
直接用arr[stoi(str)] 會出錯，要先放到num再使用
```
或是直接輸入就行了!
```cpp
int src; cin>>src;
```

### int to string
```cpp
#include <sstream>
stringstream ss;
ss << num;
ss >> str;
```
### 去掉字串空格的方法
要#include \<algorithm\>  //remove  reverse
* 補充 - reverse可以將順序倒轉  
 `reverse(v.begin(), v.end());`  

str = "  Arbitrary   str ing with lots of spaces to be removed   .";
```cpp
remove(str.begin(), str.end(), ' '); //remove可以指定任何要刪除的元素
//Arbitrarystringwithlotsofspacestoberemoved.o be removed   . 
```
因為remove後陣列的長度還是不變，尾部沒換成'\0'，還是會將舊有的資料印出  
所以要用erase指定頭尾範圍把尾部的東西去掉  
remove會回傳字串尾部的位置，可直接使用  
```cpp
str.erase(remove(str.begin(), str.end(), ' '), str.end()); //erase是大多數STL的內建函數
//Arbitrarystringwithlotsofspacestoberemoved.
```
### struct
```cpp
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
```cpp
set<int> mySet;
mySet.insert(n);
mySet.find(n);
mySet.count(n);
```
### map iterator
map的int,double等數字默認值為0  
```cpp
map< long long, int > myMap; 
map< long long, int >::iterator iter;
for (iter=myMap.begin();iter!=myMap.end();++iter){
	iter->first //key
	iter->second //value
}
```
記得判斷是用iter`!=`myMap.end()
### map count
```cpp
myMap.count(key k)
```
如果存在就回傳1(因為key只會有唯一一個)，否則回傳0

### multimap
```cpp
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
