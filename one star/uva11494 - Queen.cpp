#include <iostream>
#include <stdlib.h>
using namespace std;

int x1,y1,x2,y2;
int main(){
	while(cin>>x1>>y1>>x2>>y2 && (x1 || y1 || x2 || y2)){
		int d1 = abs(x1-x2);
		int d2 = abs(y1-y2);
		if(d1==0 && d2==0) printf("0\n");
		else if(d1==0 || d2==0 || d1==d2) printf("1\n");
		else printf("2\n");
	}
}
