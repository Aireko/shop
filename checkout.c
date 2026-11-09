/*
 * checkout.c - prices for a tiny online shop.
 * Money is kept in cents, so totals never pick up floating-point rounding.
 */
#include <stdio.h>
#include "cart.h"

#define MAX_DISCOUNT_PERCENT 100

long quote_price(const struct item *item, int percent)
{
    return apply_discount(item->cents, percent) * item->qty;
}

long apply_discount(long cents, int percent)
{
    if (percent < 0) {
        percent = 0;
    }
    if (percent > MAX_DISCOUNT_PERCENT) {
        percent = MAX_DISCOUNT_PERCENT;
    }
    return cents - round_cents(cents * percent, 100);
}

long checkout(const struct cart *cart)
{
    long total = cart->subtotal_cents;
    total = apply_discount(total, cart->coupon_percent);
    total = apply_discount(total, cart->member_percent);
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
