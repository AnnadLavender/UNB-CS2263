// playStack.c
#include <stdio.h>
#include <stdlib.h>
#include "Point2D.h"
#include "stack.h"
#define PUSH 1
#define POP 0
#define LIST 2
#define PEEK 3
int main(int argc, char* argv[])
{
  int iChoice, iNRead, failure;
  Point2D* point;
  double x,y;
  Point2D* newPoint;
  PointList* pointList = mallocPointList();

  printf("Choice (1=add, 0=remove, 2=list, 3=peek): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case PUSH:
        printf("Point value to add: ");
        int check = scanf("%lf%lf", &x,&y);
        while(check != 2)
        {
          printf("Please input the point value again: ");
          check = scanf("%lf%lf", &x,&y);
        }
        newPoint = createPoint2D(x,y);
        failure = push(newPoint, pointList);
        if(failure)
        {
          printf("Unable to add the value to the list.\n");
        }
      break;
      case POP:
        failure = pop(pointList);
        if(failure != 0)
        {
          printf("Unable to pop the value from the list.\n");
        }
      break;
      case LIST:
        print(pointList);
      break;
      case PEEK:
        peek(pointList);
      break;
      default:
        freePoint2D(newPoint);
        freePointList(pointList);
        return 0;
    }
    printf("Choice (1=add, 0=remove, 2=list, 3=peek): ");
    iNRead = scanf("%d", &iChoice);
  }
}
