# Lezione 4/4/22

## Intel x86 - 64bit

- retrocompatibilità
  - processori in grado di eseguire istruzioni anche ad 8 bit, in codice scritto per l'intel8080

- vari assembler
  - consideriamo **gas** (GNU Assembler)

## Registri

- 16 registri (circa tutti general purpose) a 64 bit, tutti preceduti da `%`
- es
  - `%rsp` stack pointer (convenzione)
- i registri come `%rax` sono estensione di registri a 32 bit che a loro volta sono estensione di registri a 16 bit e cosí via...
- `%rax` - 64 bit
  - `%eax` - 32 bit
    - `%ax` - 16 bit
      - `%ah` - 8 bit 
      - `%al` - 8 bit
- registri speciali
  - `%rip` instruction pointer
  - `%rflags` registro che contiene le flags. ogni bit rappresenta una diversa flag
    - es: carry flag - somma overflow

## ABI convenzioni di chiamata

- primi 6 argomenti
  - `%rdi`, `%rsi`, `%rdx`, `%rcx`,` %r8`, `%r9`
- 7+ argomenti
  - stack
- valori di ritorno
  - `%rax`, `%rdx`
- registri preservati
  - ... slides
- registir non preservati
  - ... slides

## Operazioni

- istruzioni a 2 operandi, il 2 operando è anche la destinazione
  - primo operando
    - costante, prefisso `$`
    - registro
    - valore in memoria, indirizzo `0x0000AB`
  - secondo operando
    - registro
    - locazione in memoria
- operazioni in grado di scrivere sia sui registri che sulla memoria a differenza di RISC-V
- unica limitazione, no entrambi operandi in memoria
- parentesi tonde attorno ad un indirizzo (magari contenuto in un registro )intendono accesso in memoria
  - es: `(%eax)`

## Indirizzamento

- `displacement (base register, index register, scale)`
- `displacement + base register + index register * scale`
  - `displacement`
    - costante a 8, 16, 32 bit
  - `base`
    - indirizzo base a cui sommare lo spiazzamento
  - `index`
    - valore preso da un altro registro utile per scorrere gli array
  - `scale`
  - potenza di 2 da 1 a 8 per scorrere un array
- casi speciali
  - `scale = 1` / no scale
  - no scale no index
    - simile a RISC-V
  - no scale no index no displacement
  - no displacement
  - ... altre combinazioni
- tabella utile sulle slide

## Sintassi

- carattere finale di opcode indica il tipo con cui stiamo operando
  - b: 8bit
  - w: 16bit
  - l: 32bit
  - q: 64bit

## Istruzioni più comuni

> praticamente tutte implementabili tramite altre istruzioni più semplici che vengono fatte implicitamente

- `mov`
  - movsx: copia dati con estensione del segno
  - movvz: copia dati con estensione con 0
- `add`
  - somma
- `sub`
  - differenza
- `mlt`
  - moltiplicazione
- `div`
  - divisione
- `inc`
  - incremento
- `rcl`
  - rotazione
- `sal`
  - shift logico
- `and/or`
- `neg`
  - complemento a 2
- `nop`
  - no operation, non fa nulla
- `stack`
  - pushq %reg
  - popq %reg
  - implementabili tramite move e modifica del valore di %rsp
- `cmp`
  - confronto tra argomenti
  - arg2 - arg1
  - setta flag
  - non modifica operandi
- `test`
  - confronto tra argomenti
  - and bit a bit
  - non modifica operandi
- `jmp`
  - salto incondizionato
- `je / jnz / jc / ...`
  - effettua un salto in base al valore di una flag
  - tabella utile sulle slide
- move condizionata in base al flag o modificata in base al tipo che viene specificato 
- `call`
  - chiamata a procedura
- `ret`
  - ritorno da procedura
- `lea`: load effective address
  - utilizzata per calcolare indirizzi senza accedere direttamente.
  - posso usarla per simulare cose del tipo: `add x3, x2, x1`. somme di piu operandi
  - usata per fare tanti trick magici dato che permette di fare somme, moltiplicazioni ecc... tra piú operandi e salvare il risultato da un altra parte
- extras
  - `inc`, `dec`
  - utili e non sostituibili da una add 1 perchè la codifica è variabile, potrei star salvando i numeri a 8 o 16 bit invece di 64 per esempio

## Esercicizi

da `C` a `x86`