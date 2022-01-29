#include <iostream>
using namespace std;

char c;
bool n=0;
int main(){
	//°O±o­n¥[!=EOF¡A§_«h·|TLE 
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
