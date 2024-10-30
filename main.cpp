#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <math.h>
#include "Square_Matrix.h"
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

   Square_Matrix A(3), B, C, D;
   //A.Input_from_console(); B.Input_from_console(); C.Input_from_console();
   A.Input_from_Console().Print();
   
   cout << A.Minor_Matrix(0, 0) << endl;
   cout << "end" << endl;
   return 0;
}