#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 256

// Function to calculate (a^b)%m using left-to-right exponentiation method
int power(int a, int b, int m) {
    int res = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % m;
        b = b >> 1;
        a = (a * a) % m;
    }
    return res;
}

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate Modular Multiplicative Inverse
int modInverse(int a, int m) {
    int g = gcd(a, m);
    if (g != 1)
        return -1;
    else
        return power(a, m - 2, m);
}

int main() {
    int p, g, k;
    int secret, private_key, public_key;

    printf("Enter the value for p: ");
    scanf("%d", &p);

    printf("Enter the value for g: ");
    scanf("%d", &g);

    printf("Enter the secret key (k < %d): ", p);
    scanf("%d", &k);

    secret = k;
    private_key = power(g, k, p);
    public_key = power(g, secret, p);

    printf("\nGenerated Private Key: %d", private_key);
    printf("\nGenerated Public Key: %d", public_key);

    // Shared secret
    int shared_secret = power(public_key, k, p);
    printf("\nShared Secret: %d", shared_secret);

    return 0;
}
    
