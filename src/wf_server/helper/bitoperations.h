#ifndef __BITOP__
#define __BITOP__

/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1<<(b)))
#define BIT_CHECK(a,b) ((a) & (1<<(b)))

/* x=target variable, y=mask */
#define BITMASK_SET(x,y) ((x) |= (y))
#define BITMASK_CLEAR(x,y) ((x) &= (~(y)))
#define BITMASK_FLIP(x,y) ((x) ^= (y))
#define BITMASK_CHECK(x,y) ((x) & (y)) == (y)


#define BITOP(a,b,op) \
 ((a)[(size_t)(b)/(8*sizeof *(a))] op ((size_t)1<<((size_t)(b)%(8*sizeof *(a)))))

 //BITOP(array, bit, |=);
 //BITOP(array, bit, &=~);
 //BITOP(array, bit, ^=);
 //if (BITOP(array, bit, &))


#endif
