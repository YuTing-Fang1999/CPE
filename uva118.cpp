#include <iostream>
#include <string>
using namespace std;

int main(){
	bool lost[55][55]={0};
	int dx, dy; cin>>dx>>dy;
	
	int x,y,newX,newY,dir;
	string dirStr;
	char cmd;
	int xChange[] = {0,1,0,-1}; //N,E,S,W
	int yChange[] = {1,0,-1,0};
	char dirChange[] = {'N','E','S','W'};
	while(cin>>x>>y>>dirStr)
	{
		bool isLost = false;
		if(dirStr == "N") dir = 0;
		else if(dirStr == "E") dir = 1;
		else if(dirStr == "S") dir = 2;
		else if(dirStr == "W") dir = 3;
		
		getchar();//del '\n'
		while((cmd=getchar())!= '\n'){
			//cout<<cmd<<endl;
			newX=x, newY=y;
			if(cmd == 'L') dir = (dir+3)%4;
			else if(cmd == 'R') dir = (dir+1)%4;
			else if(cmd == 'F'){
				newX += xChange[dir]; 
				newY += yChange[dir]; 
			}
			
			if(( newX<0 || newX>dx || newY<0 || newY>dy)){
			 	if(lost[x][y]) continue;
				isLost = true;
				lost[x][y] = true;
				while((cmd=getchar())!= '\n'){};
				break;
			}
			x=newX; y=newY;
		}
		printf("%d %d %c",x,y,dirChange[dir]);
		if(isLost) printf(" LOST\n");
		else printf("\n");
	}
	return 0;
}
