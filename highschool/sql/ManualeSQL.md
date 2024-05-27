# SQL
[manuale patrocinato dalla prof](https://www.epubeditor.it/ebook/?static=214365)  
[manuale MariaDB](https://mariadb.com/kb/en/sql-statements/)

## Sintassi
Le keyword sono case insensitive, nonostante si preferisce scriverle in maiuscolo per maggiore leggibilità. Nella shell ogni riga deve terminare con il `;`, da PHP/altri client è obbligatorio solo quando si lanciano più comandi nella stessa query

## Definizione Dati (DDL)

### CREATE
```SQL
CREATE DATABASE db_name;
```
Crea un nuovo database con il nome dato.

```SQL
CREATE TABLE table_name;
```
Crea una nuova tabella con il nome dato.

### USE
```SQL
USE db_name;
```
Ci sposta nel database specificato quando si usa la shell (automatico da PHP o altri client).

### DROP
```SQL
DROP DATABASE db_name;
```
Elimina tutte le tabelle nel database e lo elimina.

```SQL
DROP TABLE table_name;
```
Elimina la tabella nel database.

### SHOW
```SQL
SHOW DATABASES;
```
Elenca tutti i database gestiti dal DBMS.

```SQL
SHOW TABLES;
```
Elenca tutte le tabelle nel database.

### DESCRIBE
```SQL
DESCRIBE table_name;
```
Elenca tutte le colonne di una tabella assieme ad altre proprietà (es: se è una key o meno).

## Manipolazione Dati (DML)

### CREATE
```SQL
CREATE TABLE esempio(
  a INT
);
```
Crea una nuova tabella con il nome dato e le colonne specificate in base ai loro relativi tipi.

##### Esempio
```SQL
CREATE TABLE t1(
  a INT DEFAULT(1+1),
  b INT DEFAULT(a+1),
  c DATETIME DEFAULT(NOW())
);
```

> ### Vincoli intrarelazionali

> #### NOT NULL
> Il campo deve essere valorizato.
>
> #### UNIQUE
> Il valore deve essre unico nella sua tabella.
>
> ##### Esempio
> ```SQL
> CREATE TABLE esempio(
>   a INT,
>   UNIQUE(a)
> );
> ```
>
> #### CHECK
> Prima che una riga sia inserita i valori vengono controllati.
>
> ##### Esempio
> ```SQL
> CREATE TABLE esempio(
>   a INT CHECK(a >0),
>   b INT CHECK(b > 0), 
>   CHECK(a > b)
> );
> ```
>
> #### PRIMARY KEY
> Il valore assunto deve essere diverso da null e unico nella sua tabella.
>
> ##### Esempio
> ```SQL
> CREATE TABLE esempio(
>   a INT,
>   PRIMARY KEY(a)
> );
> ```
>
> ```SQL
> CREATE TABLE esempio(
>   a INT,
>   b VARCHAR(10),
>   PRIMARY KEY(a,b)
> );
> ```
>
> #### FOREIGN KEY
> Permette di correlare valori presenti su piú tabelle.
>
> ##### Esempio
> ```SQL
> CREATE TABLE author (
>   id SMALLINT NOT NULL AUTO_INCREMENT PRIMARY KEY,
>   name VARCHAR(100) NOT NULL,
> );
>
> CREATE TABLE book (
>   id SMALLINT NOT NULL AUTO_INCREMENT PRIMARY KEY,
>   title VARCHAR(200) NOT NULL,
>   author_id SMALLINT UNSIGNED NOT NULL,
>   FOREIGN KEY (author_id) REFERENCES author (id)
> );
> ```
> ```SQL
>   INSERT INTO book (title, author_id) VALUES ('Necronomicon', 1);
> );
> ```
> Se si prova ad eseguire questa operazione il DBMS restituirá errore.
>
> ```SQL
>   INSERT INTO author (name) VALUES ('Abdul Alhazred');
>   INSERT INTO book (title, author_id) VALUES ('Necronomicon', 1);
> );
> ```
> Questa invece avrá successo. Sempre utilizzando la FOREIGN KEY si possono 
> eseguire JOIN tra due tabelle distinte.

### DELETE
```SQL
DELETE FROM table_name
```
Elimina tutte le righe dalla tabella.

### UPDATE
```SQL
UPDATE table_name SET column1 = value1, column2 = expression;
```
Aggiorna tutte le righe di una tabella. L'espressione può usare il corrente valore.

##### Esempio
```SQL
UPDATE esempio SET column1 = 'colonna1', column2 = column2*10;
```

### ALTER
```SQL
ALTER TABLE esempio
```
Modifica una tabella.

##### Esempi
```SQL
ALTER TABLE esempio ADD x INT;
```
Aggiunte una nuova colonna.

```SQL
ALTER TABLE esempio CHANGE a b BIGINT UNSIGNED AUTO_INCREMENT;
```
Modifica il nome e tipo di una colonna.

```SQL
ALTER TABLE esempio ADD PRIMARY KEY(b);
```
Aggiunge una chiave primaria (con `UNIQUE` e `FOREIGN KEY` possiamo aggiungere un vincolo di unicità o una foreign key come durante la creazione).

### INSERT
```SQL
INSERT INTO esempio;
```
Inserisce una o piú righe in una tabella.

##### Esempio
```SQL
INSERT INTO person (first_name, last_name) VALUES ('John', 'Doe');
```
Inserisce una nuova riga specificando i nomi delle colonne.

```SQL
INSERT INTO person SET first_name = 'John', last_name = 'Doe';
```
Inserisce una nuova riga usando SET.

```SQL
INSERT INTO tbl_name VALUES (1, "row 1"), (2, "row 2");
```
Inserisce piú di una riga per volta.

### SELECT
```SQL
SELECT column FROM table_name;
```
Selezione delle colonne oppure tutte tramite `*` da una tabella.  
Si può anche specificare un'espressione in modo da aggiungere colonne basate sui valori correnti.

##### Esempio
```SQL
SELECT column, column*10 FROM table_name;
```

### WHERE
Serve a specificare una condizione
> ### Condizioni

> #### ALL
> L'operatore ritorna true se tutte le righe della subquery soddisfano la condizione.
> ```SQL
> SELECT column_name FROM table_name WHERE column_name comparison_operator ALL (SELECT column_name FROM table_name WHERE condition);
> ```
>
> ##### Esempio
> ```SQL
> SELECT * FROM utenti WHERE nome != ALL (SELECT nome FROM amministratori);
> ```
> Ritorna solo gli utenti che non sono amministratori.
> 
> #### ANY
> L'operatore ritorna `true` se anche solo una delle righe della subquery soddisfa la condizione.
> ```SQL
> SELECT column_name FROM table_name WHERE column_name comparison_operator ANY (SELECT column_name FROM table_name WHERE condition);
> ```
>
> ##### Esempio
> ```SQL
> SELECT * FROM utenti WHERE nome = ANY (SELECT nome FROM amministratori);
> ```
> Filtra solo gli amministratori (se il nome è quello di un amministratore allora almeno una riga darà `true`)
> 
> #### EXISTS
> È usato per testare l'esistenza di records di una subquery.
> ```SQL
> SELECT column_name FROM table_name WHERE EXISTS (SELECT column_name FROM table_name WHERE condition); 
> ```
>
> ##### Esempio
> ```SQL
> SELECT * FROM utenti WHERE nome = ANY (SELECT nome FROM amministratori);
> ```
> 
> #### IN
> Controlla se il valore di un attributo é compreso in una lista di valori.
> 
> ##### Esempio
> ```SQL
> SELECT * FROM utenti WHERE nome IN ('Eren','Jotaro','Rei','Asta');
> ```
> 
> #### LIKE
> Permette di utilizzare dei caratteri speciali durante i confronti.
> 
> - `%`
>   - Indica una qualsiasi stringa (0 o più caratteri).
> - `_`
>   - Indica un qualsiasi carattere
> 
> ##### Esempio
> ```SQL
> SELECT * FROM utenti WHERE cognome LIKE 'Jojo%';
> ```
> Seleziona tutti gli utenti il cui cognome inizia per Jojo.
> 
> ```SQL
> SELECT * FROM utenti WHERE cognome LIKE 'Levi_' ;
> ```
> Seleziona tutti gli utenti il cui cognome inizia per Levi e hanno un solo carattere a seguire.
> 
> #### BETWEEN
> Permette di specificare un range.
> 
> ##### Esempio
> ```SQL
> SELECT * FROM utenti WHERE eta BETWEEN 10 AND 20;
> ```
> Seleziona tutti gli utenti la cui età è compresa tra 10 e 20.

### JOIN
Permette di unire due tabelle.
Esistono:
- `INNER JOIN`
  - È quello di default ed equivale a scrivere `JOIN`.
- `LEFT JOIN`
- `RIGHT JOIN`

##### Esempio
| t1 | a |
| -- | - |
|    | 1 |
|    | 2 |
|    | 3 |

| t2 | b |
| -- | - |
|    | 2 |
|    | 4 |

```SQL
SELECT * FROM t1 JOIN t2 ON t1.a = t2.b;
```
| a | b |
| - | - |
| 2 | 2 |

## Funzioni aggregative
Vengono applicate sui raggruppamenti generati da `GROUP BY` (spiegazione a breve) o alternativamente sull'intero risultato.
Ad esse possono essere applicati
- ALL
  - Parola chiave di default. Scarta le righe il cui campo ha valore NULL. 
- DISTINCT
  - Scarta i doppioni.

### COUNT
```SQL
SELECT COUNT(column) FROM table_name;
```
Conta il numero di righe della selezione.
```SQL
SELECT COUNT(DISTINCT column) FROM table_name;
```
Conta il numero di righe distinte della selezione.

### SUM
```SQL
SELECT SUM(column) FROM table_name;
```
Somma i valori delle righe della selezione. Si applica solo ad attributi numerici. 
### MIN
```SQL
SELECT MIN(column) FROM table_name;
```
Seleziona il valore minimo tra le righe della selezione.
### MAX
```SQL
SELECT MAX(column) FROM table_name;
```
Seleziona il valore massimo tra le righe della selezione.
### AVG
```SQL
SELECT AVG(column) FROM table_name;
```
Calcola la media tra i valori delle righe della selezione.

### GROUP BY
```SQL
SELECT column FROM table GROUP BY column;
```
Raggruppa le righe secondo un campo uguale tra una o più colonne  
Se c'è una condizione `WHERE`, va definita prima di `GROUP BY`

##### Esempio
| name   | plays | wins |
| ------ | ----- | ---- |
| John   |    20 |    5 |
| Robert |    22 |    8 |
| Wanda  |    32 |    8 |
| Susan  |    17 |    3 |

```SQL
SELECT wins, COUNT(*) FROM plays GROUP BY wins;
```

| wins | `COUNT(*)` |
| ---- | ---------- |
|    3 |          1 |
|    5 |          1 |
|    8 |          2 |

### HAVING
```SQL
SELECT column FROM table GROUP BY column HAVING condition;
```
Filtra i risultanti raggruppamenti, va dopo `GROUP BY`.

##### Esempio
```SQL
SELECT wins, COUNT(*) FROM plays GROUP BY wins;
```

| wins | `COUNT(*)` |
| ---- | ---------- |
|    3 |          1 |
|    5 |          1 |
|    8 |          2 |

```SQL
SELECT wins, COUNT(*) FROM plays GROUP BY wins HAVING COUNT(*) < 2;
```

| wins | `COUNT(*)` |
| ---- | ---------- |
|    3 |          1 |
|    5 |          1 |
