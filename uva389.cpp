#include <iostream> 
#include <string>
#include <stdlib.h>
using namespace std;

//注意與CPE的題目有些小不同 
int main(){
	string num;
	int fromBase;
	int toBase;
	while(cin>>num>>fromBase>>toBase){
		bool isError=false;
		bool isZero=false;
		int base = 1;
		int n1=0;
		for(int i=num.size()-1;i>=0;--i){
			if( 'A'<=num[i] && num[i]<='F'){
				n1+=(num[i]-'A' + 10)*base;
				
			}
			else{
				n1+=(num[i]-'0')*base;
			}
			base*=fromBase;
		}
		if(n1==0) isZero=true;
		char n2[]="       ";
		int idx=6;
		char digit;
		while(n1){
			if(n1%toBase<=9) digit = (n1%toBase+'0');
			else digit = ((n1%toBase-10) + 'A');
			n2[idx--] = digit;
			n1/=toBase;
			if(idx<0) {isError=true;break;}
		}
		
		if(isError) printf("  ERROR\n");
		else if(isZero) printf("      0\n");//注意數字為0的case 
		else printf("%s\n",n2);
	}
	return 0;
}

