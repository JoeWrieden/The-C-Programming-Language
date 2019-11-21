#include <stdio.h>

#define MAX 100
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

struct point {
    int x;
    int y;
};
struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int, int);
struct point addpoint(struct point, struct point);
int ptinrect(struct point, struct rect);

int main() {
    struct rect screen;
    struct point middle;

    screen.pt1 = makepoint(0,0);
    screen.pt2 = makepoint(MAX,MAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
                       (screen.pt1.y + screen.pt2.y)/2);

    struct point origin, *pp;
    struct rect *rp;
    origin.x = 89;
    origin.y = 23;
    pp = &origin;
    printf("origin is (%d,%d)\n",pp->x, pp->y);

    rp = &screen;
    printf("SCREEN: (%d,%d), (%d, %d)",(rp->pt1).x,(rp->pt1).y,(rp->pt2).x,(rp->pt2).y);
    return 0;
}

struct point addpoint(struct point p1, struct point p2){
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

int ptinrect(struct point p, struct rect r) {
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

struct point makepoint(int x, int y){
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

struct rect cannonrect (struct rect r){
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}