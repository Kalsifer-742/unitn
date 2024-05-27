# Lezione 5/4/22

## ARM

- via di mezzo tra CISC e RISC
- utilizzata in sistemi embedded (telfoni, tablet), molto efficiente energeticamente
- nasce a 32 bit
- no retrocompatibilitá come intel
- RISC pragmatico, avanzato per cosí dire
- molte e potenti modalitá di indirizzamento
- minore densitá del codice perché codifica istruzioni a numero fisso di bit
- ridotto numero di registri 16, tutti general purpose

## Registri

- 16 bit a 32 registri, r0-r15
- r13 = stack pointer
- r14 = link register (indirizzo ritorno da chiamata a procedura)
- registro di flag
- utilizzo dei registri non forzato dall'ISA ma dall'ABI
- r15, program counter e flags (ultimi 4 bit)
  - z, c, n, v i 4 flag
- tabella sulle slide di tutti i flags

## Convenzioni di chiamata

> dipende sempre dall'ABI. Ci sono eccezzioni specifiche

- r0-r3 r12 registri i primi temporanei
- registri r4-r11 devono essere salvati
- r0, r1 valori di ritorno
- istruzioni prevalentemente a 3 argomenti
  - operando sinistro: registro
  - operando destro: immediato o registro
- no operandi in memoria
- `load/store` unice operazioni che accedono alla memoria

## Indirizzamento

- base + offset(immediato)
- base + indice(eventualmente scalato)
- (writeback) possibilitá di aggiornare il registro base con `!` (salvare nel registro base l'indirizzo di memoria calcolato)
  - pre-index (funziona normale come ti aspetteresti)
    - `[rb, #i]`_`[!]`_
    - `[rb, {+|-}ro`_`[,<shift>]`_`]`_`[!]`_
  - post-index (le modifiche vengono fatte all'indirizzo base dopo aver ottenuto e salvato il dato, writeback di default/implicita)
    - `[rb], #i`
    - `[rb, {+|-}ro`_`[,<shift>]`_`]`

`i = <base> + {<offset> | <indice (shiftato)>}`

- base: valore in registro
- offset: costante/immediato codificato su 12 bit
- indice: valore in registro(semplice iterare array)
- `<shift>` shift aritmetico o logico o ratazioni del registro ro. Sen non ci sono rotazioni puó essere omesso
- offset = 0 puó essere omesso

> Esempi sulle slide

- indirizzamento piú potente rispetto a RISC-V
  - aggiornamento automatico registro base
- non puó usare contemporaneamente offset ed indice a differenza di Intelx86

## Istruzioni piú comuni

- add
- addc
  - add with carry
  - aggiunge il carry bit
- sub
- subc
- rsb
  - reverse sub, fa l'operazione con gli operandi invertiti
- rsc
- and
- orr
  - or
- eor
  - xor
- bic
  - bit clear
  - funziona da maschera, ogni 1 in r2 mette a 0 il bit corrispondente in r1
- mul
  - moltiplication
- mla
  - multiplication and accumulate
  - fa una moltiplicazione e ci somma un altro valore
- shfit e rotazione
  - tramite manipolazione del terzo argomento
- non esiste la div tra interi e va implementata
- mov
  - muove dati tra registri
  - posso muovere nei registri una costante
- mvn
  - move not, muove il complemento a 1 di un registro
- b
  - branch, salto incondizionato o condizionato
- bl
  - branch and link
  - per usare le subroutine
  - salva indirizzo di ritorno in r14, il link register
- cmp
  - compare
  - setta flag senza salvare il risultato
  - si usa in combinazione con l'operazione di branch che controlla le flag per dirigere il flusso
- tst
  - settano i bit di carry
  - and bit a bit
- teq
  - xor bit a bit
- cmn
  - somma
- ldr
  - load register
- str
  - store register
- load/store esistono su 32(ldr),16(ldrh),8(ldrb) bit
- ldm
  - load multiplo
  - `ldm r0, {r1,r2,r3}` (non importa in che ordine vengono scritti i registri, poi vengono riordinati in modo crescenete per evitare inconsistenze)
    - carico in r1, r2, r3 la aree di memoria contigue successive ad r0
- stm
  - store multiplo
- ldm/stm
  - consentono di trasferire grandi quantitá di dati in modo efficiente
  - utili per gestire lo stack nei momenti di prologo ed epilogo

`ldm<mode> r [!], <register list>`

- mode (cambia anche il valore di writeback)
  - `ia` increment after
  - `ib` increment before
  - `da` decrement after
  - `db` decrement before
- se `!` é specificato, `r` viene aggiornato di conseguenza all'ultima area di memoria a cui abbiamo fatto accesso

> Seguono esempi di qaule area di memoria vado a leggere in base alla modalitá e come le cose cambiano in generale. Poi si procede con altri esempi generali di approfondimento su ARM

### sintassi

> guardare le slide per una sintassi corretta e piú precisa

- costanti `#3`
- commenti `@commento`
