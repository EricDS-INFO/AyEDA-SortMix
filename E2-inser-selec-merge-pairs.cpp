/*
Escribe un procedimiento en C++ que ordene de menor a mayor por el método de
ordenación por inserción los elementos de las posiciones impares entre sí, y luego
ordene de mayor a menor por el método de ordenación por selección los elementos de
las posiciones pares, y finalmente mezcle ambas partes.
*/
#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

void insert_select_merge_pairs(std::vector<int>& sec);

int main(void)
{
  std::vector<int> secuence = {2, 7, 1, 4, 3, 6};
  for (int i = 0; i < int(secuence.size()); i++)
    std::cout << "[" << i << ":" << secuence[i] << "]";
  std::cout << "\n"; 

  insert_select_merge_pairs(secuence);

  for (int i = 0; i < int(secuence.size()); i++)
    std::cout << "[" << i << ":" << secuence[i] << "]";
  std::cout << "\n"; 


  return 0;
}


void insert_select_merge_pairs(std::vector<int>& sec)
{  
    int sz = int(sec.size());

    //////// Elementos impares (inserción de menor a mayor)////////
    int i = 0;
    while (i < sz)
    {
        if (i%2 == 1)
        {
            int j = i - 2;
            while ( (sec[i] < sec[j]) && (j >= 0) )
            {
                std::swap(sec[i],sec[j]);                 /*1º Se intercambian los elementos en i y en j*/
                j-=2 ;                                    /*2º Se decrementa j en dos unidades*/ 
            }
        }
        i++;

    }

    //////// Elementos pares (selección de mayor a menor)////////
    for (int i = 0; i < sz;  i++)
    {
        if (i%2 == 0) /*solo índice par*/
        {
     
            int max = i;
            for (int j = i+2; j < sz; j+=2) /*iteramos de dos en dos*/
                if (sec[max] < sec[j])
                    max = j;

            std::swap(sec[i], sec[max]);
        }
    }


    //////// Mezcla de las partes
    
    int k = 0, j = sz-1;
    std::vector<int> aux;
    while((k <= sz) && (j >= sz/2 - 2))
    {
        if (sec[j] < sec[k])
        {

            aux.push_back(sec[k]);
            k += 2; 
        }
        else
        {

            aux.push_back(sec[j]);
            j -= 2;    

        }   
    }

    if (k > sz)
    {
        while (j >= sz/2)
        {
            aux.push_back(sec[j]);
            j -= 2;
        }
    }
    else
    {
        while (k <= sz)
        {
            aux.push_back(sec[k]);
            k += 2;
        }
    }
    
    sec.clear();
    for (int i = sz -1; i >= 0; i--)
        sec.push_back(aux[i]); 
    
}

