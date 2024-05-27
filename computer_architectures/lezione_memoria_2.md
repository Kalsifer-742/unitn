# Lezione 10-11/5/22

## Gerarchia della memoria

- probabile che prelevo istruzioni da locazioni vicine
- probabile che un dato mi serva nell' immediato futuro (es loop)

---

- cache
  - esiste tipo e fa le sue cose
- RAM
  - piú grossa e piú lenta
- hardiks
  - piú grossa e piú lenta

---

- blocco
  - minima unitá di informazione
- hit rate
  - percentuale di volte in cui il dato cercato lo trovo giá caricato nella memoria(cache/ram ecc...)
- miss rate
  - contrario hit rate
- tempo di hit
  - tempo per accedere al dato
- penalitá di miss
  - tempo necessario per recuperare il dato se non é caricato in memoria

> penalitá di miss > tempo di hit (molto maggiore)
> vogliamo ridurre al minimo i miss

## Cache

- memoria non accessibile dal programmatore

---

### cache a mappatura diretta

- mapping 1:1 tra la memoria principale e la cache
- piú blocchi della memoria principale corrispondono allo stesso blocco nella cache
  - campo aggiuntivo detto tag mi permette di capire precisamente a quale blocco mi riferisco nella memoria principale
  - bit di validitá mi dice se il dato nella cache é da considerarsi valido o meno

---

- trade-off
  - blocchi molto grandi esaltano la localitá spaziale ma sfarvoriscono la localitá temporale
  - costo di una miss piú alto
  - cerco il soft spot per avere il minor numero di miss possibili

---

- gestione delle miss
  - occorre fermare la pipeline
  - porto il program counter indietro di un operazione
  - attendo il trasferimento dalla memoria principale alla cache del dato necessario
  - eseguo la fetch dell' istruzione che ora si trova in memoria

---

- scritture
  - write-through
    - per evitare inconsistenze scrivo simultaneamente nella cache e nella memoria principale
    - le scritture sono molto costose
      - per ovviare metto tutte le scritture da eseguire in un buffer che poi viene periodicamente svutato
  - write-back
    - in caso di hit le modifiche vengono fatte direttamente in cache e l' update in memoria centrale avviene solamente quando il blocco viene rimpiazzato (o quando il blocco viene acceduto da un' altro core)
    - utile quando il processore deve scrivere molti dati e la memoria non gli sta dietro

### cache associative

- posso mappare qualsiasi blocco in un blocco di cache
  - peró ogni volta che cerco un dato devo scorrere l' intere cache
    - posso parallelizarlo
      - il costo hardware peró é cosí alto che ha senso farlo solo in memoria molto piccole

> minore frequenza di miss ma maggiore complessitá

---

> quando ho una cache miss devo decidere che politica di sostistuzione utilizzare, solitamente: FIFO o Least Recently Used

## cache set-associative

- ogni blocco in memoria principale puó esere mappato su n blocchi diversi di cache

> slide 40 riassuntiva dei vari tipi, molto utile

---

> cache set-associativa a 1 via = a mappatura diretta
