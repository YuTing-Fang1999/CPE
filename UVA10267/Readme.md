這題應該只有F這個指令比較麻煩，其餘的照著題目做就好了  
```
//r 是region的顏色，c是要填入的顏色
void F(int i,int j, char r, char c){
	if(i<1 || j<1 || i>Row || j>Col || arr[i][j] != r) return;
	arr[i][j]=c;
	F(i-1, j, r, c);
	F(i+1, j, r, c);
	F(i, j-1, r, c);
	F(i, j+1, r, c);
}
```
### 注意
X,Y再陣列的順序是顛倒的 => arr[Y][X]  
Y1,Y2 / X1,X2 並沒有指定誰會比較大，要自己判斷  
```
if(Y>Y2) swap(Y,Y2);
if(X>X2) swap(X,X2);
```

### 一直WA
若要填滿的顏色與該點已經填上的顏色一樣時就不要填，不然會炸掉
```
if(arr[Y][X]!=C) F(Y,X,arr[Y][X],C);
```
以下是會讓程式炸掉的測資
```
I 5 1
H 3 4 1 Z 
F 4 1 Z
S one.bmp
X
```
#### 解釋
兩個Z會一直來回震盪，無窮迴圈(因為無法分辨是已填完顏色還是未填)
```
     ↑    ↑
OO ← Z ⇋ Z → O
     ↓    ↓ 
```
但zero judge還是一直記憶體區段錯誤，可能X與Y的範圍還要判斷有無超出陣列範圍吧

### zerojudge一直WA
原來是M、N的範圍改了==
