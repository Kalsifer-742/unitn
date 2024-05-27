(*
Esame febbraio 2021
Testo

Implementare una funzione f che data una lista [a1,...,an], calcoli a1-a2+a3-a4+... La funzione così definita dovrà funzionare con liste di qualsiasi lunghezza.
*)

fun f [] = 0
  | f (a::[]) = a
  | f (a::b::[]) = a - b
  | f (a::b::c::[]) = (a - b) + c
  | f (a::b::c::d::e) = (a - b) + (c - d) + f e