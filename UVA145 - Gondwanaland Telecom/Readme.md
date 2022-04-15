模擬題，但我debug很久  
依照時段收費即可  
注意輸出的格式!  

### 解法
第三個時段橫跨了 0 ，可以把它拆成兩個時段  
時段的分界   
```
時段	0       480      1080     1320     1440  
	|--------|--------|--------|--------|  
idx          0        1        2        3
```
要注意的是有無橫跨時段    
如果沒有就直接相減即可   
如果有就分段計算  
```cpp
#include <iostream>
#include <string>
using namespace std;

char step;
float rate[5][3] = {
{0.1,0.06,0.02},
{0.25,0.15,0.05},
{0.53,0.33,0.13},
{0.87,0.47,0.17},
{1.44,0.8,0.3},
};
int ratetime[5] = {0,480,1080,1320,1440};
int m1,h1,m2,h2,startIdx,endIdx;
string phone;
int main(){
	while(cin>>step &&step!='#'){
		cin>>phone>>h1>>m1>>h2>>m2;
		
		m1=(m1+h1*60)%1440;
		m2=(m2+h2*60)%1440;
		
		int spentTime[4] = {0};
		float charge = 0;
		for(int i=0;i<=3;++i){
			if(ratetime[i]<=m1 && m1<ratetime[i+1]) startIdx=i;
			if(ratetime[i]<=m2 && m2<ratetime[i+1]) endIdx=i;
		}
//		printf("%d %d\n",m1,m2);
//		printf("%d %d\n",startIdx,endIdx);
		
		// 如果沒有跨block
		if(startIdx == endIdx && m1<m2){
			spentTime[startIdx] = m2-m1;
		}
		else{ //記得要使用+=不然如果是same block會覆蓋掉 
			spentTime[startIdx] += ratetime[startIdx+1]-m1;
			spentTime[endIdx] += m2-ratetime[endIdx];
			
			startIdx = (startIdx+1)%4;
			while(startIdx!=endIdx){
				spentTime[startIdx] += (ratetime[startIdx+1]-ratetime[startIdx]);
				startIdx = (startIdx+1)%4;
			}
		}
//		printf("%6d%6d%6d%6d\n",spentTime[1],spentTime[2],spentTime[3],spentTime[0]);
		spentTime[3]+=spentTime[0];
		for(int i=0;i<=2;++i){
			charge+=rate[step-'A'][i]*spentTime[i+1];
		}
		printf("%10s%6d%6d%6d%3c%8.2f\n",phone.c_str(),spentTime[1],spentTime[2],spentTime[3],step,charge);
	}
	return 0;
}
```

### 解答版本
天啊，沒想到這麼簡單就能寫出來了，看來我想得太複雜了...   
直接標記每個分鐘，之後再計算就好了   
但效能可能比較不好  
```cpp
int minu[1440] = {0}, time[3] = {0};
x = a * 60 + b;
y = c * 60 + d;
if (y <= x){
	for (i = 0; i < y; i++)
		minu[i] = 1;
	for (i = x; i < 1440; i++)
		minu[i] = 1;
}
else{
	for (i = x; i < y; i++)
		minu[i] = 1;
}
for (i = 0; i < 480; i++){
	if (minu[i] == 1)
		time[2]++;
}
for (i = 480; i < 1080; i++){
	if (minu[i] == 1)
		time[0]++;
}
for (i = 1080; i < 1320; i++){
	if (minu[i] == 1)
		time[1]++;
}
for (i = 1320; i < 1440; i++){
	if (minu[i] == 1)
		time[2]++;
}
```

### 解答版本2
https://yuihuang.com/zj-d089/   
比較不會出bug  
