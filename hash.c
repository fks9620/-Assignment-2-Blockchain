#include "hash.h"

unsigned char* SSHA(const unsigned char* msg, size_t length) {
    unsigned char A, B, C, D, E; //Initial Seed Value
    A = 56;
    B = 99;
    C = 102;
    D = 67;
    E = 76;

    for (int i = 0; i < length; i++) {
        for (int round = 0; round < 8; round++) {
            unsigned char g = (B & C) | (C & D);
            //unsigned char old_A = A;

            unsigned char shiftedA = A >> 2;
            unsigned char shiftedB = B >> 1;

            A = E; //good
            B = A; //good
            C = shiftedA + E; //good
			D = shiftedA ^ shiftedB; //good
			E = g + shiftedB + msg[i]; //good


            //A = A ^ (A >> 2); // Non-destructive bitshift replacement
            //B = B ^ (B >> 1); // Non-destructive bitshift replacement
            //E = (g + msg[i] + B);
            //D = A ^ B;
            //C = (A + E);
            //A = E;
            //B = old_A;
        }
    }



    unsigned char* digest = (unsigned char*)malloc(DIGEST_SIZE * sizeof(unsigned char));
    digest[0] = A;
    digest[1] = B;
    digest[2] = C;
    digest[3] = D;
    digest[4] = D;
    return digest;
}

void SSHA2(unsigned char msg[], int msgLength,
    unsigned char* A, unsigned char* B,
    unsigned char* C, unsigned char* D,
    unsigned char* E)
{
    for (int i = 0; i < msgLength; i++) {

        unsigned char oldA = *A;
        unsigned char oldB = *B;
        unsigned char oldC = *C;
        unsigned char oldD = *D;
        unsigned char oldE = *E;

        unsigned char shiftA = oldA >> 2;
        unsigned char shiftB = oldB >> 1;

        unsigned char and1 = oldB & oldC;
        unsigned char and2 = oldC & oldD;

        unsigned char orResult = and1 | and2;

        *A = oldE;
        *B = oldA;
        *C = shiftA + oldE;
        *D = shiftA ^ shiftB;
        *E = shiftB + orResult + msg[i];
    }
}

int digest_equal(struct Digest digest1, struct Digest digest2) {
    return ((digest1.hash0 == digest2.hash0) &&
        (digest1.hash1 == digest2.hash1) &&
        (digest1.hash2 == digest2.hash2) &&
        (digest1.hash3 == digest2.hash3) &&
        (digest1.hash4 == digest2.hash4));
}

void printDigest(struct Digest digest) {
    printf("%d %d %d %d %d\n", digest.hash0, digest.hash1, digest.hash2, digest.hash3, digest.hash4);
}