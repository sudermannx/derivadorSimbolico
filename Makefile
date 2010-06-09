#Makefile

CC = gcc

CFLAGS = -O3 -march=native -mtune=native -pipe -Wall -fomit-frame-pointer -g3

OBJECTS_PROYECT = \
	./temporales/interfazArbolAbstracto.o \
	./temporales/interfazPilaAbstracta.o \
	./temporales/interfazImprime.o

HEADERS_PROYECT = \
	./encabezados/interfazArbolAbstracto.h \
	./encabezados/interfazPilaAbstracta.h \
	./encabezados/interfazImprime.h

#----------------------------------------------------------->

Proyecto:

	@echo
	make derivadorSimbolico
	@echo

#----------------------------------------------------------->



derivadorSimbolico: ./proyecto/derivadorSimbolico.c $(OBJECTS_PROYECT) $(HEADERS_PROYECT)
	$(CC) -o DerivadorSimbolico $(CFLAGS) ./proyecto/derivadorSimbolico.c $(OBJECTS_PROYECT)

./temporales/interfazImprime.o: ./bibliotecas/interfazImprime.c ./encabezados/interfazImprime.h  
	$(CC) -c $(CFLAGS) ./bibliotecas/interfazImprime.c
	mv ./interfazImprime.o ./temporales/

./temporales/interfazArbolAbstracto.o: ./bibliotecas/interfazArbolAbstracto.c ./encabezados/interfazArbolAbstracto.h  
	$(CC) -c $(CFLAGS) ./bibliotecas/interfazArbolAbstracto.c
	mv ./interfazArbolAbstracto.o ./temporales/

./temporales/interfazPilaAbstracta.o: ./bibliotecas/interfazPilaAbstracta.c ./encabezados/interfazPilaAbstracta.h  
	$(CC) -c $(CFLAGS) ./bibliotecas/interfazPilaAbstracta.c
	mv ./interfazPilaAbstracta.o ./temporales/

#----------------------------------------------------------->

#----------------------------------------------------------->
cleanAll:

	@echo
	rm -f ./*~ ./encabezados/*~ ./bibliotecas/*~ ./proyecto/*~ ./temporales/*~
	@echo
	rm -f $(OBJECTS_PROYECT)
	@echo
	rm -f ./DerivadorSimbolico 
	@echo
#----------------------------------------------------------->
