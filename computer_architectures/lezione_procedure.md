# Lezione 28/03/22

## Procedure

- carico i parametri di input in posti noti a priori
- trasferisco il controllo alla procedura
  - acquisisce le risorse necessarie
  - esecuzione del compito
  - carico valori di ritorno in posti noti
  - restituisce il controllo al chiamante
- prendo il valore di ritorno e pulisco registri ecc...
- ogni architettura ha il suo protocollo su come debbano essere chiamate le procedure
- protocollo di chiamata RISC-V
  - utilizzare dove possibile i registri per passare i parametri (meccanismo più veloce)
    - `x10-x17` parametri di ingresso e di ritorno
    - `x1` indirizzo di ritorno per tornare al punto di partenza (ra, return address)
  - `x1` usato in particolare dalle istruzioni `jal`, `jalr` che effettuano il salto e contemporaneamente salvano l'indirizzo di ritorno in x1
  - l'indirizzo salvato in `x1` è il pc (program counter) + 4 (8bit * 4 = 32, istruzioni codificate in 32 bit istruzione successiva alla jal/jalr)
- se i parametri sono più dei registri disponibili si una uno stack i parametri in più.
  - `x2` (chiamato sp) è il registro che contiene l'indirizzo da cui partire a caricare i parametri nello stack
  - lo stack si può usare anche per salvare variabili locali e valori di registri che serviranno in seguito.
  - alla fine della procedura devo ricordarmi di pulire lo stack
- Prologo
  - è la fase in cui vengono salvati in memoria tutti i registri che la procedura usa per poi essere ripristinati. Durante la stessa fase vengono allocate le variabili locali nello stack se i registri non sono sufficienti
- Epilogo
  - fase in cui i valori salvati vengono ripristinati, e lo stack ripulito
- altre convenzioni sui registri
  - `x5-x7` e `x28-x31` - registri temporanei che non devono essere salvati in caso di chiamata a procedura
  - `x8-x9` e `x18-x27` - registri da salvare in caso di chiamata a procedura
- procedure ricorsive implementabili tramite lo stack

## Storage class

- variabili statiche
  - `x3` registro gp, global pointer

## Record di attivazione - Stack frame

- segmento di stack che contiene i registri salvati e le variabili locali
- `x8` registro fp, frame pointer
  - punta alla prima double word del frame di una procedura

## Dati dinamici

- stack e heap crescono una contro l'altra
  - stack, indirizzi decrescenti
  - heap, indirizzi crescenti

## Ottimizzzazione

- ricorsione è marcia perchè magari devo avere molteplici stack-frame e spostare tante cose in memoria
- posso fare la ricorsione di coda in cui la chiamata ricorsiva è l'ultima cosa che viene fatta. Questo semplifica molto l'esecuzione ma non elimina il problema
- Grazie alla ricorsione di coda posso effettuare dell'ottimizzazione che alcuni compilatori con le opportune flag eseguono in automatico. Con intelligenza posso ridurre il numero di istruzioni necessarie e rendere il codice più breve
