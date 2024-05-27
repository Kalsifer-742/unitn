# Lezione 3/05/22

## Pipeline

- introduzione al parallelismo
- fare le cose in maniera puramente sequenziale non conviene
- non devo aspettare che un job termini completamente per iniziarne uno nuovo, posso portare avanti piú cose contemporaneamente. questo perché 2 job possono essere in 2 fasi diverse
- obbiettivo mantenere la pipeline piena il piú possibile
  - durante il riempimento e svuotamento non sto andando al massimo della velocitá

### RISC-V

1. fetch
2. lettura registri e decodifica istruzione
3. esecuzione operazione o calcolo di indirizzo
4. accesso alla memoria (opzionale)
5. scrittura del risultato in un registro (opzionale)
   
- quindi la pipeline ha 5 stadi

### Performance

- nel caso ideale
- `tempo tra due istruzioni con pipeline` (inverso del throughput) `= tempo tra due istruzioni senza pipeline / numero di stadi della pipeline`

## Vantaggi RISC-V

- tutte istruzioni hanno la stezza lunghezza, facilita l'operazione di fetch
- posizione fisse degli operandi permettono un decode molto veloce
  - mentre decodifco l'istruzione posso giá andare a leggere i registri
- gli operandi in memoria sono disponibili solo per load e store. In questo modo possiamo usare la ALU per calcolare indirizzi. (Altrimenti dovrei usare la ALU 2 volte durante la stessa istruzione)
- accessi alla memoria allineati, sempre word e double word

> la regolaritá di RISC-V facilitano l'utilizzo della pipeline

## Hazard

### Svantaggi utilizzo pipeline

- hazard
  - strutturale
    - la stessa architettura (hardware) non permette l'esecuzioni di alcune operazioni tramite la pipeline
      - es: ho un unica memoria con istruzioni e dati, non potrei fare piú istruzioni contemporaneamente
  - sui dati
    - la pipeline viene messa in stallo per ottenere delle informazioni dagli stati precedenti
      - es: risultato dell'operazione precedente é un operando dell'operazione successiva
    - si puó risolvere  quasi sempre agendo a livello di compilazione. Le operazioni possono essere riordinate in modo vantaggioso mantenendo la logica del programma
    - si puó risolvere a livello hardware senza salvare il risultato in un registro (writeback) ma indirizzandolo direttamente all'istruzione successiva (bypass/operand forwarding)
      - questa propagazione puó avvenire solo verso gli stadi corrispondenti o successivi dell'istruzione successiva
  - sul controllo
    - salti condizionati bloccano la pipeline per la verifica della condizione
      - dobbiamo bloccare la pipeline per i cicli necessari
      - piú la pipeline é lunga piú la latenza aumenta
      - cerco di prevedere i salti
        - tramite assunzioni come quella che i branch non avvengano mai e quindi correggo la pipeline solo se avvengono
        - tramite circuiterie soffisticate che calcolano statistiche posso provare a prevedere cosa succeda
          - esempio un ciclo che si ripete in cui noto che la beq non si verifica probabilmente continuerá a non verificarsi per un tot di volte

> aggiorniamo lo schema della cpu tenendo ora conto della pipeline