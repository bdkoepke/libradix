#include "hexdump.h"
#include <stdio.h>

void hexdump(const char *description, const void *address, size_t length) {
    if (description != NULL)
        printf ("%s:\n", description);
    unsigned char buffer[17];
    unsigned char *pc = (unsigned char*)address;
    int i;
    for (i = 0; i < length; i++) {
        if ((i % 16) == 0) {
            if (i != 0)
                printf ("  %s\n", buffer);
            printf ("  %04x ", i);
        }
        printf (" %02x", pc[i]);
        buffer[i % 16] = ((pc[i] < 0x20) || (pc[i] > 0x7e)) ? '.' : pc[i];
        buffer[(i % 16) + 1] = '\0';
    }
    for (; (i % 16) != 0; i++)
        printf("   ");
    printf ("  %s\n", buffer);
}
