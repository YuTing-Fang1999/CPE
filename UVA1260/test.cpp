#include <iostream>
using namespace std;
//�H�D��B���w�q�ӻ��A�O�n�T�{�ۤv�P�ei-1�ӼƦr��A�ۤv���ĴX�j
//�ҥH�i�H����䰵�ƧǡA�ƨ���Ӧ�m�N���D��ۤv�p�����X��
int main(){
	int T; cin>>T;
	int A[1001];
	while(T--){
		int n; cin>>n;
		int sum = 0,j;
		for(int i=0;i<n;++i){
			int num; cin>>num;
			//using insert sort
			for(j=i-1;j>=0;--j){
				if( num < A[j] ) A[j+1] = A[j];
				else break;
			}
			A[j+1] = num;
			sum += j+1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
