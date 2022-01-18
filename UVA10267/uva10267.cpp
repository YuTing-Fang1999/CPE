#include <iostream>
#include <string.h>
#include <string>
using namespace std;

char arr[256][256];
int Row,Col,X,Y,X2,Y2;
char cmd,C;
string name;

void setC(int x, int y, int xLen, int yLen, char C){	
	for(int i=y;i<=y+yLen;++i)
		for(int j=x;j<=x+xLen;++j){
			arr[i][j] = C;
		}
			
}

void F(int i,int j, char r, char c){
	if(i<1 || j<1 || i>Row || j>Col || arr[i][j] != r) return;
	arr[i][j]=c;
	F(i-1, j, r, c);
	F(i+1, j, r, c);
	F(i, j-1, r, c);
	F(i, j+1, r, c);
}
int main(){
	
	while(cin>>cmd){
		if(cmd=='I'){
			cin>>Col>>Row;
			memset(arr,'O',sizeof(arr));
		}
		else if(cmd=='C'){
			memset(arr,'O',sizeof(arr));
		}
		else if(cmd=='L'){
			cin>>X>>Y>>C;
			arr[Y][X]=C;
		}
		else if(cmd=='V'){
			cin>>X>>Y>>Y2>>C;
			setC(X,min(Y,Y2),0,abs(Y-Y2),C);
		}
		else if(cmd=='H'){
			cin>>X>>X2>>Y>>C;
			setC(min(X,X2),Y,abs(X-X2),0,C);
		}
		else if(cmd=='K'){
			cin>>X>>Y>>X2>>Y2>>C;
			setC(min(X,X2),min(Y,Y2),abs(X-X2),abs(Y-Y2),C);
		}
		else if(cmd=='F'){
			cin>>X>>Y>>C;
			if(arr[Y][X]!=C) F(Y,X,arr[Y][X],C);
		}
		else if(cmd=='S'){
			cin>>name;
			cout<<name<<endl;
			for(int i=1;i<=Row;++i){
				for(int j=1;j<=Col;++j){
					cout<<arr[i][j];
				}
				cout<<endl;
			}
		}
		else if(cmd=='X'){
			break;
		}
		else{
			cin.ignore(1024,'\n');
		}
	}
	return 0;
}
