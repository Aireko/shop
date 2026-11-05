/*
 * checkout.c - prices for a tiny online shop.
 * Money is kept in cents, so totals never pick up floating-point rounding.
 */
#include <stdio.h>
#include "cart.h"

long checkout(const struct cart *cart)
{
    long total = cart->subtotal_cents;
    return total + shipping_cents(total);
}

long shipping_cents(long total)
{
    if (total >= 5000) {
        return 0;
    }
    return total > 0 ? 599 : 0;
}

long round_cents(long value, long divisor)
{
    return (value + divisor / 2) / divisor;
}
