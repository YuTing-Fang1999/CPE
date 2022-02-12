解法來自: https://ithelp.ithome.com.tw/m/articles/10259718  
```
購買：◆◆◆◆◆  
分組：◆◆ ◆◆ ◆  
借瓶：◆◆◇ ◆◆◇ ◆  
喝掉：◇◇◇ ◇◇◇ ◇   
兌換：◆ ◆ ◇  
喝掉：◇ ◇ ◇  
歸還：◇  
 ```
總共喝了`5 + 2 = 7`瓶

#### 公式 
ans = N + N/2(倆倆一對多出來的瓶子，之後要歸還)

### code
```cpp
#include <iostream>
using namespace std;

int N;
int main(){
	while(cin>>N){
		cout<<N + N/2<<endl;
	}
	return 0;
} 
```
