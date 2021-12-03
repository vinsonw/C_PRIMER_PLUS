// this works on wsl2, 
// not on windows cmd/powershell, probably cmd codepage problem
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL,""); // this is a must
    wchar_t s[] = L"中文说明"; // must

    // printf & wprintf couldn't be used at the same time <- undefined behavior
    // printf("hello\n");
    // printf("Length of wchar string is == %d\n", wcslen(s));

    wprintf(L"现在要打印的是：%ls\n", s); // "%ls" is a must

}
