/*
 * receipt.c - prints what the customer pays.
 */
#include <stdio.h>
#include "cart.h"

void print_receipt(const struct cart *cart, long discounted)
{
    printf("Subtotal   %8.2f\n", cart->subtotal_cents / 100.0);
    printf("To pay     %8.2f\n", discounted / 100.0);
}
