#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//global declarations
enum etypeBool {FALSE, TRUE};
enum etypeAppOption {ADD=1, SUBTRACT, MULTIPLY, DIVIDE};

//function declarations
enum etypeBool DoPractice(unsigned int iPracticeCount, enum etypeAppOption eAppOtion, int iMaxNum);

//Function: app entry point
int wmain(void)
{
//Local declarations
	enum etypeAppOption eAppOption = ADD;
	enum etypeBool eContinuePractice = TRUE;

//Statements
	wprintf_s(L"***************************************************\n"
				 L"Welcome to mathematics ramdome practice application\n"
				 L"***************************************************\n");

	do
	{
		//Declare Inputs
		int iMaxNum = 0;
		int iPracticeCount = 0;

		//Collect Inputs
		wprintf_s(L"\nChoose options for practice:\n"
					 L"To Add enter 1\n"
					 L"To Subtract enter 2\n"
					 L"To Multiple enter 3\n"
					 L"To divide enter 4\n");
		wprintf_s(L"Enter your option: ");
		wscanf_s(L"%d", &eAppOption);
		while(eAppOption < ADD || eAppOption > DIVIDE)
			{
			wprintf_s(L"Please enter correct option: ");
			wscanf_s(L"%d", &eAppOption);
			}

		wprintf_s(L"\nEnter number of practice items: ");
		wscanf_s(L"%d", &iPracticeCount);
		while(iPracticeCount < 0)
			{
			wprintf_s(L"Please enter correct number of practice items: ");
			wscanf_s(L"%u", &iPracticeCount);
			}

		wprintf_s(L"\nEnter maximum limit for any number (0 if not required): ");
		wscanf_s(L"%d", &iMaxNum);
		while(iMaxNum < 0)
			{
			wprintf_s(L"Please enter correct maximum limit: ");
			wscanf_s(L"%d", &iMaxNum);
			}

		//Now do practice
		DoPractice(iPracticeCount, eAppOption, iMaxNum);

		//Ask to continue
		wprintf_s(L"\nDo you want to continue practice (1/0): ");
		wscanf_s(L"%d", &eContinuePractice);
	}while(eContinuePractice);

	wprintf_s(L"\n***************************************************\n"
				 L"Good Bye..\n"
				 L"***************************************************\n");

//application exit
	wprintf_s(L"Please any key to exit...");
	fflush(stdin);
	_getch();
	return EXIT_SUCCESS;
}


//To Do List:
//Generate negative numbers