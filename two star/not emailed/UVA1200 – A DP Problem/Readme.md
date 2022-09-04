// 注意 1x 會以 x 表示!   
// 0x+5=5 是 IDENTITY!   
// 2x+3=0 是 -1.5 -> -2 (小於或等於解的最大整數)   

原版
```cpp
#include <iostream>
#include <string>
using namespace std;

// 注意 1x 會以 x 表示! 
// 0x+5=5 是 IDENTITY! 
// 2x+3=0 是 -1.5 -> -2 (小於或等於解的最大整數)
int main(){
	int t; cin>>t; 
	string str;
	char c;
	while(t--){
		int l_x=0,r_x=0,l_n=0,r_n=0;
		bool left=true;
		bool neg=false;
		bool is_x=false;
		bool is_n=false;
		int num=0;
		cin>>str;
		for(int i=0;i<str.size();++i){
			c = str[i];
			if('0'<=c && c<='9'){
				num*=10;
				num+=c-'0';
				is_n=true;
			}
			else if(c=='x') is_x=true;
			else if(c=='-' || c=='+' || c=='=') {
				if(is_n==false) num=1;
				if(neg) num=-num;
				
				if(is_x){
					if(left) l_x+=num;
					else r_x+=num;
				}
				else{
					if(left) l_n+=num;
					else r_n+=num;
				}
//				printf("%d %d %d %d \n", l_x, r_x, l_n, r_n);
				neg=false;
				is_x=false;
				is_n=false;
				num=0;
				
				if(c=='-') neg=true;
				if(c=='=') left=false;
			}
		}
		
		if(is_n==false) num=1;
		if(neg) num=-num;
		
		if(is_x){
			if(left) l_x+=num;
			else r_x+=num;
		}
		else{
			if(left) l_n+=num;
			else r_n+=num;
		}
		
		int x = l_x-r_x;
		int n = r_n-l_n;
		if(x==0 && n==0) printf("IDENTITY\n");
		else if(x==0 && n!=0) printf("IMPOSSIBLE\n");
		else if (n/x<0 && n%x) printf("%d\n", n/x-1);
		else printf("%d\n", n/x);
	}
	return 0;
}

```

後來看別人的code發現右邊只要變一個負號就好了    
不用多一個變數存   
```cpp
#include <iostream>
#include <string>
using namespace std;

// 注意 1x 會以 x 表示! 
// 0x+5=5 是 IDENTITY! 
// 2x+3=0 是 -1.5 -> -2 (小於或等於解的最大整數)
int main(){
	int t; cin>>t; 
	string str;
	char c;
	while(t--){
		int x=0,n=0;
		int left=1; //-1代表right 
		int neg=1;
		int num=0;
		bool is_n=false;
		cin>>str;
		for(int i=0;i<str.size();++i){
			c = str[i];
			if('0'<=c && c<='9'){
				num*=10;
				num+=c-'0';
				is_n=true;
			}
			else if(c=='x'){
				if(!is_n) num=1;
				x -= num * left * neg; 
				neg=1;
				is_n=false;
				num=0;
			}
			else if(c=='-'){
				n += num * left * neg;
				neg=-1;
				is_n=false;
				num=0;
			}
			else if(c=='+'){
				n += num * left * neg;
				neg=1;
				is_n=false;
				num=0;
			}
			else if(c=='=') {
				n += num * left * neg;
				neg=1;
				is_n=false;
				num=0;
				left=-1;
			}
//			cout<<n<<" "<<x<<endl;
		}
		if(num) n += num * left * neg;
		
		if(x==0 && n==0) printf("IDENTITY\n");
		else if(x==0 && n!=0) printf("IMPOSSIBLE\n");
		else if (n/x<0 && n%x) printf("%d\n", n/x-1);
		else printf("%d\n", n/x);
	}
	return 0;
}
```
