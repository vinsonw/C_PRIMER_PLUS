Mostly trivia about C language.
But here are some points worth noting:

* three major versions: C89/C90(these two are pratically the same), C99, C11
* peripherals: devices connected to a computer, such as the keyboard, mouse, touchscreen ,and monitor - provide for communication between the computer and you.
* compiler: translates C code into machine code that is not yet to be executed by the computer
* linker: links `object code`(machine code provided by the compiler) to `startup code` and `libraray code`, combing them into the final `executable code`. 
 > "On some systems, you must run the compile and link programs separately. On others systems, the compiler starts the linker automatically, so you have to give only the comile command" - Linux is the latter.
* `GCC/gcc` stands for `GNU Compiler Collection`.
* `cc` is used as an alias for `gcc` or `clang`.
* ~~`gcc` requires run-time options to invoke more recent C standards~~ By default, gcc(10.2.1) 
uses C18 out of box. You could use the following commands to specify a version of C standard:
```bash
gcc -std=c99 inform.c
gcc -std=c1x inform.c # for gcc versions before the acceptance of C11
gcc -std=c11 inform.c
```
* C preprocessor directives to detect C standard that your compiler uses:
> See https://youtu.be/ieERUEhs910?list=PLKR_KIjJfNjbByY02RQxP0AMKR9i-78v2&t=576 by Dan Saks.
```C
#include <stdio.h>

int main(void)
{
#if __STDC_VERSION__ == 201710L
    printf("/* it's C18 */");
#elif __STDC_VERSION__ == 201112L
    printf("/* it's C11 */");
#elif __STDC_VERSION__ == 199901L
    printf("/* it's C99 */");
#elif __STDC__ == 1
    printf("/* it's C90 */");
#else
    printf("/*it's not standard conforming */");
#endif
}
``` 
> Note after C89/C90, all C standards set `__STDC__ == 1`, so that only use this macro could not distinguish between C89/C90, C11, and C18