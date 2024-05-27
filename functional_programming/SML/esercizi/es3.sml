(*
    ESERCIZIO 3
    Testo:
    Scrivere una funzione "power : int * int -> int" in modo che, per m>=0 power(n,m) = n^m
    Assumete che 0^0 risulti 1.

    SOLUZIONE:
*)

fun power(0, 0) = 1
  | power(n, m) = 
    if m <= 0 then 1 else n * power(n, m - 1)
