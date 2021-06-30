#include "9. RVLibCalculation.h"

int Calculation(char* str);

using namespace std;

int main()
{
     //char str[] = "123-(2-3)*(10-5)";
     char str[] = "(1000+2^5)/8";
     //char str[] = "(4/2+1)";

     Calculation(str);

     return 0;
}

int Calculation(char* str)
{
     if(isBracketsCorrect(str))
     {
         TokenArr a;
         a.create();
         a.strToArr(str);
         a.toRPN();
         printf("%d", a.fromRPN());
     }
}
