## 題目說明
題目要你轉接電話，一開始是轉接設定，之後為打來的電話，要你輸出轉接過程  
如果有環出現就直接轉到9999

## 解題思路
### 要用什麼樣的資料結構?  
因為數字範圍只有四位數，可以直接開全部範圍的陣列去存  
使用一個範圍為10000(可存四位數)，用來儲存每個src的vector<Call>陣列
```
vector<Call> v[10000]; //每個v[i] 皆是一個vector<Call>
```
### 如何判別有環?
用一個陣列去標記`(called[10000])`，如果重複標記就代表有環  
利用遞迴去找  
記得要加return! 不然會傳到一開始的src  
```
int call_num(int src, int time){
	called[src] = true;
	for(int i=0;i<callVec[src].size();++i){
		if( callVec[src][i].from <= time && time <= callVec[src][i].to){
			if(called[callVec[src][i].tar]){
				return 9999;
			}else{
				//要加return!!! 
				return call_num(callVec[src][i].tar,time);
			}
		}
	}
	return src;
}
```
