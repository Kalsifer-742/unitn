(*
    ESERCIZIO 10
    Testo:    
    Scrivere una funzione "f" che dato un numero x e una lista di interi ordinata
    restituisca una lista ordinata contente x.

    es. f 5 [1,2,3,4,6,7] 
    [1,2,3,4,5,6,7]

    es.  f 5 [5,5,5,5,6] 
    [5,5,5,5,5,6]

    SOLUZIONE:

    fun length ([] : int list) : int = 0
    | length (x::xs : int list) : int = 1 + length xs

    Given a non-empty list, this function simply binds the first element of the list to the identifier x, discards it, and then recursively calls length to find the length of the remaining list xs, adding 1 to the result.

    mostrare attenzione a come il problema dice che verrà chiamata la funzione
*)

fun f x [] = x::[]
  | f x (a::b) = 
    if x > a 
    then a::(f x b)
    else x::(a::b)