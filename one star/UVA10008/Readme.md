#### 我的作法
```cpp
//先push到vector裡
for(int i=0;i<26;++i){
  if(t[i]!=0){
    Text text((char)'A'+i,t[i]);
    texts.push_back(text);
  }
}
//再用sort由大排到小
sort(texts.begin(),texts.end(),cmp);
for(int i=0;i<texts.size();++i){
  printf("%c %d\n",texts[i].c,texts[i].n);
}
```
#### 網路上的做法
```cpp
//在算次數時順便記住最大的次數
while((c = getchar())!='\n'){
  c = toupper(c);
  if('A'<=c && c<='Z') {
      t[c-'A']++;
      if(t[c-'A']>mx) mx=t[c-'A'];
    }
}
//最後從最大的次數開始print
for(int f=mx;f>0;--f){
  for(int i=0;i<26;++i){
    if(t[i]==f) printf("%c %d\n",(char)i+'A',f);
  }
}
```
