#include <iostream>
using namespace std;
// 4 ���I�A�̦h��(4*3)/2 = 6 ����i�H�s
// �C�ʾ�ܤ֭n�s3����A�α���ѤU���ʾ�N���i�A�ϥΦ����� 
// �̦h�i�H��6/3�ʾ�
// ans = [N*(N-1)/2] / (N-1) = N/2 
int N, CASE = 1;
int main(){
	while(cin>>N && N){
		printf("Case %d: %d\n", CASE++, N/2);
	}
	return 0;
} 
