### 我的方法
字串轉數字計算再轉字串
```cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

stringstream ss;
string str;
string f(string s){
	if(s.size()==1) return s;
	int n=0;
	for(int i=0;i<s.size();++i) n+=s[i]-'0';
	//int to str
	ss.clear();
	string s2;
	ss<<n;
	ss>>s2;
	return f(s2); //記得要加return! 
}
int main(){
	while(cin>>str && str!="0"){
		str=f(str);
		cout<<str<<endl;
	}
	return 0;
}
```

### 網路上的方法
感覺比較簡單直觀
```cpp
#include <iostream>
using namespace std;

int f(int num){
	if(num<10) return num;
	int num2=0;
	while(num){
		num2+=num%10;
		num/=10;
	}
	return f(num2);
}
int main(){
	int n;
	while(cin>>n && n!=0){
		cout<<f(n)<<endl;
	}
	return 0;
}
```
