# Wireless

Umbrella term per tutte le tecnologie di comunicazione senza fili, attraverso radiofrequenze

##### Vantaggi

* Ti sposti (mobilità)
* Non devi collegarti a un cavo se ti colleghi solo per qualche ora (connettività a breve termine, spostarsi significa non dover spostare cavi)
* Internet anche quando non si può modificare l'ambiente per efficiente cablaggio (all'aperto, nei musei o edifici storici)
* Costi più bassi perché compri meno attrezzatura

##### Svantaggi

* Non avendo possibilità di avere un medium dedicato la sicurezza della connessione è più complessa
* La configurazione è più complessa a causa di dettagli delle radiofrequenze
* Il segnale radio è limitato da interferenze, gli ostacoli fisici ostacolano le onde e queste posso riflettersi su varie superfici, potenzialmente allungando il percorso o causando interferenze

## Reti in Ordine di Grandezza

### NFC - Near-Field Connection

Near-Field Connection (Connessione a Corto Raggio/Campo) è anch'esso un termine ombrello per tutti i protocolli per la comunicazione a massimo 10 cm (ma usualmente si tengono 4 cm per facilità e sicurezza) tra un dispositivo iniziatore/attuatore (spesso quello attivo, quindi quello alimentato a batteria o a corrente) e un dispositivo target (può essere attivo, quindi alimentato, o passivo quindi alimentato dal campo elettromagnetico dell'attivo).

Mentre NFC definisce i protocolli, se vogliamo parlare di implementazioni si può accennare l'RFID, una tecnologia che usa piccole trasmittenti e ricevitori radio spesso accompagnati da spirali di rame come antenne (che contribuiscono all'alimentazione mediante campo elettromagnetico, funzionano come i caricatori wireless per telefono)

Le modalità di accesso sono:

1. Card Emulation:\
   l'attuatore simula un dispositivo come una carta prepagata o un biglietto
2. Peer-to-Peer:\
   Una coppia di dispositivi, per comunicare, dev'essere composta da dispositivi attivi. In base al verso della comunicazione i due dispositivi alterneranno quale dei due si comporterà da attivo e quale da passivo
3. Reader/Writer:\
   Solitamente tra un dispositivo attivo (es: telefono) e un passivo (es tag NFC, POS per i pagamenti touch), solitamente una lettura (il telefono legge un'azione dal tag NFC e spegne le smart-lights), tuttavia può capitare anche la scrittura (quelli che si comprano possono essere scritti da chiunque per utilizzo personalizzato

Pensato per trasferimenti di piccola grandezza, per l'uso di dispositivi passivi, l'accoppiamento è immediato ma a causa dell'"ottimizzazione" per questi use cases non è performantissimo in termini di velocità

### BAN - Body Area Network

Reti fatte per interconnettere vari dispositivi immediatamente vicini o attaccati al corpo, come gli smartwatch, con un range massimo di 1/2 metri. È un tipo di rete che si può formare attraverso Bluetooth per esempio

### (W)PAN - (Wireless) Personal Area Network

Rete moderatamente grande, raggio di qualche metro

ZigBee è un protocollo che permette la creazione di una WPAN

Bluetooth è anch'esso uno standard per la creazione di WPAN (che è chiamata piconet nel glossario Bluetooth) attraverso frequenze radio da 2.402 ai 2.480 GHz.\
I dispositivi possono essere master, slave, parked o standby e sono tutti costruiti per essere in tutti di questi stati (non esiste dispositivo che segua lo standard che non possa fare da master, tuttavia è possibile che il ruolo master-slave si scambi, ma il ruolo dei dispositivi è deciso in fase di connessione e creazione della piconet).\
Il dispositivo master assegna indirizzi di 3 bit agli slaves, che possono essere al massimo 7 (2^3 = 8, togliamo un indirizzo per il master), e coordina la loro comunicazione.\
I dispositivi parked sono dispositivi della piconet che possono essere invitati a diventare attivi (max 255).\
I dispositivi in stand-by sono dispositivi che non fanno parte di alcuna piconet.\
Più piconet possono essere collegate attraverso un bridge, creando una scatternet (unione di piconet bluetooth).

Bluetooth, singolarmente, specifica dei profili, identificatori che i dispositivi si scambiano e che annunciano la funzione del dispositivo (e quindi quali dati s'aspettano di ricevere e quali dati invieranno)

### WLAN - Wireless Local Area Network

Rete Wireless di raggio tra i 100 e i 500 metri

lavora su bande attorno alle frequenze 2.4 e 5 GHz, la prima è meno forte ma copre una maggiore distanza, mentre la seconda è l'opposto (+raggio, -forza).\
Single Band - una banda sola, solitamente è la 2.4GHz perché quella più "retrocompatibile"\
Dual Band - l'ESS (quindi "la rete", volendo accorciare) è composta da due reti, una sulla 2.4GHz e l'altra sulla 5\
Tri Band - Per suddividere meglio il carico abbiamo una rete in più sui 5 GHz

Le unità comunicanti sono chiamate stazioni, fare distizioni tra devices e access point è inutile spesso a causa della modalità ad-hoc che permette la creazione di reti peer-to-peer

Le stazioni collegate tra loro creano un BSS (Basic Service Set), identificato dal BSSID (Basic Service Set IDentifier) che nel caso delle reti a infrastruttura è il MAC dell'Access Point (possiamo pensarlo come uno switch per le connessioni wireless, anche se è ovviamente più complicato).\
Una o più BSS formano un ESS (Extended Service Set), identificato dall'(E)SSID (Extended Service Set IDentifier, tecnicamente nella specifica non è specificato un ESSID ma solo un SSID, tuttavia si può trovare in giro e ad esempio esiste nel PDF. SSID ed ESSID coincidono, nel senso che sono lo stesso valore e servono lo stesso scopo).\
Il medium usato per collegare le BSS è chiamato Distribution System\
Mentre il BSSID *solitamente* non è modificabile, l'(E)SSID è fatto per essere trasmesso a tutti quelli che si vogliono collegare e quindi è fatto per essere modificabile, inoltre la modifica di questo valore permette il roaming, ovvero lo scambio di BSS di appartenenza senza intervento dell'utente (passo tra due BSS che fanno parte dello stesso ESS senza riconnettermi/disconnettermi).

La scoperta (discovery) di reti vicine a cui collegarsi può avvenire in due modi:

* Passiva\
  La stazione manda ogni intervallo di tempo dei frame (Livello Data Link) Beacon, contenenti l'SSID della rete assieme al MAC della stazione che lo sta inviando (e che quindi può essere il "punto d'accesso" alla rete). Chi vuole connettersi può inviare un Frame Association-Request e, se non ci sono problemi, si vedrà ricevere un'Association-Response
* Attiva\
  La stazione manda un pacchetto Probe Request in broadcast dove può specificare l'SSID che cerca e attende Probe Responses. La stazione quindi può collegarsi a una qualsiasi di queste reti mandando un'Association-Request come spiegato prima

Come accennato prima, le reti possono essere create in modalità infrastruttura (con un AP centrale) o in modalità ad-hoc, in questo caso le stazioni si uniscono per formare una IBSS (Independent Basic Service Set)

Apparecchiatura:

* Access Point\
  Permette a dispositivi compatibili di accedere senza fili a una rete cablata (l'AP prende pacchetti e li passa da Wi-Fi a Ethernet)
* Wireless Repeater\
  Estende il raggio di una rete (effettivamente aggiungendo una stazione all'ESS, il sistema di distribuzione sono le onde radio)
* Wireless Bridge\
  Unisce due LAN (di cui almeno una wireless) per crearne una più grande, è praticamente uno switch con solo 2 entrate (ma per essere wireless almeno una di queste dev'essere wireless).\
  Nel caso abbia un AP integrato, una delle due entrate sarà la propria rete.\
  A differenza di un repeater, che inoltra tutto all'AP "centrale", un bridge si comporta come uno switch (tecnicamente uno switch è un bridge che unisce diverse LAN, ignorate se non volete fare confusione) e quindi inoltra tra le reti solo quando intuisce che sia necessario
* Wireless Router\
  Integra le funzioni di uno switch, un router, un access point e, opzionalmente, un modem.\
  È capace quindi di ricevere e inviare dati da supporti diversi e fare da ponte tra questi (modem, modula i dati nelle frequenze standard per il doppino telefonico/fibra e viceversa), collegare LAN/reti logicamente diverse (router), gestire traffico cablato (switch) e wireless (access point)

TODO: WiFi 6

### WMAN - Wireless Metropolitan Area Network

Connessioni tra più posizioni in un'area metropolitana come una città o un campus universitario.\
Utilizza infrarossi o onde radio

##### WiMAX - 802.16

Informazioni relative a 802.16-2004, non è il più recente ma non ci sono importanti cambiamenti a parte quando segnalato.\
Due tipi di stazioni:

* Base Station \
  punto di accesso per i Subscribers, è collegato alla rete in qualche modo, ad esempio tramite cavo o potenzialmente un'altra Base Station
* Subscriber Station \
  Utenti che vogliono accedere tramite telefono o laptop, oppure dei router che collegano una LAN casalinga a una Base Station per la connessione dove la copertura con altre tecnologie è cattiva.\
  Queste stations possono essere in movimento e nella versione 802.16-2005 (chiamata Mobile WiMAX) dello standard grande enfasi è posta in ciò, con sempre maggiore supporto (soprattutto negli standard successivi) per stazioni che si muovono a velocità veicolare ad esempio (si possono trovare in giro con il nome MS, Mobile Station, ma non è tanto diffuso, anche se c'è nell'ultima immagine del PDF)

Due tipi di connessioni:

* line-of-sight\
  Quando l'antenna è visibile (e quindi non ci sono ostacoli) è possibile installare una parabola o simili che punta direttamente all'antenna e usare frequenze relativamente alte (10-66 GHz), portando a corto raggio ma alta intensità del segnale
* non-line-of-sight\
  Quando ci sono ostacoli da superare, una piccola antenna può bastare per lavorare a frequenze più basse (2-11 GHz)

Due architetture di Rete:

* point-to-multipoint\
  una Base Station coordina le Subscriber Stations che accedono a un canale condiviso richiedendo una propria banda. Le Subscriber Stations non possono comunicare direttamente tra loro, eventualmente possono farlo attraverso la Base Station
* Mesh\
  è una point-to-multipoint, ma le Subscriber Stations possono comunicare tra loro, ciò permette alle SS di fare da access point per la rete per altre SS. Il supporto di questa architettura è opzionale

# Connessioni mobili
## 1G
Lanciata in Giappone da NTT(Nippon Telegraph and Telephone) nel 1979, circoscritta al'inizio solo all'area metropolitana di Tokyo. 5 anni dopo copre tutta la popolazione e diventa la prima reta a livello nazionale.
Nel 1981 viene lanciato il sistema NMT in Danimarca, Finlandia, Norvegia e Svezia.
Nel 1983 viene lanciato negli Stati Uniti con Ameritech con sede a Chicago e il telefono scelto fu Motorola DynaTAC.
Dal 2018 in poi la Russia rimane l'ultimo stato ad avere una rete NMT 1G in funzione.

I dati venivano trasmessi secondo uno standard analogico, con la seguente necessità di avere apparati molto voluminosi per colpa del modulo ricevente/trasmittente e della batteria piombo-acido, atta a compensare i consumi dell'apparecchio. 
Le reti avevano una sicurezza molto carente, e rendeva possibili intercettazioni e hacking.
### Protocolli
 - AMPS (Advanced Mobile Phone System), comparso nel 1976 negli USA, costituisce il primo standard della rete cellulare. Utilizzato principalmente al di là dell'Atlantico, in Russia e in Asia, questa rete analogica di prima generazione aveva dei bassi meccanismi di sicurezza che rendevano possibile il pirataggio delle linee telefoniche.
 - ACS (Total Access Communication System) è la versione europea del modello AMPS. Utilizzando la banda di frequenza da 900 MHz, questo sistema fu soprattutto utilizzato ampiamente in Inghilterra, poi in Asia (Hong-Kong e Giappone).
 - ETACS (Extended Total Access Communication System) è una versione evoluta dello standard TACS sviluppata nel Regno Unito utilizzando un numero maggiore di canali di comunicazione.

## 2G
Lanciata con lo standard GSM in Finlandia nel 1991.
Per la prima volta:
- Le chiamate potevano essere crittografate e le chiamate vocali digitali erano significativamente più chiare con meno rumore statico e di sottofondo.
- Le persone potevano inviare messaggi di testo (SMS), messaggi con immagini e messaggi multimediali (MMS)
Venne investito molto in questa tecnologia miglioranto le infrastrutture
la velocità iniziale fu solo di 9.6kbit/s, raggiungendo massimi di 500kbit/s grazie alle connessioni EDGE.
Vengono inserite tecniche di autenticazione e crittografia impedendo così clonazione di telefoni e prevenendo intercettazioni.
Si lavora in digitale e il segnale vocale viene compresso in modo più efficace dando la possibilità di avere un maggior numero di chiamate nella stessa banda
Resi disponibili FAX, SMS e WAP
frequenze usate : 850 900 1800 1900
### 2.5G - generazione 2 e mezzo
standard GPRS(General Packet Radio Service), evoluzione del GSM e migliora il supporto per la trasmissione dati introducendo la commutazione di pacchetto
### 2.75G - generazione 2 e 3 quarti
standard EDGE(Enhanced Data rates for GSM Evolution), evoluzione del GPRS, consente maggiori velocità
### Protocolli
Il GSM (Global System for Mobile Communications) è la tecnologia più diffusa, infatti serve l'80% di utenti, nata in Europa.
Altri standard sono:
- l'IS-95 (noto anche come cdmaOne), usato negli Stati Uniti ed in parte dell'Asia;
- l'IS-136(o D-AMPS), in passato prevalente in America;
- il PDC, usato in Giappone.
## 3G
Rilasciato in Giappone l'1 Ottobre 2001 circoscritto all'area di Tokyo e si prevedeva di passare dal 2G al 3G definitivamente nel 2006.
Risulta 40 volte più veloce del 2G, con una velocità media che passa da 384Kbps a 21Mbps, introduce internet nei telefoni e porta la connessione in tutto il mondo
Aggiunto il supporto per video-streaming e vengono usati i primi telefoni per chiamate e memorizzazione di dati nelle rete, iniziano a nascere i primi cloud
### Protocolli
- CDMA - Code Division Multiple Access . Protocollo che permette la condivisione del canale a più utenti
- W-CDMA - Utilizzata nel 3G, usa uno spettro espanso più efficace alla precedente tecnica di accesso mista TDMA/FDMA usata precedentemente
- Standard UMTS (Universal Mobile Telecommunications System) - si basa sull'interfaccia di trsmissione W-CDMA
### 3G LTE
Evoluzione del 3g che aggiunge la tecnologia MIMO (multiple input-multiple output), permette di inviare e ricevere più dati contemporaneamente aumentando sensibilmente portata di upload e donwload dei dispositivi abilitati

