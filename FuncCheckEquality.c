//Global declarations
enum etypeBool {FALSE, TRUE};

//Function: to check equality of results in calculation
enum etypeBool CheckEquality(double fNum1, double fNum2)
{
//statements
	fNum1 = ((int)(fNum1*100))/(100.0);
	fNum2 = ((int)(fNum2*100))/(100.0);

//exit
	return fNum1 == fNum2 ? TRUE : FALSE;
}