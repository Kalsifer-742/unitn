# Riassunto Info

## Dati in Azienda
Le informazioni sono dati con un contesto e possono essere usate per prendere decisioni
Flusso delle informazioni può essere:
- push: le info vengono inviate a chi ne ha bisogno
- pull: le info vengono accedute da chi ne ha bisogno

Il sistema informativo produce informazioni che supportano le decisioni aziendali e facilitano la comunicazione di queste con gli stakeholders.
Sistema Informatico (o Sistema Informatico Automatizzato) fa da supporto al Sistema Informativo ed è l'insieme di tutte le tecnologie hardware e software che processano i dati e le informazioni e automatizzano le funzioni del sistema informativo.

Data Warehouse:
Un data warehouse è progettato per avere informazioni dettagliate e sommarie estratte da diversi database aziendali (o esterni) in modo da organizzarli per facilitarne la ricerca, l'inclusione in modelli decisionali (DSS), tabelle, report (EIS) e altre applicazioni del porco di dio

Data Mining:
Insieme di tecniche matematiche e statistiche per l'interpretazione di certi comportamenti aziendali

DSS:
Decision Support Systems, applicazioni che aiutano a valutare alternative decisionale tramite un'analisi dei dati storici e modelli predittivi per il futuro

EIS:
Executive Information System fornice accesso a informazioni seguendo modalità semplici e veloci di navigazione. Permette la crezione di report e indicatori mediante elaborazione basilare

ERP:
Enterprise Resource Planning, sistemi amministrativi che presentano in un unico software attività di gestione e automazione delle operazioni gestionali

## Memorizzare Dati

### Files
I files sono tutti insiemi di bytes dio porco, ma secondo il libro ci sono:
- File di testo, sequenze di bytes in formato ASCII (o UTF-8 nel 2021 dio cane), organizzati spesso per righe
- File binari (o non strutturati)(cosa significa sta roba ma chi l'ha scritta sta cagata)
- File strutturati, cioè insiemi di record serializzati in binario.
  Un record è un insieme di informazioni riguardanti un determinato oggetto. Le informazioni che compongono il record sono chiamate campi del record
  
### File Strutturati
Una persona ad esempio è un oggetto (o record) caratterizzato dai campi nome, congome, etc...
Se un file contiene dati della stessa natura allora si può chiamare omogeneo.
Può essere comodo definire una chiave primaria, un valore univoco che facilita la ricerca.

### Operazioni fisiche
Distinzione tra record logico, descrizione di come il programmatore vede e usa il record, e il blocco (o record, il libro usa "record" per confondere ancora di più) fisico, ovvero il minimo ammontare di memoria (spesso un valore prefissato) che si può scrivere su o leggere da disco.
Un blocco fisico può contenere una frazione di un record logico come contenerne più di uno, il fattore di blocco è $\frac {grandezza\ blocco\ fisico} {grandezza\ record\ logico}$. Se è $= 1$ allora per blocco fisico troveremo un record logico (potremmo avere casi in cui un blocco fisico corrsiponde a 1.5 record logici, ad esempio), se è $> 1$ allora per blocco fisico troveremo più di un record logico, se è $< 1$ allora avermo più blocchi fisici per record logico.
Per ridurre il numero di letture da disco (che sono più lente di letture a memorie più vicine alla CPU come la RAM) allora si tenta di avere blocchi fisici grandi o record logici piccoli, in questi modi si massimizza il fattore di blocco. Avere un numero non frazionario come fattore di blocco significa che, per lettura, avremo un numero finito di record (ex: se il fattore di blocco è 3 allora leggeremo 3 record logici, se è 2.4 allora ne leggeremo 2 interi e 0.4 del terzo).

### Organizzazione dei file
- Sequenziale
  Record disposti in sequenza, si parla di file ordinato quando i record sono in ordine crescente rispetto a uno o più campi chiave, altrimenti si dirà non ordinato/
  In un file sequenziale dovremo scorrere tutti i record per trovare quello che ci interessa. Se il valore che cerchiamo è univoco possiamo fermarci appena lo troviamo, altrimenti dovremo raccogliere una lista di record.
  Per cancellare un record dovremo tracciare la cancellazione in un campo apposito in modo che possano venire saltati in fase di ricerca
  Per inserire possiamo appendere alla fine un nuovo record (ampliamento) o sovrascrivere un record eliminato (sovrapposizione), tutto questo se il file non è ordinato
- Accesso Direttto
    - Relativo
      Conoscendo la posizione relativa all'interno del file è possibile calcolare la sua posizione. Se tutti i record hanno la stessa lunghezza si può usare la formula $(n-1)\times lunghezza$ per ottenere la posizione fisica, in questo modo possiamo accedere sia sequenzialmente che direttamente alla riga che ci interessa
    - su Indice
      Il campo chiave univoco è usato per l'indicizzazione dei record nei file. Il file degli indici (che mappa le chiavi al loro blocco fisico) è solitamente in ordine crescente per facilitare la ricerca. Il file degli indici è fatto per essere leggero e direttamente caricabile in RAM.
      La ricerca di un record si fa mediante questa tabella.
      L'inserimento di un record è complicato più per la necessità di mantenere l'ordine delle chiavi. È possibile riservare un campo nel file dei dati che punta alla posizione del record che andrebbe tra la chiave corrente e la prossima. Alternativamente si può riservare dello spazio fisico con record vuoti da riempire, in questo modo si riduce l'indirezione (al posto di avere un puntatore i record vuoti sembrano record normali) ma si rischia di sprecare spazio
    - Calcolato
      Un file si definisce ad accesso calcolato quando è possibile, conoscendo la sua chiave, ottenere la sua posizione fisica. Ad esempio è possibile usare algoritmi di hasing per ottenere l'indirizzo di un'area chiamata bucket dove tenere il valore. Un file hash contiene diversi bucket che, a loro volta, contengono da uno fino a un numero $n$ di record logici.
      Una funzione di hasing può avere collisioni: due valori diversi che danno lo stesso digest, la soluzione solitamente consiste mettere i due valori nello stesso bucket, che non crea problemi finché il bucket non è pieno (ci sono $n$ elementi dentro). Si può decidere di gestire l'overflow in modo aperto mettendo il record logico nel primo bucket non pieno successivo a quello dove andava messo, in questo modo la ricerca richiederà una scansione dal bucket calcolato in poi per essere sicuri di trovare il record che vogliamo. Altrimenti possiamo seguire il metodo delle catene e designare un'area di overflow che fungerà da estensione al bucket a cui è linkata. Le aree di overflow sono collegate a mo di linked list.

## Dal FileSystem alle Basi di Dati

### EDP
Electronic Data Processing, insieme di programmi che gestiscono un insieme di dati per agevolare il raggiungimento degli obiettivi di un'azienda.
I Database nascono dalla necessità di un'astrazione per questi EDP che tolga le varie differenze dei filesystem e permetta letture e scritture concorrenti da più processi in modo autenticato e controllato, minimizzando lo spazio utilizzato.

### Vantaggi dell'uso dei Database
- Eliminazione delle ridondanze (duplicazioni di dati)
- Eliminazione delle inconsistenze (quando due dati che dovrebbero rappresentare la stessa cosa sono discordi)
- Integrità dei dati (L'inserzione o la cancellazione non devono rendere incongruente il database)

### Modello ANSI/SPARC
Il modello ANSI/SPARC definisce come un DBMS dovrebbe separare la propria organizzazione, ovvero in tre livelli di astrazione con quello sopra che si serve di quello sotto e dà servizi a quello sopra. Questi tre livelli sono il livello interno, che fornisce archiviazione al livello logico, che fornisce un modello al livello esterno, che fornisce alle applicazioni una vista sul modello logico. È bene specificare ora che nessun DBMS segue il modello ANSI/SPARC alla lettera, basti pensare a MySQL/MariaDB: le view, che sarebbero parte del livello esterno, le abbiamo usate poco.

- Livello esterno
  È il livello con cui le applicazioni dovrebbero interagire, descrive come le applicazioni (o gruppi d'applicazioni, dipende da come s'autenticano) possono vedere i dati.
- Livello logico
  Descrive il modello d'interesse per le applicazioni, da questo livello si compongono le views.
- Livello interno
  Rappresenta la struttura su disco dei livelli soprastanti, orientato all'efficienza

- Indipendenza Logica
  Possibilità di modificare lo schema logico senza impattare sul livello esterno
- Indipendenza Fisica
  Possibilità di modificare impostazioni del livello interno senza impattare sul livello logico
  
## Linguaggi e Utenti

### DDL
Il Data Definition Language è il linguaggio scelto dal DBMS per descrivere lo schema logico e le viste

### DML
Il Data Maniuplation Language è il linguaggio scelto dal DBMS per la manipolazione e il querying dei dati.
Il DML può essere procedurale (definiscono le istruzioni per la gestione dei singoli record) o dichiarativo (vanno descritti i risultati che si vogliono ottenere invece di una lista di istruzioni)

SQL è sia DDL che DML dichiartivo

### Utenti
- DBA (Database Administator), solitamente ha i permessi per creare e modificare lo schema logico, definire e mantenere lo schema interno, gestire i permessi d'accesso ed eventualmente effettuare ripristino.
- Programmatori, che usano il DML per gestire i dati nel DB
- Utenti finali, che usano le applicazioni dei programmatori per interrogare e modificare il DB

## Sicurezza
Garantire privatezza, integrità, consistenza e efficienza.

### Privatezza
il DBA determina e configura i permessi di utenti e gruppi di utenti, il DBMS controlla che questi siano rispettati

### Integrità
La struttura logica dev'essere preservata, le relazioni e le proprietà delle colonne.
Ciò si fa impostando vincoli, che possono essere
- intrarelazionali (sulle singole tabelle/relazioni) (ex: colonna ``` `mese` > 0 AND `mese` < 13```)
- interrelazionali (interessano diverse relazioni/tabelle) (ex: FOREIGN KEY)

### Transazione
Istruzioni che formano un'unità di lavoro
per rispettare la consistenza allora i vincoli devono rimanere rispettati anche dopo la transazione
Per eseguire più transazioni esistono meccanismi di sincronizzazione



