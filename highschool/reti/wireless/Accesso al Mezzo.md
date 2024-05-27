# Accesso al Mezzo nelle WLAN

Secondo lo standard 802.11 - WiFi

Ci sono diverse tecniche di accesso al mezzo specificate dallo standard, tra cui:

* DCF (Distributed Coordination Function/Funzione di Coordinazione Distribuita)\
  Coordinazione senza stazione centrale, per le reti ad hoc, basato su CSMA/CA
* PCF (Point Coordination Function/Funzione di Coordinazione dei Punti)\
  Prevede una stazione base che coordina le trasmissioni, tecnicamente non si basa su CSMA perché l'accesso al mezzo non è regolato dalle singole stazioni che ascoltano il canale (Carrier Sensing), tuttavia siccome PCF deve stare in ascolto per richieste dalla stazione base e PCF e DCF possono coesistere nella stessa rete si può dire che l'implementazione odierna sia, fino a un certo punto, basata almeno sul CSMA

Nel CSMA/CD invece si basa sul controllare il mezzo durante la trasmissione per detectare le collisioni, tuttavia leggere e scrivere il mezzo è impossibile per connessioni wireless.\
Il CSMA/CA, e quindi anche DCF e PCF, si basano sull'ascoltare il mezzo per tempi prestabiliti in modo da evitare collisioni

Nel CSMA/CA:

* Il tempo è diviso in time slots
* Ciascuna stazione che deve trasmettere attende del tempo durante il quale il mezzo deve rimanere libero
* Se il canale rimane libero, ci si può preparare a trasmettere secondo una procedura descritta dopo
* Se il canale risulta occupato, si aspetta del tempo

Nel DCF:

* Esistono unità di tempo, come:\
  SIFS - è la differenza di tempo tra l'ultimo simbolo nell'aria della richiesta e il primo simbolo nell'aria della risposta, è definito dallo standard in base a stime riguardanti l'hardware disponibile.\
  DIFS - DCF Interframe Space - Tempo usato da DCF (??, NOTE: il PDF *sembra* parlare di DCF al posto di CSMA/CA ma è un po' un casino e non ho tempo di cercare) per separare la trasmissione di due frame diversi, è calcolabile in base al SIFS.\
  EIFS - Extended Interframe Space - Calcolabile in base a SIFS, DIFS e altre metriche\
  SIFS < DIFS < EIFS
* Una stazione prima di trasmettere aspetta il tempo DIFS.
* Se il mezzo trasmissivo viene occupato durante quel tempo DIFS le stazioni che devono trasmettere attendono un tempo di backoff, la cui durata è casuale entro un certo limite massimo (nel PDF sembra molto confusa riguardo cosa chiamare "backoff" e cosa no, vari documenti anche abbastanza ufficiali non si riferiscono a questa procedura come "backoff" anche se è letteralmente ciò che accade. Credo la procedura di backoff più importante che differenzia il DCF sia quella che viene dopo).
* Se il mezzo trasmissivo rimane libero per un tempo DIFS, ci potrebbe essere una sorta race condition - più stazioni potrebbero tentare di accedere in scrittura al mezzo, con il rischio di non notare l'azione degli altri. Il DCF quindi specifica una procedura di backoff apposita per l'evitazione di questa situazione.\
  Tutte le stazioni hanno un contatore di backoff, chi lo ha a 0 lo imposta a un numero semi-casuale (vedere binary exponential backoff algorithm su Wikipedia se si vuole) e inizia il countdown. La prima che raggiunge lo 0 inizia a trasmettere, le altre fermano il proprio contatore e lo lasciano a qualsiasi numero abbia raggiunto, in modo da ripartire da quel punto alla prossima contesa. Chi ha dovuto saltare la trasmissione avrà probabilmente il counter più basso e quindi sarà privilegiato la prossima volta.\
  Siccome il tempo di backoff non è completamente casuale (non può essere troppo alto ad esempio) la probabilità che due stazioni scelgano lo stesso tempo di backoff è ancora abbastanza alta, quindi lo standard prevede l'esistenza di un frame Ack da mandare per confermare il successo della trasmissione. Questo frame viene mandato dopo che il canale è stato libero per un tempo SIFS invece di DIFS, resettando il timer di tutti e comunicando quasi istantaneamente.

### Problema della Stazione Nascosta

![Stazione Nascosta.png](Stazione%20Nascosta.png)  
Se A vuole comunicare con C non potrà notare le trasmissioni di B e quindi seguirà tutti i passaggi descritti nella DCF/PCF senza trovare problemi, causando interferenze nella comunicazione che potrebbe essere in corso tra B e C. Il problema può sorgere anche con B che vuole comunicare con C mentre quest'ultimo è occupato con A.

### Problema della Stazione Esposta

![Stazione Esposta.png](Stazione%20Esposta.png)  
B e C vogliono comunicare rispettivamente con A e D. Se B e C controllano il canale potrebbero concludere che l'altro sta accedendo al mezzo e quindi evitare la comunicazione, anche se il raggio di A e D non potrebbero mai leggere le trasmissioni dell'altro e quindi non potrebbero avere interferenze.

### RTS/CTS e Virtual Carrier Sensing

In risposta al problema della stazione nascosta si usa la coppia di frames RTS (Request to Send) e CTS (Clear To Send).

Quando A vuole comunicare con C può mandare un RTS a cui C risponde con CTS, il frame CTS viene letto anche da B che, pur essendo fuori dal raggio di A, è nel raggio di B e rileva quindi il canale come occupato.\
I Frames RTS e CTS possono avere un header chiamato duration che comunica alle stazioni una stima di quanto tempo il canale rimarrà occupato. Questa tecnica che avvisa le altre stazioni di quanto tempo il canale rimarrà occupato è chiamata NAV, Network Allocation Vector/Vettore per l'allocazione della rete, l'header duration è una possibile implemetazione.

Le comunicazioni riguardanti un RTS (quindi il CTS, eventuali dati e corrispondenti ACK) possono avvenire a distanza di SIFS invece che di DIFS perché la rete è allocata/riservata a una comunicazione e quindi non c'è contesa. La stima della durata per chi manda l'RTS comprende il tempo necessario alla ricezione di CTS, all'invio dei dati, la ricezione del corrispondente ACK e tutti i SIFS tra di loro, mentre la stima della durata che verrà inserita nel CTS è lo stesso valore ma viene tolto il tempo di ricezione del CTS e il relativo SIFS.

È possibile frammentare i pacchetti lunghi per efficienza di trasmissione e ritrasmissione in caso di interferenze e comunque sfruttare la velocità che ci dà una comunicazione preceduta da RTS/CTS  (il NAV ci permette di allocare la rete e ignorare quindi il backoff per contese) secondo un algoritmo send and wait (mandiamo il frame e poi aspettiamo il corrispondente ack).\
Ad ogni frame e corrispondente ACK è associato un nuovo header duration che aggiorna quello trattato precedentemente, allungando il tempo della comunicazione.\
In caso di fine comunicazione o mancato ack non c'è bisogno di annunciarlo alla rete, allo scadere della durata si ricomincerà ad usare il DCF/PCF normalmente aspettando un tempo DIFS etc etc.

# Differenze DCF - PCF

* La stazione coordinante sonda le altre stazioni per vedere se hanno da trasmettere, ogni trasmissione dev'essere autorizzata dalla stazione base e quindi solitamente non avvengono collisioni.\
  Lo standard definisce i frames necessari alla registrazione delle stazioni presso quella base/coordinante e al controllo della comunicazione da parte della stazione base
* Lo standard definisce anche delle tecniche che permettono alla stazione base di comandare la sospensione di una stazione, ottimizzando il consumo energetico

Nonostante le differenze secondo lo standard DCF e PCF possono coesistenere (alcuni dispositivi possono decidere di supportare solo uno dei due ad esempio) secondo le seguenti regole:

* Terminata una trasmissione possono accedere al mezzo dopo un tempo SIFS solo chi deve rispondere con un ack, chi deve rispondere a un RTS con un CTS o chi ha ricevuto un Poll dalla stazione base/coordinante
* Esiste il lasso di tempo PIFS (PCF Interframe Space), L'Access Point/Stazione coordinante aspetta un tempo PIFS invece di DIFS prima di occupare il mezzo. Siccome PIFS è sempre inferiore a DIFS e le altre stazioni resetteranno il timer quando vedranno il canale occupato, la stazione base ha la priorità sulla comunicazione nel canale, anche se esistono modi per evitare che sfrutti la sua priorità in modo da permettere anche a chi usa DCF di comunicare dopo il tempo DIFS.\
  SIFS < PIFS < DIFS < EIFS
* Il tempo EIFS è usato dalle stazioni che hanno ricevuto un frame cattivo per annunciarlo, si aspetta un tempo EIFS perché è possibile che il frame fosse inteso per un'altra stazione, quindi per evitare di interferire con l'Ack si abbassa la priorità dell'errore

# CSMA/CA in IEEE 802.15.4

IEEE 802.15.4 definisce la base per varie connessioni a medio raggio (WPAN - tipo Bluetooth) a basso rate di scambio di informazioni (il basso rate è necessario in implementazioni IoT, dove il risparmio energetico è importante). Stare in costante ascolto non è molto efficiente in termini energetici, quindi i dispositivi al posto di ascoltare durante il periodo di backoff per fermare il counter controllano solo allo scadere del tempo. Chi finisce prima trasmetterà e chi finisce dopo troverà il canale occupato, senza possibilità di fermare il counter e usare il tempo residuo successivamente, questo implica che le stazioni che hanno perso più contese non guadagnano maggiore probabilità perché non possono conservare il tempo di backoff residuo
