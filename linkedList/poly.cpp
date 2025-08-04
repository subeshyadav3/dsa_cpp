#include <stdio.h>

#define MAX 100

struct Node {
    int coef;
    int exp;
    int next;
};

struct Node poly[MAX];
int poly1Head = -1, poly2Head = -1, resultHead = -1;

void insertPolynomial(int coef, int exp, int* polyHead) {
    int newNode = 0;
    while (poly[newNode].next != -1 && newNode < MAX) newNode++;
    if (newNode >= MAX) return;
    poly[newNode].coef = coef;
    poly[newNode].exp = exp;
    poly[newNode].next = *polyHead;
    *polyHead = newNode;
}

void addPolynomials() {
    int temp1 = poly1Head, temp2 = poly2Head;
    int resultTemp = -1;
    while (temp1 != -1 && temp2 != -1) {
        if (poly[temp1].exp == poly[temp2].exp) {
            int coefSum = poly[temp1].coef + poly[temp2].coef;
            if (coefSum != 0) {
                int newNode = 0;
                while (poly[newNode].next != -1 && newNode < MAX) newNode++;
                if (newNode < MAX) {
                    poly[newNode].coef = coefSum;
                    poly[newNode].exp = poly[temp1].exp;
                    poly[newNode].next = resultHead;
                    resultHead = newNode;
                }
            }
            temp1 = poly[temp1].next;
            temp2 = poly[temp2].next;
        } else if (poly[temp1].exp > poly[temp2].exp) {
            int newNode = 0;
            while (poly[newNode].next != -1 && newNode < MAX) newNode++;
            if (newNode < MAX) {
                poly[newNode].coef = poly[temp1].coef;
                poly[newNode].exp = poly[temp1].exp;
                poly[newNode].next = resultHead;
                resultHead = newNode;
            }
            temp1 = poly[temp1].next;
        } else {
            int newNode = 0;
            while (poly[newNode].next != -1 && newNode < MAX) newNode++;
            if (newNode < MAX) {
                poly[newNode].coef = poly[temp2].coef;
                poly[newNode].exp = poly[temp2].exp;
                poly[newNode].next = resultHead;
                resultHead = newNode;
            }
            temp2 = poly[temp2].next;
        }
    }
}

void displayPolynomial(int polyHead) {
    if (polyHead == -1) {
        printf("Polynomial is empty.\n");
        return;
    }
    int temp = polyHead;
    while (temp != -1) {
        printf("%dx^%d ", poly[temp].coef, poly[temp].exp);
        if (poly[temp].next != -1) printf("+ ");
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
