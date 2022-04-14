#include <iostream>
using namespace std;

int uglyNum[2000];
int main(){
	uglyNum[1] = 1;
	int i2=1, i3=1, i5=1; //ヘ玡计皐 
	int afterMul2=2, afterMul3=3, afterMul5=5; // afterMul5 = uglyNum[i5] * 5
	int next;
	
	for(int n=2;n<=1500;++n){
		//т瞒ヘ玡计程计(程计) 
		next = min(afterMul2, min(afterMul3, afterMul5));
		uglyNum[n] = next;
		
		//狦uglyNum籔ㄤafterMul妓(琌そ计)
		//碞盢皐1穝afterMul狡璸衡 
		if(next == afterMul2){
			i2++;
			afterMul2 = uglyNum[i2] * 2;
		}
		
		if(next == afterMul3){
			i3++;
			afterMul3 = uglyNum[i3] * 3;
		}
		
		if(next == afterMul5){
			i5++;
			afterMul5 = uglyNum[i5] * 5;
		}
	}
	
	printf("The 1500'th ugly number is %d.\n",uglyNum[1500]);
	return 0;
} 
