#include <iostream>
#include <string>
using namespace std;

int main(){
	int now,high,low;
	string str;
	while(cin>> now && now){
		//boundary
		high = 10;
		low = 1;
		getline(cin,str); //del \n
		while(getline(cin,str)){
			if(str == "too high") high = min(high,now-1);
			if(str == "too low") low = max(low,now+1);
			if(str == "right on"){
				if(low<=now && now<=high)
					cout<<"Stan may be honest"<<endl;
				else cout<<"Stan is dishonest"<<endl;
				break;
			}
			cin>>now;
			getline(cin,str);
		}	
	}
	
	return 0;
}
		
