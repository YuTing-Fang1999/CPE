題目給的點沒有先後順序，要自己判斷重複的點在哪   

平行四邊形的性質，對角線的點相加會相等   
```
p1+p3 = p2+p4  
```
題目會給你 `p1 p2 p2 p3`   
p4 = p1+p3-p2  
先全部相加 = p1+p2+p2+p3    
再減掉重複的那個點 => p1+p2+p2+p3 - 3*p2 = p1+p3-p2  = p4

```cpp
#include <iostream>
using namespace std;
//找平行四邊形的第四個點
//注意給的測資沒有固定方向，要自己找重疊的點
double x[4],y[4],ax,ay; 
int main(){
	while(cin>>x[0]>>y[0]){
		ax=x[0]; ay=y[0];
		for(int i=1;i<4;++i){
			cin>>x[i]>>y[i];
			ax+=x[i]; ay+=y[i];
		}
		for(int i=0;i<4;++i){
			for(int j=i+1;j<4;++j){
				if(x[i] == x[j] && y[i] == y[j]){
					printf("%.3f %.3f\n",ax-3*x[i],ay-3*y[i]);
					break;
				}
			}
		}	
	}
	
	return 0;
} 
```
