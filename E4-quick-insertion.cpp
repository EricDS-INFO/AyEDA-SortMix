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
  std::vector<int> secuence = /* {7,1,3,5,4} */ {22, 21, 36, 42, 33, 38, 45, 31, 17};
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
  // Se elige un pivote -> se hacen los recorridos ascendente y descendente
  // ascendente encuentra un valor menor o igual al pivote -> lo inserta en orden en la izquierda
  // ascendente encuentra un valor mayor -> el recorrido se detiene
  // descendente encuentra un valor mayor o igual al pivote -> lo inserta en orden en la derecha
  // descendenta encuentra un valor menor -> el recorrido se detiene
  // ambos recorridos se detienen -> intercambian los elementos donde pararon
  
  int i = 0, f = sec.size() -1, sz = sec.size();
  int p = sec[(f+i)/2];
  std::cout << "inicio: " << i;
  std::cout << "    fin: " << f;
  std::cout << "    pivote: " << p <<"\n";  

  while (i <= f) 
  {
    while (sec[i] <= p) 
    { // Inserta i izquierda
      int j = i;
      while ( (sec[i] <= sec[j]) && (j >= 0) ) 
      {      
        std::swap(sec[i],sec[j]);
        j-- ;
      } 
      i++ ;

    };
    
        std::cout << "aqui\n";
    while (sec[f] >= p) 
    { // Inserta f derecha (sec,f);
      int g = f;

      while ( (sec[f] >= sec[g]) && (g < sz) ) 
      {

        std::swap(sec[g],sec[f]);
        g++ ;
      }
      f-- ;
      
    }
    if (i <= f) 
    { // Intercambia
        std::swap(sec[i],sec[f]);
    }
  } 
}
