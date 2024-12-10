#pragma once
#include <iostream>
class MatrixEx�eption
{
public:
   virtual ~MatrixEx�eption() {}

   virtual void Print() const
   {
      std::cout << "Error: Unknown error" << std::endl;
   }
   
};

class OutOfRange : public MatrixEx�eption
{
public:
   void Print() const override
   {
      std::cout << "Error: Index out of range" << std::endl;
   }
};

class SizeAreNotSame : public MatrixEx�eption
{
public:
   void Print() const override
   {
      std::cout << "Error: Sizes matrixes are not same" << std::endl;
   }
};

class WrongRowsColumns : public MatrixEx�eption
{
public:
   void Print() const override
   {
      std::cout << "Error: Wrong rows and columns in this matrix" << std::endl;
   }
};

class WrongData : public MatrixEx�eption
{
public:
   void Print() const override
   {
      std::cout << "Error: Wrong enter data" << std::endl;
   }
};

class WrongNotSquare : public MatrixEx�eption
{
public:
   void Print() const override
   {
      std::cout << "Error: Not square matrix" << std::endl;
   }
};