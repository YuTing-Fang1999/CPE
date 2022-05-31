#include <iostream>
#include <string.h>
using namespace std;

string str;
int main(){
	while(cin>>str){
		int YuanFen = -1;
		for(int ST=1;ST<=10000;++ST){
			int point[100];
			int len=0;
			//reverse input
			for(int i=str.size()-1;i>=0;--i){
				int num = str[i]-'A' + ST;
				while(num){
					point[len++] = num%10;
					num/=10;
				}
			}
			while(len>=4){
				--len;
				for(int i=0;i<len;++i){
					point[i] = (point[i] + point[i+1]) % 10;
				}
			}
			if(point[0] == 0 && point[1] == 0 && point[2]==1){
				YuanFen = ST;
				break;
			}
		}
		
		if(YuanFen<0) printf(":(\n");
		else printf("%d\n", YuanFen);
	}
	return 0;
}
