(*
    ESERCIZIO 4
    Testo:
    La radice quadrata intera positiva di un numero intero non negativo è una funzione
    introot tale che "introot m" è il più grande intero tale che n * n è minore
    pari o uguale a m. Definire questa funzione in ML.

    es. introot 15
    3*3 = 9 <= 15 --> return 3
    es. introot 16
    4*4 = 16 <= 16 --> return 4

    SOLUZIONE:
*)

fun introot(m : int) =
    let
        fun tmproot(n, m) = 
            if n * n <= m
            then n
            else tmproot(n - 1, m)
    in
        tmproot(m, m)
    end