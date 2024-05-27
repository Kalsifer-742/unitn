# Lezione 24/3/22

## Memory allocation

- static
  - allocated at compiletime
- dynamic
  - allocated at runtime
    - stack: LIFO
    - heap: allocated and deallocated at any time

## Static

- absolute address manteined during the execution
- examples
  - global variables
  - local variables
  - costants
  - NOT recursion

## Dynamic

- Stack
  - roba della lezione di calcolatori sulle procedure
  - activation record for every instance of a subprogram
  - LIFO
  - to reduce memory usage in languages without recursion
  - anonymus blocks = nested blocks. Stack is not necessary to implement them
- Heap
  - roba della lezione di calcolatori sulle procedure
  - not trivial to implement
  - fragmentation
  - No LIFO
  - fragmnetation
    - internal
      - block size is to big
    - external
      - free space broken up into small pieces