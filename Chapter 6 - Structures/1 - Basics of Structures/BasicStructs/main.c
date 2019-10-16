#include <stdio.h>

int main() {

    struct point{
        int x;
        int y;
    };
    struct rectangle{
        struct point pt1;
        struct point pt2;
    };


    struct point pt = {320, 200};
    struct rectangle screen = {{20, 20}, {10, 10}};

    printf("%d, %d\n", pt.x, pt.y);
    printf("%d, %d, %d, %d\n", screen.pt1.x, screen.pt2.x, screen.pt1.y, screen.pt2.y);
    float area;
    area = (screen.pt1.x-screen.pt2.x) * (screen.pt1.y, screen.pt2.y);

    printf("Area of the rectangle is %g", area);

    return 0;
}