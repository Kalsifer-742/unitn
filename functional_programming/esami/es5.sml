(*
Si scriva una funzione conta (avente tipo ' 'a list -> int) che riceve come argomento una lista di ' 'a. La funzione conta ritorna il numero di elementi della lista senza considerare i duplicati.

Come esempio, l'invocazione conta ["pera", "pera", "pera", "pera"]; deve avere risultato 1, conta ["red", "red", "green", "blue"]; deve avere risultato 3 e conta [2, 3, 4, 2]; deve avere risultato 3.

IMPORTANTE: notare il tipo della funzione!

val rec conta = fn [] => 0
                 | a::b => if (List.exists ((fn y => a = y)) b) then (conta b) else 1+(conta b);
*)

fun conta [] = 0
  | conta (a::b) =
    if List.exists (fn y => y = a) b
    then conta b
    else 1 + conta b;