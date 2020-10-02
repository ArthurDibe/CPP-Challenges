# Get Screen Info

This section you can find a solution to get information about the physical screen of you machine that runs Linux Kernel.

* `main.cpp`: This module allocate dynamic memory through a function called initialize and swap variables' contents by calling the templated function swap.<br>

* `makefile`: has the instructions to system compile, recompile and clean the file objects used in the compilation.

## Instructions
1. Place both files "main.cpp" and "makefile" in the same directory.
2. In the shell, enter "make", that will compile the .cpp with file object
3. The "make" command will generate the executable file called "output"
4. Run the "output" file with sudo. That is necessary because our program
   is going to communicate with your linux kernel via input output controls,
   in order to retrieve your machine information



