# Lezione 17/5/22

## I/O

- indispensabiole perché permette di interfacciarsi con il calcolatore, che sarebbe inutile, se sprovvisto di tali interfacce
- sistemi espandibili ed eterogenei
- sistemi dalla diversa prestazione
  - tempo di accesso / latenza / tempo di risposta
    - dispositivi interattivi (mouse)
  - throughput
    - dischi, interfacce di rete
- i dispositivi di comunicazione sono collegati al processore tramite un bus apposito
  - concetto di interrupt

## Bus

- processore/memoria
  - specializzati, corti, veloci
- Bus I/O
  - lunghi e permettono la connessione di periferiche eterogenee
  - tipicamente non sono collegati direttamente alla memoria e si appoggiano ad un Bus di sistema
    - nelle prime architetture si utilizzava un unico grosso bus parallelo che collegava tutto
    - per problemi di clock e frenquenze ora si usano architetture piú complesse formate da piú bus
- Bus sincrono
  - tra le linee di controllo vi é il clock
  - funziona tramite un protocollo collegato al ciclo di clock
  - tutto avviene su istanti di tempo discretizzati
  - **pro**
    - molto semplice da implementare
    - molto veloce
  - **contro**
    - poca robustezza al drift(piccoli scostamenti) del clock
    - tutte le periferiche devono andare alla stessa velocitá
- Bus asincrono
  - governato da segnali di handshake
  - periferiche e processore segnalano quando hanno dati da trasmettere
  - sono necessarie apposite linee di controllo per segnalare inizio e fine transizioni che permettono di collegare periferiche a velocitá diversa
  - concetto di master e slave, chi spedisce e chi riceve
  - **pro**
    - robusto relativamente ad eventuali ritardi
    - consente di comunicare con periferiche di tipo diverso
  - **contro**
    - lento nelle interazioni (diversi segnali di controllo necessari alla comunicazione)
    - circuiteria di gestione del procotocollo complessa
- Bus ibridi
  - spesso utilizzati
  - sono asincroni ma é presente anche un segnale di clock
- Esempio x86
  - Controllore hub della memoria (North bridge)
    - hub per contriollo memoria
  - Controllore hub dell' I/O (South Bridge)
    - hub per connessione ad altri bus
  - North bridge é collegato a processore e memoria, il south bridge é collegato "in cascata" al north bridge. I dati passano quindi per il northbridge per comunicare con la memoria o il processore
  - recentemente
    - si incorpora tutto all' interno del processore

## Sistema Operativo

- programmi che condividono il processore condividono il sistema di I/O
- i trasferimenti dati vengono effettuati utilizzando interrupt
  - la gestione viene effettuata solamente dal kernel quando il processore entra in modalitá supervisor. Non puó quindi essere effettuata da un programma scritto dall' utente
- controllo di operazioni I/O spesso si interseca con le problematiche di concorrenza
- Il sistema operativo deve
  - garantire che un utente abbia i permessi per accedere alle periferiche di I/O
  - fornire comandi di alto livello per gestire operazioni di basso livello
  - gestire gli interrupts generati dai dispositivi di I/O
  - gestire la concorrenza, quindi ripartire equamente tra i programmi l' accesso ad un dispositivo
- Per implementare queste funzionalitá serve che
  - il SO possa inviare comandi alle periferiche
    - memory mapped I/O
    - tramite istruzioni speciali dedicate all' I/O
  - i dispositivi possano notificare la corretta esecuzione di un' operazione
  - sia possibile trasferire dati direttamente tra dispositivo e memoria

## trasmettere / ricevere dati

- memory mapped
  - scrivendo/leggendo in particolari locazioni di memoria per passare i comandi di controllo
    - il controllore I/O intercetta l' indirizzo particolare che viene invece ignorato dal controllore della memoria e trasmette il dato sotto forma di comando (ogni periferiche ha un' indirizzo di memoria mappata ad essa)
    - queste aree di memoria non sono accessibili ai programmi ma solo al sistema operativo
    - quando un dispostivo vuole comunicare utilizza le stesse aree di memoria
    - esempio
      - quando premo un carattere per scriverlo a terminale un particolare bit verrá settato a 1 per indicare la corretta stampa del carattere
- modalitá piú semplice per trasmettere dati é il polling
  - attendo attivamente e testo periodicamente un bit di stato per esempio
  - > esempio in RISC-V
  - costo del polling
    - il processore spreca troppo tempo (cicli di clock) a verificare lo stato delle periferiche, soprattuto se sono molto veloci