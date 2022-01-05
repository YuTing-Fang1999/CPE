```
#include <iostream>
using namespace std;

int N;
int arr[100005];
int main(){
	while(cin>>N && N){
		for(int i=0;i<N;++i) cin>>arr[i];
		int move = 0;
		for(int i=1;i<N;++i){
			for(int j=0;j<N-i;++j){
				if(arr[j]>arr[j+1]){
					swap(arr[j],arr[j+1]);
					++move;
				}
			}
		}
		if(move%2) printf("Marcelo %d\n",move);
		else printf("Carlos %d\n",move);
	}
	return 0;
}
```
一開始想說這麼簡單怎麼會放在第6題  
原來直接使用bubble sort會有TLE的問題   
要使用其他排序法才行  

### 解法  
1. 使用merge sort  


2. 使用BIT(Binary Index Tree)  
https://louisfghbvc.pixnet.net/blog/post/331500736-uva-11495-bubbles-and-buckets
