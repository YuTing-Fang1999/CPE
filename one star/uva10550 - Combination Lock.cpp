#include <iostream>
using namespace std;
//�`�N��׳��n��9 (360/40)
//�`�N���ɰw��ɡA��׬O�f�ɰw��
//��l�ӵ۳��J���N�n 

int d,dial,a,b,c;
int main(){
	while(cin>>dial>>a>>b>>c && (dial || a || b ||c)){
		d=720;
		d+=((dial-a+40)%40)*9;
		d+=360;
		d+=((b-a+40)%40)*9;
		d+=((b-c+40)%40)*9;
		cout<<d<<endl;
	}

}
