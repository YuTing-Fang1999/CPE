#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//output
//1. minimum possible value for A
//2. �h�֥i����A���Ʀbinput��(���Ƥ]�n�p��) 
//3. ���h�֥i����A���Ƥ��binput��
//    (���ƼƦC�|����Ӥ���ơA��Ӥ���ƶ��s�b����Ƭҥi�ର���ƦC�������) 

int n,minMid,maxMid,cnt;
vector< int > X;
int main(){
	while(cin>>n){
		X.clear();
		for(int i=0;i<n;++i) {
			int x; cin>>x;
			X.push_back(x);
		}
		sort(X.begin(), X.end());
		
		if(X.size()%2){ //odd
			minMid = maxMid = X[n/2];
		}
		else{
			minMid = X[n/2 -1];
			maxMid = X[n/2];
		}
		
		cnt=0;
		for(int i=0;i<X.size();++i){
			if(X[i]==minMid || X[i]==maxMid) cnt++;
		}
		
		printf("%d %d %d\n",minMid,cnt,maxMid-minMid+1);
	}
	return 0;
} 
