#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct stack
{
int data;
struct stack* next;

}st;

void push(st** top, int data)
{
    st* new = (st*)malloc(sizeof(st));
    
    new->data = data;
    new->next = *top;
    *top = new;
    
}

int peek(st* top)
{
    return top->data;
}

int empty(st* top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}
void pop(st** top)
{
    
        st* temp=*top;
        *top=(*top)->next;
        free(temp);
        temp=NULL;    
}

int getMaxArea(int* hist, int n)
{
   st* stk=NULL; 
   int i,max=INT_MIN;
   for(i=0;i<n;){
       if(empty(stk)){
           push(&stk,i);
           i++;
       }
       else if(hist[i]>=hist[peek(stk)]){
           push(&stk,i);
           i++;
       }
       else {
           int t=peek(stk);
           pop(&stk);
           int area;
           if(!empty(stk)){
               area=hist[t]*(i-peek(stk)-1);
           }
           if(empty(stk)){
               area=hist[t]*i;
           }
           if(area>max){
               max=area;
           }
       }
   }
   while(!empty(stk)){
        int t=peek(stk);
           pop(&stk);
           int area;
           if(!empty(stk)){
               area=hist[t]*(i-peek(stk)-1);
           }
           if(empty(stk)){
               area=hist[t]*i;
           }
           if(area>max){
               max=area;
           }
   }
   return max;
}


int main() {
   
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        
    }
    
    int r = getMaxArea(arr, n);
    printf("%d", r);
    return 0;
