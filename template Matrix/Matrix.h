#pragma once
#include <iostream>
#include "Exсeption.h"
#include <math.h>
#include "Vector.h"
using namespace std;

template<typename T>
class Matrix
{
protected:
   int row;
   int column;

   T** matrix;

public:


   Matrix(int row_ = 2, int column_ = 3)
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

   Matrix(const Matrix<T>& other_)
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

   virtual ~Matrix()
   {
      for (int i = 0; i < row; i++)
         delete[] matrix[i];
      delete[] matrix;
   }

   Matrix<T> operator+(const Matrix<T>& other_) const
   {
      if (row != other_.row || column != other_.column)
         throw SizeAreNotSame();

      Matrix<T> result(row, column);
      for (int i = 0; i < row; i++)
         for (int j = 0; j < column; j++)
            result[i][j] = matrix[i][j] + other_[i][j];

      return result;

   }

   Matrix<T>& operator+=(const Matrix<T>& other_)
   {
      if (row != other_.row || column != other_.column)
         throw SizeAreNotSame();

      for (int i = 0; i < row; i++)
         for (int j = 0; j < column; j++)
            matrix[i][j] += other_[i][j];

      return *this;
   }

   Matrix<T> operator-(const Matrix<T>& other_) const
   {
      if (row != other_.row || column != other_.column)
         throw SizeAreNotSame();

      Matrix<T> result(row, column);
      for (int i = 0; i < row; i++)
         for (int j = 0; j < column; j++)
            result[i][j] = matrix[i][j] - other_[i][j];

      return result;
   }

   Matrix<T>& operator-=(const Matrix<T>& other_)
   {
      if (row != other_.row || column != other_.column)
         throw SizeAreNotSame();

      for (int i = 0; i < row; i++)
         for (int j = 0; j < column; j++)
            matrix[i][j] -= other_[i][j];

      return *this;
   }

   Matrix<T> operator*(const Matrix<T>& other_) const
   {
      if (row != other_.column || column != other_.row)
         throw WrongRowsColumns();

      Matrix<T> result(row, other_.column);

      for (int i = 0; i < result.row; i++)
         for (int j = 0; j < result.column; j++)
            for (int k = 0; k < column; k++)
               result[i][j] += matrix[i][k] * other_[k][j];

      return result;
   }

   Matrix<T>& operator*=(const Matrix<T>& other_)
   {
      if (row != other_.column || column != other_.row)
         throw WrongRowsColumns();

      Matrix<T> result(row, other_.column);

      for (int i = 0; i < result.row; i++)
         for (int j = 0; j < result.column; j++)
            for (int k = 0; k < column; k++)
               result[i][j] += matrix[i][k] * other_[k][j];

      (*this) = result;

      return *this;
   }

   Matrix<T> operator*(const T& number_) const
   {
      Matrix<T> temp(*this);

      for (int i = 0; i < row; i++)
         for (int j = 0; j < column; j++)
            temp[i][j] = number_ * temp[i][j];

      return temp;
   }

   Matrix<T>& operator*=(const T& number_)
   {
      for (int i = 0; i < row; i++)
         for (int j = 0; j < column; j++)
            matrix[i][j] = number_ * matrix[i][j];

      return *this;
   }

   Matrix<T>& operator=(const Matrix<T>& other_)
   {
      if (this == &other_)
         return *this;

      if (row != other_.row || column != other_.column)
      {
         delete[] matrix;
         row = other_.row;
         column = other_.column;
         matrix = new T * [row];
         for (int i = 0; i < row; i++)
            matrix[i] = new T[column];
      }

      for (int i = 0; i < row; i++)
         for (int j = 0; j < column; j++)
            matrix[i][j] = other_[i][j];

      return *this;
   }

   Matrix<T>& operator^(int n_)
   {
      throw WrongNotSquare();
   }

   bool operator==(const Matrix<T>& other_) const
   {
      return ((row == other_.row) && (column == other_.column));
   }

   bool operator!=(const Matrix<T>& other_) const
   {
      return ((row != other_.row) && (column != other_.column));
   }

   T* operator[](int index) const
   {
      return matrix[index];
   }

   T* operator[](int index)
   {
      return matrix[index];
   }

   friend ostream& operator<<(ostream& stream, const Matrix<T>& matrix)
   {
      for (int i = 0; i < matrix.row; i++)
      {
         for (int j = 0; j < matrix.column; j++)
            stream << matrix[i][j] << ' ';
         stream << endl;
      }
      stream << endl;
      return stream;
   }

   friend istream& operator>>(istream& stream, Matrix<T>& matrix)
   {
      for (int i = 0; i < matrix.row; i++)
      {
         for (int j = 0; j < matrix.column; j++)
            stream >> matrix[i][j];
      }
      return stream;
   }

   void Set_Element(int row_, int column_, T value_)
   {
      if ((row_ < 0 || row_ >= row) || (column_ < 0 || column_ >= column))
         throw OutOfRange();
      matrix[row_][column_] = value_;
   }
   
   T Get_Element(int row_, int column_) const
   {
      if ((row_ < 0 || row_ >= row) || (column_ < 0 || column_ >= column))
         throw OutOfRange();
      return matrix[row_][column_];
   }

   int Get_Row() const
   {
      return row;
   }

   int Get_Column() const
   {
      return column;
   }

   Matrix<T>& Input_from_Console()
   {
      for (int i = 0; i < row; i++)
         for (int j = 0; j < column; j++)
            if (!scanf_s("%lf", &matrix[i][j])) throw WrongData();

      return *this;
   }

   Matrix<T>& Print()
   {
      for (int i = 0; i < row; i++)
      {
         for (int j = 0; j < column; j++)
            printf("%lf ", matrix[i][j]);
         printf("\n");
      }
      std::cout << '\n';

      return *this;
   }

   virtual Matrix<T>& Transposition()
   {
      Matrix<T> temp(*this);

      delete[] matrix;
      row = temp.column;
      column = temp.row;

      matrix = new double* [row];
      for (int i = 0; i < row; i++)
         matrix[i] = new double[column];
      for (int i = 0; i < row; i++)
         for (int j = 0; j < column; j++)
            matrix[i][j] = temp[j][i];

      return *this;
   }

   Matrix<T> Inverse_Matrix()
   {
      throw WrongNotSquare();
   }


   virtual T Determinant_Matrix()
   {
      throw WrongNotSquare();
   }

   virtual T Minor_Matrix(int i, int j)
   {
      throw WrongNotSquare();
   }

   Matrix<T> Pow(int n_)
   {
      throw WrongNotSquare();
   }

   //friend Matrix* Add_Array_Matrix(Matrix*& array_matrix_, size_t& size_, size_t capasity_, Matrix& matrix_);

   

};

template<typename T>
class Square_Matrix : public Matrix<T>
{
   using Matrix<T>::matrix;
   using Matrix<T>::row;
   using Matrix<T>::column;

public:
   Square_Matrix<T>(int order_ = 2) : Matrix<T>(order_, order_) { ; }

   Square_Matrix<T>(const Square_Matrix<T>& other_) : Matrix<T>(other_) { ; }

   Square_Matrix operator+(const Square_Matrix& other_) const
   {
      if (row != other_.row)
         throw SizeAreNotSame();

      Square_Matrix<T> result(row);
      for (int i = 0; i < row; i++)
         for (int j = 0; j < row; j++)
            result[i][j] = matrix[i][j] + other_[i][j];

      return result;
   }

   Square_Matrix& operator+=(const Square_Matrix& other_)
   {
      if (row != other_.row)
         throw SizeAreNotSame();

      for (int i = 0; i < row; i++)
         for (int j = 0; j < row; j++)
            matrix[i][j] += other_[i][j];

      return *this;
   }

   Square_Matrix operator-(const Square_Matrix& other_) const
   {
      if (row != other_.row)
         throw SizeAreNotSame();

      Square_Matrix<T> result(row);
      for (int i = 0; i < row; i++)
         for (int j = 0; j < row; j++)
            result[i][j] = matrix[i][j] - other_[i][j];

      return result;
   }

   Square_Matrix& operator-=(const Square_Matrix& other_)
   {
      if (row != other_.row)
         throw SizeAreNotSame();

      for (int i = 0; i < row; i++)
         for (int j = 0; j < row; j++)
            matrix[i][j] -= other_[i][j];

      return *this;
   }

   Square_Matrix& operator=(const Square_Matrix& other_)
   {
      if (this == &other_)
         return *this;

      if (row != other_.row)
      {
         delete[] matrix;
         row = other_.row;
         column = other_.row;
         matrix = new double* [row];
         for (int i = 0; i < row; i++)
            matrix[i] = new double[row];
      }

      for (int i = 0; i < row; i++)
         for (int j = 0; j < row; j++)
            matrix[i][j] = other_[i][j];

      return *this;
   }


   Square_Matrix& operator=(const Matrix<T>& other_)
   {
      if (this == &other_)
         return *this;
      if (other_.Get_Row() != other_.Get_Column())
         throw WrongNotSquare();

      if (row != other_.Get_Row() || column != other_.Get_Column())
      {
         delete[] matrix;
         row = other_.Get_Row();
         column = other_.Get_Row();
         matrix = new double* [row];
         for (int i = 0; i < row; i++)
            matrix[i] = new double[column];
      }

      for (int i = 0; i < row; i++)
         for (int j = 0; j < column; j++)
            matrix[i][j] = other_[i][j];

      return *this;
   }

   Square_Matrix operator*(const Square_Matrix& other_) const
   {
      if (row != other_.row)
         throw WrongRowsColumns();

      Square_Matrix<T> result(row);

      for (int i = 0; i < row; i++)
         for (int j = 0; j < row; j++)
            for (int k = 0; k < row; k++)
               result[i][j] += matrix[i][k] * other_[k][j];

      return result;
   }

   Square_Matrix& operator*=(const Square_Matrix& other_)
   {
      if (row != other_.row)
         throw WrongRowsColumns();

      Square_Matrix<T> result(row);

      for (int i = 0; i < row; i++)
         for (int j = 0; j < row; j++)
            for (int k = 0; k < row; k++)
               result[i][j] += matrix[i][k] * other_[k][j];

      (*this) = result;

      return *this;
   }

   Square_Matrix operator*(const T& number_) const
   {
      Square_Matrix<T> temp(*this);

      for (int i = 0; i < row; i++)
         for (int j = 0; j < row; j++)
            temp[i][j] = number_ * temp[i][j];

      return temp;
   }

   Square_Matrix& operator*=(const T& number_)
   {
      for (int i = 0; i < row; i++)
         for (int j = 0; j < row; j++)
            matrix[i][j] *= number_;

      return *this;
   }

   Square_Matrix operator^(int n_)
   {
      if (n_ < 0) throw WrongData();//Заменить на деление

      Square_Matrix temp(row);
      for (int i = 0; i < row; i++)
         temp.matrix[i][i] = 1;

      for (int i = 1; i <= n_; i++)
         temp = temp * (*this);

      return temp;
   }

   bool operator==(const Square_Matrix& other_) const
   {
      return (row == other_.row);
   }

   bool operator!=(const Square_Matrix& other_) const
   {
      return (row != other_.row);
   }

   T* operator[](int index) const
   {
      return matrix[index];
   }

   T* operator[](int index)
   {
      return matrix[index];
   }

   friend ostream& operator<<(ostream& stream, const Square_Matrix& matrix)
   {
      for (int i = 0; i < matrix.row; i++)
      {
         for (int j = 0; j < matrix.row; j++)
            stream << matrix[i][j] << ' ';
         stream << endl;
      }
      stream << endl;
      return stream;
   }


   friend istream& operator>>(istream& stream, Square_Matrix& matrix)
   {
      for (int i = 0; i < matrix.row; i++)
      {
         for (int j = 0; j < matrix.row; j++)
            stream >> matrix[i][j];
      }
      return stream;
   }

   Matrix<T> Inverse_Matrix()
   {
      Square_Matrix<T> temp((*this).Transposition());

      temp = temp * (1.0 / (*this).Determinant_Matrix());

      return (Matrix<T>)temp;
   }

   double Determinant_Matrix()
   {
      double determinant = 0;

      if (row == 1)
         return matrix[0][0];

      Square_Matrix<T> temp_matrix(row - 1);

      for (int i = 0; i < row; i++)
      {
         int vt = 0;
         for (int v = 1; v < row; v++)
         {
            int wt = 0;
            for (int w = (wt == i) ? (1) : (0); w < row; (wt == i) ? (w = w + 2) : (w++))
            {
               temp_matrix[vt][wt] = matrix[v][w];
               wt++;
            }
            vt++;
         }
         determinant += ((i % 2 ? -1 : 1) * matrix[0][i]) * temp_matrix.Determinant_Matrix();
      }


      return determinant;
   }

   double Minor_Matrix(int i, int j)
   {

      Square_Matrix<T> temp_matrix(row - 1);

      int vt = 0;
      for (int v = (vt == i) ? (1) : (0); v < row; (vt == i) ? (v = v + 2) : (v++))
      {
         int wt = 0;
         for (int w = (wt == i) ? (1) : (0); w < row; (wt == i) ? (w = w + 2) : (w++))
         {
            temp_matrix[vt][wt] = matrix[v][w];
            wt++;
         }
         vt++;
      }

      return temp_matrix.Determinant_Matrix();
   }

   // double Algebraic_Complement_Matrix();

   Matrix<T> Pow(int n_)
   {
      if (n_ < 0) throw WrongData();//Заменить на деление

      Square_Matrix<T> temp(row);
      for (int i = 0; i < row; i++)
         temp.matrix[i][i] = 1;

      for (int i = 1; i <= n_; i++)
         temp = temp * (*this);


      return (Matrix<T>)temp;
   }

   Square_Matrix<T>& Transposition()
   {
      double temp;

      for (int i = 0; i < row; i++)
         for (int j = 0; j < i; j++)
         {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
         }

      return *this;
   }

   //friend Matrix* Add_Array_Matrix(Matrix*& array_matrix_, size_t& size_, size_t& capasity_, Square_Matrix& matrix_);

   Vector Trace(int level)
   {
      Square_Matrix<T> copy(*this);
      Vector result;

      for (int l = 1; l < level;)
      {
         for (int i = 0; i < row; i++)
            result[l] += copy[i][i];

         copy.Pow(++l);
      }

      return result;
   }
};



