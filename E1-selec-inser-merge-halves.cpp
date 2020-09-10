/*
Escribe un procedimiento en C++ que ordene la primera mitad de la secuencia o
vector por el método de selección de menor a mayor, luego ordene la segunda mitad
también por el método de inserción, pero de mayor a menor, y finalmente mezcle
ambas mitades de forma que el vector quede ordenado de mayor a menor ordenada.
*/

#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

void select_insert_merge_halfs(std::vector<int>& sec);

int main(void)
{
  std::vector<int> secuence = {10, 1, 9, 2, 4, 0};

  for (int i = 0; i < int(secuence.size()); i++)
    std::cout << "[" << i << ":" << secuence[i] << "]";
  std::cout << "\n"; 

  select_insert_merge_halfs(secuence);

  for (int i = 0; i < int(secuence.size()); i++)
    std::cout << "[" << i << ":" << secuence[i] << "]";
  std::cout << "\n"; 


  return 0;
}



void select_insert_merge_halfs(std::vector<int>& sec)
{
  //////// primera mitad (inserción de menor a mayor)////////
  int n = int(sec.size());
  for (int i = 0; i < n/2; i++) 
  { 
    int min = i ; /*Búsqueda del mínimo en la primera mitad*/
    for (int j = i+1; j < n/2; j++)
      if (sec[j] < sec[min])
        min = j ;
    std::swap(sec[min],sec[i]);
  }

  for (int i = 0; i < int(sec.size()); i++)
    std::cout << "[" << i << ":" << sec[i] << "]";
  std::cout << "<-- Primera mitad de menor a mayor\n"; 


  //////// segunda mitad //////// 
  int i = n/2 + 1;
  while ( i < n )                             /*Se recorre la segunda mitad del vector*/
  {
    int j = i - 1 ;                           /*j es el elemento anterior a i*/
    while ( (sec[i] > sec[j]) && (j >= n/2) )  /*Mientras el elemento en j sea menor que el elemento en i y j sea mayor que n/2*/
    {
      std::swap(sec[i],sec[j]);                 /*1º Se intercambian los elementos en i y en j*/
      j-- ;                                     /*2º Se decrementa j*/
    };
    i++;                                      /*i se incrementa*/
  };


  for (int i = 0; i < int(sec.size()); i++)
    std::cout << "[" << i << ":" << sec[i] << "]";
  std::cout << "<-- Segunda mitad de mayor a menor\n"; 


  //////// mezcla ////////

  //////////////
  /////// Se seleccionan los elementos menores en ambas mitades (como solo es una iteración si o si es mitad y mitad, en otro caso se aplican llamadas recursivas)
  i = 0; 
  int j = n-1, k = 0 ;   
  std::vector<int> aux;           /*Vector auxiliar para la mezcla*/
  aux.resize(sec.size());
  while ((i <= n/2) && (j >= n/2)) /*Se hacen los dos recorridos i asciende y j desciende el vector hasta la mitad*/
  { 
    if (sec[i] < sec[j])          /*Si el elemento en i es menor que en j, en k se coloca el de i (el menor)*/
    {   
      aux[k] = sec[i] ;
      i++ ;                       /*se incrementa i*/
    } 
    else                          /*Si el elemento en i es mayor que en j, en k se coloca el de j (el menor)*/
    { 
      aux[k] = sec[j] ;
      j-- ;                       /*se decrementa j*/
    }
    k++ ;                         /*Siempre se incrementa k*/
  };

  //////////////
  /////// Se insertan en el vector auxiliar los elementos restantes no seleccionados
  if (i > n/2) /*si se sale siendo i mayor que el centro*/ 
  {
    while (j > n/2) /*Se insertan los elementos restantes en aux */
    { 
      aux[k] = sec[j] ;
      j-- ; k++ ;
    }
  }
  else         /*si se sale siendo i menor que el centro*/ 
  {
  while (i <= n/2) /*Se insertan los elementos restantes en aux */
  { 
    aux[k] = sec[i] ;
    i++ ; k++ ;
  };

  //////////////
  /////// Se copia el vector auxiliar en el original
  for (int k = 0; k < n; k++)
    sec[k] = aux[k] ;
  }
}

