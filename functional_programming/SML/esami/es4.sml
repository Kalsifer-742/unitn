(*
Testo

Si scriva una funzione sommali (avente tipo int -> int list -> int) che riceve come argomento un intero n ed una lista di interi l. La funzione sommali somma ad n gli elementi di l che hanno posizione pari (se la lista contiene meno di 2 elementi, sommali ritorna n).

Come esempio, l'invocazione sommali 0 [1,2]; deve avere risultato 2; sommali 1 [1,2,3]; deve avere risultato 3; sommali 2 [1,2,3,4]; deve avere risultato 8.
*)

fun sommali n [] = n
  | sommali n (a::[]) = n
  | sommali n (a::b::c) = b + sommali n c
