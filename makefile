c=gcc
op=-Wall -Wextra
file=file/
es=file/es/

all : es.o file.o ligue.o match.o equipe.o main.c 	
	$(c) $(op)  es.o file.o ligue.o match.o equipe.o main.c -o exe
ligue.o : ligue.c ligue.h
	$(c) $(op) -c ligue.c
match.o : match.c match.h
	$(c) $(op) -c match.c
equipe.o : equipe.c equipe.h
	$(c) $(op) -c equipe.c	
file.o : $(file)file.c $(file)file.h
	$(c) $(op) -c $(file)file.c	
es.o : $(es)es.c $(es)es.h
	$(c) $(op) -c $(es)es.c	

clean:
	rm -rf *.o exe

