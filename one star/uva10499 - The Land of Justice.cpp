//�y�魱�n=4*pi*r^2
//�ꭱ�n=pi*r^2
//�C�h���@�����|�W�[�@�Ӷꭱ�n
//pi*r^2 / 4*pi*r^2 = 1/4 = 25%
#include <iostream>
using namespace std;
int main(){
	long long n;
	while(cin>>n && n>0){
		if(n==1) cout<<"0%"<<endl;
		else cout<<n*25<<"%"<<endl;
	}
	return 0;
}


