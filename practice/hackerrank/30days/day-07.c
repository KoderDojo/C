#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    
    int *arr = malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", arr + i);
    }

    for(int i = n-1; i > -1; i--) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
