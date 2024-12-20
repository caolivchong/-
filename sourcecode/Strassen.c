# include <stdio.h>
# include "functions.h"
# include <stdlib.h>
//假定输入矩阵为符合形式m*(2^k)的方阵
void strassen(matrix input1, matrix input2,matrix*output)
{
    //为减少每次递归时创建的矩阵数量，对矩阵进行了重复使用而降低了代码可读性
    int r = (input1.row)/2;
    //注释中标出了重用名
    //递归乘法中标号如下：I=P5*P6,II=P7*P3,III=P1*P8,IV=P2*P9,V=P10*P4,VI=P11*P12,VII=P13*P14
    matrix A11={r,r,NULL}/*P1,III*/,A12={r,r,NULL}/*P13*/,A21={r,r,NULL}/*P11,VII,C11*/,A22={r,r,NULL}/*P2,IV,C21*/;
    matrix B11={r,r,NULL}/*P3,II*/,B12={r,r,NULL}/*P12*/,B21={r,r,NULL},B22={r,r,NULL}/*P4,V,C12*/;
    matrix P5={r,r,NULL}/*I*/,P6={r,r,NULL}/*VI,C22*/,P7={r,r,NULL},P8={r,r,NULL},P9={r,r,NULL},P10={r,r,NULL};

    //分配空间
    initialMatr(&A11);
    initialMatr(&A12);
    initialMatr(&A21);
    initialMatr(&A22);
    initialMatr(&B11);
    initialMatr(&B12);
    initialMatr(&B21);
    initialMatr(&B22);
    initialMatr(&P5);
    initialMatr(&P6);
    initialMatr(&P7);
    initialMatr(&P8);
    initialMatr(&P9);
    initialMatr(&P10);

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

    //计算出七个矩阵乘法所需要相乘的14个矩阵（P1=A11，P2=A12，P3=A21，P4=A22）
    matrPlus(A11,A22,&P5);
    matrPlus(B11,B22,&P6);
    matrPlus(A21,A22,&P7);
    matrPlus(B12,B22,&P8);
    matrMinus(B21,B11,&P9);
    matrPlus(A11,A12,&P10);
    matrMinus(A21,A11,&A21);
    matrPlus(B11,B12,&B12);
    matrMinus(A12,A22,&A12);
    matrPlus(B21,B22,&B21);

    //计算七个乘法
    // if(r < 32){    //当阶数小于32时使用普通算法
    //     normMulti(P5,P6,&P5);
    //     normMulti(P7,B11,&B11);
    //     normMulti(A11,P8,&A11);
    //     normMulti(A22,P9,&A22);
    //     normMulti(B22,P10,&B22);
    //     normMulti(A21,B12,&P6);
    //     normMulti(A12,B21,&A21);
    // }else{
        strassen(P5,P6,&P5);//I
        strassen(P7,B11,&B11);//II
        strassen(A11,P8,&A11);//III
        strassen(A22,P9,&A22);//IV
        strassen(B22,P10,&B22);//V
        strassen(A21,B12,&P6);//VI
        strassen(A12,B21,&A21);//VII
    //}

    //相加减得到AB的四块
    //C11
    matrPlus(A21,P5,&A21);
    matrPlus(A21,A22,&A21);
    matrMinus(A21,B22,&A21);
    //C21
    matrPlus(A22,B11,&A22);
    //C12
    matrPlus(B22,A11,&B22);
    //c22
    matrPlus(P6,P5,&P6);
    matrPlus(P6,A11,&P6);
    matrMinus(P6,B11,&P6);

    //合块
    for(i=0;i<r;i++)
        for(j=0;j<r;j++){
            output->content[i][j] = A21.content[i][j];
            output->content[i][j+r] = B22.content[i][j];
            output->content[i+r][j] = A22.content[i][j];
            output->content[i+r][j+r] = P6.content[i][j];
        }

    //全部免费辣
    freeMatr(A11);
    freeMatr(A12);
    freeMatr(A21);
    freeMatr(A22);
    freeMatr(B11);
    freeMatr(B12);
    freeMatr(B21);
    freeMatr(B22);
    freeMatr(P5);
    freeMatr(P6);
    freeMatr(P7);
    freeMatr(P8);
    freeMatr(P9);
    freeMatr(P10);
    
}