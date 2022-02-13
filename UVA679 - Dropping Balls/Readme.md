每經過一個節點就會分為兩邊  
位置為偶數的往左，位置為奇數的往右  

例:
```
  I = 1 2 3 4 5 6 7 8
idx = 0 1 2 3 4 5 6 7 = I-1
```
idx%2 == 0 往左  
idx%2 == 1 往右  

分完後的idx = idx/2  
```
左邊  H=(L+H)/2          右邊  L=(L+H)/2+1
  I = 1 3 5 7              I = 2 4 6 8
idx = 0 1 2 3            idx = 0 1 2 3
```
一直重複上述步驟直到L==H  

```cpp
#include <iostream>
#include <cmath> 
using namespace std;

int T,D,I;
int main(){
	cin>>T;
	while(T--){
		cin>>D>>I;
		int L=pow(2.0,D-1),H=pow(2.0,D)-1;
		--I;
		while(L!=H){
			if(I%2) L=(L+H)/2+1; //right
			else  H=(L+H)/2; //left
			//printf("I=%d, L=%d, H=%d\n",I,L,H);
			I/=2;
		}
		cout<<L<<endl;
	}
	cin>>T;
	return 0;
}
```
