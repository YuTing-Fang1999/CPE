12959
# CPE
## 需複習的
11728(如果正著推很難算就用逆推的!)   
437(要懂得是演算法的精華而不是直接套用!)  
12911(完全不會寫QQ)  
725(能用暴力解救用暴力解!)  
11489(next_permutation,  質數篩)  

## 基本用法
### 位移
```
i << n //將i左移n位 (左移一位代表乘2)
i >> n //將i右移n位 (右移一位代表除2)
```

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
