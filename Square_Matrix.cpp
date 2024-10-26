#include "Square_Matrix.h"

Square_Matrix::Square_Matrix(int order_) : Matrix(order_, order_) { ; }

Square_Matrix::Square_Matrix(const Square_Matrix& other_) : Matrix(other_) { ; }

Matrix& Square_Matrix::Inverse_Matrix()
{

   return *this;
}

double Square_Matrix::Determinant_Matrix()
{
   double determinant = 0;

   Square_Matrix temp_matrix(row - 1);

   for (int i = 0; i < row; i++)
   {
      int vt = 0;
      for (int v = (v == i) ? (1) : (0); v < row; (v == i) ? (v = v + 2) : (v++))
      {
         int wt = 0;
         for (int w = (w == i) ? (1) : (0); w < row; (w == i) ? (w = w + 2) : (w++))
         {
            temp_matrix[vt][wt] = matrix[v][w];
            wt++;
         }
         v++;
      }

      determinant += ((i % 2 ? -1 : 1) * matrix[0][i]) * temp_matrix.Determinant_Matrix();
   }

   return determinant;
}




