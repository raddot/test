#include<stdio.h>
#include<stdlib.h>

int **allocate(int row,int col)
{
	int i;
	int **mat;
	mat=(int **)malloc(sizeof(int *)*row);
	for(i=0;i<row;i++)
	{
		mat[i]=(int *)malloc(sizeof(int*)*col);
	}
	return mat;
}

void read(int mat1[][20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}
}

void display(int mat1[][20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",mat1[i][j]);
		}
		printf("\n");
	}
}

void read1(int **mat1,int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&*(*(mat1+i)+j));
		}
	}
}

void display1(int **mat1,int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",*(*(mat1+i)+j));
		}
		printf("\n");
	}
}

int addition(int **mat1,int **mat2,int row1,int col1,int **mat3)
{
	int i,j;
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			*(*(mat3+i)+j)=*(*(mat1+i)+j)+*(*(mat2+i)+j);
		}
	}
}

int subtraction(int **mat1,int **mat2,int row1,int col1,int **mat3)
{
	int i,j;
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			*(*(mat3+i)+j)=*(*(mat1+i)+j)-*(*(mat2+i)+j);
		}
	}
}

int transpose(int **mat1,int **mat3,int row1,int col1)
{
	int i,j;
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			*(*(mat3+j)+i)=*(*(mat1+i)+j);
		}
	}
}

int multiply(int mat1[][20],int mat2[][20],int row1,int col1,int row2,int mat3[][20])
{
	int i,j,k;
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			for(k=0;k<row2;k++)
			{
				mat3[i][j]+=mat1[i][k]*mat2[k][j];
			}
		}
	}
}

main()
{
	int **mat1,**mat2,**mat3;
	int matA[20][20],matB[20][20],matC[20][20];
	int ch,flag;
	int row1,col1,row2,col2,row3,col3;
	do
	{
		printf("\nenter the choice:");
		printf("\n1.accept matrix");
		printf("\n2.display matrix");
		printf("\n3.matrix addition");
		printf("\n4.matrix subtraction");
		printf("\n5.matrix transpose");
		printf("\n6.matrix multiplication");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				do
				{
					printf("\nenter the no of rows of mat1:");
					scanf("%d",&row1);
					printf("\nenter the no of columns of mat1:");
					scanf("%d",&col1);
				}while(row1<0 && col1<0);
				mat1=allocate(row1,col1);
				printf("\nenter the values:\n");
				read1(mat1,row1,col1);
				
				do
				{
					printf("\nenter the no of rows of mat2:");
					scanf("%d",&row2);
					printf("\nenter the no of columns of mat2:");
					scanf("%d",&col2);
				}while(row2<0 && col2<0);
				mat2=allocate(row2,col2);
				printf("\nenter the values:\n");
				read1(mat2,row2,col2);
				flag=1;
				break;
			case 2:
				if(flag==0)
				{
					printf("\naccept the matrix first");
				}
				else
				{
					printf("\nfirst matrix is:\n");
					display1(mat1,row1,col1);
					printf("\nsecond matrix is:\n");
					display1(mat2,row2,col2);
				}
				break;
			case 3:
				if(flag==0)
				{
					printf("accept the matrix first");
				}
				else
				{
					if(row1!=row2 && col1!=col2)
					{
						printf("rows and columns should be equal");
					}
					else
					{
						mat3=allocate(row1,col1);
						addition(mat1,mat2,row1,col1,mat3);
						display1(mat3,row1,col1);
					}
				}
				break;
			case 4:
				if(flag==0)
				{
					printf("accept the matrix first");
				}
				else
				{
					if(row1!=row2 && col1!=col2)
					{
						printf("rows and columns should be equal");
					}
					else
					{
						mat3=allocate(row1,col1);
						printf("the subtraction is:\n");
						subtraction(mat1,mat2,row1,col1,mat3);
						display1(mat3,row1,col1);
					}
				}
				break;
			case 5:
				if(flag==0)
				{
					printf("accept the matrix first");
				}
				else
				{
					printf("\nenter your choice:");
					printf("\n1.First Matrix");
					printf("\n2.Second Matrix");
					scanf("%d",&ch);
					if(ch==1)
					{
						mat3=allocate(row1,col1);
						printf("transpose of the matrix1 is:\n");
						transpose(mat1,mat3,row1,col1);
						display1(mat3,row1,col1);
					}
					else
					{
						mat3=allocate(row2,col2);
						printf("transpose of the matrix 2:");
						transpose(mat2,mat3,row2,col2);
						display1(mat3,row2,col2);
					}
				}
				break;
			case 6:
				printf("\nenter the no of row of mat1:");
				scanf("%d",&row1);
				printf("\nenter the no of column of mat1:");
				scanf("%d",&col1);
				mat1=allocate(row1,col1);
				printf("\nenter the values:");
				read(matA,row1,col1);
				printf("\nenter the no of row of mat2:");
				scanf("%d",&row2);
				printf("\nenter the no of column of mat2:");
				scanf("%d",&col2);
				mat2=allocate(row2,col2);
				printf("\nenter the value:");
				read(matB,row2,col2);
				printf("\nthe matrix 1 is");
				display(matA,row1,col1);
				printf("\nthe matrix 2 is:");
				display(matB,row2,col2);
				printf("\nenter the choice:");
				printf("\n1.A*B");
				printf("\n2.B*A");
				scanf("%d",&ch);
				if(ch==1)
				{
					if(col1!=row2)
					{
						printf("multiplication is not possible");
					}
					else
					{
						printf("\nthe multiplication is:\n");
						multiply(matA,matB,row1,col1,row2,matC);
						display(matC,row1,col2);
					}
				}
				else
				{
					if(col2!=row1)
					{
						printf("multiplication not possible");
					}
					else
					{
						printf("the multiplication is:\n");
						multiply(matB,matA,row2,col1,col2,matC);
						display(matC,row2,col1);
					}
				}
				break;
		}
		printf("\ndo u want to continue?(Y/N):");
		scanf("%c",&ch);
	}while(ch!='N' && ch!='n');
}	
