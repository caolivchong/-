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
    
}