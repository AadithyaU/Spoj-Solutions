#include <stdio.h>
#define sd(x) scanf("%d",&x)

int main()
{
    int array[10], sum = 0;
    for (int i = 0; i < 10; ++i) {
        sd(array[i]);
        sum += array[i];
        if (sum >= 100) {
            if (sum - 100 <= 100 - (sum-array[i])) printf("%d\n", sum);
            else printf("%d\n", sum-array[i]);
            return 0;
        }
    }
    printf("%d\n", sum);
    return 0;
}
