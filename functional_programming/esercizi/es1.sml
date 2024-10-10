(*
    ESERCIZIO 1
    Testo:
    Scrivere una funzione f che ritorna "uno" se riceve come paramentro 1 e "qualcos'altro" altrimenti.

    SOLUZIONE:
*)

fun f(1) = "uno"
  | f(_) = "qualcos'altro"

fun ftrad(x) = case x of
    1 => "uno"
  | _ => "qualcos'altro"

val rec fstd = 
    fn 
    1 => "uno"
  | _ => "qualcos'altro"