# Algebra relazionale
L’algebra relazionale è un linguaggio procedurale che definisce il procedimento
da utilizzare per ottenere la soluzione. Essa utilizza degli operatori che sono definiti su relazioni e che consentono di
ottenere come risultato una relazione.

## Sintassi
OPERATORE <sub>condizione</sub> (INSIEME su cui operare)  
_Gli esempi non seguono la denominazione corretta con i pedici_

### Ridenominazione
REN <sub>a ← b</sub> (R)  
Rinomina una colonna senza cambiarne i valori

| Matricola   | Nome        |
| ----------- | ----------- |
| P001        | Paolo       |
| P002        | Mario       |

```sql
REN Utente ← Nome (Studenti)
```

| Matricola   | Utente      |
| ----------- | ----------- |
| P001        | Paolo       |
| P002        | Mario       |


### Selezione
SEL <sub>a = b</sub> (R)  
Seleziona un sottoinsieme da una tabella in base a un'espressione booleana
| Matricola   | Utente      |
| ----------- | ----------- |
| P001        | Paolo       |
| P002        | Mario       |

```sql
SEL Nome='Paolo' (Studenti)
```

| Matricola   | Utente      |
| ----------- | ----------- |
| P001        | Paolo       |

### Proiezione
PROJ <sub>a, b</sub> (R)  
Mostra gli attributi della relazione

| Matricola   | Utente      |
| ----------- | ----------- |
| P001        | Paolo       |
| P002        | Mario       |

```sql
PROJ Matricola (Studenti)
```

| Matricola   |
| ----------- |
| P001        |
| P002        |

### EQUI JOIN
A <sub>x</sub> JOIN B <sub>y</sub>  
Unisce le due tabelle secondo un attributo comune

| Matricola   | Utente      |
| ----------- | ----------- |
| P001        | Paolo       |
| P002        | Mario       |

| MediaVoti   | Matricola   |
| ----------- | ----------- |
| 8           | P001        |
| 5           | P003        |

```sql
Studenti Matricola JOIN MedieVoti Matricola
```

| MediaVoti   | Matricola   | Utente      |
| ----------- | ----------- | ----------- |
| 8           | P001        | Paolo       |

### LEFT & RIGHt JOIN
A <sub>x</sub> LEFT JOIN B <sub>y</sub>  

A <sub>x</sub> RIGHT JOIN B <sub>y</sub>  

Unisce le due tabelle ritornando tutte le righe dalla prima o seconda tabella. Quelle senza match avranno valore NULL.

| Id | Name     | Age | Address   | Salary   |
| ----------- | ----------- | ----------- | ----------- | ----------- |
|  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
|  2 | Khilan   |  25 | Delhi     |  1500.00 |
|  3 | kaushik  |  23 | Kota      |  2000.00 |
|  4 | Chaitali |  25 | Mumbai    |  6500.00 |
|  5 | Hardik   |  27 | Bhopal    |  8500.00 |
|  6 | Komal    |  22 | MP        |  4500.00 |
|  7 | Muffy    |  24 | Indore    | 10000.00 |

| Oid | Date  | CustomerId | Amount |
| ----------- | ----------- | ----------- | ----------- |
| 102 | 2009-10-08 00:00:00 |           3 |   3000 |
| 100 | 2009-10-08 00:00:00 |           3 |   1500 |
| 101 | 2009-11-20 00:00:00 |           2 |   1560 |
| 103 | 2008-05-20 00:00:00 |           4 |   2060 |

```sql
PROJ Id, Name, Amount, Date (Customers Id LEFT JOIN CustomerId Ordini)
```

| Id          | Name        | Amount      | Date                |
| ----------- | ----------- | ----------- | -----------         |
| 1           | Ramesh      |   NULL      | NULL                |
| 2           | Khilan      |   1560      | 2009-11-20 00:00:00 |
| 3           | kaushik     |   3000      | 2009-10-08 00:00:00 |
| 3           | kaushik     |   1500      | 2009-10-08 00:00:00 |
| 4           | Chaitali    |   2060      | 2008-05-20 00:00:00 |
| 5           | Hardik      |   NULL      | NULL                |
| 6           | Komal       |   NULL      | NULL                |
| 7           | Muffy       |   NULL      | NULL                |
