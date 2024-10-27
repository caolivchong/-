# include <stdio.h>
# include "functions.h"
# include <time.h>
int main()
{
    int r,c;
    printf("Input the number of the row of matrix A:");
    scanf("%d",&r);
    printf("Input the number of the column of matrix A:");
    scanf("%d",&c);

    matrix A={r,c,NULL};
    initialMatr(&A);
    scanMatr(&A);





    printMatr(A);
    freeMatr(A);
    return 0;
}

/*
    clock_t start,end;
    double time_used;

    start = time(NULL);
    //
    end =time(NULL);

    time_used = difftime(end,start);

*/


/*
    


*/