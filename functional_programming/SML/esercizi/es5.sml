(*
    ESERCIZIO 5
    Testo:
    Scrivere una funzione che restituisca il valore 2 per gli argomenti 0, 1 e 2
    e restituisca 3 per tutti gli altri argomenti (interi). Scrivi due soluzioni: 
    (a) usando pattern matching 
    (b) usando if-then-else

    SOLUZIONE:
*)

fun funnymatch(0) = 2
  | funnymatch(1) = 2
  | funnymatch(2) = 2
  | funnymatch(_) = 3

fun match(x) = case x of 
    0 => 2
  | 1 => 2
  | 2 => 2
  | _ => 3

fun ifelse(x) =
    if x = 0 orelse x = 1 orelse x = 2
    then 2
    else 3