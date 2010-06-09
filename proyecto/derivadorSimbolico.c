#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


#include "../encabezados/interfazPilaAbstracta.h"
#include "../encabezados/interfazArbolAbstracto.h" 
#include "../encabezados/interfazImprime.h" 

      int main( int argc, char * argv [] )
      {
      
      char * expresion = (char *) NULL;
      
      expresion = (char *) malloc( sizeof(char *) * 1 );

      NodoArbol * Expresion = (NodoArbol *) NULL;
      NodoArbol * Derivada =  (NodoArbol *) NULL;
      
      NodoArbol * Der =  (NodoArbol *) NULL;
      NodoArbol * Izq =  (NodoArbol *) NULL;
      
      NodoArbol * DerD = (NodoArbol *) NULL;
      NodoArbol * IzqD = (NodoArbol *) NULL;
      
      
      NodoPila * PilaExpresion =(NodoPila *) NULL;
      NodoPila * PilaDerivada  =(NodoPila *) NULL;
      
      NodoArbol * AuxD =  (NodoArbol *) NULL;
      NodoArbol * AuxI =  (NodoArbol *) NULL;
      
      NodoArbol * AuxD1 =  (NodoArbol *) NULL;
      NodoArbol * AuxD2 =  (NodoArbol *) NULL;
      NodoArbol * AuxD3 =  (NodoArbol *) NULL;
      
      NodoArbol * AuxI2 =  (NodoArbol *) NULL;
      NodoArbol * AuxI3 =  (NodoArbol *) NULL;
      
      NodoArbol * UNO =  (NodoArbol *) NULL;
      NodoArbol * DOS =  (NodoArbol *) NULL;
      
      int c;
      
	c=0;
	while( argv[1][c] ) 
	{
	  expresion[0] = argv[1][c];
		
	  Expresion = CreaNodoArb( (void *) strdup(expresion), (NodoArbol *) NULL, (NodoArbol *) NULL);
	  
	      if( argv[1][c] == 'x')
		
			Derivada = CreaNodoArb( (void *) strdup("1"), (NodoArbol *) NULL, (NodoArbol *) NULL );
		
		else
		  if( isdigit(argv[1][c]) )
		 
			Derivada = CreaNodoArb( (void *) strdup("0"), (NodoArbol *) NULL, (NodoArbol *) NULL );
		 
		else
		  if( argv[1][c] == '+' || argv[1][c] == '-' )
		 {
		   
		   Der = (NodoArbol *) sacar( &PilaExpresion );
		   Izq = (NodoArbol *) sacar( &PilaExpresion );
		   
		   Expresion->ptr_izquierdo = Izq;
		   Expresion->ptr_derecho = Der;
		    
		   DerD = (NodoArbol *) sacar( &PilaDerivada );
		   IzqD = (NodoArbol *) sacar( &PilaDerivada );
		   
		   Derivada = CreaNodoArb( (void *) strdup(expresion), IzqD, DerD);
		  }
		  else
		    if( argv[1][c] == '*')
		    {
			Der = (NodoArbol *) sacar( &PilaExpresion );
			Izq = (NodoArbol *) sacar( &PilaExpresion );
		   
			Expresion -> ptr_izquierdo = Izq;
			Expresion -> ptr_derecho = Der;
			
			DerD = (NodoArbol *) sacar( &PilaDerivada );
			IzqD = (NodoArbol *) sacar( &PilaDerivada );
		  
			AuxD = CreaNodoArb( (void *) strdup(expresion), Der, IzqD);
			
			AuxI = CreaNodoArb( (void *) strdup(expresion), Izq, DerD);
			
			Derivada = CreaNodoArb( (void *) strdup("+"), AuxI, AuxD);
			
		    }
		    else
		      if( argv[1][c] == '^')
		      {
			Der = (NodoArbol *) sacar( &PilaExpresion );
			Izq = (NodoArbol *) sacar( &PilaExpresion );
		   
			Expresion -> ptr_izquierdo = Izq;
			Expresion -> ptr_derecho = Der;
			
			DerD = (NodoArbol *) sacar( &PilaDerivada );
			IzqD = (NodoArbol *) sacar( &PilaDerivada );
			
			UNO = CreaNodoArb( (void *) strdup("1"), (NodoArbol *) NULL, (NodoArbol *) NULL );
		  
			AuxD1 = CreaNodoArb( (void *) strdup("-"), Der, UNO );
			
			AuxD2 = CreaNodoArb( (void *) strdup("^"), Izq, AuxD1 );
			
			AuxD3 = CreaNodoArb( (void *) strdup("*"), IzqD, AuxD2 );
			
			Derivada = CreaNodoArb( (void *) strdup("*"), Der, AuxD3 );
			
		      }
		      else
			if( argv[1][c] == 'e')
			{
			  Der = (NodoArbol *) sacar( &PilaExpresion );
			  Izq = (NodoArbol *) NULL;
		   
			  Expresion -> ptr_izquierdo = Izq;
			  Expresion -> ptr_derecho = Der;
			
			  DerD = (NodoArbol *) sacar( &PilaDerivada );
			  IzqD = (NodoArbol *) NULL;
			
			  AuxD3 = CreaNodoArb( (void *) strdup("exp"), IzqD, Der );
			
			  Derivada = CreaNodoArb( (void *) strdup("*"), DerD, AuxD3 );
			}
			else
			  if( argv[1][c] == 'l')
			  {
			    Der = (NodoArbol *) sacar( &PilaExpresion );
			    Izq = (NodoArbol *) NULL;
		   
			    Expresion -> ptr_izquierdo = Izq;
			    Expresion -> ptr_derecho = Der;
			
			    DerD = (NodoArbol *) sacar( &PilaDerivada );
			    IzqD = (NodoArbol *) NULL;
			
			    Derivada = CreaNodoArb( (void *) strdup("/"), DerD, Der );
			  }
			  else
			    if( argv[1][c] == 's')
			    {
			      Der = (NodoArbol *) sacar( &PilaExpresion );
			      Izq = (NodoArbol *) NULL;
		   
			      Expresion -> ptr_izquierdo = Izq;
			      Expresion -> ptr_derecho = Der;
			
			      DerD = (NodoArbol *) sacar( &PilaDerivada );
			      IzqD = (NodoArbol *) NULL;
			
			      AuxD3 = CreaNodoArb( (void *) strdup("cos"), (NodoArbol *) NULL, Der );
			
			      Derivada = CreaNodoArb( (void *) strdup("*"), DerD, AuxD3 );
			    }
			    else
			      if( argv[1][c] == 'c')
			      {
				Der = (NodoArbol *) sacar( &PilaExpresion );
				Izq = (NodoArbol *) NULL;
		   
				Expresion -> ptr_izquierdo = Izq;
				Expresion -> ptr_derecho = Der;
			
				DerD = (NodoArbol *) sacar( &PilaDerivada );
				IzqD = (NodoArbol *) NULL;
			
				AuxD3 = CreaNodoArb( (void *) strdup("sin"), (NodoArbol *) NULL, Der );
				
				AuxI3 = CreaNodoArb( (void *) strdup("-"), (NodoArbol *) NULL, DerD );
			
				Derivada = CreaNodoArb( (void *) strdup("*"), AuxI3, AuxD3 );
			      }
			      else
				if( argv[1][c] == 't')
				{
				  Der = (NodoArbol *) sacar( &PilaExpresion );
				  Izq = (NodoArbol *) NULL;
		   
				  Expresion -> ptr_izquierdo = Izq;
				  Expresion -> ptr_derecho = Der;
			
				  DerD = (NodoArbol *) sacar( &PilaDerivada );
				  IzqD = (NodoArbol *) NULL;
				  
				  DOS = CreaNodoArb( (void *) strdup("2"), (NodoArbol *) NULL, (NodoArbol *) NULL );
				  
				  AuxI3 = CreaNodoArb( (void *) strdup("sec"), (NodoArbol *) NULL, Der );
			
				  AuxD3 = CreaNodoArb( (void *) strdup("^"), AuxI3, DOS );
			
				  Derivada = CreaNodoArb( (void *) strdup("*"), DerD, AuxD3 );
				}
				else
				   if( argv[1][c] == '/')
				   {
				      Der = (NodoArbol *) sacar( &PilaExpresion );
				      Izq = (NodoArbol *) sacar( &PilaExpresion );
		   
				      Expresion -> ptr_izquierdo = Izq;
				      Expresion -> ptr_derecho = Der;
			
				      DerD = (NodoArbol *) sacar( &PilaDerivada );
				      IzqD = (NodoArbol *) sacar( &PilaDerivada );
				      
				      DOS = CreaNodoArb( (void *) strdup("2"), (NodoArbol *) NULL, (NodoArbol *) NULL );
		  
				      AuxD2 = CreaNodoArb( (void *) strdup("*"), Izq, DerD );
			
				      AuxI2 = CreaNodoArb( (void *) strdup("*"), Der, IzqD );
			
				      AuxI3 = CreaNodoArb( (void *) strdup("-"), AuxI2, AuxD2 );
			
				      AuxD3 = CreaNodoArb( (void *) strdup("^"), Der, DOS );
			
				      Derivada = CreaNodoArb( (void *) strdup("/"), AuxI3, AuxD3 );
			
				  }
				  else
				    if( argv[1][c] == 'C' )
				    {
				     
				      Der = (NodoArbol *) sacar( &PilaExpresion );
				      Izq = (NodoArbol *) NULL;
		   
				      Expresion -> ptr_izquierdo = Izq;
				      Expresion -> ptr_derecho = Der;
			
				      DerD = (NodoArbol *) sacar( &PilaDerivada );
				      IzqD = (NodoArbol *) NULL;
				      
				      DOS = CreaNodoArb( (void *) strdup("2"), (NodoArbol *) NULL, (NodoArbol *) NULL );
		  
				      AuxI3 = CreaNodoArb( (void *) strdup("csc"), (NodoArbol *) NULL, Der );
				      
				      AuxD2 = CreaNodoArb( (void *) strdup("^"), AuxI3, DOS );
				      
				      AuxD3 = CreaNodoArb( (void *) strdup("-"), (NodoArbol *) NULL, AuxD2 );
			
				      Derivada = CreaNodoArb( (void *) strdup("*"), DerD, AuxD3 );
				    }
				    else
				      if( argv[1][c] == 'S' )
				      {
				     
				      Der = (NodoArbol *) sacar( &PilaExpresion );
				      Izq = (NodoArbol *) NULL;
		   
				      Expresion -> ptr_izquierdo = Izq;
				      Expresion -> ptr_derecho = Der;
			
				      DerD = (NodoArbol *) sacar( &PilaDerivada );
				      IzqD = (NodoArbol *) NULL;
		  
				      AuxI3 = CreaNodoArb( (void *) strdup("sec"), (NodoArbol *) NULL, Der );
				      
				      AuxD2 = CreaNodoArb( (void *) strdup("tan"), (NodoArbol *) NULL, Der );
				      
				      AuxD3 = CreaNodoArb( (void *) strdup("*"), AuxI3, AuxD2 );
			
				      Derivada = CreaNodoArb( (void *) strdup("*"), DerD, AuxD3 );
				      }
				      else
					if( argv[1][c] == 'G')
					 {
					   
					    Der = (NodoArbol *) sacar( &PilaExpresion );
					    Izq = (NodoArbol *) NULL;
		   
					    Expresion -> ptr_izquierdo = Izq;
					    Expresion -> ptr_derecho = Der;
			
					    DerD = (NodoArbol *) sacar( &PilaDerivada );
					    IzqD = (NodoArbol *) NULL;
					    
					    AuxD2 = CreaNodoArb( (void *) strdup("cot"), (NodoArbol *) NULL, Der );
		  
					    AuxI3 = CreaNodoArb( (void *) strdup("csc"), (NodoArbol *) NULL, Der );
				      
					    AuxD2 = CreaNodoArb( (void *) strdup("*"), AuxI3, AuxD2 );
				      
					    AuxD3 = CreaNodoArb( (void *) strdup("-"), (NodoArbol *) NULL, AuxD2 );
			
					    Derivada = CreaNodoArb( (void *) strdup("*"), DerD, AuxD3 );
					  }
					
				  

	      empujar( &PilaExpresion, (void *)(Expresion) );  
	      empujar( &PilaDerivada, (void *)(Derivada) );
	  
	  
	  c++;
	}
	
	printf("\n\n\t\t\t\t[ PROYECTO ]\t");
	printf("\n\n\t\t\t  [ DERIVADOR SIMBOLICO ]\t\n\n");
	
	printf("\n\t>Exprecion en Infijo ---->\t");
	imprimeI( Expresion, imprimeStr);
	printf("\n\n");	 
	printf("\n\t>Derivada en Infijo  ---->\t");
	imprimeI( Derivada, imprimeStr);
	printf("\n\n");	  
      
	return 0;
      }
      
