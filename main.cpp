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

int menu()
{
   cout << "1. Print matrix" << endl;
   cout << "2. Input elements" << endl;
   cout << "3. Create new matrix" << endl;
   cout << "4. Arithmetic operations" << endl;
   cout << "5. Comparison operations" << endl;
   cout << "6. Transponitoin matrix" << endl;
   cout << "7. Exponentiation matrix" << endl;
   cout << "8. Inverse matrix" << endl;
   cout << "9. Determinant matrix" << endl;
   cout << endl;
}
//throw:
//1 - Выход за пределы
//2 - Не одинаковый размер матрицы
//3 - Колонки не совпадают со строками другой матрицы или наоборот
//4 - Неправильно введенные данные
//5 - Неквадратная матрица
int main()
{
   Matrix* array_matrix;

   unsigned int choice;
   try
   {
      while (1)
      {
         menu();

         cin >> choice;

         switch (choice)
         {
         case 1:
            ;
         case 2:
            ;
         case 3:
            ;
         default:
            break;
         }
      }
   }
   catch (int error)
   {
      ;
   }
   int N = 3;
   Square_Matrix A(4), B, C, D;
   //A.Input_from_Console().Print();// B.Input_from_Console().Print(); // C.Input_from_console();

   cin >> A;
   cout << A;

   Vector a;

   a = Max_from_Diagonals(A);

   a.Print_Vectors();
   cout << "end" << endl;
   return 0;
}