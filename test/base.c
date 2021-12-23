// #include<stdio.h>  // not required

int main() {
    int m = 2;
    // handle IO
    read_int(m);
    int t6 = m + 100;
    int t = t6 % 2;
    print_int(t);
    //  printf("%d", (m+100) % 2);

    int i = 0;
    int factorial = 3;
    int result = 1;
    while (factorial > 0) {  // factorial
        result = result * factorial;
        factorial = factorial - 1;
    }
    t = result % 100;
    print_int(t);
    // printf("%d\n", result % 100);
    t = t - 1;
    for (int j = 0; j < t; j = j + 1) {
        if(j>2){
        	print_int(j);
        }
    }
    
    
    return 0;
}

/*  input:6
output:
0634


*/
