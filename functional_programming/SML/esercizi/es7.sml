(*
    ESERCIZIO 7
    Testo:    
    Scrivere una funzione che restituisca il più piccolo dei suoi due argomenti 
    (a) usando argument pattern
    (b) usando una dichiarazione locale

    SOLUZIONE:
*)

fun min(x : int, y : int) =
    if x < y
    then x
    else y

fun minB(t:int*int) = 
        let 
            val (a,b)=t 
        in 
            if (a<b) then a else b 
        end