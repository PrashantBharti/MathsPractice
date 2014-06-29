#include <time.h>

//Function: to get random seed
unsigned int GetRandomSeed(void)
{
//local declarations
	time_t timeNow = 0;
	struct tm timeRef;
	double seconds = 0;

//statements
	timeRef.tm_hour = 0;
	timeRef.tm_min = 0;
	timeRef.tm_sec = 0;
	timeRef.tm_mon = 0;
	timeRef.tm_mday = 1;
	timeRef.tm_year = 100;

	time(&timeNow);
	seconds = difftime(timeNow, mktime(&timeRef));

//exit
	return (unsigned int)seconds;
}