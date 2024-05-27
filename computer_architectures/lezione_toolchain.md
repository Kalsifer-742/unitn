# Lezione 19/4/22

## Toolchain

* le fasi delle compilazione
  * preprocessore
  * compilatore
  * assembler
  * linker (mette assieme linguaggio macchina e librerie)
* programma C
  * compilatore
    * linguaggio assembler
      * assembler
        * file oggetto + file oggetto di librerie
          * linker
            * programma eseguibile
              * loader
                * carica in memoria
* queste operazioni solitamente vengono eseguite in automatico ma sui sistemi unix per esempio possono essere compiute manualmente

### Struttura Memoria

* nella parte testo ci vanno le effettive istruzioni in binario

### gcc

* nei pdf si trovano esempi degli effettivi flag e comandi da usare
* concetto di cross compilation
* file.c > compilatore > file.s (assembly)
* spesso i file temporanei nemmeno vengono salvati
* solita storia sull'ottimizzazione

### Assembler

* sostituisce pseudo istruzioni con cose comprensibili alla cpu
* converte i numeri in binario
* gestie label
* gestisce i salti
* gestisce i metadati

### File oggetto

* Header
  * specifica dimensione e poszione segmenti nel file
* Segmenti
  * Text Segment
    * codice linguaggio macchina
  * Data Segment
    * contiene i dati allocati per la durata del programma. Sia statici che dinamici
* Symbol Table
  * associa simboli ad indirizzi
  * converte simboli non definiti, cioé presenti in altri moduli
* Relocation Table
  * converte istruzioni che fanno riferimento ad indirizzi assoluti che vanno quindi patchati quando il programma viene caricato in memoria
* Debugging info
  * cose ...

### Linker

> il suo scopo é quello di eliminare tutte le tabelle e produrre codice autosufficiente in cui tutti gli indirizzi siano stati patchati. sempre il linker decide come dati e codice sono disposti in memoria

* simboli
  * definiti
    * associati ad un indirizzo nella tabella
  * non definiti
    * presenti nella tabella dei simboli ma definiti in un altro file
  * locali
    * definiti ed utilizzabili solo in un file
* librerie
  * librerie statiche
    * .a
  * librerire dinamiche
    * .so
    * linking a tempo di esecuzione, mentre viene caricato
  * lazy linking
    * linking eseguito durante l'esecuzione, il caricamento in memoria viene fatto alla prima chiamata ad un libreria esterna, tipo just in time

### Riassunto Finale

> la lezione procede con esempi lunghissimi e noiosissimi nel suo stile. Poi fa degli esempi pratici sul suo mac. Consultare slide per dettagli.