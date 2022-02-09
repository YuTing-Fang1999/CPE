#include <iostream>
#include <string>
using namespace std;

int num,cnt;
string str;
int main(){
	while(cin>>num && num){
		cnt=0;
		str="";
		while(num){
			int b = num%2;
			num/=2;
			if(b){
				cnt++;
				str = "1"+str;
			}
			else str = "0"+str;
		}
		printf("The parity of %s is %d (mod 2).\n",str.c_str(),cnt);
	}
	return 0;
}
