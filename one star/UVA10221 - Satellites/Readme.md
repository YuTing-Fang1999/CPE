### 題目
計算出2顆衛星的距離(直線距離、弧長)  
![image](https://user-images.githubusercontent.com/66452317/153210153-6667cd0c-72de-4127-b8da-42b3f3f0d2fe.png)

1°(度) = 60'(分) = 3600"(秒)

#### input
`s a unit`  
```cpp
r = 6440+s;  
arc = 2*M_PI*r*(a/360);  
chord = 2*r*sin(a/2 * M_PI/180);  
```
#### 注意要使用M_PI的話，引入要放最上面
```cpp
#define _USE_MATH_DEFINES
#include <cmath>
```

### code
```cpp
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

double s,a,arc,chord;
string unit;
int main(){
	while(cin>>s>>a>>unit){
		if(unit=="min") a/=60;
		while(a>=360) a-=360;
		if(a>180) a=360-a;
		double r =6440+s;
		arc = 2*M_PI*r*(a/360);
		chord = 2*r*sin(a/2 * M_PI/180);
		printf("%.6f %.6f\n",arc,chord);
	}
	return 0;
}
```
