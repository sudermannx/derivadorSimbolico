#include "../encabezados/interfazArbolAbstracto.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

NodoArbol * 
CreaNodoArb(void * dato, NodoArbol * ptr_izquierdo, NodoArbol * ptr_derecho)
 {
  
  NodoArbol * nvo;
  nvo = ( NodoArbol *) malloc( sizeof( NodoArbol * )  );
  
    if(nvo)
    {
      
      ( nvo )->dato =  (void *)dato; 
      ( nvo )->ptr_izquierdo = ptr_izquierdo;
     
      (  nvo )->ptr_derecho = ptr_derecho;
      
      return nvo;
    }
    else
    {
      printf("\n\t==No hah memoria==\n\t");
      return ( NodoArbol * ) NULL;
    }
  
 }