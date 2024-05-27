# Lezione 02/05/2022

> tabelloni e schemoni riassuntivi sulle slide 17

## CPU

### sempre piú avanti

- riutilizzo delle stesse componenti per fare diverse operazioni
  - utilizzo multiplexer per redirigere il segnale e indtrodurre diversi input oltre che diversi output
- promemoria che qualsiasi operazione deve avvenire in max 1 ciclo di clock

## ALU

- la utilizziamo per fare diverse operazioni diverse da loro
  - per generare i bit di controllo della ALU utilizziamo:
    - i campi funz7, funz3 e due bit detti ALUop
  - utilizziamo una codifica a livelli multipli
    - 1 livello - unita di controllo genera gli ALUop basandosi sul codop dell'istruzione assembly
    - 2 livello - unita di controllo della ALU combina ALUop, funz3 e funz7
      - genera i segnali di controllo per la ALU

> esempi completi di codifica e cicli di clock dei vari tipi di istruzioni sulle slide

- abbiamo un mapping tra i segnali di controllo e il codop dell'istruzione

## Clock

- di fatto il clock non é veramente tarato sull'operazione piú lenta perché é estremamente svantaggioso.
  - impedisce ottimizzazioni
- modernamente la cpu é composta di sotto componenti che possono lavorare a frequenze diverse
- non stiamo ancora considerando l'esistenza della cache