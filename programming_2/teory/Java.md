# Java

Vtable(Virtual Table) in memoria.

Tabella associata ad ogni classe che contiene puntatori alle locazione di memoria dei metodi

![Alt text](resources/vtable_image.png)

## Visibility

## Ereditarietà e Polimorfismo

- keyword `extends`
  - `Class Cane extends Mammifero {}`
- la sottoclasse ereditá tutti gli attributi e tutti i metodi della superclasse
- java non supporta l'eredità multipla
- una classe se non diversamente specificato eredità la classe Object, _radice dell'intera gerarchia_
- Object fornisce alcuni importanti metodi:
  - `equals(Object)`
  - `finalize()` - deprecata in teoria
  - `toString()`
- overriding
  - consiste nel redefinire i metodi della superclasse
- `super`
  - é una pseudo variabile utilizzata per riferire metodi della superclasse
  - risale tutta la gerarchia finché non lo trova
  - un metodo `static` deve essere overridato da un'altro metodo `static`
- costruttori
  - non vengono ereditati
  - tramite `super` possono essere chiamati i costruttori della superclasse. Va messa come prima istruzioni.
  - costruttore di default
    - Se la classe definisce un costruttore con parametri non può essere creato un costruttore di default. Se il programmatore specifica un costruttore il linguaggio non introduce altro.
  
  ```java
  class A {
    int x;

    // A() {
    //   this.x = 0;
    // }
    A(int x) {
      this.x = x;
    }
  }

  class B extends A {
    B() { super(); } //il compilatore inserisce questa riga
  }
  ```
  
  - ^^^ se il programmatore non specifica un costruttore per la sottoclasse il compilatore chiama il costruttore di default della superclasse.
  Se il costruttore di default della superclasse non è definito il codice non può compilare.
- UML
  - esiste
- Overloading
  - possono esistere più metodi con lo stesso nome e diverse implementazioni che si distinguono per numero e/o tipo di parametri
  - il valore di ritorno non permette di distinguere due metodi, no overloading sul tipo di ritorno

- overloading vs overriding
  - a volte avviene uno a volte l'altro dipende dai casi e tipi statici e dinamici (guarda slide)

- keyword
  - final
    - definisce una classe o un metodo come non più modificabile (o una variabile). disattiva il dynamic dispatch
  - private
    - visibile solo internamente alla classe
  - protected
    - visibile solo dalle classi dello stesso package e dalle sottoclassi
    - visibile solo internamente. è come se fosse private.
  - `this` per riferirmi ad attributi o metodi della mia classe o all`istanza
  - `static` crea metodi e variabili della classe che possono essere usati anche senza instanziare un'oggetto. sono gli stessi per l'intera classe. stessa area di memoria

## Classi astratte

- `abstract`
  - keyword per definire classi o metodi astratti
  - un metodo astratto non ha alcuna implementazione. Viene implementato dalle sottoclassi
  - se un metodo è astratto l'intera classe deve essere astratta
  - non posso istanziare classi astratte

## Polimorfismo

- Principio di sostituzione di Liskov

  - > Se s è un sottotipo di T, allora variabili di tipo T in un programma possono essere sostitutie da variabili di tipo S senza alterare alcuna proprietà desiderabile del programma
    >
    > ```java
    > Point p = new Point(1,2);
    > p.move(3,4);
    > ---
    > Point p = new NamedPoint(1,2,"A");
    > p.move(3,4);
    > ```
    >
  - funziona perchè aggiungo informazioni che al massimo non vengono usate. Rispetto le funzionalità precedenti.

- legame dinamico tra oggetto e tipo, si distingue:
  - dynamic binding (java)
    - tipo statico (deciso a compiletime)
      - il compilatore determina la firma del metodo basandosi sempre sul tipo statico
    - tipo dinamico (deciso a runtime, in java tutte le decisioni sono prese durante l'esecuzione)
      - in caso di overriding la specifica implementazione del metodo la cui firma è stata scelta a compiletime viene determinata a runtime basandosi sul tipo dinamico
    - regola per il binding
      - > il metodo scelto dipende dal tipo dinamico (new ...()) e viene deciso a runtime in questo modo:
        - Si cerca il metodo all'interno della classe del tipo statico
        - Si controlla se il tipo dinamico è una sottoclasse del tipo statico
        - Se è un sottotipo si controlla se è definito un override
        - Se la risposta è si si utilizza l'implementazione della sottoclasse, altrimenti quella della classe padre
        - il tipo statico determina quali metodi possono essere invocati. il tipo dinamico determina quale (ri)definizione eseguire
    - > reminder che il dinamic binding non è una cosa che avviene durante la compilazione. Bisogna ricordarsi quali metodi possono essere effettivamente eseguiti.
  - late binding
  - lazy evaluation

- 3 tipi
  - polimorfismo di sottotipo
    - tramite ereditarietà
  - ad hoc
    - overloading di funzioni
  - parametrico
    - generics

- static
	- rende il binding statico

> non c'è dynamic binding sui metodi statici

## Casting

- conversioni forzata tra tipo di riferimento
- possibile forzare conversione da un tipo T ad un suo sottotipo T1 se il tipo dinamico é un sottotipo di T1
- upcasting e downcasting

```java
Object o = new AutomobileElettrica(); //UPCASTING (conversione implicita, polimorfismo, regola is-a)
Automobile a = o;   // errato, Object non è un
                    // sottotipo di Automobile
Automobile a = (Automobile) o;  // corretto (casting) DOWNCASTING
```

- `istanceof`
  - mi permette di determinare il tipo dinamico di un oggetto

## Gestione degli errori

Alcuni errori vanno gestiti obbligatoriamente.
Gli errori di runtime non siamo obbligati a gestirli. altrimenti per esempio ogni possibile `NULL` value richiederebbe un` try catch`.

```java

void metodo_exception() throws TipoEccezzione1, TipoEccezzione2 {
  try 
  {
    //codice rischioso che potrebbe generare un errore
    int z = Integer.parseInt(inputString);
    System.out.println("input valido!");
  } 
  catch (TipoEccezzione e)
  {
    //codice da eseguire se si verifica un errore
    System.out.println("input non valido!");
    throw new TipoEccezzione(parametro);
  }
  catch (TipoEccezzione e)
  {
    // posso avere più di un catch
    // il primo catch corretto per quella eccezione viene eseguito
  }
  finally
  {
    //codice da eseguire in ogni caso
  }

  throw new TipoEccezzione2(parametro);
  
  /*
    The finally block always executes when the try
    block exits. This ensures that the finally block is
    executed even if an unexpected exception
    occurs. But finally is useful for more than just
    exception handling — it allows the programmer
    to avoid having cleanup code accidentally
    bypassed by a return, continue, or break.
    Putting cleanup code in a finally block is always
    a good practice, even when no exceptions are
    anticipated.
  */
```

Non posso tirare errori che non siano uno un sottotipo dell'alto.
se il metodo dice che lancia un tipo di errore all'interno posso lanciare solo figli di quell'errore.

eridetarietè ed errori si incrociano e bisogna stare attenti alla gerarchia degli errori

## Interfacce

dai ora sai i traits

in java puoi usare le interfacce come tipo statico. (parallelismo con i trait objects???)

## Collections

- Collection é un oggetto che raggruppa elementi multipli in una singola entitá
- differisce dagli array perché gli elementi possono essere eterogenei e la lunghezza non é prefissata
- Java Collection Framework
  - interfacce
  - implementazioni
  - algoritmi
- Collection
  - set
    - sortedset
  - list
  - queue
    - deque
  - map
    - sortedmap
- operazioni base
  - add, remove. (ritornano true se la colletion é cambiata dopo l' operazione)
- bulk operations
  - operazioni su piú elementi contemporaneamente
    - containsAll, removeAll
    - toArray() trasforma una collezzione in un' array
- Map, associazione chiave valore

> procede a mostrare come funzionano le interfacce e le collections, come implementare varie interfacce ed eseguire alcune operazioni come la visita. inoltre da una rapida spiegazione di alcune strutture dati


Nascono ancora prima di aggiungere i generics quindi sono abbastanza rotte. se un metodo prende una collections non specifichiamo il tipo. dato che tutto è un object posso metterci dentro quello che voglio. le collection non parametrizzate è come se fossero collection di object.

## Tipizzazione parametrica

- Generics

sui generici non c'è il subtyping. è rotto.

## Iteratori

attenzione ai for each perchè il ciclo interno avanza anche l'operatore esterno se ci facciamo stampare la cosa esterna

```java
for(Iterator<String> i = words.iterator(); i.hasNext();) {
  for(Iterator<String> j = words.iterator(); j.hasNext();) {
    System.out.println(i.next() + " " + j.next());
  }
}


//uguale

for(String i: words) {
  for(String j: parole) {
    System.out.println(i + " " + j);
  }
}
```

## Uguaglianza e identitá: equals

> Durante il confronto tra oggetti devo fare particolare attenzione. Sto confrontando due indirizzi che quindi sono diversi. Devo affidarmi a valori interni o diversamente.

- ==
  - su oggetti controlla gli indirizzi
- equals
  - di base non risolve niente perché é implementata con == ed é pensata per essere overridata
  - la lezione procede a mostrare come implementare per bene un metodo equals pensando a tutti gli imprevisti del caso
  - GetClass
    - che é meno generico di istanceOf che considera le sottoclassi
    - mi permette di controllare se 2 oggetti sono precisamente della stessa classe
- intellij ci puó generare il metodo equals automaticamente

```java
@Override
public boolean equals(Object o) {
if (this == o) return true;
if (o == null || getClass() != o.getClass()) return false;
P p = (P) o;
return x == p.x && y == p.y;
}
@Override
public int hashCode() {
return Objects.
hash(x, y);
}
```

## Static

* modificatore che associa alla classe e non all'oggetto
* valore condiviso tra le istanze
* metodi chiamabili senza creare un istanza
* limiti di variabili e metodi statici

> breve infarinatura, l'argomento verrá trattato piú a fondo successivamente

## Hashcode
> spiega cosa sia l' hash

> perché serve fare l'override di hashcode oltre che di equals:

- [geekforgeeks](https://www.geeksforgeeks.org/override-equalsobject-hashcode-method/)
- [stackoverflow](https://stackoverflow.com/questions/2265503/why-do-i-need-to-override-the-equals-and-hashcode-methods-in-java)

> hashcode viene chiamato prima di equals per efficienza. con equals vado sul sicuro e non sbaglio mai. insomma ricordarsi di implementare quello che serven

Non valgono i reciproci:
> equals uguali -> hashcode uguali
> equals diversi ->(non garantito) hashcode diversi
> hashcode diversi -> oggetti diversi

## Comparable

> Definisce un unico metodo
`int compareTo(Object o)`
che ritorna
- un intero negativo se this è minore di o
- un intero positivo se this è maggiore di o
- 0 se this è uguale a o

## Comparator

> Definisce un unico metodo
`int compare(Object o1, Object o2)`
che permette di delegare il confronto ad una classe separata. Definisco una classe per ogni metodo di comparazione necessario. La classe implementa solo il metodo compare. É una classe ausiliara piccolissima

Posso usare un comparatore esterno per avere diversi metodi di paragone quando mi serve.
alla funzione sort posso passare un comparatore diverso invece di quello intrinseco della clase

## Autoboxing

- jvm implicitamente converte un valore primitivo in un oggetto
    - `add(new Integer(3))` -> `add(3)`
- non devo piú preoccuparmi della cosa e posso tranquillamente usare i tipi primitivi

## JavaDoc

- speciali commenti nel codice, diventano documentazione
- javadoc puó generare documentazione dai commenti del codice

#### Errore tipico

```java
public class PratoFiorito extends Application {
  public PratoFiorito(Input input) {
  ...
  }
  @Override
  public void start(Stage stage) {
    Input input = new Input();
    PratoFiorito pf = new PratoFiorito(input);
...

//Non create MAI un costruttore non vuoto di una classe che estende Application
//Non istanziate MAI una classe che estende Application
```

## Eventi pressione tasti

- `KEYTYPED`
  - `e.getCharacter().equals("W")`

- `KEYPRESSED` e `KEYRELEASED`
  - `e.getCode() == KeyCode.W`

---

- `fireEvent()`
  - utile per evitare di riscrivere lo stesso codice
  - utilizzo l' eventhandler per l' evento specifico dell' oggetto su cui viene chiamato

```java
...
if (keyEvent.getCharacter().equals("u”)) {
  b1.fireEvent(new ActionEvent());
...
```

## Propagazione eventi

- Focus
  - finestra/componente selezionato

---

- Propagazione gerarchica degli eventi
  - l' evento scende gerarchicamente per poi risalire allo stesso modo
    - capturing (filters)
      - gli eventi scendono la catena gerarchica fino a raggiungere il componente che li ha creati
      - decido che eventi gestisce l'handler
    - bubbling (handlers)
      - gli eventi risalgono la catena gerarchica

> voglio che funzioni cosí perché per esempio in una calcolatrice posso creare un handler sul contenitore dei tasti che se scritto opportunamente in modo generico interecetta gli eventi dei tasti. Altrimenti dovrei scrivere un sacco di handler o assegnare lo stesso handler a tutti i tasti

- TARGET
  - mi dice chi ha generato l' evento (o perché é stato generato un evento)
- SOURCE
  - mi dice chi sta gestendo l' evento

---

> posso bloccare gli eventi nella catena

```java
t.consume()
```

---

```java
...
EventHandler<KeyEvent> keyEventHandler =
  new EventHandler<KeyEvent>(){
  public void handle(KeyEvent keyEvent) {
    System.out.println(keyEvent.getSource() + " =>" + keyEvent.getTarget());

    switch (keyEvent.getCharacter()){
      case "u":
      case "U":
        b1.fireEvent(new ActionEvent()); b1.requestFocus();
        break;
      case "d":
      case "D":
        b2.fireEvent(new ActionEvent()); b2.requestFocus();
        break;
    }
  };
...
stage.addEventHandler(KeyEvent.KEY_PRESSED,keyEventHandler);
...
```

classi anonime con le interfacce. utile per gli event handler per cui non voglio creare un'intera classe solo per gestire un evento.

## Lambda expressions

```java
c.setOnMouseEntered(new EventHandler<MouseEvent>() {
    public void handle(MouseEvent event) {
        System.out.print("Entered");
        c.setFill(Color.RED);
    }
);

c.setOnMouseEntered((MouseEvent event) -> {
        System.out.print("Entered");
        c.setFill(Color.RED);
    }
);
```

Per scrivere una Lambda specifico un'interfaccia che ha 1 solo metodo.
Quindi gli passo 1 solo metodo che è l'unica cosa che posso eseguire. rispetto la firma. (l'ho spiegato male, spero che il me futuro capirà)

- Consumer
- High order function

classi anonime vs lambda:

- classi anonime utilizza più memoria sia come storage che come ram

> se possibile usare interfacce standard. poi ci sono un sacco di convenzioni e consigli

Inferring the functional interfaces

- Does the interface have only one abstract (unimplemented) method ?
- Do the parameters (types) of the lambda expression match the parameters (types) of the single method ?
- Does the return type of the lambda expression match the return type of the single method ?

## Generics

> chiamati template in c++

- evitiamo cast espliciti che possono creare errori ed evitiamo che si inseriscano oggetti del tipo che non ci interessano in una lista per esempio

```java
class Group<T> { ... } //definizione
Group<Student> gs = ... //uso
Group<Tourist> gt = ... //uso
```

- posso usare solo metodi Object perché non conosco i tipi
- posso fare metodi generici
- bisogna fare attenzione ai generics in java perché sono stati aggiunti tardi e quindi sono zucchero sintattico. il compilatore converte le strutture nelle alternative non tipizzate e fa i cast per noi
  - quindi non posso assegnare ad una lista di tipo padre una di tipo figlio
    - un gruppo di studenti non é sottoclasse di un gruppo di persone
- sono implementati tramite type erasure

---

- I generics in Java sono implementati mediante type erasure
  - L’informazione sui parametri tipo viene eliminata dopo i controlli statici
  - Vengono inseriti gli opportuni cast per mantenere i vincoli sul tipo
- Questa scelta mantiene compatibilità con API che non usano generics
  - ma genera una serie di limitazioni

#### Wildcard

- È possibile specificare una o più wildcard
  - Rappresentano un tipo non noto
    - `Group<?> g = new Group<Student>();`
  - Non possono essere usate per creare oggetti
    - `Group<?> g = new Group<?>(); // no!`
  - Posso limitare le wildcard
    - `Group<? extends Persona> g = new Group<Student>()`
  - È possibile specificare più di un tipo: se c’è una classe deve essere la prima
    - `Group<? extends Persona & Comparable> g = new Group<Student>(); //studente implementa Comparable`
  - È possibile «limitare» le wildcard anche verso le superclassi
    - `Group<? super Studente> g = new Group<Persona>();`
    - anche Studente va bene. penso significhe quella classe e tutte quelle superiori

wildcard è utile da utilizzare per i parametri dei metodi più che altro

---

#### Limitazioni

- Non posso fare array di generics
  - deriva sempre dall' implementazione
  - new T[] non e' ammesso
- Generics non si possono usare con instanceof
- I parametri tipo non possono essere tipi primitivi
  - ma con wrapper e autoboxing solitamente si risolve

```java
Object obj = new LinkedList<Long>();
obj instanceof List //true
obj instanceof List<?> //true
obj instanceof List<Long> //error
obj instanceof List<? extends Number> //error
obj instanceof List<? super Number> //error
```

- altri casi particolari...
- [approfondimento sui generics in java](http://www.angelikalanger.com/GenericsFAQ/JavaGenericsFAQ.html)

## Extras

- dentro le lamba attraverso this posso solo riferirmi all'oggetto che la usa

- Parametricity

## Clonazione

- shallow copy
  - copia del puntatore
  - `A = B`
- deep copy
  - copia della struttura e dei suoi valori
  - `a = b.clone()`

```java
protected Object clone()
    throws CloneNotSupportedException
//Creates and returns a copy of this object. The precise meaning of "copy" may depend on the class of the object.
```

- the expression: `x.clone() != x` will be `true`,
- and that the expression: `x.clone().getClass() == x.getClass()` will be `true`, but these are not absolute requirements.
- While it is typically the case that: `x.clone().equals(x)` will be `true`, this is not an absolute requirement.

```java
class P implements Cloneable {
    ...
    public Object clone(){
        try {
            return super.clone(); // copia bit a bit
        } catch (CloneNotSupportedException e) {
            System.err.println("Implementation error");
            System.exit(1);
        }
        return null; //qui non arriva mai
    }
}
```

> se clono un oggetto che contiene un array clono il puntatore allo stesso array. Non viene creato un nuovo array uguale perché faccio una copia bit a bit se non specificato diversamente

---

- shallow copy
- deep copy

---

> non so perché ha fatto una digressione sulla clonazione degli oggetti in c++

## Composition VS Inheritance

usare oggetti interni a cui delego l'implementazione delle funzioni dell'interfaccia

## JavaFX

esempi di codice in lecture 11 e 12

### MVC

Model View Controller
