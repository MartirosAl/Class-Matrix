#pragma once
#include "Matrix.h"
class Square_Matrix : public Matrix
{
public:
   Square_Matrix(int order_ = 2);

   Square_Matrix(const Square_Matrix& other_);

   Matrix& Inverse_Matrix();

   double Determinant_Matrix();

   double Minor_Matrix(int i, int j);

   double Algebraic_Complement_Matrix();


};

