# include <stdio.h>
# include "functions.h"
# include <stdlib.h>
//不需要手动初始化的智能加减


//相乘条件判断及算法选取和引用
void efficientMulti(matrix input1,matrix input2,matrix*output)
{
    if(input1.column!=input2.row)
        printf("Error:the two can't be multipled.");

    else
    {
        if(output->row==output->column)
            /*call an unwritten fuction*/;
        else
            normMulti(input1,input2,output);
    }
}