(*
    ESERCIZIO 9
    Testo:    
    Scrivere una funzione "f" che concateni 2 liste

    SOLUZIONE:

    l1 @ l2
    returns the list that is the concatenation of l1 and l2.
*)

fun concat(xs: int list, ys: int list) =
    if null xs
    then ys
    else hd(xs) :: concat(tl(xs), ys)

fun f a b = a @ b;