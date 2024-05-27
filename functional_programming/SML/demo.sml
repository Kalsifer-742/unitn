(* type check prima di runnare, controllo l'ambiente statico, guarda solo i tipi *)
(* evaluation quando il programma runna *)
val x = 33;
(* cambio l'ambiente dinamico creando un nuovo binding  *)
val y = ~17;
(* - può essere usato solo come espressione in ml, devo usare ~ per negare*)
val z = (x + y) + (y + 2);
(* commento *)
val test = if z < 0 then z + 1 else z;
(* i due branch condizionali devono avere lo stesso tipo *)
abs z; (* esempio di chiamare una funzione, parentesi facoltative *)
x div 3; (* divisione tra interi si usa div mentre tra real / *)

(* sintassi *)
(* type-checking *)
(* evaluation *)

(* use "input.sml" evaluation di tutte le righe del file una dopo l'altra*)
(* REPL Read-Eval-Print-Loop *)
(* CTRL+D end session *)

(* non sono necessari nei file mentre nel terminale si*)

(* assunto y >= 0 *)
fun pow(x: int, y: int) = if y = 0 then 1 else x * pow(x, y-1)
(* pow = fn : int * int -> int , tipo della funzione, i parametri sono separati da * *)
fun cube(x: int) = pow(x, 3)

(* tupla, roba a caso di lunghezza fissa *)
val tup = (2, true)
(* #2 tup, accedo al secondo valore della tupla *)
fun swap (pr : int * bool) = (#2 pr, #1 pr)

(* swap(4, true) *)
val nesting = (7,(true,9))
val estrazione = #1 (#2 nesting)

(* 
lista, roba uguale di lunghezza infinita
[3,4,5]
*)
val lista = [2,3+1,4]
(*
88::77::lista
[6]::[[3,2],[1,0]]

null lista, se la lista è vuota ritorna true
hd lista, ritorna primo elemento della lista
tl lista, ritorna tutti gli elementi tranne il primo
int list, significa una lista di int 

[] ha tipo 'a list e prende il tipo della prima cosa che ci metto dentro
3::[]
*)

fun sum_list (xs : int list) =
    if null xs
    then 0
    else hd xs + sum_list(tl xs)

fun countdown (x : int) =
    if x = 0
    then []
    else x :: countdown(x - 1)

(* 
ricorsione con le liste
se voglio interagire con tutti gli elementi devo fare una funzione ricorsiva di qualche tipo che sfrutta la terminale
domanda che devo farmi:
qual'è la risposta per la lista vuota
qual'è la risposta per la lista non vuota, da pensare relativamente alla coda della lista

funzioni che creano liste
creo liste partendo da liste più piccole
*)