這題也是debug de 好久  
注意以下程式碼執行完，n會等於3  
```
ss<<"1 1 1";
int n=-1;
while(ss>>a[++n]){
  cout<<a[n]<<endl;
}
```

### 原版-使用陣列
```
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int x;
string str;
stringstream ss;
int a[10000];

int main(){
  while(cin>>x){
    cin.ignore();
    ss.clear();
    getline(cin,str); 
    ss<<str;
    int n=0;
    while(ss>>a[n++]){
      //cout<<a[n-1]<<endl;
    }
    //printf("n=%d\n",n);
    n-=2; //super important!
    int num=0;
    for(int i=0;i<n;++i){
      num+=a[i]*(n-i)*pow((float)x,n-i-1);
      //cout<<a[i]*(n-i)*pow((float)x,n-i-1)<<endl;
    }
    cout<<num<<endl;
  }
  return 0;
}
```

### 下次還是直接使用vector好了，比較不會出錯
```
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int x;
string str;
stringstream ss;
vector< int > a;

int main(){
  while(cin>>x){
    cin.ignore();
    ss.clear();
    a.clear();

    getline(cin,str); 
    ss<<str;
    int tmp;
    while(ss>>tmp){
      a.push_back(tmp);
    }
    int n=a.size()-1;
    int num=0;
    for(int i=0;i<n;++i){
      num+=a[i]*(n-i)*pow((float)x,n-i-1);
    }
    cout<<num<<endl;
  }
	return 0;
}

```

### 從尾算到頭效能更好
```
int n=a.size()-1;
int num=0;
int mul =1;
for(int i=n-1;i>=0;--i){
  num+=a[i]*(n-i)*mul;
  mul*=x;
}
```
