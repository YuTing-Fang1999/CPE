#include <iostream>
#include <string>
using namespace std;
// 上面1，北面2，西面3，每面與其對面和為7
// 2
// 1 3 6 4
// 5
int N;
string cmd;
int main(){
	while(cin>>N && N){
		int top = 1;
		int bottom = 6;
		int north = 2;
		int south = 5;
		int west = 3;
		int east = 4;
		while(N--){
			cin>>cmd;
			if(cmd=="north"){ 
				int temp=top;
				top = south;
				south = bottom;
				bottom = north;
				north = temp;
			}
			else if(cmd=="east"){
				int temp=top;
				top = west;
				west = bottom;
				bottom = east;
				east = temp;
			}
			else if(cmd=="south"){
				int temp=top;
				top = north;
				north = bottom;
				bottom = south;
				south = temp;
			}
			else if(cmd=="west"){
				int temp=top;
				top = east;
				east = bottom;
				bottom = west;
				west = temp;
			}
		}
		cout<<top<<endl;
	}
	return 0;
}
