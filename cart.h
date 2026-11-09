#ifndef CART_H
#define CART_H

struct cart {
    long subtotal_cents;
    int coupon_percent;
    int member_percent;
};

struct item {
    long cents;
    int qty;
};

long quote_price(const struct item *item, int percent);
long apply_discount(long cents, int percent);
long checkout(const struct cart *cart);
long shipping_cents(long total);
long round_cents(long value, long divisor);
void print_receipt(const struct cart *cart, long discounted);

#endif
