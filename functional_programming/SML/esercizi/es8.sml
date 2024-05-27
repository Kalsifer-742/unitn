(*
    ESERCIZIO 8
    Testo:    
    Scrivere una funzione "mul" che calcoli n ∗ z senza usare la moltiplicazione, 
    dove n è un numero intero positivo e z è un numero intero

    SOLUZIONE:
*)

fun mul(n, z) =
    if z = 1
    then n
    else n + mul(n, z - 1)