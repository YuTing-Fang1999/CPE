### 題目說明
Change the binary to a number with base -2 

### 方法
#### 當x是正數時，ex: x = 7  
```
i =   0  1  2
      1  2  4
7 =   1  1  1
```
將2轉成-2時要加4，才會等同原本的數
```
i =   0  1  2
      1 -2  4
7  =  1  1  2
```
所以當(i%1==1 && b[i]==1)時，b[i+1]++  

#### 當x是負數時，ex: x = -7  
```
i =    0   1   2
      -1  -2  -4
-7=    1   1   1
```
將-1轉成1時要減2，才會等同原本的數  
同理，-4轉成4時要減-8，才會等同原本的數
```
i =   0  1  2  3
      1 -2  4 -8
-7=   1  2  1  1
```
所以當(i%1==0 && b[i]==1)時，b[i+1]++    

之後將大於2的值轉換掉即可  
ex: -2\*2 + 4 = 0  
ex: -2\*2 = 4 + (-8)  

### Code
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int T; cin>>T;
	for(int t=1;t<=T;++t){
		cout<<"Case #"<<t<<": ";
		int x; cin>>x;
		if(x==0) {
			cout<<0<<endl;
			continue;
		}
		int sign = 1;
		if(x<0){
			x = -x;
			sign = -1;
		}
		vector< int > b;
		while(x){
			b.push_back(x%2);
			x /= 2;
		}
		b.push_back(0);
		b.push_back(0);
		if(sign==1){
			for(int i=0;i<b.size();++i){
				if(i%2==1 && b[i]==1){ //2 -> -2, 4 -> [i+1]++
					b[i+1]++;
				}
			}
		}
		else{
			for(int i=0;i<b.size();++i){
				if(i%2==0 && b[i]==1){ //-1 -> 1, -2 -> [i+1]++
					b[i+1]++;
				}
			}
		}

		for(int i=0;i<b.size();++i){
			if(b[i]>=2){
				if(b[i+1]>=1){ //-2*2 + 4 = 0
					b[i]-=2;
					b[i+1]-=1;
				}
				else{
					b[i]-=2; //ex: -2*2 = 4-8; 4*2 = -8+16
					b[i+1]++;
					b[i+2]++;
				}
			}
		}
		
		int i = b.size()-1;
		while(b[i]==0) i--;
		while(i>=0) {
			cout<<b[i];
			i--;
		}
		cout<<endl;
	}
}
```

