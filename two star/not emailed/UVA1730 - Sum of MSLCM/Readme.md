Can not use table (because the N is too big).  
We can find the regular pattern.  
For example, when N = 6,   

Maximum sum of set is all factor of i
```
1 -> (1)          
2 -> (1, 2)  
3 -> (1,    3)  
4 -> (1, 2,   4)  
5 -> (1,        5)
6 -> (1, 2, 3,    6)
```

The occerrence times of number is  
```
1 -> N//1 = 6        
2 -> N//2 = 3
3 -> N//3 = 2
4 -> N//4 = 1
5 -> N//5 = 1
6 -> N//6 = 1
```

The MSLSM[6] = `1*6 + 2*3 + 3*2 + 4*1 + 5*1 + 6*1 - 1`
