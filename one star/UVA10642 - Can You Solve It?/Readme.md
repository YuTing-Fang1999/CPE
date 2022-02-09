```
(0,0) 0  
(0,1) 1  
(0,2) 3  
(0,3) 6  
(0,4) 10
(0,5) 15
...
(0,n) (1+n)/2 * n
```
```
(2,3) = (0,5) + 2
(x,y) = (0,n) + x
    n = x+y
```

```cpp
#include <iostream>
using namespace std;

int T,x1,y1,x2,y2;
int main(){
	cin>>T;
	for(int CASE=1;CASE<=T;++CASE){
		cin>>x1>>y1>>x2>>y2;
		int n1 = x1+y1;
		int n2 = x2+y2;
		int c1 = (1+n1)*n1/2 + x1;
		int c2 = (1+n2)*n2/2 + x2;
		printf("Case %d: %d\n",CASE,c2-c1);
	}
	return 0;
} 
```
