#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
    double x;
    double y;
}Point;

//Forward Function Declaration
void Point_print(const Point* self);

Point add(Point p1, Point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

int main()
{
    // TODO: Declare a struct Point Variable
    Point aPoint;
    aPoint.x = 1.0;
    aPoint.y = 2.0;
    Point_print(&aPoint);

    printf("\n");

    Point a = {1.0, 2.0};
    Point b = {3.0, 4,0};
    Point c = add(a,b);
    printf("%f %f %f", a.x, b.x, c.x);

    
   


    return 0;
}

void Point_print(const Point *self)
{
    printf("(%f,%f)\n", self->x, self->y);
}