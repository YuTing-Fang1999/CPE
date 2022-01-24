input
```
1234567891234567891
```
output
```
    1. 12 hajar 3 shata 45 kuti 67 lakh 89 hajar 1 shata 23 kuti 45 lakh 67 hajar 8 shata 91
```
### 注意
* case number要空4格
* 輸入為0就直接輸出0

#### 我的寫法
```cpp
#include <iostream>
using namespace std;

long long kuti,lakh,hajar,shata;
long long num;
int T=0;

//利用遞迴反轉輸出順序 
void bangla(long long num){
	kuti=num/10000000; num%=10000000;
	if(kuti>=100){
		bangla(kuti);
		kuti=kuti%100; 
		num%=10000000;
		printf(" kuti");
	}
	else if(kuti){
		printf(" %ld kuti",kuti);
	}
	lakh=num/100000; num%=100000;
	hajar=num/1000; num%=1000;
	shata=num/100; num%=100;
	
	if(lakh) printf(" %ld lakh",lakh);
	if(hajar) printf(" %ld hajar",hajar);
	if(shata) printf(" %ld shata",shata);
	if(num) printf(" %ld",num);
}
int main(){
	while(cin>>num){
		printf("%4d.",++T);
		if(num==0) printf(" 0");
		else bangla(num);
		printf("\n");
	}
	return 0;
}
```


#### 網路上的寫法  
一樣是用遞迴，但遞迴的層數比我還多，每print一次數字就遞迴一次  
運用遞迴的順序去記住print的順序  
當數字小於100時就print，之後才會往下print單位    
雖然比較不直觀，但這遞迴的用法我要好好學習一下  
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

void bangla(long long num) {
    if (num >= 10000000) {
        bangla(num / 10000000);
        cout << " kuti";
        num %= 10000000;
    }
    if (num >= 100000) {
        bangla(num / 100000);
        cout << " lakh";
        num %= 100000;
    }
    if (num >= 1000) {
        bangla(num / 1000);
        cout << " hajar";
        num %= 1000;
    }
    if (num >= 100) {
        bangla(num / 100);
        cout << " shata";
        num %= 100;
    }
    if (num)
        cout << " " << num;
}

int main() {
    long long num;
    long long countCase = 0;

    while (cin >> num) {
        cout << setw(4) << right << ++countCase << ".";
        if (num)
            bangla(num);
        else
            cout << " 0";
        cout << endl;
    }

    return 0;
}
```
