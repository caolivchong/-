# include <stdio.h>
# include "functions.h"
# include <stdlib.h>
//假定输入矩阵为符合形式m*(2^k)的方阵
void c_w(matrix input1, matrix input2,matrix*output)
{
    //为减少每次递归时创建的矩阵数量，对矩阵进行了重复使用而降低了代码可读性
    int r = (input1.row)/2;
    matrix A11={r,r,NULL},A12={r,r,NULL},A21={r,r,NULL},A22={r,r,NULL};
    matrix B11={r,r,NULL},B12={r,r,NULL},B21={r,r,NULL},B22={r,r,NULL};
    matrix S1={r,r,NULL},S2={r,r,NULL},/*S3=A21*/S4={r,r,NULL},/*T1=B12*/T2={r,r,NULL},T3={r,r,NULL},T4={r,r,NULL};

    //分配空间
    initialMatr(&A11);
    initialMatr(&A12);
    initialMatr(&A21);
    initialMatr(&A22);
    initialMatr(&B11);
    initialMatr(&B12);
    initialMatr(&B21);
    initialMatr(&B22);
    initialMatr(&S1);
    initialMatr(&S2);
    initialMatr(&S4);
    initialMatr(&T2);
    initialMatr(&T3);
    initialMatr(&T4);

    //分块
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<r;j++){
            A11.content[i][j] = input1.content[i][j];
            A12.content[i][j] = input1.content[i][j+r];
            A21.content[i][j] = input1.content[i+r][j];
            A22.content[i][j] = input1.content[i+r][j+r];

            B11.content[i][j] = input2.content[i][j];
            B12.content[i][j] = input2.content[i][j+r];
            B21.content[i][j] = input2.content[i+r][j];
            B22.content[i][j] = input2.content[i+r][j+r];
        }
    
    //八个加减
    matrPlus(A21,A22,&S1);
    matrMinus(S1,A11,&S2);
    matrMinus(A11,A21,&A21);//S3
    matrMinus(A12,S2,&S4);
    matrMinus(B12,B11,&B12);//T1
    matrMinus(B22,B12,&T2);
    matrMinus(B22,B12,&T3);
    matrMinus(T2,B21,&T4);

    //计算七个乘法
    // if(r < 32){    //当阶数小于32时使用普通算法
    //     normMulti(A11,B11,&A11);//R1
    //         freeMatr(B11);
    //     normMulti(A12,B21,&A12);//R2
    //         freeMatr(B21);
    //     normMulti(S4,B22,&S4);//R3
    //         freeMatr(B22);
    //     normMulti(A22,T4,&T4);//R4
    //         freeMatr(A22);
    //     normMulti(S1,B12,&S1);//R5
    //         freeMatr(B12);
    //     normMulti(S2,T2,&S2);//R6
    //         freeMatr(T2);
    //     normMulti(A21,T3,&T3);//R7
    // }else{
        c_w(A11,B11,&A11);
            freeMatr(B11);
        c_w(A12,B21,&A12);
            freeMatr(B21);
        c_w(S4,B22,&S4);
            freeMatr(B22);
        c_w(A22,T4,&T4);
            freeMatr(A22);
        c_w(S1,B12,&S1);
            freeMatr(B12);
        c_w(S2,T2,&S2);
            freeMatr(T2);
        c_w(A21,T3,&T3);
    //}
    
    //7步相加减得到AB的四块
    matrPlus(A11,A12,&A12);//C1
    matrPlus(A11,S2,&A11);//C2
    matrPlus(A11,T3,&T3);//C3
    matrPlus(A11,S1,&A11);//C4
    matrPlus(A11,S4,&A11);//C5
    matrMinus(T3,T4,&T4);//C6
    matrPlus(T3,S1,&T3);//C7

    //合块
    for(i=0;i<r;i++)
        for(j=0;j<r;j++){
            output->content[i][j] = A12.content[i][j];
            output->content[i][j+r] = A11.content[i][j];
            output->content[i+r][j] = T4.content[i][j];
            output->content[i+r][j+r] = T3.content[i][j];
        }
    
    //释放空间
    freeMatr(A11);
    freeMatr(A12);
    freeMatr(A21);
    freeMatr(S1);
    freeMatr(S2);
    freeMatr(S4);
    freeMatr(T3);
    freeMatr(T4);

}