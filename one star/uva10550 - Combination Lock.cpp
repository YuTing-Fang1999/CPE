#include <iostream>
using namespace std;
//注意刻度都要乘9 (360/40)
//注意當順時針轉時，刻度是逆時針轉
//其餘照著部驟做就好 

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
