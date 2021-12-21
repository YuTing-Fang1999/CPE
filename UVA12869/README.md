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
![image](%E6%95%B8%E5%AD%B8%E8%A6%8F%E5%BE%8B.png)
出處: https://www.youtube.com/watch?v=yYWqH2k22Yk  
這我如果沒看答案真的想不到耶  
話說如果只看最後的0確實是只要是10(2*5)的倍數即可，下次寫之前先思考一下吧!  
不過每五次階層5的個數就會變化一次(增加一個5的倍數)，真的也要多想想才會發現  
因為  
```
0,5,10,15,20,25.....  
(0*5,1*5,2*5,3*5,4*5,5*5......)  
```
不過當加入的是5的次方就不只加入一個5了
(25, 125, 625 ......)
