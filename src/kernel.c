#include <stddef.h>
#include <stdint.h>

void kernel_main(void) 
{
    const char *str = "Hello, kernel World!";
    volatile char *video = (volatile char*) 0xB8000;

    for (size_t i = 0; str[i] != '\0'; i++) {
        video[i*2] = str[i];
        video[i*2 + 1] = 0x07;
    }
}

