#include "8. RVLibStack.h";

using namespace std;

int main ()
{
   Stack s;
   s.create();

   for(int i = 0; i < 8; i++)
   {
       s.push(i * 2 + 1);
   }
   s.print();
   int out;
   bool a;
   for(int i = 0; i < 11; i++)
   {
       a = s.pop(& out);
       printf("%d ",out);
       printf("%d ",a);
       printf("\n");
   }


   return 0;
}
