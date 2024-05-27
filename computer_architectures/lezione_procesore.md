# Lezione 26/4/22

## CPU

* passaggi generici
  * prelievo istruzione dalla memoria
  * lettura di valori o registri che vengono ricavati a partire dai campi dell'istruzione
* utilizzano la ALU quasi tutti i tipi di istruzioni
  * calcolco indirizzo per salvare o leggere dati
  * istruzioni aritmetico/logiche
  * branch con confronti
* datapath
* ciclo della cpu/percorso dei dati - schema sulle slide
  * program counter
  * memoria istruzioni (fetch)
  * registri (carico operandi)
  * ALU
  * blocchi sommatori (gestiscono il pc)
* (datapath) semplicificazione non accurata
  * non vi é un flusso continuo di dati ma tante eccezzioni ed input condizionali
    * entrano in gioco i multiplexer
  * serve un qualcosa che dall'alto coordini tutto e invii diversi segnali di controllo
  * non stiamo considerando il tempo
* tutti bus a 64bit e 32bit(istruzioni)
* clock di sistema
  * semplifichiamo immaginando che il clock basti per tutte le istruzioni e che tutto avviene in 1 ciclo di clock
  * nella realtá i componenti possono operare a clock diversi
* flip flop latch d
  * utilizzati per fare registri
  * utilizzati per temporizzare diversi componenti, in modo da evitare inconsistenze

> ha continuato per un sacco a mostrare paso passo come vengono scompattate le istruzioni. Ha detto un sacco di cose ovvie apparte alcune utili a cui stare attenti da riguardare rapidamente sulle slide. Sono le uniche cose non intuitive che bisogna sapere e basta. Riporto le piú importanti:

Salto condizionato

Anche in questo caso bisogna sommare all’attuale PC l’offset a 12 bit (dopo averlo\
esteso a 64 bit con segno) che consente di fare salti da -2^12 a 2^12 .

Note:

* L’architettura dell’insieme delle istruzioni specifica che l’indirizzo di base per il\
  calcolo dell’indirizzo di salto è quello dell’istruzione di salto stessa.
* L’architettura stabilisce che il campo offset sia spostato di 1 bit a sinistra per\
  fare sì che l’offset codifichi lo spiazzamento in numero di mezze parole\
  (aumentando lo spazio di indirizzamento dell’offset di un fattore 2 rispetto a\
  codifica dello spiazzamento in byte).
* La ragione per lo shift di uno (anziché di due) è dovuta alla presenza non\
  documentata sul libro di istruzioni compresse a 16 bit per alcuni processori\
  RISC-V.