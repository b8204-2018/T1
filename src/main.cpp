#include <stdlib.h>

#include <iostream>
#include <vector>




int printMatrix (std::vector <std::vector <int>> &matrix) {

  std::cout << "Печать матрицы" << std::endl;


  for (int i = 0; i < matrix. size (); i++) {

    std::cout << std::endl << "Строка: " << i + 1 << std::endl;


    for (int j = 0; j < matrix [i]. size (); j++) {

      std::cout << matrix [i] [j] << " ";

    }

  }


  return 0;

}




std::vector <std::vector <int>> createMatrix () {

  int row;
  int column;


  std::vector <std::vector <int>> matrix;


  std::cout << "Введите количество строк матрицы" << std::endl;
  std::cin >> row;


  if ((row % 2) > 0) {

    std::cout << "\nЧисло строк должно быть чётным\n\n";


    exit (0);

  }


  std::cout << "Введите количество столбцов матрицы" << std::endl;
  std::cin >> column;


  matrix. resize (row);

  for (int i = 0; i < matrix. size (); i++) {

    matrix [i]. resize (column);

  }


  for (int i = 0; i < row; i++) {

    for (int j = 0; j < column; j++) {

      matrix [i] [j] = rand () % 100 + 1;

    }

  }


  return matrix;

}




std::vector <std::vector <int>> evenOdd (std::vector <std::vector <int>> matrix) {

  std::vector <std::vector <int>> newMatrix;


  newMatrix. resize (matrix. size ());


  for (int i = 1; i < matrix. size (); i = i + 2) {

    newMatrix [i - 1] = matrix [i];

  }


  for (int i = 1; i < matrix. size (); i = i + 2) {

    newMatrix [i] = matrix [i - 1];

  }


  return newMatrix;

}




std::vector <std::vector <int>> transpose (std::vector <std::vector <int>> &matrix) {

  std::vector <std::vector <int>> newMatrix;


  newMatrix. resize (matrix [0]. size ());


  for (int i = 0; i < newMatrix. size (); i++) {

    newMatrix [i]. resize (matrix. size ());

  }


  for (int i = 0; i < matrix. size (); i++) {

    for (int j = 0; j < matrix [i]. size (); j++) {

      newMatrix [j] [i] = matrix [i] [j];

    }

  }


  return newMatrix;;

}




int main () {

  std::cout << "Создание матрицы\n";
  std::vector <std::vector <int>> matrix = createMatrix ();


  std::cout << "\n\nИсходная матрица \n";
  printMatrix (matrix);


  std::cout << "\n\nЗаменяем чётные строки матрицы на нечётные\n";
  std::vector <std::vector <int>> evenOddMatrix = evenOdd (matrix);


  std::cout << "\n\nМатрица с произведённой заменой чётных строк на нечётные\n";
  printMatrix (evenOddMatrix);


  std::cout << "\n\nТранспонирование исходной матрицы\n";
  std::vector <std::vector <int>> transposeMatrix = transpose (matrix);


  std::cout << "\n\nТранспонированная исходная матрица\n";
  printMatrix (transposeMatrix);


  std::cout << "\n\nТранспонирование матрицы с заменёнными чётными строками на нечётные\n";
  std::vector <std::vector <int>> transposeEvenOddMatrix = transpose (evenOddMatrix);


  std::cout << "\n\nТранспонированная матрица с изменёнными чётными строками на нечётные\n";
  printMatrix (transposeEvenOddMatrix);


  return 0;

}
