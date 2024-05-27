# Lezione ?/3/22

## cose

- `hd(L)` primo elemento di una lista
- `tl(L)` coda della lista = tutto tranne il primo elemento
- `[1,2] @ [3,4]` concatenazione tra liste
- `^` concatenazione tra stringhe
- `nil` termine di una lista
- `2 :: [3,4]` mette in testa un elemento ad una lista
- `explode("abcd")` lista di caratteri
- `implode(#"a", #"b")` da lista a stringa
- `int, real, bool, char, string`
- tipi complessi, liste e tuple
  - `("ab", [1,2,3], 4)`
  
## functions

- `fun upper(c) = chr (ord(c) - 32)`
  - `upper(#"a")`
  - automatic function type recognition. Special example with number multiplication: `*` defined for integers and real. To solve we can use: `fun square(x: real) = x * x`
- multiple arguments
  - all functions have 1 parameter that can be a **tuple**. Es: `fun max3(a:real,b,c) = ...` (note that `b` and `c` are considered reals)
- variables used in the functions assume the value they had when the function was intialized, es: `val x = 3; fun add(a) = a + x; val x = 10; addx(2)` result 5

## recursion

```ml
fun reverse L = 
  if L = nil then nil 
  else reverse (tl L) @ [hd L];
```
