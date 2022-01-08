題目有個小陷阱，答案與回覆的行數可以不同   
難怪我一直想說為什麼兩個都要個別輸入行數，還有題目說PE要注意換行是什麼意思==  
反正就多標記換行的位置吧!  

測資
```
1
For example, there are 850 groups that have 80 to 99 clusters.
2
For example, there are 8
50 groups that have 80 to 99 clusters.
```
```
2
For example, 
there are 850 groups that have 80 to 99 clusters.
2
For example, there are 8
50 groups that have 80 to 99 clusters.
```
兩個合起來都會是For example, there are 850 groups that have 80 to 99 clusters.  
但以上要輸出的是Presentation Error  

### CPE的題目有修改過，跟UVA不同
