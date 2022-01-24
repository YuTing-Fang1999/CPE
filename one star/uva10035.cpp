#include <iostream>
using namespace std;

int main()
{
   int n1, n2;
   while (cin >> n1 >> n2 && (n1 || n2))
   {
      int c = 0;
      int n = 0;
      while (n1 || n2)
      {
         if ((n1 % 10) + (n2 % 10) + c >= 10)
         {
            c = 1;
            ++n;
         }
         else
         {
            c = 0;
         }
         n1 /= 10;
         n2 /= 10;
      }
      if (n == 0)
         printf("No carry operation.\n");
      else if (n == 1)
         printf("1 carry operation.\n");
      else
         printf("%d carry operations.\n", n);
   }
   return 0;
}
