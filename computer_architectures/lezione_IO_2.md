# Lezione 18/5/22

## Interrupts

- interrupt é un segnale usato per segnalare al processore che la periferica é pronta ad eseguire il trasferimento richiesto
  - possono avere diverso grado di urgenza
  - occorre un modo per sagnalare al processore quale periferica chiede l' interrupt
- sono asincroni rispetto al flusso delle istruzioni nel programma
  - non esistono istruzione assembly per generali ma solo per gestirli
  - posso ritardare l' interrupt ad un momento piú opportuno (per esempio posso impedire che funzioni fondamentali al calcolatore all' interno del kernel non vengano interrotte)
- **pro**
  - niente piú polling
  - non serve interrompere l' esecuzione del programma se non quando il dato é pronto
  - pago il costo solamente quando c'é un dato da trasmettere e non costantemente
- **contro**
  - occorre hardware speciale per
    - permettere alle periferiche di generare interrupts
    - rilevare l'interrupt e salvare lo stato per eseguire una ISR(Interrupt Service Routine) e riprendere da dove si era interrotto 
  - c'é dell'overhead rispetto al polling

## Exceptions

- trasferimenti non programmati del controllo del programma
  - eventi interni al programma che vanno gestiti, gestiti dal programma stesso
- System Exception Handler
  - routine di gestione delle eccezzioni che interviene salvando lo stato, gestendo l' eccezzione e ripristinando lo stato precedente.

Tipi di eccezzioni

- Interrupts
  - causati da eventi I/O...
- Traps (Eccezioni)
  - eventi interni al programma
    - page fault
    - segmentation fault
    - arithmetic overflow
    - ...
  - sincroni al programma
  - gestiti dal trap handler
  - posso provare ad rieseguire l'istruzione che ha generato l'errore o abortire il programma
- Environment call/break
  - call
    - esplicita richiesta di un servizio di sistema (stampa di un carattere)
  - break
    - esplicita chiamata per motivi diagnostici o di debug (break GDB)

## Gestione delle eccezioni

> stato della macchina viene salvato e poi ripristinato

- salto diretto all'indirizzo della routine di gestione
  - si associa al PC il registro STVEC che punta alla routine e viene salvata la causa nel registro SCAUSE
  - **pro**
    - non serve accedere alla memoria per ottenere l' indirizzo della routine di gestione
  - **contro**
    - nella routine di gestione occorre fare riferimento alla causa
- vettore di interruzione
  - memorizzo in una tabella gli indrizzi delle varie routine di gestione
  - STVEC contiene l' indirizzo base di una serie di routine di gestione che si occupano ognuna di una causa. SCAUSE viene comunque utilizzato e ora il PC sará assegnato come STVEC + SCAUSE * 4
  - **pro**
    - la causa dell' eccezzione é nota e puó essere utilizzata per identificare la routine opportuna
  - **contro**
    - serve accedere alla memoria per prelevare l' indirizzo della corretta routine di gestione

## Salvataggio stato della macchina

- Salvataggio sullo stack
- Salvataggio su registri ausiliari (visibili e non)
- Salvataggio in registri speciali

---

- RISC-V
  - salvataggio sullo stack e su registri speciali
  - vari registri a 64-bit utili a questo scopo
    - `SEPC`
      - contiene l'indirizzo dell' istruzione che ha generato l'eccezione
    - `SSTATUS`
      - contiene i bit di abilitazione globale degli interrupt
    - `SCAUSE`
      - i bit 63 e [3-0] codificano le possibili sorgenti di errore
    - `STVAL`
      - Supervisor Trap Value
      - Contiene l' indirizzo al quale si é verificato un riferimento errato alla memoria
    - `SIE`
      - specifica abilitazioni piú fini degli interrupt
    - `SIP`
      - SUpervisor Interrupt Pending
      - Monitoraggio degli interrupt di attesa
    - `STVEC`
      - indirizzo interrupt
    - `SSCRATCH`
      - registro per salvataggi temporanei
  - questi registri si trovano in un banco interno al processore chiamato Control Status Register (CSR)
  - al verificarsi di eccezioni la parte di controllo della CPU modifica questi registri
    - PC viene aggiornato a PC+4
    - l'istruzione colpevole da memorizzare in SEPC é quindi il PC
    - il PC viene sovrascritto al valore di STVEC

---

- Sstatus Register
  - livello di privilegio
    - S-Supervisor
    - U-User
    - chi si trova ad un livello non sa se esistono livelli di privilegio superiori
  - SIE (S- Interrupt Enable bit 10)
    - abilita globalmente gli interrupt a quel dato livello, per non entrare in loop viene subito disabilitato a 0 quando l' interrupt é stato gestito
  - SPIE (S- Previous Interrupt Enable bit 5)
    - indica lo stato precedente del bit SIE al momento dell'eccezione
  - SPP (S- Previous privilege mode bit 8)
    - indica il livello di privilegio precedente al momento in cui si é verificata l'eccezione

---

- Sie(interruzione effetuata) e Sip(interruzione pending, in attesa) register
  - controllo fine(preciso) degli interrupt
  - i bit di abilitazione danno informazioni sulla sorgente dell'eccezione
    - E => interrupt esterno
    - T => interrupt del timer
    - S => interrupt software
 
---

> slide 18 riasume cosa succede all'avvenire di un interrupt

- SRET
  - utilizzata per ripristinare lo stato della macchina al momento precedente all' interruzione
 
---

- SCAUSE register
  - Int(1 bit), bit 63
    - 1 - sorgente é un interrupt
    - 0 - sorgente é un eccezione
  - Code(4 bit), bit 3-0
    - codifica la ragione dell'eccezione

---

> istruzioni RISC-V per la letture e scrittura di SEPC, SCAUSE ecc...(registri speciali)

- Atom instructions (Immediate +I)
  - secondo operando é sempre il csr(STVEC, ecc...)
  - Atomic Read & Write
    - `CSRRW`
  - Atomic Read & Set bits
    - `CSRRS`
  - Atomic Read & Clear bits
    - `CSRRC`

---

> slide 21-.. gestione delle eccezzioni in RISC-V, cambiamento del datapath, occortezze nella pipeline