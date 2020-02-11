void swap(int * x,int * y) // must pass in addresses
{
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}
