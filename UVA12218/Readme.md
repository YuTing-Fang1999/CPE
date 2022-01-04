### 先建質數表，再使用二進位窮舉所有排列可能  

### 質數篩
```
memset(isPrime,true,sizeof(isPrime));
isPrime[0]=isPrime[1]=false;
for(int i=2;i<sqrt((float)N);++i){
  if(isPrime[i]){
    for(int j=i*i;j<N;j+=i){
      isPrime[j] = false;
    }
  }
}
```

### next_permutation
```
string str="abcd";
do{
  ...
}while(next_permutation(str.begin(),str.end()));
```
結果
```
abcd
abdc
acbd
acdb
adbc
adcb
bacd
badc
bcad
bcda <=如果str為"bcda"，那麼會從這裡開始列(個數為15)
bdac
bdca
cabd
cadb
cbad
cbda
cdab
cdba
dabc
dacb
dbac
dbca
dcab
dcba <=如果str為"dcba"，那麼會從這裡開始(個數為1)
24
```
因此在做之前要先sort由小排到大  
