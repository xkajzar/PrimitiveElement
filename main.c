#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long gcd(long long a, long long b) { return b==0 ? a : gcd(b, a%b); }

long long ipow(long long base, long long exp, long long input)
{
    long long result = 1;

    for (;;)
    {

        if (exp & 1){
            result = result * base;
            result = result % input;
        }
        exp >>= 1;
        if (!exp){
            break;
        }
        base = base * base;
        base = base % input;

    }

    return result;
}


int main()
{
    long long input, num, count = 0, result=0;
    long long i, j, k;
    char c='y';

    while(c!='n')
    {
    result=0;
    count=0;
    printf("enter a prime number\n");
    scanf("%d", &input);
    getchar();

    long long *checkarray;

    checkarray=(long long*)malloc(input*sizeof(long long));


    for(i=1; i<input; i++){

        for(k=0; k<input; k++){
            checkarray[k]=0;
        }


        for(j=1; j<input; j++){
            if(checkarray[(ipow(i, j, input))%input]==0){

               // printf("%d ", j);

                checkarray[(ipow(i, j, input))%input]=1;
                if(j==input-1)
                {
                    result = i;
                    i=input;
                }
            }
            else{
             //   printf("mistake %d", j);
                j=input;
            }

        }


    }
    int size=0;
    j=0;
    if(result==0){
     printf("Not a prime number\n");

    }
    else{
    for (i=1; i<input; i++){
        if(gcd(i, input-1)==1){
            checkarray[j++]=i;
            size++;
            count++;
        }

    }
    for(i=0; i<size; i++){
        printf("%d, ", ipow(result, checkarray[i], input));
    }

    }


  /*  if(count==0){
        printf("not found\n");
    }*/
    printf("\n count: %d", count);


    printf("\n continue: y/n");
    c=getchar();
    getchar();
    }
    return 0;
}

