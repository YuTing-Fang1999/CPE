#include <iostream>
#include <vector>
using namespace std;

struct rect{
	double x1,x2,y1,y2;
};

int main(){
	char c;
	vector< rect > rects;
	while(cin>>c && c!='*'){
		rect r;
		cin>>r.x1>>r.y2>>r.x2>>r.y1;
		rects.push_back(r);
	}
	double x,y;
	int p=0;
	while(cin>>x>>y && x!=9999.9 && y!=9999.9){
		p+=1;
		bool isIn = false;
		for(int i=0;i<rects.size();++i){
			if( rects[i].x1<x && x<rects[i].x2 && rects[i].y1<y && y<rects[i].y2){
				printf("Point %d is contained in figure %d\n",p,i+1);
				isIn = true;
			}
		}
		if(!isIn) printf("Point %d is not contained in any figure\n",p);
	}
	return 0;
}
