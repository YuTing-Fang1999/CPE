
## 總結
先分成兩個case
* 小於vec_num[i]  
	* 第i位出現的個數 = p 
	* 0~9出現的個數 = (p / 10) * ( d - i )
* 等於vec_num[i]  
	* 第i位出現的個數 = (num % p  ) + 1

## 計算 0~9 的個數  
\* = 1 個 0 ~ 9  
** = 20 個 0 ~ 9 ( 十位數字重複10次，後面加上10組* = 10 + 10\*1 )  
*** = 300 個 0 ~ 9 (百位數字重複100次，後面加上10組** = 100 + 10\*20)   
**** = 4000 個 0 ~ 9  (1000 + 10\*300)

以此類推  -> 0 ~ 9 的個數  
= (p / 10) * ( \*的個數 )   
= (p / 10) * ( d - i )   

## Example
假設num=213   
位數d=2, p=10^d=100  
vec_num[0] = 2  
vec_num[1] = 1  
vec_num[2] = 3  

## i=0, p=100
### 小於num_vec[i] = 2 的case (後面隨便填)  
#### 第i位出現的個數 = p
0\*\* -> 0 出現 100 次 (\*\* = 0\~99)  
1\*\* -> 1 出現 100 次  

#### 第i位固定，0~9出現的個數
0\*\* -> 0 \~ 9 出現 20 次  
1\*\* -> 0 \~ 9 出現 20 次  

-> 0 ~ 9 的個數  
= (p / 10) * ( d - i ) \* vec_num[0]    
= 10 * 2 * 2 = 40   

### 等於num_vec[i] = 2 的case
#### 第i位出現的個數  
2\*\* -> 2 出現 14 (0~13) 次  
= (num % p  ) + 1  
= (213 % 100) + 1 = 14  

## i=1, p=10 

### 小於num_vec[1] = 1 的case (後面隨便填)
#### 第i位出現的個數 = p
20\* -> 0 出現 10 次
#### 計算0~9 的個數
20\* -> 0 ~ 9 出現 1 次    
= (p / 10) * ( d - i ) \* vec_num[1]  
= 1 * 1 * 1 = 1   

### 等於num_vec[1] = 1 的case
#### 第i位出現的個數
21\* -> 1 出現 4 次 (0~3)   
= (num % p  ) + 1  
= (213 % 10) + 1 = 4  

## i=2, p=1 
### 小於num_vec[i] = 3 的case (後面隨便填)  
#### 第i位出現的個數 = p
210 -> 0 出現 1 次   
211 -> 1 出現 1 次    
212 -> 2 出現 1 次   

#### 計算0~9 的個數  
(p / 10) * ( d - i ) \* vec_num[2]   
= 0 * 0 * 3   
= 0   

### 等於num_vec[1] = 1 的case
#### 第i位出現的個數
213 -> 3 出現 1 次   
= (num % p  ) + 1  
= (213 % 1) + 1 = 1  


```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> counting(int num){
	// num to vec
	int num2=num; // 要先copy一份!! 
	vector<int> num_vec;
	while(num2!=0){
		num_vec.push_back(num2%10);
		num2/=10;
	}
	reverse(num_vec.begin(), num_vec.end());
	
	// counting
	vector<int> ans(10, 0);
	int d = num_vec.size()-1;
	int p = pow(10, d);
	
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
		ans[num_vec[i]] += (num % p) + 1;

		ans[0]-=p; //將開頭為0的部分先去掉
		p/=10; 
	}

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

