#include <iostream>
#include <cmath>
using namespace std;
//       3           7
//(1) (1,2) (3,2,1) (1,2,3,4) ���l 
//(1) (2,1) (1,2,3) (4,3,2,1) ���� 
int term;
int main(){
	while(cin>>term){
		int N = pow(term, 0.5);
		int tot = (1+N)*N/2;
		
		while(tot<term){ //��j�󵥩�term�ɴN���� 
			tot+=++N;
		}
		//N�N��ϰ�̪��̤j�� 
		tot-=N; //�e�@�Ϫ�tot 
		int dif = term-tot;
		
		if(N%2 == 0){ //���l���A�����f  
			printf("TERM %d IS %d/%d\n",term,dif,N-dif+1);
		} 
		else{ //���l�f�A������ 
			printf("TERM %d IS %d/%d\n",term,N-dif+1,dif);
		}
	}
	return 0;
}
