算出  
* A有但B沒有的牌有幾張
* B有但A沒有的牌有幾張
* 取最小值
#### 善用set
```cpp
#include <iostream>
#include <set>
using namespace std;
//善用set
set< int > setA,setB,setAB;
int An,Bn,n;
int main(){
	while(cin>>An>>Bn && An && Bn){
		setA.clear();setB.clear();setAB.clear();
		while(An--){
			cin>>n;
			setA.insert(n);
			setAB.insert(n);
		}
		while(Bn--){
			cin>>n;
			setB.insert(n);
			setAB.insert(n);
		}
		cout<<min(setAB.size()-setA.size(), setAB.size()-setB.size())<<endl;
	}
	
	return 0;
}

```
