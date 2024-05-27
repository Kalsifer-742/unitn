# Architetture WEB

Le architetture WEB si basano su una serie di livelli chiamati TIER.

I Tier principali sono:

- Presentation ⇒ acquisisce i dati dell'utente, direttamente connesso
- Business ⇒ elabora i dati acquisiti e fornisce risposta
- Data ⇒ gestisce l'accesso ai dati
- Security ⇒ monitoraggio della rete
- Networking ⇒ connettività e privacy utente
- Data storage ⇒ operazione con DB

**Microservizi**: approccio per lo sviluppo di architetture software secondo cui essa è divisa in servizi indipendenti uno dall'altro che comunicano tramite API.

La suddivisione in microservizi permette all'architettura software di essere più facile e veloce.

Gateway API: si occupa della gestione delle API ⇒ il client interroga il Gateway API che si preoccupa di chiamare i vari servizi.