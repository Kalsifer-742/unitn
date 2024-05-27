(*
Esame luglio 2022
Testo

Scrivere una funzione f di tipo int list -> int list che presa in input una lista trasformi ogni elemento "a" della lista nel seguente modo:

    se a >= 0 allora l'elemento "a" dovrà essere trasformato in a^2-1
    altrimenti l'elemento "a" dovrà essere trasformato in a^2+1

ESEMPIO f [~1,2,3,0,~5,6]; dovrà dare in output: val it = [2, 3, 8, ~1, 26, 35]: int list
*)

fun f(xs: int list) =
    if null xs
    then []
    else if hd(xs) >= 0
    then hd(xs)*hd(xs)-1 :: f(tl(xs))
    else hd(xs)*hd(xs)+1 :: f(tl(xs))