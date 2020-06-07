#include<stdio.h>

typedef enum days
{
  SUNDAY=1,
  MONDAY,
  TUSEDAY
}days_t;

typedef struct calender
{
  days_t day;
  int month;
  int year;
}calender_t;
#define value 1
calender_t cal;
void setCalender(int day,int month,int year)
{
  cal.day=day;
  cal.month=month;
  cal.year=year;
}
void main()
{
  setCalender(value,5,2002);
  
  printf("day:%d month:%d year:%d",cal.day,cal.month,cal.year);
}