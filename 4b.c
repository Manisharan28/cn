

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long mod_exp(long long base, long long exponent,
                  long long modulus) {
    long long result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}

int main() {
    long long p, q, n, phi, e, d;
    long long encrypted, decrypted, message;

    printf("Enter a prime number p: ");
    scanf("%lld", &p);

    printf("Enter another prime number q: ");
    scanf("%lld", &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    e = 2;
    while (gcd(e, phi) != 1)
        e++;

    printf("Chosen e = %lld\n", e);

    d = 1;
    while ((e * d) % phi != 1)
        d++;

    printf("Public Key (n = %lld, e = %lld)\n", n, e);
    printf("Private Key (n = %lld, d = %lld)\n", n, d);

    do {
        printf("Enter message (integer less than %lld): ", n);
        scanf("%lld", &message);
    } while (message < 0 || message >= n);

    encrypted = mod_exp(message, e, n);
    printf("Encrypted message: %lld\n", encrypted);

    decrypted = mod_exp(encrypted, d, n);
    printf("Decrypted message: %lld\n", decrypted);

    return 0;
}
