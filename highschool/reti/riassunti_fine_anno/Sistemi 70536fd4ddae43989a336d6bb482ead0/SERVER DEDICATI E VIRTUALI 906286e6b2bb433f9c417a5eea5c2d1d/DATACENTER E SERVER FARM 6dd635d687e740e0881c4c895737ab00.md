# DATACENTER E SERVER FARM

I datacenter sono i luoghi fisici in cui riesiedono le server farm(gruppo di server) e storage.

I data center prevedono vari UPS e sistemi di raffreddamento/sicurezza ecc.

I datacenter sono classificati in IV Tier a seconda del loro tempo massimo di downtime annuo

SICUREZZA FISICA DATA CENTER ⇒ mettere a terra le apparecchiature, UPS, climatizzazione, sistemi anticendio/allagamento.

SICUREZZA LOGICA DATA CENTER ⇒ sistemi IDS, policy di Disaster Recovery(backup)

**SERVER FARM**: insieme di server che condividono applicazioni, carico e/o dati.

Cloning server farm ⇒ su ogni nodo vengono installati gli stessi dati e stesse applicazioni in questo modo le richieste vengono gestite in modo ottimale.

-shared disk: server condiviso per la condivisione dei dati

-shared nothing:ogni clone ha un disco fisso contente i dati
(difficile da aggiornare, adatto per sistemi read-only)

Partitioning server farm ⇒ duplicazione hardware/software ma non dei dati; il backup è possibile clonando i server interessati