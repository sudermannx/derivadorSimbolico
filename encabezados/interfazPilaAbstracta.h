struct nodoPila {   
   void * dato;                  
   struct nodoPila *ptrSiguiente; 
}; 

typedef struct nodoPila NodoPila; 
typedef NodoPila *ptrNodoPila; 


void empujar( ptrNodoPila *ptrCima, void * info );
void * sacar( ptrNodoPila *ptrCima );
int estaVacia( ptrNodoPila ptrCima );
void imprimePila( ptrNodoPila ptrActual );