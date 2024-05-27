# Lezione ?/3/22

## names

- binding of an identifier to a variable.
  - compile time - prior execution
  - runtime - during execution
- discorsi noiosissimi sulla teoria di programmazione, tipo la dichiarazione, aliasing, local names, confronti con altri linguaggi ecc...
- scopes spiegati in maniera strana, tipo teorica.
  - shadowing
  - lifetime: un oggetto puó vivere piú o meno a lungo della sua associazione (reference/puntatore)
  - scope statico
    - all info in the program text
    - associations at compile time
    - principle of independence
    - easier to implement and more efficient
  - scope dinamico
    - info derived during execution
    - hard to read code
    - hard to implement, less efficient