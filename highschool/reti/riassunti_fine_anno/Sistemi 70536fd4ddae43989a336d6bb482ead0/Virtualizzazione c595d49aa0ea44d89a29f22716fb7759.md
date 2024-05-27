# Virtualizzazione

Virtualizzazione: tecnologia che consente di astrarre logicamente una risorsa fisica.

La virtualizzazione è utile in quanto con una singola risorse è possibile averne molteplici di logiche, abbassando dunque i costi di consumo e hardware

Un esempio è la virtualizzazione di un server che permette dunque di avere diversi server virtuali isolati ed indipendenti

La virtualizzazione avviene tramite l'astrazione del software dall'hardware.Quest'operazione viene eseguita da un Hypervisor(HOST)

Type 1, Bare Metal: si appoggia direttamente sull'hardware dell'host, e i sistemi guest vengono eseguito su di esso.

Type 2: l'HyperVisor viene eseguito come un'applicazione sul SO Host, dunque l'HyperVisor opera dopo il SO e Hardware

VANTAGGI

- Riduzione spazio
- Ridondanza
- sistemi isolati ed indipendenti

Con la virtualizzazione è possibile eseguire una Migration di un Server da un luogo all'altro.

STORAGE VIRTUALIZATION ⇒ unisce diversi sistemi di archiviazione per farli sembrare una risorsa centralizzata, usata nelle SAN.
Viene creato un nuovo livello che si pone tra il sistema di archiviazione ed il server, le richieste vengono mappate nel pool di archiviazione virtuale e accede ai dati

DESKTOP VIRTUALIZATION ⇒ consente di avere un desktop in cloud accessibile da remoto(Bring Your Own Device) 

APPLICATION VIRTUALIZATION ⇒ consente di accedere ad una applicazione da remoto tramite la loro virtualizzazione, in questo modo le applicazioni vengono rese centralizzate

DATA VIRTUALIZATION ⇒ raccolta di dati da vari fonti e gestibili in un unico posto