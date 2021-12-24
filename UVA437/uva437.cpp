#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct Box{
	int L;
	int W;
	int H;
	Box(int l, int w, int h){
		L=l; W=w; H=h;
	}
};
vector<Box> boxes;
int HEIGHT[180];

bool box_cmp(Box b2, Box b1){
	//put the bigger to the front 
	if (b2.W > b1.W) return true;
	if (b2.W == b1.W && b2.L > b1.L) return true;
	return false;
}

int max_height(){
	int max=0;
	//using LIS
	//先從最底的box放(i=0)
	for(int i=0;i<boxes.size();++i){
	    if(!HEIGHT[i]) HEIGHT[i] = boxes[i].H; //如果為0的話就初始本身高度
	    //printf("HEIGHT[%d]=%d\n",i,HEIGHT[i]);
	    //再找能放在i上面的box，因為i以前的box不可能放在i上面(都比較大)，所以可以從i+1找  
		for(int j=i+1;j<boxes.size();++j){
			if( (boxes[j].L < boxes[i].L) && 
				(boxes[j].W < boxes[i].W) && 
				(HEIGHT[i]+boxes[j].H > HEIGHT[j]) ){ //如果加入後能讓高度變大
				
				 HEIGHT[j] = HEIGHT[i]+boxes[j].H;
				 //printf("box%d 放到 box%d 上面，高度=%d\n",j,i,HEIGHT[j]);
			}
		}
		//後面到這裡基本上就全算完了，直接找最大值 
		//printf("HEIGHT[%d]=%d\n",i,HEIGHT[i]);
	    if(HEIGHT[i] > max) max = HEIGHT[i];
	}
	return max;
}

int main(){
	int n, CASE = 0; 
	while(cin>>n && n){
		++ CASE;
		boxes.clear();
		memset(HEIGHT, 0, sizeof(HEIGHT));
		while(n--){
			int x,y,z; cin>>x>>y>>z;
			Box b1(x, y, z); boxes.push_back(b1);
			Box b2(x, z, y); boxes.push_back(b2);
			Box b3(y, x, z); boxes.push_back(b3);
			Box b4(y, z, x); boxes.push_back(b4);
			Box b5(z, x, y); boxes.push_back(b5);
			Box b6(z, y, x); boxes.push_back(b6);
		}
		sort(boxes.begin(),boxes.end(),box_cmp);
		printf("Case %d: maximum height = %d\n",CASE,max_height()); 
	}
	return 0;
}
