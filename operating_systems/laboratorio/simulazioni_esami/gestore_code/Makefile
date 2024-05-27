DEST = .

#le variabili possono essere sovrascritte da riga di comando con make nome=value
#1>&2 ridirezione stdout a stderr
$(DEST)/coda: main.c
	@[[ ! -d $(DEST) ]] && 1>&2 echo "?ERROR" || gcc -Wall main.c -o $(DEST)/coda
