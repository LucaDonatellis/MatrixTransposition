scrivi comandi di compilazione, versione e collegamenti al file
simd, prefetch per implicit
non usare o3 usa o2 con i flag
access pattern nell ultimo coso el corso
deve contenere il pbs

dentro il pbs export NUM_THREADS = 1;

g++ -o serial serial.cpp -fopenmp
./serial 16384
g++ -o implicit implicit.cpp -fopenmp -O2 -march=native -ftree-vectorize -fprefetch-loop-arrays -funroll-loops
./implicit 16384
g++ -o onlyOMP onlyOMP.cpp -fopenmp
./serial 16384
g++ -o explicit explicit.cpp -fopenmp -O2 -march=native -ftree-vectorize -fprefetch-loop-arrays -funroll-loops
./explicit 16384