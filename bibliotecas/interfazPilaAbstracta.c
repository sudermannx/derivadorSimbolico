#include<stdlib.h>
#include<stdio.h>

#include "../encabezados/interfazPilaAbstracta.h" 

void empujar( ptrNodoPila *ptrCima, void * info )
{ 
   ptrNodoPila ptrNuevo; 

   ptrNuevo = malloc( sizeof( NodoPila ) );

  
   if ( ptrNuevo != NULL ) {   
      ptrNuevo->dato = info;
      ptrNuevo->ptrSiguiente = *ptrCima;
      *ptrCima = ptrNuevo;
      
      //printf( "se empujo un elemento.\n"  );
   } 
   else { 
      printf( " no se inserto. Memoria insuficiente.\n"  );
   } 
} 


void * sacar( ptrNodoPila *ptrCima )
{ 
   ptrNodoPila ptrTemp; 
   void * valorElim; 
   ptrTemp = *ptrCima;
   valorElim = ( *ptrCima )->dato;
   *ptrCima = ( *ptrCima )->ptrSiguiente;
   free( ptrTemp );

   return valorElim;

} 


void imprimePila( ptrNodoPila ptrActual )
{ 

   
   if ( ptrActual == NULL ) {
      printf( "La pila esta vacia.\n\n" );
   }
   else { 
      printf( "La pila es:\n" );

      while ( ptrActual != NULL ) { 
         //printf( "%d --> ", ptrActual->dato );
         ptrActual = ptrActual->ptrSiguiente;
      }

      printf( "NULL\n\n" );
   } 

} 


int estaVacia( ptrNodoPila ptrCima )
{ 
   return ptrCima == NULL;

}



