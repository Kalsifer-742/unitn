(*
Esame giungo 2023
Testo

scrivere una curried function “f” che prenda in input una lista di stringhe[ai, ai+1, …] e un intero n, e ritorni una lista di stringhe[bi, bi+1, …] in cui bi è uguale ad ai solo se la lunghezza di ai è minore o uguale ad n, altrimenti bi è uguale ad ai senza il primo carattere.

> f2 [" ", "ab", "abc", "abcd", "abcde"] 3;
val it = [" ", "ab", "abc", "bcd", "bcde"]: string list

f [" ", "ab", "abc", "abcd", "abcde"] 3;

*)

fun f [] n = []
  | f (a::l) n =
    if size(a) <= n
    then a :: f l n
    else substring(a, 1, size(a)-1) :: f l n


fun f2 (nil) n = nil 
  | f2 (a::l) n = 
    if (length (explode a) <= n) 
    then a::(f (l) n) 
    else implode(tl(explode(a)))::(f (l) n);