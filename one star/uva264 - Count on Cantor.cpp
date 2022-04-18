#include <iostream>
#include <cmath>
using namespace std;
//       3           7
//(1) (1,2) (3,2,1) (1,2,3,4) 分子 
//(1) (2,1) (1,2,3) (4,3,2,1) 分母 
int term;
int main(){
	while(cin>>term){
		int N = pow(term, 0.5);
		int tot = (1+N)*N/2;
		
		while(tot<term){ //當大於等於term時就停止 
			tot+=++N;
		}
		//N代表區域裡的最大值 
		tot-=N; //前一區的tot 
		int dif = term-tot;
		
		if(N%2 == 0){ //分子順，分母逆  
			printf("TERM %d IS %d/%d\n",term,dif,N-dif+1);
		} 
		else{ //分子逆，分母順 
			printf("TERM %d IS %d/%d\n",term,N-dif+1,dif);
		}
	}
	return 0;
}
