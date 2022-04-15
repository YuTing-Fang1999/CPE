找出最大子矩陣總和
![](https://i.imgur.com/KlKiTfW.jpg)
### Input

```
  0   -2   -7    0
  9    2   -6    2
 -4    1   -4    1
 -1    8    0   -2
```
### row_array
![](https://i.imgur.com/wW78ud8.png)

```
  0   -2   -9   -9
  9   11    5    7
 -4   -3   -7   -6
 -1    7    7    5
```
### 計算
![](https://i.imgur.com/hpjGAFp.png)

```cpp
#include <iostream>

using namespace std;

int main()
{
   int n;
   int arr[100][102];
   int row_arr[100][102];
   while (cin >> n)
   {
      for (int i = 0; i < n; ++i)
      {
         for (int j = 1; j <= n; ++j) //要從1開始輸入，否則第一個col永遠會被減掉
         {
            cin >> arr[i][j];
            row_arr[i][j] = row_arr[i][j - 1] + arr[i][j];
         }
      }

//      for (int i = 0; i < n; ++i)
//      {
//         for (int j = 0; j <= n; ++j)
//         {
//            cout << row_arr[i][j] << "  ";
//         }
//         cout << endl;
//      }

      int maxSum = 0, sum = 0;
      for (int j = 1; j < n; ++j)
      {
         for (int k = 0; k < j; ++k)
         {
            sum = 0;
            for (int i = 0; i < n; ++i)
            {

               sum += row_arr[i][j] - row_arr[i][k];
               if (sum > maxSum)
                  maxSum = sum;
               if (sum < 0)
                  sum = 0; //不然只會越加越小
               // printf("%d %d %d, sum=%d\n", j, k, i, sum);
            }
         }
      }
      cout << maxSum << endl;
   }

   return 0;
}
```
