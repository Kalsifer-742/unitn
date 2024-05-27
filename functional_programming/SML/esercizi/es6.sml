(*
    ESERCIZIO 6
    Testo:
    Scrivere una funzione che restituisca -1 per i numeri negativi, 0 per 0 e +1 per
    argomenti positivi. Si può usare il pattern matching?

    SOLUZIONE:
*)

fun f(x : int) =
    if x < ~1
    then 0
    else if x = 0
    then 0
    else 1