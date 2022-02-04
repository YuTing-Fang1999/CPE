#### 這題主要是難在數學計算  
S => 有幾個case  
N => 有幾個player  
p => 贏一次的機率  
I => 求第I個player的機率是多少  

#### input
```
2 => S
2 0.166666 1 => N p I
2 0.166666 2
```

#### 注意要把所有的可能都算進去(從第一輪到第R輪，因為如果沒分出勝負就要一直比下去)
輸的機率  
`q = 1 - p`  
透過歸納我們可以得知第 R 回合獲勝的機率為    
`q^{(R-1)*N} * q^(I-1) * p`   
=`q^(I-1) * p * q^0`   
+`q^(I-1) * p * q^N`  
+`q^(I-1) * p * q^2N`  
...    

=`q^(I-1) * p * (q^0 + q^N + q^2N ...)`   

#### 等比級數q^0 + q^N + q^2N...
每次皆乘以q^N  
```
a = q^0 + q^N + q^2N...+q^((R-1)N)
a*(q^N) = q^N + q^2N...+q^RN

a(q^N-1) = q^RN-1
a = q^RN-1/q^N-1 = -1/q^N-1 = 1/1-q^N
```

ans = `q^(I-1) * p * (1/1-q^N) = q^(I-1)*p / 1-q^N`

### code
```cpp
#include <iostream>
#include <cmath>
using namespace std;

int S,N,I;
//注意要使用double精度才會準 
double p,q,ans;
int main(){
	cin>>S;
	while(S--){
		cin>>N>>p>>I;
		q=1-p;
		//注意p為0的case 
		if(p==0) printf("%.4f\n",0);
		else printf("%.4f\n",(pow(q,(I-1))*p) / (1-pow(q,N)));
	}
	return 0;
} 
```
