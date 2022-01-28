### 模擬題
* king只能上下左右移動
* queen可以垂直水平移動
* legal 代表queen是垂直水平移動，但只要king擋住路就無法前進(不可跟king重疊)
* allow 代表queen沒有移動到king的隔壁

首先確定是是在哪個row和col
```
row = num/8
col = num%8
```
#### ligal   
首先要確認  
  1. move的位置不可跟queen一樣!(我的bug出在這)  
  2. move與queen是否在同一個row或col   
  3. king與queen是否在同一個row或col    
    如果是 => king如果在move與queen之間就違法(我的bug出在這)    
              原本是用move是否在king與queen之間來判斷的，但如果king沒擋住路的話還是合法的!    

#### allowed move   
move與king要隔一個距離(不能在king隔壁)  
* 注意col=0 or 7的case

#### continue
判斷queen move 後，king是否還能移動  
  => king 在角落且move正好堵住他   
  
### code
```cpp
#include <iostream>
using namespace std;

int q,k,m; //queen,king,move
int qR,qC,kR,kC,mR,mC;

bool isIllegalState(){
	return k==q;
}

bool isBetween(int a,int b,int c){
	if(a > b) swap(a,b);
	return ( a <= c && c <= b);
}
bool isIllegalMove(){
	//printf("%d %d %d\n",qR,kR,mR);
	if(q==m) return true; //queen與move同一個位置
	if(qR != mR && qC != mC) return true; //queen不是水平垂直移動
	if(qR == kR && isBetween(qC,mC,kC)) return true; //king在move與queen中間
	if(qC == kC && isBetween(qR,mR,kR)) return true;
	return false;
}

bool isMoveNotAllowed(){
	return ((kC!=0 && m==k-1) || (kC!=7 && m==k+1) || m==k-8 || m==k+8); //注意col=0,7的case
}

bool isContinue(){
	return !((k==0 && m==9) || (k==7 && m==14) || (k==56 && m==49) || (k==63 && m==54));
}

int main(){
	while(cin>>k>>q>>m){
    		//compute row col
		kR=k/8;kC=k%8;
		qR=q/8;qC=q%8;
		mR=m/8;mC=m%8;
		
		if(isIllegalState()) 
			cout<<"Illegal state"<<endl;
		else if(isIllegalMove()) 
			cout<<"Illegal move"<<endl;
		else if(isMoveNotAllowed())
			cout<<"Move not allowed"<<endl;
		else if(isContinue())
			cout<<"Continue"<<endl;
		else
			cout<<"Stop"<<endl;
	}
	return 0;
```
