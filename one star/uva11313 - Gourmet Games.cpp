#include <iostream>
using namespace std;
//每一集有 m 個廚師
//每一集的優勝者將留下進行下一個階段的比賽
//如果參賽者的人數不能被 m 整除，有些人就成為「種子」直接晉級下一階段
//最後會有一個冠軍 
int T,n, m;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		int p=0;
		while(n>=m){
			p += n/m;
			n = n/m + n%m;
		}
		if(n==1) printf("%d\n",p);
		else printf("cannot do this\n");
	}
	return 0;
}
