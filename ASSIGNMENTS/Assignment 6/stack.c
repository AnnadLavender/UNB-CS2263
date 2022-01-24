#include <stdio.h>
#include <stdlib.h>
#include "Point2D.h"
#include "stack.h"
// Other supported functions
pPtLink createPointLink(Point2D* point)
{
  pPtLink pPointLink = (pPtLink) malloc(sizeof(PtLink));
  if(pPointLink == (pPtLink)NULL)
  {
    return pPointLink;
  }
  pPointLink->payload = point;
  return pPointLink;
}

void freePointLink(pPtLink pPointLink)
{
    free(pPointLink);
    return;
}

// stack creation
PointList* mallocPointList()
{
  PointList* pointListThis = (PointList*) malloc(sizeof(PointList));
  if(pointListThis == (PointList*)NULL )
  {
    return pointListThis;
  }
  pointListThis->head = (pPtLink)NULL;
  pointListThis->tail = (pPtLink)NULL;
  pointListThis->iterator = (pPtLink)NULL;
  pointListThis->nLinks = 0;

  return pointListThis;
}

// push
int push(Point2D* newPoint, PointList* pointList)
{
  pPtLink pPointLink = createPointLink(newPoint);
  if(pPointLink == (pPtLink)NULL)
  {
    return 1;
  }
  if(pointList->head == pointList->tail && pointList->head == NULL)
  {
    pointList->head = pPointLink;
    pointList->tail = pointList->head;
  }
  else
  {
    pPointLink->next = pointList->head;
    pointList->head = pPointLink;
  }
  pointList->nLinks++;
  return 0; //success
}

// pop
int pop(PointList* pointList)
{
  pPtLink temp;
  if(pointList->head == (pPtLink)NULL)
  {
    return EOF;
  }
  temp = pointList->head;
  pointList->head = pointList->head->next;
  pointList->nLinks--;
  printf("Popped point: (%.1lf, %.1lf)\n", getXPoint2D(temp->payload), getYPoint2D(temp->payload));
  return 0;//success
}

// peek
void peek(PointList* pointList)
{
  if(pointList->head == (pPtLink)NULL)
  {
    printf("The list is empty, unable to peek the point\n");
  }
  else
  {
    Point2D* point = pointList->head->payload;
    printf("Peeked point: (%.1lf, %.1lf)\n", getXPoint2D(point), getYPoint2D(point));
  }
}

// reporting the stack contents
void print(PointList* pointList)
{
  pPtLink current = pointList->head;
  int i = 0;
  if(current == (pPtLink)NULL)
  {
    printf("The list is empty\n");
    return;
  }

  while(current != (pPtLink)NULL)
  {
    printf("Point %d: (%.1lf, %.1lf)\n", i, current->payload->x, getYPoint2D(current->payload));
    printf("- PtLink: %p\n- payload: %p\n- next: %p\n\n", current, current->payload, current->next);
    i++;
    current = current->next;
  }
}

// stack destruction
void freePointList(PointList* pointList)
{
  pPtLink current = pointList->head;
  while(pointList->head != (pPtLink)NULL)
  {
    current = pointList->head->next;
    freePointLink(pointList->head);
    pointList->head = current;
  }
  free(pointList);
  return;
}
