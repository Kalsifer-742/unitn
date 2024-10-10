(*
Esame settembre 2020
Testo

Si consideri il tipo di dato FOR = For of int * (int -> int); i cui valori For(n, f) rappresentano funzioni che implementano un ciclo for come il seguente:

int ciclofor (int x) {
    for (int i = 0; i < n; i++) {
        x = f(x);
    }
    return x;
}

Si scriva una funzione eval (avente tipo FOR -> (int -> int)) che riceve come argomento un valore di tipo FOR e ritorna una funzione da interi ad interi che implementa il ciclo indicato qui sopra (applica n volte la funzione f all'argomento).

Come esempio, se val f = fn x => x * 2, allora eval (For(3, f)) ritornerà una funzione che dato un numero i ritorna i * 8:

val f = fn x => x * 2;
eval (For(3, f));
val g = eval (For(3, f));
g 5;

datatype FOR = For of int * (int -> int);
val rec eval = fn For (n, f) => fn x => if (n > 0)
                                        then
                                            eval (For (n - 1, f)) (f x)
                                        else
                                            x;
*)

datatype FOR = For of int * (int -> int);

fun eval (For (n, f)) = fn x => if n > 0
                                then eval (For (n - 1, f)) f x
                                else x;