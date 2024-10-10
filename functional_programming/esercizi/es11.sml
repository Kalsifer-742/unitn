(*
    ESERCIZIO 11
    Testo:    
    Scrivere una funzione isOrdinata che data una lista restituisca true se essa è ordinata in ordine crescente
    false altrimenti

    SOLUZIONE:

    <>	"not equal to"
*)

fun isOrdinata(l) =
    if null l orelse length l = 1
    then true
    else if hd(l) < hd(tl(l)) 
    then isOrdinata(tl(tl(l)))
    else false

fun isOrdinata2 [] = true
     |  isOrdinata2 (a::[]) = true
     |  isOrdinata2 (a::b::l) = if a > b then false else isOrdinata(b::l);