假設a=213   
位數d=3, p=10^(d-1)=100  
vec_num[2] = 2  
vec_num[1] = 1  
vec_num[3] = 3  

#### 計算** 0~9 的個數  
** = 20 個 0 ~ 9 ( 十位數字10個，個位數字重複10次 )  
*** = 300 個 0 ~ 9 (百位數字重複100次，後面加上10組** = 100+10*20)   
**** = 4000 個 0 ~ 9  

以此類推  -> 0 ~ 9 的個數  
= (p / 10) * ( \*的個數 )   
= (p / 10) * ( d - i - 1 )   

## i=0, p=100
### 先處理200以前的數字
#### 首位出現的個數
0\*\* -> 0 出現 100 次 = p (\*\* = 0\~99)  
1\*\* -> 1 出現 100 次  

#### 首位固定，0~9出現的個數
0\*\* -> 0 \~ 9 出現 20 次  
1\*\* -> 0 \~ 9 出現 20 次  

-> 0 ~ 9 的個數  
= (p / 10) * ( \*的個數 ) \* vec_num[0]    
= 10 * 2 * 2 = 40   

### 200以後的數字
#### 首位出現的個數  
2\*\* -> 2 出現 14 次 = 13 (0\~12) + 1 (13)   

## i=1, p=10 

### 先處理210以前的數字
#### 第i位出現的個數 = p
20\* -> 0 出現 10 次
#### 計算0~9 的個數
20\* -> 0 ~ 9 出現 1 次    
= (p / 10) * ( \*的個數 ) \* vec_num[1] 
= 1 * 1 * 1 = 1   

### 210以後的數字
#### 第i位出現的個數
21\* -> 1 出現 3 次 = 2 (0~1) + 1 (2)   

## i=2, p=1 
#### 計算0~9 的個數
0 * 0 * 3 = 0
#### 第i位出現的個數 = p
210 -> 0 出現 1 次  
211 -> 1 出現 1 次  
212 -> 2 出現 1 次

## 總結
先看首位，分成<vec_num[i]與=vec_num[i]的case  
之後分別計算第i位出現的個數，與0~9出現的個數  

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> counting(int num){
	// num to vec
	vector<int> num_vec;
	while(num!=0){
		num_vec.push_back(num%10);
		num/=10;
	}
	reverse(num_vec.begin(), num_vec.end());
	
	// counting
	vector<int> ans(10, 0);
	int p = 1;
	int d = num_vec.size()-1;
	
	for(int i=0;i<d;++i){
		p *= 10;  
		ans[0]-=p; //將開頭為0的部分先去掉 
	}
	
	for(int i=0;i<num_vec.size();++i){
		// 小於num_vec[i]的case
		// 第i位出現的個數
		for(int j=0;j<num_vec[i];++j){
			ans[j] += p;
		}
		
		// 後面0~9出現的個數 -> *
		for(int j=0;j<10;++j){
			ans[j] +=  (p/10) * (d - i) * num_vec[i];
		}
		
		// 等於num_vec[i]的case
		// 第i位出現的個數
		if(i<d){ //避免p=1的情況發生 
			ans[num_vec[i]] += (num % p);
		}
		ans[num_vec[i]]++; 
		p/=10; 
	}
	
	for(int i=0;i<10;++i){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return ans;
}
int a, b;
int main(){
	while(cin>>a>>b && a && b){
		if(a<b) swap(a,b);
		vector<int> ans_a = counting(a);
		vector<int> ans_b = counting(b-1);
		for(int i=0;i<9;++i){
			cout<<ans_a[i]-ans_b[i]<<" ";
		}
		cout<<ans_a[9]-ans_b[9]<<endl;
	}
	return 0;
}
```

