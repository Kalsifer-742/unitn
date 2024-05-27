(*
    ESERCIZIO 2
    Testo:
    Scrivere una funzione "prod" che calcoli il prodotto di tutti gli interi tra 2 numeri m ed n. (con m >= m inclusi).
	Usare poi questa funzione per scrivere una funzione C(n,k) la quale calcola il numero di combinazioni di n elementi
	presi k a k. 
	Definita dalla formula matematica: C(n, k) = n!/(k! * (n − k)!)
	che equivale anche a: C(n, k) = (n − k + 1) · (n − k + 2) · · · n / 1 · 2 · · · k

    SOLUZIONE:
*)

fun prod(m : int, n : int) =
    if m = n
    then n
    else m * prod(m - 1, n)

fun C(n : int, k: int) =
    prod(n, n - k + 1) div prod(k, 1)
