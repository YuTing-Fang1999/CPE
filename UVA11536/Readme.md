#### 解法
題目只求最短的長度，所以從左掃到右，記住目前最小的Len，再與之後的Len做比較，留下最小的Len  

#### 如何更新a
```
while(cnt[X[a]]>1) {
  //beware the order
  cnt[X[a]]--;
  a++; 
  //
  while(X[a]>K){
    a++;
  }
}
```

#### 如何更新Len
如果集合裡的數都到齊了就可以更新  
```
if(num==K) minLen = min(minLen,i-a+1);
```

#### 注意
* M會改變，所以每次的X都要重算一次!!
* cnt記得也要初始化!
```
memset(cnt,0,sizeof(cnt));
X.clear();
X.push_back(1);
X.push_back(2);
X.push_back(3);
for(int i=3;i<N;++i)
  X.push_back((X[i-1]+X[i-2]+X[i-3])%M+1);
```



