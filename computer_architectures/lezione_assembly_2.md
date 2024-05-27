# Lezione 22/3/22

## Istruzioni e varie

- shift logico a sinistra corrisponde alla moltiplicazione. n x 2^k, dove k è il numero delle posizioni di shift. (problemi di overflow)
- shift logico a destra corrisponde alla divisione. n / 2^k.
  non funziona sempre (numeri negativi), quindi utilizziamo lo shift artimetico a destra; ovvero a sinistra non aggiungo 0 ma bit uguali al bit di segno
- and bit a bit (maschera per settare bit a 0)
- or bit a bit (maschera per settare bit a 1)
- rotazione, non c'é un operazione automatica ma puó essere ottenuta per mezzo di successive istruzioni (shift su registri diversi ed un or finale)
- `XOR`
  - `xor x9, x9, x9` ha come effetto di azzerare il valore del registro x9
- `NOT`
  - non viene fornito da RISC-V essendo un operatore unario. In risc-V tutte le operazioni devono avere 3 operandi di tipo registro.
  - Il `NOT` si può derivare dallo `XOR: NOT(A) = XOR(A, 1)`
- salto condizionato
  - `beq rs1, rs2, L1` `if(rs1 == rs2) jump to L1`
  - `bne rs1, rs2, L1` `if(rs1 != rs2) jump to L1`
  - specifico a quale riga fare il salto per mezzo delle LABEL, queste ultime vengono tradotte in indirizzi dall'assembler
  - blocco di base
  - > sequenza di istruzioni che non contengono ne istruzioni di salto ne etichette di destinazione
  - una delle prime fasi della compilazione è quella di individuare i blocchi di base.
  - Tutti i cicli in linguaggi di alto livello vengono implementati con blocchi di base.
  - altri tipi di salto condizionato basati su diverse condizioni: <, >, < (unsigned), >= (unsigned)
    - u sta per unsigned
  - trucchetto:
    - posso usare bgeu per controllare se un indirizzo è valido per un array. Non tenendo conto del fatto che il numero sia negativo o meno posso controllare sia che l'indice non sia troppo grande o inferiore a 0
  - switch case
    - cascata di if-then-else
    - tecnica diversa
      - salvo in dei registri (tabella) gli indirizzi a cui saltare.
      - carico in un registro l'indirizzo a cui saltare
      - faccio un salto incondizionato all'indirizzo puntato dal registro tramite l'istruzione `jalr` (jump and link register)
  