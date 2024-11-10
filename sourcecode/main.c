# include <stdio.h>
# include "functions.h"
# include <time.h>
int main()
{
    int r;
    printf("Input the number of the row of matrix A:");
    scanf("%d",&r);

    matrix A = {r,r,NULL}, B = {r,r,NULL}, C1 = {r,r,NULL}, C2 = {r,r,NULL};
    initialMatr(&A);
    initialMatr(&B);
    initialMatr(&C1);
    initialMatr(&C2);
    
    scanMatr(&A);
    scanMatr(&B);

    clock_t start1,end1;
    double time_used1;
    start1 = time(NULL);
    strassen(A,B,&C1);
    end1 =time(NULL);
    time_used1 = difftime(end1,start1);

    clock_t start2,end2;
    double time_used2;
    start2 = time(NULL);
    normMulti(A,B,&C2);
    end2 =time(NULL);
    time_used2 = difftime(end2,start2);



    printf("strassen for %lf ms :",time_used1);
    printMatr(C1);
    printf("strassen for %lf ms :",time_used2);
    printMatr(C2);

    freeMatr(A);
    freeMatr(B);
    freeMatr(C1);
    freeMatr(C2);
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