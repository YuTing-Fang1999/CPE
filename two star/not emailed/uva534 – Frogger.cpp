#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point{
	int x, y;
	double dist; //�N��q�_�I����o��minmax_dist 
};

double cal_dist(Point p1, Point p2){
	return pow( pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2), 0.5 );
}

int main(){
	int S = 0;
	int n;
	while(cin>>n && n){
		// input
		bool book[205] = {false};
		Point start_point;
		cin>>start_point.x>>start_point.y;
		start_point.dist = 0;
		
		n --;
		vector< Point > rocks;
		int x, y;
		while(n--){ 
			Point p;
			cin>>p.x>>p.y;
			p.dist = cal_dist(start_point, p);
			rocks.push_back(p); //rocks[0] = end_point
		}
		
		// Dijkstra
		for(int t=0;t<rocks.size();++t){
			// ��X�٨S��L�Bminmax_dist�̤p���I 
			double min_dist = 1e9;
			int idx;
			for(int i=0;i<rocks.size();++i){
				if(!book[i] && rocks[i].dist < min_dist){
					idx = i;
					min_dist = rocks[i].dist;
				}
			}
			book[idx] = true;
			//�p�G���ǥ��I(idx)�Y�u�u����(i)��minmax_dist�Z��
			for(int i=0;i<rocks.size();++i){
				if(rocks[idx].dist < rocks[i].dist &&
					cal_dist(rocks[idx], rocks[i]) < rocks[i].dist
				){
					rocks[i].dist = max(rocks[idx].dist, cal_dist(rocks[idx], rocks[i]));
				}
			}
		}
		
		//rocks[0] = end_point
		printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++S,  rocks[0].dist);
	}
	return 0;
}
