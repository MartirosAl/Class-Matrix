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

Matrix* Add_Array_Matrix(Matrix*& array_matrix_, size_t& size_, size_t& capasity_, Matrix& matrix_)
{
   Matrix* temp = new Matrix[size_];
   for (int i = 0; i < size_; i++)
      temp[i] = array_matrix_[i];

   delete[] array_matrix_;

   
   array_matrix_ = new Matrix[size_ + 1];
   for (size_t i = 0; i < size_; i++)
      array_matrix_[i] = temp[i];

   array_matrix_[size_] = matrix_;

   size_++;
   return array_matrix_;
}

Matrix* Add_Array_Matrix(Matrix*& array_matrix_, size_t& size_, size_t& capasity_, Square_Matrix& matrix_)
{
   Matrix* temp = new Matrix[size_];
   for (int i = 0; i < size_; i++)
      temp[i] = array_matrix_[i];

   delete[] array_matrix_;

   array_matrix_ = new Matrix[size_ + 1];
   for (size_t i = 0; i < size_; i++)
      array_matrix_[i] = temp[i];

   array_matrix_[size_] = matrix_;

   size_++;
   capasity_++;
   return array_matrix_;
}

void menu()
{
   cout << "1. Print matrix" << endl;
   cout << "2. Edit elements" << endl;
   cout << "3. Create new matrix" << endl;
   cout << "4. Arithmetic operations" << endl;
   cout << "5. Comparison operations" << endl;
   cout << "6. Transponitoin matrix" << endl;
   cout << "7. Exponentiation matrix" << endl;
   cout << "8. Inverse matrix" << endl;
   cout << "9. Determinant matrix" << endl;
   cout << ">> ";
}

int main()
{
   Matrix* array_matrix = new Matrix[1];
   cout << array_matrix[0];
   size_t capacity_array_matrix = 1;
   size_t size_array_matrix = 0;

   unsigned short int choice;
   while (1)
   {
      try
      {
         system("cls");
         menu();

         cin >> choice;

         system("cls");
         switch (choice)
         {
         case 1:
            for (size_t i = 0; i < size_array_matrix; i++)
               cout << '#' << i << endl << array_matrix[i];
            cout << "Done" << endl;  
            system("pause");
            continue;
         case 2:
            for (size_t i = 0; i < size_array_matrix; i++)
               cout << '#' << i << endl << array_matrix[i];
            unsigned short int index2;
            cout << "Enter number matrix: ";
            cin >> index2;
            for (size_t i = 0; i < array_matrix[index2 - 1].Get_Row(); i++)
               for (size_t j = 0; j < array_matrix[index2 - 1].Get_Column(); j++)
                  array_matrix[index2 - 1].Input_from_Console();
            cout << "Done" << endl;
            system("pause");
            continue;
         case 3:
            int row3, column3;
            cout << "Enter row and column: ";
            cin >> row3 >> column3;
            if (row3 == column3)
            {
               Square_Matrix s_temp3(row3);
               cout << "Enter matrix: " << endl;
               cin >> s_temp3;
               Add_Array_Matrix(array_matrix, size_array_matrix, capacity_array_matrix, s_temp3);
            }
            else
            {
               Matrix temp3(row3, column3);
               cout << "Enter matrix: " << endl;
               cin >> temp3;
               Add_Array_Matrix(array_matrix, size_array_matrix , capacity_array_matrix, temp3);
            }
            cout << "Done" << endl;
            system("pause");
            continue;
         case 4:
            unsigned short int choice4;
            size_t index4_1;
            size_t index4_2;
            size_t index4_3;
            char sign4 = '\0';

            while (sign4 != '+' || sign4 != '-' || sign4 != '*')
            {
               cout << "Choice arithmetic operation (+, -, *)" << endl;
               cin >> sign4;
               if (sign4 != '+' || sign4 != '-' || sign4 != '*')
                  break;
               cout << "wrong operation";
               system("pause");
               system("cls");
            }
            system("cls");            
            for (size_t i = 0; i < size_array_matrix; i++)
               cout << '#' << i << endl << array_matrix[i];
            cout << "? " << sign4 << " ? = ?" << endl;
            cout << "Choice first matrix" << endl;
            cin >> index4_1;
            system("cls");
            for (size_t i = 0; i < size_array_matrix; i++)
               cout << '#' << i << endl << array_matrix[i];
            cout << "#" << index4_1 << ' ' << sign4 << " ? = ?" << endl;
            cout << "Choice second matrix" << endl;
            cin >> index4_2;
            system("cls");
            for (size_t i = 0; i < size_array_matrix; i++)
               cout << '#' << i << endl << array_matrix[i];
            cout << "#" << index4_1 << ' ' << sign4 << "#" << index4_2 << " = ? " << endl;
            cout << "Choice third matrix" << endl;
            cin >> index4_3;
            system("cls");
            
            if (index4_1 == index4_3 || index4_2 == index4_3)
            {
               switch (sign4)
               {
               case '+':
                  array_matrix[index4_1 == index4_3 ? index4_1 : index4_2] += array_matrix[index4_1 != index4_3 ? index4_1 : index4_2];
                  break;
               case '-':
                  array_matrix[index4_1 == index4_3 ? index4_1 : index4_2] -= array_matrix[index4_1 != index4_3 ? index4_1 : index4_2];
                  break;
               case '*':
                  array_matrix[index4_1 == index4_3 ? index4_1 : index4_2] *= array_matrix[index4_1 != index4_3 ? index4_1 : index4_2];
                  break;
               }
            }
            else
            {
               switch (sign4)
               {
               case '+':
                  array_matrix[index4_3] = array_matrix[index4_1] + array_matrix[index4_2]; 
                  break;
               case '-':
                  array_matrix[index4_3] = array_matrix[index4_1] - array_matrix[index4_2];
                  break;
               case '*':
                  array_matrix[index4_3] = array_matrix[index4_1] * array_matrix[index4_2];
                  break;
               }
            }
            cout << "Done" << endl;
            system("pause");
            continue;
         case 5:

         default:
            break;
         }
      }
      catch (int error)
      {
         //throw:
         //1 - ����� �� �������
         //2 - �� ���������� ������ �������
         //3 - ������� �� ��������� �� �������� ������ ������� ��� ��������
         //4 - ����������� ��������� ������
         //5 - ������������ �������
         switch (error)
         {
         case 1:
            ;
         case 2:
            ;
         case 3:
            ;
         case 4:
            ;
         case 5:
            ;
         }
      }
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