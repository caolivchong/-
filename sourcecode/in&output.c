# include <stdio.h>
# include "functions.h"
# include <stdlib.h>
//终端输入
void scanMatr(matrix*a)
{
    printf("Please input the content of the matrix one by one:\n");
    int i,j;
    for(i=0;i<a->row;i++)
        for(j=0;j<a->column;j++)
            scanf("%d",&a->content[i][j]);
}
void printMatr(matrix a)
{
    int i,j;
    for(i=0;i<a.row;i++){
        for(j=0;j<a.column;j++)
            printf("%-4d",a.content[i][j]);
        printf("\n");
    }
}
//文件输入
