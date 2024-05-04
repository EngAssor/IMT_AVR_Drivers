

#include "STD_TYPES.h"
#include <stdio.h>
struct Array
{
    /* data */
    s32 data[16];
    u8 len;
    u8 size;
};
struct Array input={{'1','2',';','+','1',';','*','5',';','/','1','1',';','-','1',';'},15,16};
//struct Array input={{'1','*','2','+','5'},5,16};

struct Array op={{0},0,16}; // this hold operations during the pursing
struct Array expr={{0},0,16}; // this to save the expression after been converted
struct Array op1={{0},0,16}; // this hold operand
/*
S_push stand for stack push
this function doesn't retern anything and takes pointer to the struct that has the stack array
and the value
*/
void S_push(struct Array * A,s8 value)
{
    // make suer thta's the array isn't full
    if(A->len>=A->size)
    {
    }
    else
    {
        A->data[A->len++]=value;
    }
}

/*
S_pop stand for stack pop
this function  return the value that the array hold and takes pointer to the struct that has the stack array
*/
u8 S_pop(struct Array * A)
{
    u8 temp;
    // make sure that the array isn't empty
    if(A->len<=0)
    {
        temp= -1;
    }
    else
    {
        temp= A->data[--A->len];
    }
    return temp;
}

/*
-getpriority is a function that takes the opretion and retrun it's priority
*/
u8 getpriority(u8 opretion)
{
    u8 res ;
    switch (opretion)
    {
    case '*':
         res=1;
         break;
    case '/':
         res=1;
         break;
    case '+':
         res=0;
         break;
    case '-':
         res=0;
         break;
    default:
        res=-1;
        break;
    }
return res;
}
void infixtopostfix(struct Array * input,struct Array * op,struct Array *  expr )
{

    u8 priority;
    u8 operation,temp;
    for(u8 i=0;i<input->len;i++)
    {

        if((input->data[i] >='0' && input->data[i] <= '9') || input->data[i] == ';' )
        {

            S_push(expr,input->data[i]);
        }
        else
        {

           operation=input->data[i];
            priority=getpriority(operation);
            if(priority != -1)
            {

                if(op->len==0)
                {

                    S_push(op,input->data[i]);
                }
                else
                {
                    while( op->len && priority<=(getpriority(op->data[op->len-1])))
                    {
                        temp=S_pop(op);
                        S_push(expr,temp);
                    }                      
                    S_push(op,input->data[i]);
                   
                }
            }
        }
    }
      while (op->len !=0)
                        {
                            temp=S_pop(op);
                            S_push(expr,temp);
                        }

    S_push(expr,'=');

}
int stoi(char a[], int len) {
    int res = 0;
    int i = 0;
    int factor = 1; // Positional weight

    // Start from the least significant digit
    for (i = len - 1; i >= 0; i--) {
        // Check if the character is a digit
        if (a[i] >= '0' && a[i] <= '9') {
            // Convert the character to its integer value and add it to the result
            res += (a[i] - '0') * factor;
            // Update the positional weight for the next digit
            factor *= 10;
        }

    }
    return res;
}

struct Array get_operand(struct Array  * expression )
{
    struct Array oprand ={{0},0,16}; // this hold operand
    int i=0;


        while (expression->data[i]!= ';' && expression->data[i] >= '0' && expression->data[i]<='9')
    {
        /* code */
        oprand.data[i]=expression->data[i];
        oprand.len++;
        i++;
    }

    // shift the exprssion array left
    for(;i>=0;i--)
    {
        for(int j=i;j<expression->len;j++)
        {
            expression->data[j]=expression->data[j+1];
        }
        expression->len--;
    }
    return oprand;
}
char get_opration(struct Array  * expression)
{
    char opreation ='?';
    if(expression->data[0] == '*' || expression->data[0] == '-' || expression->data[0] == '+' || expression->data[0] == '/' )
        opreation = expression->data[0];

        return opreation;
}
struct Array StoIExpr(struct Array * expr)
{   
    struct Array S ;
    S.len=0;
    u8 oprand[10];
    u8 len=0;
    u8 i =0;
    s32 value=0;
    while(i<expr->len)
    {
        while (expr->data[i] != ';')
        {
           if(expr->data[i]>= '0' && expr->data[i] <= '9')
          {  
            oprand[len++]=expr->data[i++];   
            
          } 
          else
          {
            i++;
          }
        }
      value=stoi(oprand,len);
      len=0;
      i++;
      S_push(&S,value);

        
    }
    return S;
}
 float clc( struct Array * exp )
 {
    
    
 }
 int main(void)
 {
    infixtopostfix(&input,&op,&expr);
    expr=StoIExpr(&expr);
    for(int i=0;i<expr.len;i++)
    {
        printf("%c",expr.data[i]);
    }

    return 0;
 }

