/* Author: Fateh Karan Singh Sandhu
*  Date: August 30, 2018
*
* This program takes input from user and tells them how
* much days and data are left in their cell plan and
* tells them how much their average usage is.
*/

#include<stdlib.h>
#include<stdio.h>

int main (int argc, char **argv) {

if (argc != 4) {
printf("Usage: %s a, b ,c (Total Data in plan, Current Day, Used Data)\n", argv[0]);
}

// declare variables for input data
double totalData, currentDay, usedData;

totalData = atof (argv[1]);
currentDay = atof (argv[2]);
usedData = atof (argv[3]);

if ( totalData < 0) {
  printf("Total Data cannot be negative\n");
  exit(1);
}

if ( currentDay < 0) {
  printf("Days cannot be negative\n");
  exit(1);
}

if ( usedData < 0) {
  printf("Used Data cannot be negative\n");
  exit(1);
}

if ( currentDay > 30) {
  printf("Days cannot be more than 30 (one month)\n");
  exit(1);
}

double averageDataUse = usedData / currentDay ; // calculate aveage data use

double expectedDataUse = totalData / 30 ; // expected data use by customer

double overUse = averageDataUse - expectedDataUse; // overuse by customer

double remainingDays = 30 - currentDay; // remaining days in data plan

double totalOverUse = ( averageDataUse * 30 ) - ( expectedDataUse * 30 );
// total overusage if customer keeps using data at same speed

double remaingUsageForPlan = (totalData - usedData) / remainingDays;
// the average data that should be used to stay below plan

if (averageDataUse > expectedDataUse && usedData < totalData) {
printf("%.0f days used, %.0f days remaining \n", currentDay, remainingDays);
printf("Average Daily Use: %f GB/day\n\n", averageDataUse);
printf("You are EXCEEDING your average daily use (%.2f GB/day)\n", expectedDataUse);
printf("Continuing this high usage, you'll exceed your data plan by %f GB\n\n", totalOverUse);
printf("To stay below your plan, you must not use more than %f GB/day\n", remaingUsageForPlan);
}

if (averageDataUse < expectedDataUse && usedData < totalData) {
printf("%.0f days used, %.0f days remaining \n", currentDay, remainingDays);
printf("Average Daily Use: %f GB/day\n\n", averageDataUse);
printf("You are at or below your average daily use (%.2f GB/day)\n", expectedDataUse);
printf("You can use upto %f GB/day and stay under data limit\n", remaingUsageForPlan);
}

if (usedData > totalData ) {
printf("%.0f days used, %.0f days remaining \n", currentDay, remainingDays);
printf("Average Daily Use: %f GB/day\n\n", averageDataUse);
printf("You've already met your data plan limit, looks like you're getting some overuse charges\n");
}

  return 0;
}
