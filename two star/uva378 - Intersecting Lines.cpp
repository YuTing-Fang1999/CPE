#include <iostream>
#define INF 1e9
using namespace std;
// y = mx + b
// m = (y1-y0)/(x1-x0) when x1!=x0
// b = y - mx;
// m1*x + b1 = m2*x + b2
// x = (b2-b1)/(m1-m2)
int main(){
	int N; cin>>N;
	double x[4], y[4];
	printf("INTERSECTING LINES OUTPUT\n");
	while(N--){
		for(int i=0;i<4;++i) {
			cin>>x[i];
			cin>>y[i];
		}
		double m1, m2, b1, b2, px, py;
		if(x[1]==x[0]) {
			m1 = INF;
			b1 = x[0];	
		}
		else {
			m1 = (y[1]-y[0])/(x[1]-x[0]);
			b1 = y[0] - m1*x[0];
		}
		
		if(x[2]==x[3]) {
			m2 = INF;
			b2 = x[2];	
		}
		else {
			m2 = (y[3]-y[2])/(x[3]-x[2]);
			b2 = y[2] - m2*x[2];
		}
//		printf("%f %f %f %f\n",m1,m2,b1,b2);
		if(m1 == m2){
			if(b1 == b2) printf("LINE\n");
			else printf("NONE\n");
		}
		else{
			if(m1 == INF) {
				px = x[0];	
				py = m2*px + b2;
			}
			else if(m2 == INF){
				px = x[2];
				py = m1*px + b1;
			} 
			else {
				px = (b2-b1)/(m1-m2);
				py = m1*px + b1;	
			}
			printf("POINT %.2f %.2f\n",px,py);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
