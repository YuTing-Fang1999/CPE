```
n1 = q1*d + r  
n2 = q2*d + r  
...
```
因為有r在，不能直接取GCD，要先相減把r削掉  
注意相減為0的case(取GCD會爆)  

### code
```cpp
#include <iostream>
using namespace std;

int GCD(int a, int b){
	while((a%=b) && (b%=a));
	return (a+b);
}
int main(){
	int n1,n2,d;
	while(cin>>n1 && n1){
		cin>>n2;
		d = abs(n1-n2);
		while(cin>>n2 && n2){
			if(abs(n1-n2))
				d = GCD(d,abs(n1-n2));
		}
		cout<<d<<endl;
	}
	return 0;
}
```
