// playQueue.c
#include <stdio.h>
#include <stdlib.h>
#include "Point2D.h"
#include "queue.h"
#define ENQUEUE 1
#define DEQUEUE 0
#define LIST 2
#define PEEK 3
int main(int argc, char ** argv)
{
  int iChoice, iNRead, failure;
  double x,y;
  Point2D* newPoint;
  PointList* pointList = mallocPointList();

  /* Processing loop */
  printf("Choice (1=enqueue, 0=dequeue, 2=list, 3=peek): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case ENQUEUE:
      printf("Point value to add: ");
      int check = scanf("%lf%lf", &x,&y);
      while(check != 2)
      {
        printf("Please input the point value again: ");
        check = scanf("%lf%lf", &x,&y);
      }
      newPoint = createPoint2D(x,y);
      failure = enqueue(newPoint, pointList);
      if(failure)
      {
        printf("Unable to add the value to the list.\n");
      }
      break;
      case DEQUEUE:
      failure = dequeue(pointList);
      if(failure != 0)
      {
        printf("Unable to dequeue the value from the list.\n");
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
    printf("Choice (1=enqueue, 0=dequeue, 2=list, 3=peek): ");
    iNRead = scanf("%d", &iChoice);
  }
  return EXIT_SUCCESS;
}
