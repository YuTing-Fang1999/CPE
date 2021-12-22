## 題目說明
題目要你轉接電話，一開始是轉接設定，之後為打來的電話，要你輸出轉接過程  
如果有環出現就直接轉到9999

## 解題思路
### 要用什麼樣的資料結構?  
multimap?  
是說用陣列應該就可以了==，因為輸入是照著時間順序輸的，數字也小到可以直接開全部範圍的陣列去存，算了反正就當作多學的吧    
### 如何判別有環?  
回到起點就代表有環

### string to int
```
atoi(str.c_str)
```
直接輸入就行了!
```
int src; cin>>src;
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
