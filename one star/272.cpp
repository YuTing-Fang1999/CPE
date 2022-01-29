#include <iostream>
using namespace std;

char c;
bool n=0;
int main(){
	//記得要加!=EOF，否則會TLE 
	while((c=getchar())!=EOF){
		if(c=='"'){
			n=!n;
			if(n) cout<<"``";
			else cout<<"''";
		}
		else cout<<c;
	}
	return 0;
}
