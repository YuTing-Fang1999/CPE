一直timeout==  
最後看答案才知道題目的重點其實是問有沒有cycle  
http://kos74185foracm.blogspot.com/2011/08/615-is-it-tree.html  
當集合大於2或是將同一個集合內的兩個點連起來(必然會形成cycle)就不是tree  
演算法作業好像有寫過  
https://github.com/YuTing-Fang1999/Algorithms-Java/tree/master/hw03_IslandCounting  

或是直接用DFS判斷  
https://timbian.wordpress.com/2015/03/21/uva-615-is-it-a-tree/  
tree 真的是我永遠的痛ಥ_ಥ  

### 解法
isNode[i] 判斷是不是node  
in[i]  判斷是不是root  
visited[i]  

如果是root->DFS or BFS->break;  
如果是node但沒被拜訪過 or visited超過一次-> not tree
