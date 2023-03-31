// make a Structure of time having hours,mins,sec and write a function to add two times.
#include<stdio.h>

struct Time
{
    int hour,min,sec;
};

struct Time addTime(struct Time t1,struct Time t2)
{
    struct Time t3;
    t3.sec=t1.sec+t2.sec;
    t3.min=t1.min+t2.min;
    t3.hour=t1.hour+t2.hour;
    if(t3.sec>=60)
    {
        t3.sec=t3.sec-60;
        t3.min=t3.min+1;
    }
    if(t3.min>=60)
    {
        t3.min=t3.min-60;
        t3.hour=t3.hour+1;
    }
    return t3;
}

struct Time takeInput()
{
    struct Time t;
    printf("Enter the time in HH:MM:SS format: ");
    scanf("%d:%d:%d",&t.hour,&t.min,&t.sec);
    return t;
}

int main(){
    struct Time t1,t2,t3;
    t1=takeInput();
    t2=takeInput();
    t3=addTime(t1,t2);
    printf("The sum of the two times is: %d:%d:%d\n",t3.hour,t3.min,t3.sec);

}