# arhiva educationala infoarena

Solutions to some of the problems from [arhiva educationala infoarena](https://infoarena.ro/arhiva-educationala).

Problems included:
 - [x] [000 - Algoritmul lui Euclid](https://infoarena.ro/problema/euclid2) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/000_euclid2.h)
 - [x] [001 - Cel mai lung subsir comun](https://infoarena.ro/problema/cmlsc) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/001_cmlsc.h)
 - [x] [005 - Potrivirea sirurilor](https://infoarena.ro/problema/strmatch) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/005_strmatch.h)
 - [ ] [008 - Subsir crescator maximal](https://infoarena.ro/problema/scmax) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/008_scmax.h)
 - [x] [009 - Algoritmul lui Dijkstra](https://infoarena.ro/problema/dijkstra) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/009_dijkstra.h)
 - [x] [010 - Ciurul lui Eratosthenes](https://infoarena.ro/problema/ciur) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/010_ciur.h)
 - [x] [011 - Generare de permutari](https://infoarena.ro/problema/permutari) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/011_permutari.h)
 - [x] [012 - Ridicare la putere in timp logaritmic](https://infoarena.ro/problema/lgput) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/012_lgput.h)
 - [x] [013 - BFS - Parcurgere in latime](https://infoarena.ro/problema/bfs) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/013_bfs.h)
 - [x] [014 - Parcurgere DFS - componente conexe](https://infoarena.ro/problema/dfs) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/014_dfs.h)
 - [ ] [016 - Range minimum query](https://infoarena.ro/problema/rmq) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/016_rmq.h)
 - [x] [017 - Combinari](https://infoarena.ro/problema/combinari) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/017_combinari.h)
 - [x] [022 - Paduri de multimi disjuncte](https://infoarena.ro/problema/disjoint) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/022_disjoint.h)
 - [x] [025 - Heapuri](https://infoarena.ro/problema/heapuri) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/025_heapuri.h)
 - [x] [026 - Arbore partial de cost minim](https://infoarena.ro/problema/apm) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/026_apm.h)
 - [x] [051 - Problema rucsacului](https://infoarena.ro/problema/rucsac) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/051_rucsac.h)
 - [x] [058 - Diametrul unui arbore](https://infoarena.ro/problema/darb) - [Solution](https://github.com/andcov/infoarena_arhiva_educationala/blob/master/058_darb.h)

## Prerequisites
You must have a C++ compiler and CMake installed. If you do not, you will not be able to run the project, but you may still see the solutions (e.g. look at `001_cmlsc.h` for the solution for [001 - Cel mai lung subsir comun](https://infoarena.ro/problema/cmlsc)). 

## Installation & Usage
 * Clone this repo: `git clone https://github.com/andcov/infoarena_arhiva_educationala.git && cd infoarena_arhiva_educationala`
 * Initialise CMake: `cmake ./`
 * In `main.cpp`, set the header according to the problem you want to solve. (e.g. `#include "001_cmlsc.h"` if you want to run the solution for [001 - Cel mai lung subsir comun](https://infoarena.ro/problema/cmlsc))
 * Build the project: `cmake --build ./`
 * Set `input.in` to your desired input
 * Run the program: `./infoarena_arhiva_educationala`
 * Print the result: `cat output.out`
