Mostly trivia about C language.
But here are some points worth noting:

* three major versions: C89/C90(these two are pratically the same), C99, C11
* peripherals: devices connected to a computer, such as the keyboard, mouse, touchscreen ,and monitor - provide for communication between the computer and you.
* compiler: translates C code into machine code that is not yet to be executed by the computer
* linker: links `object code`(machine code provided by the compiler) to `startup code` and `libraray code`, combing them into the final `executable code`. 
 > "On some systems, you must run the compile and link programs separately. On others systems, the compiler starts the linker automatically, so you have to give only the comile command" - Linux is the latter.
* `GCC/gcc` stands for `GNU Compiler Collection`.
* `cc` is used as an alias for `gcc` or `clang`.
* `gcc` requires run-time options to invoke more recent C standards:
```bash
gcc -std=c99 inform.c
gcc -std=c1x inform.c # for gcc versions before the acceptance of C11
gcc -std=c11 inform.c
```