### 說明
先算出整個圖的高，還有初始的y起點  
之後將y座標倒轉(h-y)  

### 有很多小細節須注意
高 = high-low(最高點-最低點)  
y起點 = -low  

如果第一行都沒東西的話就不要print(用endIdx==-1來判斷)  
如果後面沒東西的話也不要print(用endIdx==x來判斷)  

上升(R) 是先輸入後再更新座標  
下降(F) 是先更新座標再輸入  

### 標準解答的做法
https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/10800.php  
直接開兩倍的畫布，從中間開始畫，並且記錄上下邊界  
去掉空格的方法是從尾部開始填入'\0'，直到不再遇到空格(碰到尾端)  
之後再print row時用--i的方式倒轉y的輸出順序  
