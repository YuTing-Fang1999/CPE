### 直接照抄題目的程式碼即可
```cpp
#include <iostream>
using namespace std;

int GCD(int a,int b){
	while((a%=b) && (b%=a));
	return (a+b);
}
int N;
int main(){
	while(cin>>N && N){
		int G=0;
		for(int i=1;i<N;i++)
		for(int j=i+1;j<=N;j++)
		{
			G+=GCD(i,j);
		}
		cout<<G<<endl;
	}
	return 0;
}
```

### 比較快的方法
用一個table紀錄G(N)的值   
G(N-1)與G(N)只差在要多算一層而已  
使用遞迴去堆  
```cpp
#include <iostream>
using namespace std;

int N;
int table[505];

int GCD(int a,int b){
	while((a%=b) && (b%=a));
	return (a+b);
}

int G(int N){
	if(table[N]) return table[N];
	else{
		int ans=0;
		for(int i=1;i<N;i++) ans+=GCD(i,N);
		
		table[N] = G(N-1)+ans;
		return table[N];
	}
}

int main(){
	for(int i=0;i<505;++i) table[i]=0;
	table[2]=1;
	while(cin>>N && N){
		cout<<G(N)<<endl;
	}
	return 0;
}
```
