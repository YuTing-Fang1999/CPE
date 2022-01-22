### 這題卡住的地方
用中位數時，會不會有S,A中位數交界，但此點不在題目給的座標裡(例外case)
#### 不會，能代表中位數就代表此線上一定會有它的座標

```cpp
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int T,SLen,ALen,F;

int Spos[50001];
int Apos[50001];
int main(){
	cin>>T;
	while(T--){
		cin>>SLen>>ALen>>F;
		for(int i=0;i<F;++i){
			cin>>Spos[i];
			cin>>Apos[i];
		}
		sort(Spos,Spos+F);
		sort(Apos,Apos+F);
		int mid = F/2 - (F%2==0);
		printf("(Street: %d, Avenue: %d)\n",Spos[mid],Apos[mid]);
	}
	return 0;
}
```
