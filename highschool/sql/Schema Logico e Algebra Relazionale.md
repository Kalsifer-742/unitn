# Ristrutturazione Schema ER

Una volta sviluppato lo Schema ER, questo va ristrutturato per prepararlo alla conversione in schema logico. In questa fase si possono fare considerazioni riguardanti le performance, indipendentemente dal DBMS che useremo.

Generalmente i passi sono:

* Analisi delle Ridondanze\
  Si verifica se eventuali dati ripetuti (non contano solo le ripetizioni ma anche dati che si possono ricavare da altri attributi anche di altre entità) possono essere eliminati.\
  Un dato ridondante non dev'essere calcolato quando letto, ma occupa più spazio e rende gli aggiornamenti più 
* Eliminazione delle Generalizzazioni\
  Tutte le generalizzazioni devono diventare entità concrete in qualche modo, senza perdere informazioni.\
  (Almeno) 3 possibili casi
  * Entità figlie accorpate all'entità genitore\
    Può convenire quando gli accessi al genitore e alle figlie sono perlopiù contestuali (il tipo di entità figlia che cerco dipende dal "contesto", da altre informazioni).\
    La generalizzazione può essere parziale o totale, esclusiva o sovrapposta.\
    Si applica spostando gli attributi dei figli nell'entità genitore, opzionalmente se la generalizzazione è esclusiva si può aggiungere un campo che specifica quale entità figlia si va a rappresentare.\
    Gli attributi obbligatori per le figlie diventano opzionali per il genitore, le relazioni sulle figlie diventano associazioni sul genitore, potenzialmente cambiando la cardinalità minima.\
    Spostando gli attributi nel genitore abbiamo meno entità e quindi potenzialmente meno accessi, ma abbiamo più spazio sprecato per i null
  * Entità genitore accorpata nelle entità figlie\
    Perlopiù conveniente quando gli accessi si fanno esclusivamente ad uno dei figli, raramente assieme. La generalizzazione d'origine dev'essere totale, può essere esclusiva e sovrapposta, ma quest'ultimo caso porterebbe a ridondanza.\
    Si applica spostando gli attributi e le relazioni del genitore nelle entità figlie, eventualmente cambiando le cardinalità delle ultime.\
    Nel caso si facciano accessi esclusivi in base al tipo dell'entità questo permette di aggregare tutte le entità dello stesso tipo, tuttavia le relazioni del genitore sono duplicate e con generalizzazioni sovrapposte abbiamo informazioni ripetute
  * Generalizzazioni con associazioni\
    La generalizzazione può essere parziale o totale, esclusiva o sovrapposta\
    L'entità genitore e le entità figlie sono tutte presenti e collegate da relazioni, richiedendo diversi accessi. Per rapida associazione le figlie devono avere lo stesso identificatore primario del genitore.\
    Con questo metodo non avrò mai dati ridondanti, ma 
* Partizionamento/accorpamento di entità e associazioni\
  Valutare se conviene dividere entità o associazioni in più entità/associazioni o se accorparne.
  * Partizionamento\
    Può risultare vantaggioso quando diverse entità dello stesso tipo vengono accedute separatamente\
    Può essere:
    * Verticale\
      Sono gli attributi a distribuirsi in due tipi d'entità diverse
    * Orizzontale\
      Divido le entità in due tipi tenendo gli stessi attributi, a quel punto ho creato una distinzione quasi esclusivamente formale 
  * Accorpamento\
    Quando due tipi d'identità hanno una relazione tra loro la cui cardinalità è (0, 1):(0, 1)/1:0/1:1 e sono frequentemente lette e scritte assieme, posso valutare l'accorpamento sotto un singolo tipo d'entità. Altre cardinalità di relazioni (N:N ad esempio) significherebbe inutile ridondanza di dati o spazio sprecato da null
* Scelta degli Identificatori Primari\
  Si sceglie uno tra gli identificatori di un'entità come primario, dev'essere unico per entità dello stesso tipo
* La prof inserisce Eliminazione degli attributi multivalore, ma questi sono supportati in alcuni DBMS e quindi non farebbero parte della ristrutturazione.\
  Convertire gli attributi multivalore in relazioni con altre entità

# Traduzione dello Schema ER in Schema Logico

[Specifica](https://drive.google.com/file/d/1P0LSie3Fh22yiIl9tlkKh9uSmH_A19rr/view)

Usa i costrutti di un particolare modello logico adottato dal DBMS per definire (e successivamente gestire) i dati seguendo lo schema definito dallo Schema ER ristrutturato

## Modello e Algebra Relazionale

Teorizzato e proposto da Edgar F. Codd nel 1970 per favorire l'indipendenza dei dati

* Indipendenza Logica: Variazioni della struttura logica non necessariamente influenzano i programmi che si interfacciano col database (non abbiamo visto le VIEWs in MySQL/MariaDB ma ci sono)
* Indipendenza Fisica: Variazioni della serializzazione del database su memoria permanente non modificano la sua struttura logica

Rappresentato con tabelle, ogni riga è una t-pla di t attributi, ogni colonna è un sottoinsieme del dominio che colleziona tutti gli attributi che fanno parte di quel dominio usati nelle t-ple (d'ora in poi tuple perché mi scoccio).\
Il grado di una relazione è il numero di colonne (e quindi il numero di attributi)\
La cardinalità di una relazione è il numero di righe (e quindi il numero di tuple)

Lo schema di un database è l'insieme degli schema delle relazioni di cui è composto (uno schema è la definizione delle relazioni e dei loro attributi)

### Vincoli

* Intrarelazionali - all'interno di una relazione
  * riguardanti uno o più attributi della tupla
  * riguardanti uno o più attributi su più tuple di una relazione
* Interrelazionali - riguardanti più relazioni
  * foreign keys

### Chiavi Primaria ed Esterna

* Superchiave, o chiave composta: è un insieme di attributi che identifica in modo univoco una tupla in una relazione. Per tupla ci possono essere più superchiavi
* Chiave Primaria: Superchiave con l'insieme più piccolo di attributi, dev'essere unica nella relazione e non può essere null
* Chiave esterna, o foreign key: attributo o attributi che assumono lo stesso valore presente in una chiave di una tupla di un'altra relazione, può essere null per indicare che non fa riferimento a nessuna tupla nell'altra relazione

### Integrità dei Dati

* Integrità di Dominio\
  Un attributo può solo assumere valori appartenenti al proprio dominio
* Integrità dell'entità\
  Il valore di una chiave primaria identifica univocamente le tuple
* Integrità referenziale\
  Se una relazione ha una chiave esterna questa deve assumere un valore esistente nell'altra relazione a cui ci riferiamo

### Traduzione

`nome_entità(chiave/i primarie, foreign key*, attributo1, attributo2)`

la chiave primaria (che può essere composta di più attributi) va sottolineata, il nome dell'entità diventa il nome della relazione

Le relazioni 1:N vanno a mettere nella relazione che partecipa con molteplicità massima N una foreign key che fa riferimento alla tupla nell'altra relazione

Le relazioni 1:1 la foreign key può essere messa in ambo le relazioni

Una foreign key può essere anche fare parte della primary key (e, se unica e mai null, può essere l'unico attributo in una primary key)

Gli attributi multivalore diventano relazioni 1:N o N:N

### Operazioni

[Sintassi](https://drive.google.com/file/d/1oDGFRmKmzVoa_x4r_CtdSMOz4cW73VDz/view)

* Operatori insiemistici (presi dalla matematica degli insiemi): Unione, intersezione, differenza e prodotto cartesiano\
  Sono operatori binari che si usano su due relazioni definiti dagli stessi attributi (stesse colonne)
* Operatori specifici: proiezione, selezione e rinomina
  * Rinomina: Rinomina il nome di un attributo (colonna) in modo da rendere compatibile una relazione nel caso l'unica discrepanza sia quella (non cambia il tipo, solo il nome)
  * Selezione: Applica a una relazione una condizione (espressione booleana) e filtra le tuple che non la soddisfano
  * Proiezione: Data una relazione R e un sottoinsieme A dei suoi attributi (colonne), ritorna le colonne A della relazione R
* I Join
  * JOIN prende due relazioni e due attributi (colonne) rispettivi e unisce le tuple quando gli attributi specificati delle due relazioni sono uguali
* altri di minore importanza