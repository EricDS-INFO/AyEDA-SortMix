/*
4.- Escribe un procedimiento C++ que aplique un procedimiento de ordenación que
combine las ideas de los métodos de ordenación por inserción y Quicksort de la forma
siguiente: en primer lugar se elige un pivote, entonces dos índices recorren la parte por
ordenar en sentidos ascendente descendente, respectivamente. Si el recorrido ascendente
encuentra un valor menor o igual que el pivote, lo inserta en orden por la izquierda pero
si encuentra un valor mayor que el pivote se detiene. Si el recorrido descendente
encuentra un valor mayor o igual que el pivote, lo inserta por la derecha pero si
encuentra un valor menor que el pivote se detiene. Cuando ambos recorridos se
detienen, se intercambian los elementos donde se han parado que se insertan en la parte
correspondiente y se continúa el proceso hasta que ambos recorridos se encuentren.
*/

#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

void quick_insertion(std::vector<int>& sec);

int main(void)
{
  std::vector<int> secuence = {1, 32, 72, 2, 4};
  for (int i = 0; i < int(secuence.size()); i++)
    std::cout << "[" << i << ":" << secuence[i] << "]";
  std::cout << "\n"; 

  quick_insertion(secuence);

  for (int i = 0; i < int(secuence.size()); i++)
    std::cout << "[" << i << ":" << secuence[i] << "]";
  std::cout << "\n"; 


  return 0;
}


void quick_insertion(std::vector<int>& sec)
{
    
}
