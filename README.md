# Matrix Multiplication with OpenMP

Tested with gcc-9.1.0 and gcc-14.2.0

### Compilation commands:
- g++ -o serial serial.cpp -fopenmp
- g++ -o implicit implicit.cpp -fopenmp -O2 -ftree-vectorize
- g++ -o onlyOMP onlyOMP.cpp -fopenmp
- g++ -o explicit explicit.cpp -fopenmp -O2 -ftree-vectorize

### To test different threads:
- On linux: export NUM_THREADS = 1
- On cmd: set NUM_THREADS=1
- On Powershell: $env:OMP_NUM_THREADS=6

### Execution commands:
- ./serial 4096
- ./implicit 4096
- ./onlyOMP 4096
- ./explicit 4096

On cmd you can test the scripts using the command ./test explicit 

### Executing on the cluster:
- qsub serial.pbs
- qsub implicit.pbs
- qsub onlyOMP.pbs
- qsub explicit.pbs

PBS files contains scripts to test different options.
In order to do specific tests you can add the test at the end of the PBS file, comment the other tests or copy the settings of the PBS file for the specific implementation.

### Formatting output
If you want to see results in a better way just copy the output files of the PBS call and input that on the ruby program, the output contains one line for each execution with 9 couples of value of matrix size n and the time it took to execute.

The output files generated by the PBS scripts can be processed using a Ruby script for easier analysis. Ensure that the output contains the starting boilerplate and that the isTranspose function is commented out unless testing its correctness.

### Validation
To test the correct functioning of the codes just un-comment the isTransopse function.