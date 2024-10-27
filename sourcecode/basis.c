# include <stdio.h>
# include "functions.h"
# include <stdlib.h>

//为矩阵内容分配空间和回收
void initialMatr(matrix* a)
{
    int i;
    a->content=(type**)malloc((a->row)*sizeof(type*));
    for(i=0;i<a->row;i++)
        a->content[i]=(type*)malloc((a->column)*sizeof(type));
}
void freeMatr(matrix a)
{
    int i;
    for(i=0;i<a.row;i++)
        free(a.content[i]);
    free(a.content);
}

//矩阵加减
void matrPlus(matrix input1,matrix input2,matrix*output)
{
        int i,j;
        for(i=0;i<output->row;i++)
            for(j=0;j<output->column;j++)
                output->content[i][j] = input1.content[i][j]+input2.content[i][j];
}
void matrMinus(matrix input1,matrix input2,matrix*output)
{
        int i,j;
        for(i=0;i<output->row;i++)
            for(j=0;j<output->column;j++)
                output->content[i][j] = input1.content[i][j]-input2.content[i][j];
}
//转置inversion

//普通相乘
void normMulti(matrix input1, matrix input2, matrix*output)
{
    int i,j,k;
    for(i=0;i<output->row;i++)
        for(j=0;j<output->column;j++){
            output->content[i][j]=0;
            for(k=0;k<input1.column;k++)
                output->content[i][j]+=input1.content[i][k]*input2.content[k][j];
    }
}