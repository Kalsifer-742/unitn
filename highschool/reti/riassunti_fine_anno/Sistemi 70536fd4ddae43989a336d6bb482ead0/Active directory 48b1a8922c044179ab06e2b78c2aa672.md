# Active directory

Servizio che gestisce le risorse di rete e le rende accessibili agli utenti; gli accessi sono regolati da un controller.

Le risorse sono memorizzate come oggetti, i quali sono descritti degli attributi.
Gli oggetti possono essere foglia o contenitore e vengono organizzati sia fisicamente che logicamente

I componenti fisici controllano il modo in cui le risorse sono strutturate e memorizzate nella directory.

- Sito ⇒ insieme di subnet
- Subnet ⇒ IP specifico con una subnet specifica
- Global Catalog ⇒ database contenente tutti gli oggetti e i rispettivi attributi principal

I componenti logici controllano il modo in cui le risorse sono visualizzate .

- Domini ⇒ gruppi di oggetti con le stesse policy e stesso servername

    la relazione di fiducia tra i vari domini si chiama ⇒ **TRUST**
    Questa relazione può essere unidirezionale intransitiva | bidirezionale transitiva.

- Alberi ⇒ Gerarchizzazione padre-figlio
- Foreste ⇒ insieme di alberi
- Unità organizzative ⇒ container logici che facilitano l'amministrazione

L'active directory implementa DNS: servizio di risoluzione IP⇒ hostname e viceversa.

Il DNS è realizzato tramite un database distribuito di una gerarchizzazione di server DNS di domini differenti.
Ad ogni dominio corrisponde un nameserver

I TLD possono essere classificati in base

- posizione geografica
- organizzazione
- funzione

La gerarchia di domini è diviso in zone, ogni zona è responsabile di se stessa e le informazioni contenute in essa si trovano in 2+ Authoritative Server

Implementa anche DHCP