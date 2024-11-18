/*
1.
#include <stdio.h>

int main()
{
    int a = 97;
    int *ptr = &a;
    printf("The address of a is %u.\n", ptr);
    printf("The value of variable a is %d.\n",  *ptr);
    return 0;
}
*/

/*
2.
#include<stdio.h>
int pointer(int i);

int main(){
    int i = 97;
    int *ptr = &i;
    printf("The value of i = %d.\n", i);
    printf("The address of i = %u.\n", ptr);
    pointer(i);
    return 0;
}

int pointer(int i){
    printf("The value of i = %d.\n", i);
    printf("The address of i = %u.\n", &i);
    return 0;
}
*/

/*
3.
#include<stdio.h>
int pointer(int *a);

int main(){
    int a;
    printf("Enter the value of a: \n");
    scanf("%d", &a);
    pointer(&a);
    return 0;
}

int pointer(int *a){
    int num;
    num = 10 * *a;
    printf("The new value of a will be %d.\n", num);
    return 0;
}
*/

/*
4.
#include<stdio.h>
int sumavg(int a,int b,int *sum,float *average);

int main(){
    int a,b,sum;
    float average;
    printf("Enter the value of a and b: \n");
    scanf("%d%d", &a,&b);
    sumavg(a,b,&sum,&average);
    printf("The sum and average of %d and %d will be %d and %.1f.\n",a,b,sum,average);
    return 0;
}

int sumavg(int a,int b,int *sum,float *average){
    *sum = a + b;
    *average = (float)(*sum)/2;
    return 0;
}
*/

/*
5.
#include<stdio.h>

int main(){
    int i = 97;
    int *ptr = &i;
    int **ptrr = &ptr;
    
    printf("The value of i = %d.\n", **ptrr);
    return 0;
}
*/

/*
6.
#include<stdio.h>
int wrong_pointer(int a);
void pointer(int *a);
int main(){
    int a;
    printf("Enter the value of a: \n");
    scanf("%d", &a);
    wrong_pointer(a);
    printf("Value of after the execution of this programme is %d.\n", a);
    return 0;
}
void pointer(int *a){
    *a *= 10;
}
int wrong_pointer(int a){
    a *= 10;
    return a;
}
*/
