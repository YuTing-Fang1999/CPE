### 說明
給你一個sum of factor要你算出他原本的product  
如果這個sum of factor對應到多個product，輸出最大的  

這題真正的關鍵是我沒搞清楚sum of factor(因子和)的定義，所以想超久==  
### 定義
例:
12  
12的因子有`1, 2, 3, 4, 6, 12`    
因子和 = 1+2+3+4+6+12   

### 解法  
如果直接算很困難就用逆推的!   
先算出每個數字他的sum of factor   
之便利陣列找出他的index   
因為sum of factor一定比自己大，所以算到1000即可  


