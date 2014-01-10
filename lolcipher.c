#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void blocksplit(int in, int inb);
void blockcombine(int a, int b, int c);

int main()
{
    srand(time(NULL));
    blocksplit(61, 42);
    blockcombine(92, 19, 224);
    exit(0);
}

void blocksplit(int in, int inb)
{
    unsigned int a,b,c, d, e, f;
    printf("Input was %d %d\n", in, inb);
    a = rand()&0xF;
    b = in/a;
    c = in - (a*b);
    printf("Block is %d, %d, %d\n", a, b, c);

    
    d = rand()&0xF;
    e = inb/d;
    f = inb - (d*e);
    printf("Block is %d, %d, %d\n", d, e, f);

    int outa, outb, outc;
    outa = a<<4 | b;
    outb = c<<4 | d;
    outc = e<<4 | f;
    printf("Outputs are %d, %d, %d\n", outa, outb, outc);

}


void blockcombine(int a, int b, int c)
{
    unsigned int outa, outb;
    printf("a and b  and c and d are %d, %d, %d, %d, %d, %d\n", a>>4, a&0xF, b>>4, b&0xF, c>>4, c&0xF);
    outa = (a>>4) * (a&0xF) + (b>>4); 
    outb = (b&0xF) * (c>>4) + (c&0xF);
    printf("Combined block is %u, %u\n", outa, outb);
}
