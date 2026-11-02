/*
 * checkout.c - prices for a tiny online shop.
 * Money is kept in cents, so totals never pick up floating-point rounding.
 */
#include <stdio.h>
#include "cart.h"

long shipping_cents(long total)
{
    return total > 0 ? 599 : 0;
}

long round_cents(long value, long divisor)
{
    return (value + divisor / 2) / divisor;
}
