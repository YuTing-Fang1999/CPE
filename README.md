# CPE

## uva12869
```cpp=
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector< long long int> v;

 long long int fzero(long long int n){
 	long long int i = v.size();
 	long long int num;
 	if(i<=n){
 		num = v[i-1];
	 	while(i<=n){
	 		num*=i;
	 		v.push_back(num);
	 		//printf("F(%lld)=%lld\n",i,v[i]);
	 		++i;
	 	}
	 }
	 else{
	 	num = v[n];
	 }
 	
 	//printf("num=%lld\n",num);
 	long long int zero = 0;
 	while(num%10 == 0){
 		zero++;
 		num/=10;
	 }
	//printf("zero=%lld\n",zero);
 	return zero;
 }
 		

int main(){
	v.push_back(1);
	long long int low, high;
	while(cin>>low>>high){
		if(!low && !high) break;
		set<long long int> mySet;
		for(long long int i=low;i<=high;++i){
			mySet.insert(fzero(i));
		}
		cout<<mySet.size()<<endl;
	}
	return 0;
}
```
原本想說用vector動態計算應該就可以了吧，結果TLE   
後來用另一個vector紀錄之前算過的0，還是TLE  
最後上網看答案才知道會有一種數學的規律==  
這我如果沒看答案真的想不到耶  
