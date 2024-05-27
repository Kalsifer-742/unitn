# Lezione 9/5/22

## Memorie

- ad indirizzamento diretto
  - volatile
  - immediato accesso
  - cache
  - ram
- ad indirizzamento indiretto
  - non volatile
  - hardisk

> accenni al paging/swapping

- tempo di accesso
  - tempo richiesto per un' operazione
- tempo di ciclo
  - tempo tra due operazioni successive
- accesso
  - casuale
  - sequenziale

- RAM
  - random access memory
- ROM
  - read only memory

- MAR
  - memory address register
    - indirizzo
- MDR
  - memory data register
    - dato vero e proprio
- linee di controllo
  - MFC
    - memory function completed

- memoria organizzata come matrice
  - in base a come raggruppo i bit cambio anche il numero di pin I/O del banco di memoria

## Hardware

- il banco possiede un address decoder
- sense write circuit
  - selezione la modalitá di lettura o scrittura della cella
- la struttura puó essere implementata con diverse tecnologie
  - consumano poco
  - hanno accesso veloce

### SRAM

- cella di memoria
  - piú componenti per cella

> discorso su perché avere 2 linee per ogni cella e costruzione interna tramite transistore e diodi in retroazione. Necessario avere sotto le slide e vedere i disegni

### DRAM

- un unico componente per cella
  - densitá molto elevata
- richiedono un continuo refresh
  - consumano di piú

> schema per capire lettura e scrittura sulle slide

- abbiamo bisogno di un sacco di I/O a causa della quantitá di celle
  - per risolvere multiplexo (nel tempo) indirizzamento alle righe e alle colonne
    - prima passo indirizzo righe, poi quello delle colonne
  - memorie non indirizzate al singolo bit

> altri schemi importanti per capire come funziona l' indirizzamento

- trasferimenti
  - di solito trasferisco dati a blocchi(pagine)
- FPM
  - fast page mode
  - se salvo i dati consecutivamente non ho bisogno di riselezionare la riga ad ogni trasferimento ma posso semplicemente continuare a leggere in modo sequenziale

- sync
  - non sono sincronizzate e le operazioni vengono gestite da particolari segnali: RAS e CAS.
  - il processore deve tenere conto di questo eventuale desync

### SDRAM

- ram sincrone praticamente
  - aggiungo dei buffer per sincronizzare
  - in questo modo disaccoppio l' operazione di lettura da quella di refresh
  - accesso FPM facile

- latenza
  - quanto il processore deve attendere per un dato dalla memoria nel caso peggiore
- velocitá massima possibile/banda (in modalitá FPM)
  - utile per le cache
  - trasferimento dati con periferiche molto velocitá

- posso scrivere in fronte di salita e discesa separando i banchi in uno sensibile ai fronti di salita ed uno sensibile ai fronti di discesa
  - non perdo performance
  - lo faccio organizzando la memoria in banchi separati