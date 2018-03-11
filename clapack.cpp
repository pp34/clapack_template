// clapack.cpp: 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <tchar.h>



// TODO: 在此处引用程序需要的其他头文件
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "levmar.h"

extern"C"
{
#include <f2c.h>
#include <clapack.h>
}

#define SIZE 4

int main()
{
 	char JOBU;
 	char JOBVT;
 
 	int i;
 
 	//数据类型integer是fortran里的。这里在C++下可以使用的原因是f2c.h文件中已经作了定义
 	integer M = SIZE;
 	integer N = SIZE;
 	integer LDA = M;
 	integer LDU = M;
 	integer LDVT = N;
 	integer LWORK;
 	integer INFO;
 
 	integer mn = min(M, N);
 
 	integer MN = max(M, N);
 
 	double a[SIZE*SIZE] = { 16.0, 5.0, 9.0 , 4.0, 2.0, 11.0, 7.0 , 14.0, 3.0, 10.0, 6.0, 15.0, 13.0, 8.0, 12.0, 1.0 };
 	double s[SIZE];
 	double wk[201];
 	double uu[SIZE*SIZE];
 	double vt[SIZE*SIZE];
 
 	JOBU = 'A';
 
 	JOBVT = 'A';
 
 	LWORK = 201;
 
 	/* Subroutine int dgesvd_(char *jobu, char *jobvt, integer *m, integer *n,
 	doublereal *a, integer *lda, doublereal *s, doublereal *u, integer *
 	ldu, doublereal *vt, integer *ldvt, doublereal *work, integer *lwork,
 	integer *info)
 	*/
 	dgesvd_(&JOBU, &JOBVT, &M, &N, a, &LDA, s, uu, &LDU, vt, &LDVT, wk, &LWORK, &INFO);
 
 	printf("INFO=%d \n", INFO);
 
 	for (i = 0; i< SIZE; i++) {
 		printf("s[ %d ] = %f\n", i, s[i]);
 	}
 
 	system("pause");



	return 0;
}

