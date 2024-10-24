#include "Matrix.h"
#define _CRT_SECURE_NO_WARNINGS

Matrix::Matrix(int row_, int column_)
{
   row = row_;
   column = column_;

   matrix = new double* [row];
   for (int i = 0; i < row; i++)
      matrix[i] = new double[column];
   for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++)
         matrix[i][j] = 0;
}

Matrix::Matrix(const Matrix& other_)
{
   row = other_.row;
   column = other_.column;

   matrix = new double* [row];
   for (int i = 0; i < row; i++)
      matrix[i] = new double[column];
   for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++)
         matrix[i][j] = other_[i][j];
}

Matrix::~Matrix()
{
   for (int i = 0; i < row; i++)
      delete[] matrix[i];
   delete[] matrix;
}

Matrix Matrix::operator+(const Matrix& other_)
{
   if (row != other_.row || column != other_.column)
      throw 2;

   Matrix result(row, column);
   for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++)
         result[i][j] = matrix[i][j] + other_[i][j];

   return result;

}

Matrix Matrix::operator*(const Matrix& other_)
{
   if (row != other_.column || column != other_.row)
      throw 3;

   Matrix result(row, other_.column);

   for (int i = 0; i < result.row; i++)
      for (int j = 0; j < result.column; j++)
         for (int k = 0; k < result.row; k++)
            result[i][j] += matrix[i][k] * other_[k][j];

   return result;
}

Matrix Matrix::operator=(const Matrix& other_)
{
   if (row != other_.row || column != other_.column)
   {
      delete[] matrix;
      row = other_.row;
      column = other_.column;
      matrix = new double* [row];
      for (int i = 0; i < row; i++)
         matrix[i] = new double[column];
   }

   for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++)
         matrix[i][j] = other_[i][j];

   return *this;
}

double* Matrix::operator[](int index) const
{
   return matrix[index];
}

double* Matrix::operator[](int index)
{
   return matrix[index];
}

void Matrix::Set_Element(int row_, int column_, double value_)
{
   if ((row_ < 0 || row_ >= row) || (column_ < 0 || column_ >= column))
      throw 1;
   matrix[row_][column_] = value_;
}

double Matrix::Get_Element(int row_, int column_)
{
   if ((row_ < 0 || row_ >= row) || (column_ < 0 || column_ >= column))
      throw 1;
   return matrix[row_][column_];
}

int Matrix::Get_Row()
{
   return row;
}

int Matrix::Get_Column()
{
   return column;
}

void Matrix::Input_from_console()
{
   for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++)
         if (!scanf_s("%lf", &matrix[i][j])) return;
}

void Matrix::Print()
{
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < column; j++)
         printf("%lf ", matrix[i][j]);
      printf("\n");
   }
}

void Matrix::Transposition()
{
   Matrix temp(*this);
   
   delete[] matrix;
   row = temp.column;
   column = temp.row;

   matrix = new double* [row];
   for (int i = 0; i < row; i++)
      matrix[i] = new double[column];
   for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++)
         matrix[i][j] = temp[j][i];

}
