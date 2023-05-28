# leetcode_practice
Use leetcode to learn algorithms


## Illustrate
1. This branch `makepipi` contains **Makefile** files, which can implement compilation rules on both **Linux** and **Windows** platforms.
2. The execution order of commands in the Makefile file is compile first, then link. i.e.  `g++ -c hello.cpp`, then `g++ -o hello hello.o`. 
3. For each cpp file is independent, there are multiple generation targets and it is not possible to generate a single `exe`.
4.  Now it **not support Linux** for .exe files are not direct executable file.

## How to Run
1. Enter the following command on the command line:
```makefile
make
```
2. Then the machine will automatically compile and link, and generate an exe file. You can see `g++ -c -Wall ....` and `It's building...`, which shows that it has been successfully generated. Then enter the following on the command line:
```makefile
ls
```
3. Normally, you can see multiple exe files. Then select the file you want to run, and enter the file name of exe for the value. For example:
```makefile
hello
```
4. Finally, if running on a Windows platform, you may need to use the `make cleanwin` command to clear all exe files. Whereas on Linux , please use the `make cleanlin`
