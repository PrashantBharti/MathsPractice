#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Global Declarations
enum etypeBool {FALSE, TRUE};
enum etypeAppOption {ADD=1, SUBTRACT, MULTIPLY, DIVIDE};

//Global Functions
unsigned int GetRandomSeed(void);
enum etypeBool CheckEquality(double fNum1, double fNum2);

//Function: to generate practice instances
enum etypeBool DoPractice(unsigned int iPracticeCount, enum etypeAppOption eAppOption, int iMaxNum)
{
//local declarations
	int iNum1 = 0; //first number
	int iNum2 = 0; //second number
	double fResult = 0.0; //result of mathematical operation
	double fUserAns = 0.0; //answer by user
	unsigned short iCorrectAnswers = 0;
	unsigned short iWrongAnswers = 0;
	unsigned short iPracticeInstance = 0;

//statements
	while(iPracticeCount)
	{
		time_t timeBefore = 0;
		time_t timeAfter = 0;
		double timeDiff = 0.0;
		int iTotalHrs = 0;
		int iTotalMins = 0;
		int iTotalSecs = 0;
		unsigned int iPracticeSeed = 0;

		wprintf_s(L"\n********************************************\n"
					 L"Practice Instance: %d\n", ++iPracticeInstance);

		//generate first number
		iPracticeSeed = GetRandomSeed();
		srand(iPracticeSeed);
		iNum1 = iMaxNum ? rand()%iMaxNum : rand();

		//generate second number
		iPracticeSeed = iPracticeSeed*iNum1;
		srand(iPracticeSeed);
		iNum2 = iMaxNum ? rand()%iMaxNum : rand();
		while(eAppOption == DIVIDE && iNum2 == 0)
			iNum2 = iMaxNum ? rand()%iMaxNum : rand();

		switch (eAppOption)
		{
		case ADD:
			wprintf_s(L"\nSolve: %d + %d = ", iNum1, iNum2);
			fResult = (double)iNum1 + (double)iNum2;
			break;
		case SUBTRACT:
			wprintf_s(L"\nSolve: %d - %d = ", iNum1, iNum2);
			fResult = (double)iNum1 - (double)iNum2;
			break;
		case MULTIPLY:
			wprintf_s(L"\nSolve: %d x %d = ", iNum1, iNum2);
			fResult = (double)iNum1 * (double)iNum2;
			break;
		case DIVIDE:
			wprintf_s(L"\nSolve: %d / %d = ", iNum1, iNum2);
			fResult = (double)iNum1 / (double)iNum2;
			break;
		}
		time(&timeBefore);
		wscanf_s(L"%lf", &fUserAns);
		time(&timeAfter);
		timeDiff = difftime(timeAfter, timeBefore);

		iTotalSecs = (int)timeDiff%60;
		iTotalMins = (int)timeDiff/60;
		iTotalHrs = iTotalMins/60;
		iTotalMins = iTotalMins%60;

		if(CheckEquality(fResult, fUserAns))
		{
			wprintf_s(L"Total time taken(HH:MM:SS): %d:%d:%d", iTotalHrs, iTotalMins, iTotalSecs);
			wprintf_s(L"\nCorrect Answer\n");
			iCorrectAnswers++;
		}
		else
		{
			wprintf_s(L"Total time taken(HH:MM:SS): %d:%d:%d", iTotalHrs, iTotalMins, iTotalSecs);
			wprintf_s(L"\nWrong Answer. Correct Answer is: %lf\n", fResult);
			iWrongAnswers++;
		}
		wprintf_s(L"\n********************************************\n");
		iPracticeCount--;
	}

	wprintf_s(L"\nIn this practice\n"
				 L"Total Correct Answers: %d\n" 
				 L"Total Wrong Answers: %d\n", iCorrectAnswers, iWrongAnswers);

//function exit
	return TRUE;
}