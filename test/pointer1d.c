

int main()
{
    int a = 2;
    int b = 3;
    print_int(a);
    print_int(b);
    int* pa = &a;
    int* pb = &b;
    int t = *pb;
    *pb = *pa;
    *pa = t;  
    print_int(a);
    print_int(b);
    return 0;
}



//2332
