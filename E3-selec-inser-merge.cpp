/*
Escribe un procedimiento C++ que aplique el procedimiento de ordenación
siguiente: se aplica una iteración del método Quicksort para dividir la secuencia en dos
partes y se ordena, la primera parte por inserción y la segunda por selección.
 */
#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

void quick_insert_select(std::vector<int>& sec);

int main(void)
{
  std::vector<int> secuence = {1, 32, 72, 2, 4};
  for (int i = 0; i < int(secuence.size()); i++)
    std::cout << "[" << i << ":" << secuence[i] << "]";
  std::cout << "\n"; 

  quick_insert_select(secuence);

  for (int i = 0; i < int(secuence.size()); i++)
    std::cout << "[" << i << ":" << secuence[i] << "]";
  std::cout << "\n"; 


  return 0;
}


void quick_insert_select(std::vector<int>& sec)
{
    
}
