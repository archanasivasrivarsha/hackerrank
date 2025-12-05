#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
double triangle_area(triangle t) {
    double s = (t.a + t.b + t.c) / 2.0;
    return sqrt(s * (s - t.a) * (s - t.b) * (s - t.c));
}
int cmp_area(const void *p1, const void *p2) {
    triangle *t1 = (triangle*)p1;
    triangle *t2 = (triangle*)p2;
    double area1 = triangle_area(*t1);
    double area2 = triangle_area(*t2);
    
    if (area1 < area2) return -1;
    if (area1 > area2) return 1;
    return 0;
}

// Sort triangles by area
void sort_by_area(triangle *arr, int n) {
    qsort(arr, n, sizeof(triangle), cmp_area);
}
int main()
