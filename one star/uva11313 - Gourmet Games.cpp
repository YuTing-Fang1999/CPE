#include <iostream>
using namespace std;
//�C�@���� m �Ӽp�v
//�C�@�����u�Ӫ̱N�d�U�i��U�@�Ӷ��q������
//�p�G���ɪ̪��H�Ƥ���Q m �㰣�A���ǤH�N�����u�ؤl�v�����ʯŤU�@���q
//�̫�|���@�ӫa�x 
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
