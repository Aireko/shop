#ifndef CART_H
#define CART_H

struct cart {
    long subtotal_cents;
    int coupon_percent;
    int member_percent;
};

long checkout(const struct cart *cart);
long shipping_cents(long total);
long round_cents(long value, long divisor);
void print_receipt(const struct cart *cart, long discounted);

#endif
