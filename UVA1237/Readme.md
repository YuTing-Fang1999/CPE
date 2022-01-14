### 因為有可能是以下case，所以就算是由小排到大還是必須要`myData[i].L>price`才能斷定有無重複
```
       price   
         |
------------
  ----   |
    -----------------------
         |
```
if(myData[i].L>price) break;
