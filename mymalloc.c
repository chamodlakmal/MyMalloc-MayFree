#include<stdio.h>
char *array[25000];
char *index=array;
char deAllocate='f';
char Allocate='a';
void MyFree(void* ad);
char* find_block(int s);
void* MyMalloc(int size)
{
    if(size<=0)
    {
        return NULL;
    }

    if(!(*index))
    {
        *index= deAllocate;
        *(int *)(index+1)=24999-5;

    }
    int s=size;
    char* b=find_block(s);
    if(b)
    {
        if(*(int *)(b+1)>=size+5)
        {
            char* temp;
            int b_size=*(int *)(b+1);
            b_size=b_size-s-5;
            temp=b+s+5;
            *temp=deAllocate;
            *(int *)(temp+1)=b_size;
            *(int *)(b+1)=s;
            *b=Allocate;
        }
        else if(*(int *)(b+1)==size)
        {
            *b=Allocate;
        }
        else
        {
            return NULL;
        }
        return ((void*)b+5);
}
}

char* find_block(int s)
{
    char *m=index;
    int num=0;
    while(1){
        num=*(int *)(m+1);
        if(*m==deAllocate&&num>=s+5)
        {
            return (m);
        }
        else if(*m==deAllocate&&num==s)
        {
            return (m);
        }
        else if(m>index+24999)
        {
            return NULL;
        }
        else
        {
            if(m+num+s+5>=index+24999)
            {
                printf("Memory is Not Enough\n");
                return NULL;
            }
        }
        m=*(int *)m+num+5;
    }
    return (m);
}
void MyFree(void* ad)
{
    char* m=index,*next,*pre,*adress=(char *)(ad-5);

    while(m!=adress)
    {
        if(m>index+24999)
        {
            break;
        }
        else{
            pre=m;
            m=m+*(m+1)+5;
            next=*(int *)m+*(int *)(m+1)+5;
        }
    }
    if(*(adress+*(int *)(adress+1)+5)=='a'||*(adress+*(int *)(adress+1)+5)=='f')
                next=adress+*(int *)(adress+1)+5;

        if(m==adress)
        {
            *m=deAllocate;
        }
        if(m==adress&&*(next)=='f')
        {
            *m=deAllocate;
           *(int *)(m+1)=*(int *)(m+1)+*(int *)(next+1)+5 ;
        }
        if(m==adress&&*(pre)=='f')
        {
           *pre=deAllocate;
           *(int *)(pre+1)=*(int *)(m+1)+*(int *)(pre+1)+5 ;
        }

}
