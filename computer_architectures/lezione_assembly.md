# Lezione 21/3/22

## Assembly

## RISC-V

* un instruction set deve necessariamente prevedere le istruzioni per il calcolo delle operazioni aritmetiche

### 3 principi

* 1 la semplicità favorisce la regolarità
  * prevede soltanto istruzioni aritmetiche a 3 operandi
    * `add a, b, c`;
    * `sub dest, b, c`;
* operazioni complesse vanno scomposte in tanti piccoli passaggi
* commenti fatti con `#` proseguono per tutta la riga
* gli operandi possono operare solo su valori presenti sui registri sui cui quindi dobbiamo caricare le nostre variabili
* a disposizione 32 registri a 64 bit su cui fare operazioni
  * 64 bit = double word
  * 32 bit = word
* 2 minori sono le dimensioni, maggiore la velocità
  * la trasmissione del segnale è più rapida, per questo uso solo 32 registri veloci da raggiungere. Posso avere clock più corti/veloci
  * load
    * `ld x9, 8(x22)`
      * `ld` - operiamo su una parola doppia
      * `x9` - registro di destinazione
      * 8 - bytes di spiazzamento
      * `(x22)` - indirizzo base da cui partire
      * indirizzo finale - `(x22 + 8)`
    * es accesso ad una cella di un' array
      * `A[12] = h + A[8];`
      * `ld x9 8*8[(x22)]`
        * assumo che l'array sia composta da elementi tuti di 64 bit (8 byte)
  * register spilling
    * é l'operazione di caricare dalla memoria ai registri e viceversa i valori delle variabili che servono al momento. Il compilatore in automatico compie queste operazioni. (assomiglia al paging)
  * costanti e valori immediati vengono salvati su registri, non possono essere usati come operandi così allo stato brado. Questo è però molto scomodo ed inefficiente perciò esistono istruzioni che permettono di operare su costanti
    * `addi x22, x22, 4`
  * registro `x0` contiene il numero 0. Utile per spostare un registro in un altro tramite l'operazione di somma con lo 0
  * endians, modo in cui i numeri vengono salvati in memoria
    * Little Endian(Intel, RISC-V)
      * cifra più significativa a destra. l'indirzzo di memoria del numero punta alla cifra (byte) meno significativa.
    * Big Endian(Motorola e protocolli Internet)
      * cifra più significativa a sinistra. l'indirzzo di memoria del numero punta alla cifra (byte) più significativa.
  * rappresentazione delle istruzioni
    * istruzioni mnemoniche sotto forma di parole vengono tradotte in numeri e poi in binario per diventare vero e proprio codice macchina
    * RISC-V prevede che ogni istruzione(tipo R, registro) sia codificata in 32 bit
      * |numero bits|7 bit | 5 bit | 5 bit |3 bit|5 bit |7 bit | 
        |-------- |--------|-------|-------|-----|-------|---------|
        |esempio |0000000 | 10101 | 10100 | 000 | 01001 | 0110011 | |nome campo |funz7 | rs2 | rs1 |funz3| rd | codop |
        * 1, 4, 6 - campo codificano l'istruzione
        * 2 campo - secondo operando
        * 3 campo - primo operando
        * 5 campo - risultato
        * RISC-V prevede 32 registri numerati da 0 a 31 e che quindi possono essere specificati come operandi (5bit)
        * codop - codice operativo funzione
        * funz7 funz3 - codici operativi aggiuntivi
        * rs1 - primo operando sorgente
        * rs2 - secondo operando sorgente
        * rd - operando destinazine
* 3 un buon progetto richiede buoni compromessi
  * compromesso di codificare tutte le operazioni in 32 bit
    * limite numero istruzioni
    * limite numero registri
    * limite alle modalità di indirizzamento
    * molta efficienza
  * istruzione(tipo I, immediato)
  * |numero bits|12 bit | 5 bit | 3 bit |5 bit|7 bit |
    |-------- |--------|-------|-------|-----|-------|
    |esempio |0000000 | 10101 | 10100 | 000 | 01001 |
    |nome campo |cost o addr | rs1 |funz3| rd | codop |
  * esempio: `ld x9, 64(x22)`
  * istruzione(tipo S, store?)
  * |numero bits|12 bit | 5 bit | 5 bit |3 bit|5 bit |7 bit |
    |-------- |--------|-------|-------|-----|-------|-------|
    |esempio |0011111 | 00001 | 00010 | 011 | 01000 |0100011| |nome campo |cost o addr | rs2 |rs1 | funz3 | cost o addr | codop |
  * esempio: `sd x9, 240(x10)`