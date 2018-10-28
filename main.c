#include<stdio.h>
#include "MyMalloc.h"
void* MyMalloc(int size);
void MyFree(void * adress);
int main()
{
    void* a=MyMalloc(100);
   void* a1=MyMalloc(14);
    void* a52=MyMalloc(40);
   void* a78=MyMalloc(90);

    printf("%d\n",a);
    void* a11=MyMalloc(10);

    printf("%d\n",a1);
    printf("%d\n",a52);
    printf("%d\n",a78);
    printf("%d\n",a11);
   MyFree(a1);


   void* a4=MyMalloc(14);

   printf("%d\n",a4);

    void* a5=MyMalloc(10);

   printf("%d\n",a5);
   void* a2=MyMalloc(5);

   void* a3=MyMalloc(90);
   printf("%d\n",a3);
    MyMalloc(24700);
    return 0;
}

