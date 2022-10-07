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

But the N is too big, it still will be TLE.   
The occerrence times of number is same in interval.  
Calculate the same occerrence times of number together.    
The MSLSM[6] = `1*6 + 2*3 + 3*2 + (4+5+6)*1 - 1`   

`Occurrences times of L ~ R is T` (L ~ R 出現的次數皆為 T)    
T = N//L `Occerrence times of L` (L出現的次數)    
R = N//T `Number repeated T times and closest to N` (重複T次且最接近N的數)   

init L=0, R=0
```
L=R+1 (L=1)
times = N/L = 6
R = N/times = 1
Occurrences times of 1 ~ 1 is 6
```

```
L=R+1 (L=2)
times = N/L = 3
R = N/times = 2
Occurrences times of 2 ~ 2 is 3
```

```
L=R+1 (L=3)
times = N/L = 2
R = N/times = 3
Occurrences times of 3 ~ 3 is 6
```

```
L=R+1 (L=4)
times = N/L = 1
R = N/times = 6
Occurrences times of 4 ~ 6 is 1
```

```
L=R+1 (L=7)
L>N: break
```
