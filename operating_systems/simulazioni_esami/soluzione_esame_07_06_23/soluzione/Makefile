main: main.c
	@if [ -e $(FILE) ]; then mkdir $(DIR) && cp $(FILE) $(DIR) && gcc main.c -pthread -o $(DIR)/$(EXE); else echo "errore: file non esistente"; fi