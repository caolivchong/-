/*我们还介绍了如何通过 SM3 和 S2M3 算法使用动态填充和动态剥离。
动态填充。对于解构阶段的每一轮，我们都会检查所考虑矩阵的维数。
如果矩阵已经有偶数行和列，我们不需要做任何事情，因为我们可以简单地将它分成四个块。
然而，如果行数或列数是奇数，即维度是奇数，我们添加额外的行或列（或两者，如果需要）。
对于 SM3 协议，我们将此行或列初始化为零；对于 S2M3 协议，我们将 Epk(1) 初始化为 0。
然后，我们照常执行协议。一旦我们将这两个矩阵相乘，我们就删除多余的行或列，并返回结果。
使用动态填充可以避免大量的内存分配。
事实上，静态填充将填充矩阵以获得等于 2 的幂的行数和列数。
动态剥离。与之前的方法相反，动态剥离方法将具有奇数维度d的方阵A（分别为B）分成四个块A1、A2、A3和A4（分别为B1、B2、B3和B4）。
块A1（分别B1）具有维度（d -1），矩阵A2（分别B2）具有维度（d -1）×1，矩阵A3（分别B3）具有维度1×（d -1），并且矩阵 A4（或 B4）的维度为 1。
图 5：矩阵 A 的动态剥离B 的维度为 d，其中 d 为奇数。
因此，对于 SM3 和 S2M3 协议解构阶段的每一轮（其中矩阵 A 和 B 具有奇数阶），reduce 函数根据动态剥离方法分割两个矩阵。
然后将获得的块A1和B1视为新的矩阵A和B，并按照所考虑的协议进行乘法。
其他块乘法使用块乘法算法计算并在组合阶段使用。*/

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