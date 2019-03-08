CC=gcc
CFLAGS=
LDFLAGS=
EXEC=recLang
FREQ=../data/allemand.txt allemand ../data/anglais.txt anglais ../data/arabe.txt arabe ../data/chinois.txt chinois ../data/coréen.txt coréen ../data/espagnol.txt espagnol ../data/francais.txt français ../data/italien.txt italien ../data/japonais.txt japonais ../data/néerlandais.txt néerlandais ../data/portugais.txt portugais ../data/russe.txt russe ../data/catalan.txt catalan ../data/chinoisClassique.txt chinois_classique ../data/ourdou.txt ourdou ../data/ukrainien.txt ukrainien
DEL=stats.txt
FILE=../test/inconnu.txt


all: $(EXEC) 

recLang: recLang.o
	$(CC) -o recLang recLang.o $(CFLAGS)

recLang.o: recLang.c recLang.h
	$(CC) -o recLang.o -c recLang.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
	rm -rf $(DEL)

stats:
	./$(EXEC) $(FREQ)

recon:
	./$(EXEC) $(FILE)
