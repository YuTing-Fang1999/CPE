### 給一個字串，看能組出多少3個字的字串
input
`AACAA`可組出`AAC` `ACA` `CAA` `AAA`四種

### 解法
由左往右篩  
在窮舉時，如果前面的組合已經重複了就不繼續窮舉    
#### 建table
解法參考這: https://edwardtong.pixnet.net/blog/post/45741736-%E3%80%90uva-13257%E3%80%91

用table標記出前方最近相同字元位置   
-1代表在此之前無出現相同字元  
```
input   N  U  E  V E  
table  -1 -1 -1 -1 2
```

用三個迴圈   
* i代表第一個字的位置
* j代表第二個字的位置
* k代表第三個字的位置  

透過表可知道這個字在範圍內有沒有出現過，如果有就略過，沒有的話就+1，並且登記在table裡   

組合  
```
loop1  ans: NUE
loop2  ans: NUV
loop3  ans: NEV
loop4  ans: NEE
loop5  ans: NVE
loop6  ans: UEV
loop7  ans: UEE
loop8  ans: UVE
loop9  ans: EVE
```

### code
```cpp
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int T;
int table[100005]={0},mark[26]={0};
string str;

int main(){
	cin>>T;
	while(T--){
		cin>>str;
		//gen table
		memset(mark,-1,sizeof(mark));
		for(int i=0;i<str.size();++i){
			table[i]=mark[str[i]-'A'];
			mark[str[i]-'A']=i;
		}
		//count
		int cnt=0;
		for(int i=0  ;i<str.size();++i){
			if(table[i]>=0) continue;
			for(int j=i+1;j<str.size();++j){
				if(table[j]>i) continue;
				for(int k=j+1;k<str.size();++k){
					if(table[k]>j) continue;
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
```
