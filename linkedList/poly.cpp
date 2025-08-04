#include <stdio.h>

#define MAX 100

struct Node {
    int coef;
    int exp;
    int next;
};

struct Node poly[MAX];
int poly1Head = -1, poly2Head = -1, resultHead = -1;
int freeIndex = 0;

int getFreeNode() {
    if (freeIndex >= MAX) return -1;
    poly[freeIndex].next = -1;
    return freeIndex++;
}

void insertPolynomial(int coef, int exp, int* polyHead) {
    int newNode = getFreeNode();
    if (newNode == -1) return;
    poly[newNode].coef = coef;
    poly[newNode].exp = exp;
    poly[newNode].next = -1;

    if (*polyHead == -1 || poly[newNode].exp > poly[*polyHead].exp) {
        poly[newNode].next = *polyHead;
        *polyHead = newNode;
    } else {
        int current = *polyHead;
        while (poly[current].next != -1 && poly[poly[current].next].exp > exp)
            current = poly[current].next;
        poly[newNode].next = poly[current].next;
        poly[current].next = newNode;
    }
}

void addPolynomials() {
    int temp1 = poly1Head, temp2 = poly2Head;
    int* lastPtr = &resultHead;
    while (temp1 != -1 && temp2 != -1) {
        int newNode = getFreeNode();
        if (newNode == -1) return;

        if (poly[temp1].exp == poly[temp2].exp) {
            int sum = poly[temp1].coef + poly[temp2].coef;
            if (sum != 0) {
                poly[newNode].coef = sum;
                poly[newNode].exp = poly[temp1].exp;
                poly[newNode].next = -1;
                *lastPtr = newNode;
                lastPtr = &poly[newNode].next;
            }
            temp1 = poly[temp1].next;
            temp2 = poly[temp2].next;
        } else if (poly[temp1].exp > poly[temp2].exp) {
            poly[newNode].coef = poly[temp1].coef;
            poly[newNode].exp = poly[temp1].exp;
            poly[newNode].next = -1;
            *lastPtr = newNode;
            lastPtr = &poly[newNode].next;
            temp1 = poly[temp1].next;
        } else {
            poly[newNode].coef = poly[temp2].coef;
            poly[newNode].exp = poly[temp2].exp;
            poly[newNode].next = -1;
            *lastPtr = newNode;
            lastPtr = &poly[newNode].next;
            temp2 = poly[temp2].next;
        }
    }

    while (temp1 != -1) {
        int newNode = getFreeNode();
        if (newNode == -1) return;
        poly[newNode].coef = poly[temp1].coef;
        poly[newNode].exp = poly[temp1].exp;
        poly[newNode].next = -1;
        *lastPtr = newNode;
        lastPtr = &poly[newNode].next;
        temp1 = poly[temp1].next;
    }

    while (temp2 != -1) {
        int newNode = getFreeNode();
        if (newNode == -1) return;
        poly[newNode].coef = poly[temp2].coef;
        poly[newNode].exp = poly[temp2].exp;
        poly[newNode].next = -1;
        *lastPtr = newNode;
        lastPtr = &poly[newNode].next;
        temp2 = poly[temp2].next;
    }
}

void displayPolynomial(int polyHead) {
    int temp = polyHead;
    while (temp != -1) {
        printf("%dx^%d", poly[temp].coef, poly[temp].exp);
        if (poly[temp].next != -1) printf(" + ");
        temp = poly[temp].next;
    }
    printf("\n");
}

int main() {
    insertPolynomial(4, 3, &poly1Head);
    insertPolynomial(3, 2, &poly1Head);
    insertPolynomial(2, 1, &poly1Head);

    insertPolynomial(5, 3, &poly2Head);
    insertPolynomial(2, 1, &poly2Head);
    insertPolynomial(1, 0, &poly2Head);

    printf("Polynomial 1: ");
    displayPolynomial(poly1Head);

    printf("Polynomial 2: ");
    displayPolynomial(poly2Head);

    addPolynomials();

    printf("Resultant Polynomial: ");
    displayPolynomial(resultHead);

    return 0;
}
