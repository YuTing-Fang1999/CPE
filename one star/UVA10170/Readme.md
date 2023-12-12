每次進來的M都會加一(住的天數延長一天)，問D天後是幾個M  
(S+n)/2 *(n-S) <= D  
n為答案  

### 最簡單的暴力解
```cpp
long long D,M;
while(cin>>M>>D){
  int nowD=M;
  for(;nowD<D;++M,nowD+=M);
  cout<<M<<endl;
}
```
直接TLE

用減的話就不會TLE了
```cpp
long long D,M;
while(cin>>M>>D){
  while(D>0){
    D-=M;
    M++;
  }
  cout<<M-1<<endl;
}
```
我也不知道為甚麼會這樣==  

後來發現問題是因為我把nowD的型態設成int了，改成long long就好了(這樣才不會進入無限迴圈)  
但好像還是會比較慢  
使用加 => 68ms  
使用減 => 44ms  

### code
```cpp
#include <iostream>
using namespace std;

long long D,M;
int main(){
  while(cin>>M>>D){
    while(D>0){
      D-=M;
      M++;
    }
    cout<<M-1<<endl;
  }
	return 0;
}
```
