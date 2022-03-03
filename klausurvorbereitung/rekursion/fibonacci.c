#include <stdio.h>

int fibonacci(int index) {
    if (index==0) {
        return 0;
    } else if (index==1) {
        return 1;
    }return (fibonacci(index-2)+fibonacci(index-1));
}

int main() {
    int temp=fibonacci(5);
    printf("Fibonacci: %d", temp);
}