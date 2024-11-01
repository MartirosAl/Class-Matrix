#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <math.h>
#include "Square_Matrix.h"
#include "Vector.h"
using namespace std; 

double Min(Matrix matrix_)
{
   double min = matrix_[0][0];

   int row = matrix_.Get_Row();
   int column = matrix_.Get_Column();
   for (int i = 1; i < row; i++)
      for (int j = 0; j < column; j++)
         if (min > matrix_[i][j]) min = matrix_[i][j];

   return min;
}

Vector Max_from_Diagonals(Square_Matrix& matrix_)
{
   int size = matrix_.Get_Row() * 2 - 1;
   Vector array(nullptr, (size_t)size);

   int index = 0;

   for (int i = matrix_.Get_Row() - 1; i >= 0; i--)
   {
      double diagonal1 = 0;
      double diagonal2 = 0;
      int temp = i;
      
      for (int j = 0; j < matrix_.Get_Row() - i; j++)
      {
         if (diagonal1 < matrix_[temp][j]) diagonal1 = matrix_[temp][j];
         if (diagonal2 < matrix_[j][temp]) diagonal2 = matrix_[j][temp];

         temp++;
      }
      
      array[index] = diagonal1;
      if (i != 0)
         array[size - 1 - index] = diagonal2;
      index++;
   }


   return array;
}

int main()
{
   //Matrix a;

   //try 
   //{
   //   a.Set_Element(0, 0, 5);
   //}
   //catch (int error)
   //{
   //   switch (error)
   //   {
   //   case 1:
   //      printf("Outside the array");
   //   }
   //}

   //a.Print();
   //a.Transposition();
   //a.Print();
   int N = 3;
   Square_Matrix A(4), B, C, D;
   A.Input_from_Console().Print();// B.Input_from_Console().Print(); // C.Input_from_console();

   Vector a;

   a = Max_from_Diagonals(A);

   a.Print_Vectors();
   cout << "end" << endl;
   return 0;
}