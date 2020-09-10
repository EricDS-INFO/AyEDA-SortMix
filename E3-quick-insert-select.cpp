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
  // Quicksort pero sin llamada recursiva (aplicando una sola llamada al programa)
  // Se aplica una sola iteración, por eso f = 1
  int i = 0, f = 1, sz = int(sec.size());
  int pivote = sec[sz/2];
  while (i <= f)
  {
    while (sec[i] < pivote) i++;
    while (sec[f] > pivote) f--;
    if (i <= f)
    {
      std::swap(sec[i],sec[f]);
      i++;
      f--;
    }
  }
  std::cout << "pivote: " << pivote;
  std::cout << " inicio: " << i;
  std::cout << " final: " << f <<std::endl;

  std::cout << "Vector tras quick: \n";
  for (int i = 0; i < int(sec.size()); i++)
    std::cout << "[" << i << ":" << sec[i] << "]";
  std::cout << "\n"; 


  // Primera parte: ordenación por inserción
  for (int i = 0; i < f; i++)
  {
    int j = i;
    while ((sec[j] > sec[i]) && (j >= 0))
    {
      std::swap(sec[i], sec[j]);
      j--;
    }
  }
std::cout << "Vector tras inserción: \n";
  for (int i = 0; i < int(sec.size()); i++)
    std::cout << "[" << i << ":" << sec[i] << "]";
  std::cout << "\n"; 

  // Segunda parte ordenación por selección

  for (int i = f; i < sz; i++)
  {
    int min = i;
    for (int j = i; j < sz; j++)
      if (sec[min] > sec[j])  min = j; 
    
    std::swap(sec[min], sec[i]);
  }

std::cout << "Vector tras selección: \n";

}
