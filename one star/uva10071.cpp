#include <iostream>
using namespace std;

//因為是問2t時走多遠，所以目前的速度(經過t秒的速度)為平均速度
//不用去管初速度與加速度是多少，直接用平均速度*總時間即可 
int v,t;
int main(){
	while(cin>>v>>t) cout<<v*2*t<<endl;
	return 0;
} 
