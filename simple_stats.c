/*
 * PROGRAM NAME: simple_stats.c
 * 
 * AUTHOR:       Trisha Echual
 *  
 * DESCRIPTION:  Program stores 10 random numbers in an array
 *               and determines the largest, smallest, average,
 *               sum, population standard variance, and
 *               population standard deviation.
 *               Random numbers range from -100 to +100.
 *               Program is designed with efficiency in mind.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void sayHello(int size)
{
  printf("\nHello!\n\nI will randomly generate %d numbers\nand display statistics of the set of numbers...\n\n", size); 
}

int main(int argc, char *arg[])
{
  const int SIZE = 10;
  const int MAX_NUM = 100;
  const int MIN_NUM = -100;

  int randA[SIZE];
  
  int sum = 0;
  int max = MIN_NUM;
  int min = MAX_NUM;
  double avg;
  double stdVar = 0;
  double stdDev;
  
  sayHello(SIZE); // Message to user

  srand(time(0)); // Seed

  for (int i = 0; i < SIZE; i++)
    {
      // Fill array
      randA[i] = rand() % (MAX_NUM + 1 - MIN_NUM) + MIN_NUM;
      printf("number %d = %d\n", i, randA[i]);

      // Find sum
      sum = sum + randA[i];
      
      // Find max
      if (randA[i] >= max)
	max = randA[i];

      // Find min
      if (randA[i] <= min)
	min = randA[i];    
    }

  // Find average
  avg = (double)sum/SIZE;

  for (int i = 0; i < SIZE; i++)
    {
      stdVar = stdVar + (((double)randA[i] - avg)*((double)randA[i] - avg));
    }

  stdVar = stdVar/SIZE;
  stdDev = sqrt(stdVar);

  
  // Print all data
  printf("The sum is: %d\n", sum);
  printf("The minimum value is: %d\n", min);
  printf("The maximum value is: %d\n", max);
  printf("The average value is: %f\n", avg);
  printf("The population standard variance is: %f\n", stdVar);
  printf("The population standard deviance is: %f\n", stdDev);
}


