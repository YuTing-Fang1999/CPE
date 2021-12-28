### 題目說明
找出j<i且arr[j] - arr[i] 為最大值的數(senior-junior的最大值)  

### 一開始的寫法=>暴力解O(n^2)
TIMELIMIT
```
for(int i=1;i<n;++i){
  for(int j=0;j<i;++j){
    if(arr[j]-arr[i]>max) max=arr[j]-arr[i];
  }
}
```

### 偷看網路上的解法
想了那麼久沒想到最後解法那麼簡單==  
邊輸入邊計算，後面輸進來的都是junior  
把前面的輸入過的最大值-現在輸進來的值，如果有比較大就更新  
```
int nowMax; cin>>nowMax;
int dif = -300000,x;
for(int i=1;i<n;++i){
  cin>>x;
  if(nowMax-x > dif) dif=nowMax-x;
  if(x > nowMax) nowMax = x;
}
```

### 以後不要再自己蝦想了，想半小時都想不出來直接看解答就好，免得一直往錯誤的方向鑽  
