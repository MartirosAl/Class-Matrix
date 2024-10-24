#pragma once
#include <iostream>
#include <math.h>

class Matrix
{
   int row;
   int column;

   double** matrix;

public:

   Matrix(int row_ = 2, int column_ = 3);

   Matrix(const Matrix& other_);

   ~Matrix();

   Matrix operator+(const Matrix& other_);

   Matrix operator*(const Matrix& other_);

   Matrix operator=(const Matrix& other_);

   double* operator[](int index) const;

   double* operator[](int index);

   void Set_Element(int row_, int column_, double value_);
   

   double Get_Element(int row_, int column_);

   int Get_Column();

   int Get_Row();

   void Input_from_console();

   void Print();

   void Transposition();

};

