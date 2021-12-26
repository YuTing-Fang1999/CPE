# CPE
## 需複習的
11729(想超久)  
## 基本用法
### string to int
```
atoi(str.c_str)
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
### multimap
引入
```
#include <map>
```

建構
```
multimap<string,Call> callMap;
```

輸入
```
callMap.insert({src, c});
```

查詢
```
multimap<string,Call>::iterator iter;
iter = callMap.find("1111");
int count = callMap.count("1111");
for(int i=0;i<count;++iter,++i){
  printf("%s %s\n",iter->first.c_str(),iter->second.tar.c_str());	
}
```
