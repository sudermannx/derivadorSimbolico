#include<stdio.h>
#include "../encabezados/interfazArbolAbstracto.h"
//#include "../encabezados/interfazImprime.h"

void imprimeStr( void * s )
{
  printf("%s", (char *) s );
}

void imprimeI( NodoArbol * r, void (*f) (void *) )
{
 if(!r) return;
 
 imprimeI( r -> ptr_izquierdo, f );
 
 f(r -> dato );
 
 imprimeI( r-> ptr_derecho, f );
  
}