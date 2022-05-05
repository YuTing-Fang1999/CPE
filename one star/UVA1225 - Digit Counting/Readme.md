直接暴力解建表

```cpp
#include <iostream>
#include <string.h>
using namespace std;
//Create a table
//ex: 13 = table[12] + 1 + 3

int T,N;
int table[10001][10];
int main(){
	memset(table, 0, sizeof(table));
	for(int i=1;i<10001;++i){		
		//copy from previous table
		for(int j=0;j<10;++j){
			table[i][j] = table[i-1][j];
		}
		//add new number
		int temp = i;
		while(temp){
			table[i][temp%10]++;
			temp/=10;
		}
	}
	
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<9;++i){
			printf("%d ", table[N][i]);
		}
		printf("%d\n", table[N][9]);
	}
	return 0;
} 
```

使用演算法
https://www.youtube.com/watch?v=6zfXmg9Btao  
這在leetcode居然被歸類為Hard  
果然不管什麼題目一扯到算法就變得很難  
