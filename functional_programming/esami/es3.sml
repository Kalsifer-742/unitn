(*
Esame giugno 2022
Testo

Implementare una funzione f che, dato un file "text.txt" contenente una lista con un numero pari di caratteri restituisca una lista (type string list) di coppie di caratteri, ignorando i primi due e proponendo i successivi due iterativamente (quindi si avranno i caratteri 3,4 seguiti da 7,8, e così via).

Il file contenente il codice e file "text.txt" devono trovarsi nella stessa directory. Il file "text.txt" di esempio viene fornito unitamente a questo file.

Un'ipotetica esecuzione del codice da bash potrebbe essere:

Assicurarsi di avere il file "text.txt". Lanciare poly da terminale

> use "cognome_nome.sml";
val it = ["ac","ef","54",""]: string list

La funzione f deve essere definita in un file .sml autocontenuto ma separato da qualsiasi codice di test sia usato. Si consegni il file .sml contente la definizione di f. Rinominare il file con cognome_nome.sml.

open TextIO;

fun helper(stream, "", n) = []
  | helper(stream, str, n) =
    if n mod 2 = 0
    then str :: helper(stream, TextIO.inputN(stream, 2), n+1)
    else helper(stream, TextIO.inputN(stream, 2), n+1)

fun wrapper(stream) =
    helper(stream, TextIO.inputN(stream, 2), 1)

fun getstream(filename) = wrapper(TextIO.openIn(filename));

getstream("text.txt");
*)

fun f filename =
    let
        val stream = TextIO.openIn(filename)
        fun helper("", n) = []
          | helper(str, n) =
            if n mod 2 = 0
            then str :: helper(TextIO.inputN(stream, 2), n+1)
            else helper(TextIO.inputN(stream, 2), n+1)
    in
        helper(TextIO.inputN(stream, 2), 1)
    end;

f "text.txt";