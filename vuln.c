#include <stdio.h>
#include <windows.h>

int main(void) {
    char buffer[256];
    printf("Enter your input:\n");

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Vulnerable printf: user input used directly as format string!
    printf(buffer);

    printf("\nThanks for playing!\n");

    char flag[] = "flag{leak_master}";
    volatile char *keep_flag = flag;
    (void)keep_flag;

    return 0;
}
