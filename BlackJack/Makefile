UTILa=Carta.c
UTILb=Pilha.c
MAIN=main.c
BINARY=executavel
NAME=Atividade3

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

all: 
	gcc -Wall -g $(MAIN) $(UTILa) $(UTILb) -o $(BINARY) -s

run:
	./$(BINARY)

debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTILa) $(UTILb) -o executavel

clean:
	@rm $(BINARY)

zip:
	@zip -r $(NAME).zip *