# ifndef __FUCTIONS__
# define __FUCTIONS__

# define type int   //矩阵数据类型可修改

typedef struct {
    int row;
    int column;
    type** content;
} matrix ;

//为矩阵内容分配空间和回收
void initialMatr(matrix* a);
void freeMatr(matrix a);
//矩阵的输入输出
void scanMatr(matrix*a);
void printMatr(matrix a);   
//相乘条件判断及算法选取和引用
void efficientMulti(matrix input1,matrix input2,matrix*output);
//矩阵加减
void matrPlus(matrix input1,matrix input2,matrix*output);
void matrMinus(matrix input1,matrix input2,matrix*output);
//矩阵相乘
void normMulti(matrix input1,matrix input2,matrix*output);
void strassen(matrix input1,matrix input2,matrix*output);
void c_w(matrix input1, matrix input2,matrix*output);

# endif