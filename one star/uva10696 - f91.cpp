//if N <= 100, then f91(N) = f91( f91( N+11) )
//if N >= 101, then f91(N) = N-10
//�p�G�Ʀr�j�󵥩�101����-10
//�p�G�Ʀr�p�󵥩�100�A�̫�@�w�|���101~111����
//�p�G�Ȭ�111�Af91( f91(111) ) = f91( 101 ) = 91
//���p��X�ȫD111�A�Ҧp105�A�|�@�����_����+11�P-10�A�����ܦ�111�A�̫��٬O�|��X91 
#include <iostream>
using namespace std;

int main(){
	int N;
	while(cin>>N && N){
		if(N>=101) printf("f91(%d) = %d\n", N, N-10);
		else printf("f91(%d) = 91\n",N);
	}
	return 0;
}
