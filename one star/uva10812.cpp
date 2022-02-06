#include <iostream>
using namespace std;
//a+b=s
//a-b=d
//2a=s+d
//a=(s+d)/2
//b=s-a;
//注意非負整數包含0 
int n;
double s,d,a,b;
int main(){
	cin>>n;
	while(n--){
		cin>>s>>d;
		a=(s+d)/2;
		b=s-a;
//		printf("%f %f\n",a,b);
		if(b<0 || b>(int)b) printf("impossible\n");
		else printf("%d %d\n",(int)a,(int)b);
	}
	return 0;
} 
