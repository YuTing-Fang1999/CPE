#include <iostream>
#include <stdlib.h>
using namespace std;

struct Land{
	int x1, y1, x2, y2;
};

int main(){
	int N; cin>>N;
	for(int Night=1;Night<=N;++Night){
		
		Land l1, l2;
		cin>>l1.x1>>l1.y1>>l1.x2>>l1.y2;
		cin>>l2.x1>>l2.y1>>l2.x2>>l2.y2;
		
		//compute overlapped length
		int strong_w = (l1.x2-l1.x1) + (l2.x2-l2.x1) - ( max(l1.x2, l2.x2) - min(l1.x1, l2.x1) );
		int strong_h = (l1.y2-l1.y1) + (l2.y2-l2.y1) - ( max(l1.y2, l2.y2) - min(l1.y1, l2.y1) );
		int strong = 0;
		if(strong_w>0 && strong_h>0) strong = strong_w * strong_h;
		
		int weak = (l1.x2-l1.x1) * (l1.y2-l1.y1) + (l2.x2-l2.x1) * (l2.y2-l2.y1) - (strong*2);
		printf("Night %d: %d %d %d\n", Night, strong, weak, 10000-strong-weak);
	}
	return 0;
}
