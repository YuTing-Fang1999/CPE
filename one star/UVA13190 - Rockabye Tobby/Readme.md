### 暴力解
0.06s
```cpp
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct Medicine{
	int t;
	string str;
};

int GCD(int x, int y){
	while((x%=y) && (y%=x)) ;
	return x+y; 
}

int T, n, k;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		vector< Medicine > M;
		while(n--){
			Medicine m;
			cin>>m.str>>m.t;
			M.push_back(m);
		}
		//加速的地方 
		//找出每種藥物服用時間的最小公因數，當成時間累進的最小單位
		int D = 0;
		for(int i=0;i<M.size();++i){
			D = GCD(D, M[i].t);
		}
		
		int cnt = 0;
		int time = 0;
		while(cnt<k){
			time += D;
			for(int i=0;i<M.size();++i){
				if(time % M[i].t == 0){
					printf("%d %s\n", time, M[i].str.c_str());
					++cnt;
					if(cnt==k) break;
				}
			}
		}
	}
	return 0;
}
```

### 使用Priority Queue
0.03s
```cpp
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct Medicine{
	int p; // priority
	int f; // frequency
	int t; // time
	string str;
	Medicine(int p, int f, int t, string str){
		this->p = p;
		this->f = f;
		this->t = t;
		this->str = str;
	}
};

bool operator<(const Medicine &a, const Medicine &b){
	if(a.t == b.t) return a.p > b.p;
	else return a.t > b.t;
}

int T, n, k;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		
		priority_queue < Medicine > myQ;
		int f; // frequency
		string str;
		for(int i=0;i<n;++i){
			cin>>str>>f;
			myQ.push(Medicine(i,f,f,str));
		}
		
		while(k--){
			Medicine m = myQ.top(); myQ.pop();
			printf("%d %s\n", m.t, m.str.c_str());
			myQ.push(Medicine(m.p,m.f,m.t+m.f,m.str));
		}
	}
	return 0;
}
```
