#include <iostream>
#include <vector> 
#include <sstream>
#include <cmath>
using namespace std;

int main(){
//	cout<<pow(32767, 0.5); //181.017
	bool table[190] = {0};
	vector< int > Prime;
	for(int i=2;i<190;++i){
		if(!table[i]) Prime.push_back(i);
		for(int j=i*i;j<190;j+=i){
			table[j] = true;
		}
	}
	string line;
	while(getline(cin, line) && line != "0"){
		stringstream ss(line);
		int n,p;
		int num = 1;
		//pow to base10
		while(ss>>n>>p){ 
			num *= pow(n, p);
		}
		--num;
		//base10 to pow
		int cnt = 0;
		for(int i=Prime.size()-1;i>=0;--i){
			if(num % Prime[i] == 0){
				if(cnt) printf(" ");
				printf("%d",Prime[i]);
				
				cnt = 0;
				while(num && num % Prime[i] == 0){
					cnt++;
					num /= Prime[i];
				}
				printf(" %d",cnt);
			}
		}
		printf("\n");
	}
	
	return 0;
}
