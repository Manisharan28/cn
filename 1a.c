
#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[220];
    int i = 0, j = 0;

    printf("Enter string: ");
    scanf("%99s", a);

    strcpy(b, "DLESTX");
    j = strlen(b);

    while (a[i] != '\0') {
        if (strncmp(&a[i], "DLE", 3) == 0) {
            strcpy(&b[j], "DLE");
            j += 3;
        }

        b[j++] = a[i++];
    }

    strcpy(&b[j], "DLEETX");

    printf("Frame after stuffing: %s\n", b);

    return 0;
}
