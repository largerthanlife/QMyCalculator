/*
 * File name: show.cpp
 * Description: Define some function .
				See the name of these functions so that to know what function they have
 * Author: Liu Zechao
 * Version: 1.8
 * Date: 2017/6/11
 * Function List:	unsigned int Menu();
 *					void ShowLine();
 *					void ShowInformation();
 *					void ShowHelp();
 *					void ShowSample();
 *					void Myshow();
 *					void ShowRectangle();
 */

#include"calculator.h"

void StringHandle(OpcharType * const s, bool *error);
void ConversionOfBODH(OpcharType *s);
OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag);

/*
 * Description:	int Menu();
 * Calls:		void ShowLine();
 *				void ShowInformation();
 *				void StringHandle(OpcharType * const s);
 *				void ConversionOfBODH(OpcharType *s);
 *				OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag);
 * Called By:	int main();
 * Input:		None.
 * Output:		Show the basic imformation and functions that can be used in the screen.
 * Return:		The label of functions.
 * Others:		It is permissible to input a mathematical expression in the version, as long as the result is included.
 *				If no label fits, error reporting mechanism will be called in the main() function.
 */
int Menu()
{
	void ShowLine();
	void ShowInformation();
	bool error = 0;

	OpcharType s[MAXSTRING];
	OprandType label = 0;
	bool flag = 0;

	//ShowRectangle();
	ShowInformation();
	ShowLine();
	printf("\t\t\tM E N U\n\n");
	printf("\t\tChoose a label of these follow functions:\n\n");
	printf("\t\t1.Calculate\n\n");
	printf("\t\t2.Variance and Standard deviation\n\n");
	printf("\t\t3.Definite  Integral\n\n");
	printf("\t\t4.Solve  Equation\n\n");
	printf("\t\t5.Help  and  Information\n\n");
	printf("\t\t6.Show  some  samples\n\n");
	printf("\t\tYour  choice is:_\b");
	
    //gets_s(s);
	StringHandle(s, &error);  //Even though there are error, it cannot find.
	ConversionOfBODH(s);
	if (strcmp(s, "q") && strcmp(s, "quit"))
	{
		label = EvaluateExpression(s, 0, 0, &flag); //The second and third parameter is useless, make them zero
		ShowLine();
		system("cls");
		return (int)label;
	}
	else
	{
		system("cls");
		ShowInformation();
		ShowLine();
		printf("\n\t\tThanks for using.\n\n");
		ShowLine();
		exit(0);
	}
}

/*
 * Description:	void ShowLine();
 * Calls:		None.
 * Called By:	int Menu();
 *				int main();
 * Input:		None.
 * Output:		Show a line in the screen and start a new line.
 * Return:		None.
 * Others:		None.
 */
void ShowLine()
{
	for (int i = 0; i < LINELENGTG; i++)
		putchar('-');
	printf("\n");
}

/*
 * Description:	void ShowInformation();
 * Calls:		None.
 * Called By:	int Menu();
 *				int main();
 * Input:		None.
 * Output:		Show the real time and the version number.
 * Return:		None.
 * Others:		None.
 */
void ShowInformation()
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("\t\t%s", asctime(timeinfo));
	//printf("date:")
	//system("date /T TIME /T");
	//system("TIME /T");
	//printf("Liu ZeChao\tNanJing University\n");
	printf("\t\tversion:%.1f\n",VERSION);
}

/*
 * Description:	void ShowHelp();
 * Calls:		None.
 * Called By:	int main();
 * Input:		None.
 * Output:		Show the functions that can be used, the way of inputting, some basic information about the program and the author.
 *				Show some notices.
 * Return:		None.
 * Others:		None.
 */
void ShowHelp()
{
	printf("\tThis is a simple calculator\n");
	printf("\tUsing DBC case as input\n");
	printf("\tUsing @ to represent the square symbol\n");
	printf("\tUsing [x] to seek the absolute value of x\n");
	printf("\tUsing \"e + 1\"instead of\"y = e + 1\"to seek the value of y\n");
	printf("\tYou can only use real number as input\n");
	printf("\tYou can only use \"x\" as the independent variable while using function2\n");
	printf("\tYou can use upper or lower letter while input\n");
	printf("\tYou can use \"ans\" to represent the result while input\n");
	printf("\tYou can use \"pi\" and \"e\"while input\n");
	printf("\tYou can use \"h\" ,\"o\",\"b\"to represent the Hex, Octal and Binary\n");
	printf("\tYou can use \"rand\" to get a interger between 1 and 6\n");
	printf("\t\tBut these oprators could only be uesd in interger\n");
	printf("\tThe lower and upper limit should both be numbers(not \"ans\")\n");
	printf("\tThe 1ength of input-string should be less than 50\n");
	printf("\tThe range of input limit is between %g and %g\n", DBL_MIN, DBL_MAX);
	printf("\tThe rang of result is between %g and %g\n", DBL_MIN, DBL_MAX);
	printf("\tThe result of definite integral isn't exact enough\n");
	printf("\tThe solving equation function is not uesful at all\n");
	printf("\tWhile using function2, remember to ends with an '@'\n");
	printf("\tIt's useful to check the sample before using this calculator\n");
	printf("\tIf you want to quit, input \"q\" or \"quit\" in the menu\n");
	printf("\tIf you find any error, send email to 151180088@smail.nju.edu.cn\n");
	printf("\tThanks for using!\n");
	printf("\t\t\t\t\tLiu Zechao from NJU\n\n");
	printf("\tPress any key to return to the menu\n");
}

/*
 * Description:	void ShowSample();
 * Calls:		None.
 * Called By:	int main();
 * Input:		None.
 * Output:		Show some possible input, including a majority of error-input, and show the corresponding results.
 *				Show some characteristic.
 * Return:		None.
 * Others:		None.
 */
void ShowSample()
{
	unsigned int order = 1;
	printf("\tHere are some samples to show what operator and function can be used:\n\n");
	printf("\t%d.\tlg10                =                1\n",order++);
	printf("\t%d.\t   ln(e)            =                1\n", order++);
	printf("\t%d.\t5  %%  2             =                1\n", order++);
	printf("\t%d.\t[1-[-2]]            =                1\n", order++);
	printf("\t%d.\tasin(sin(1))        =                1\n", order++);
	printf("\t%d.\t2!  -  0!           =                1\n", order++);
	printf("\t%d.\t10h/1000b - 1o      =                1\n", order++);
	printf("\t%d.\t-2/-2               =                1\n", order++);
	printf("\t%d.\tpi\\e                =                1\n", order++);
	printf("\t%d.\t2sinx              <=>           2*sin(x)\n", order++);
	printf("\t%d.\tcosx^2             <=>         cos(x^2)\n", order++);
	printf("\t%d.\t3^3*2              <=>          2*(3^3)\n", order++);
	printf("\t%d.\t4lnx               <=>          4*ln(x)\n", order++);
	printf("\t%d.\ttan(pi/2)          <=>        TAN(PI/2)\n", order++);
	printf("\t%d.\t2 ans              <=>             2ANS\n", order++);
	printf("\t%d.\trand               <=>    {1,2,3,4,5,6}\n", order++);
	printf("\t%d.\ty = 2x             <=>           error!\n", order++);
	printf("\t%d.\tlg(-1)             <=>           error!\n", order++);
	printf("\t%d.\t(cos0)/0           <=>           error!\n", order++);
	printf("\t%d.\t6%%0                <=>           error!\n", order++);
	printf("\t%d.\ttox(1)             <=>           error!\n", order++);
	printf("\t%d.\tacos(-1.0001)      <=>           error!\n", order++);
	printf("\t%d.\tlg[10]             <=>           error!\n", order++);
	printf("\t%d.\tlg([10])           <=>         correct!\n", order++);
	printf("\t%d.\t10000!             <=>        overflow!\n", order++);
	printf("\t%d.\t(No Input)         <=>              0\n\n", order++);
	printf("\tPress any key to return to the menu\n");
}

/*
 *
 */
void Myshow()
{
	ShowLine();
	printf("\t\tHope you could see it someday\n\n");
	printf("\t\tHope you have a wonderful life\n\n");
	printf("\t\tAnd I would be a better man%c\n\n", 1);
	printf("\t\t\t\t to Princess Sweet cake\n");
	ShowLine();
	getchar();
	exit(0);
}

/*
 * Description:	void ShowRectangle();
 * Calls:		None.
 * Called By:	None;
 * Input:		None.
 * Output:		Show rectangles in the screen.
 * Return:		None.
 * Others:		This function isn't used at present version.
 */
void ShowRectangle()
{
	HWND hwnd;
	HDC hdc;
	system("color F1");
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	//LineTo(hdc, 200, 300);
	//for(int i = 1; i < 10; i++)
	//	Rectangle(hdc, i, i, 640-i, 400-i);
	//for(int i = 50; i < 60; i++)
	//	Rectangle(hdc, i, i, 640-i, 400-i);
	//for(int i = 100; i < 110; i++)
	//	Rectangle(hdc, i, i, 640-i, 400-i);
	//for(int i = 150; i < 160; i++)
	//	Rectangle(hdc, i, i, 640-i, 400-i);
	//for(int i = 300; i < 310; i++)
	//Rectangle(hdc, i, i, 640-i, 400-i);

	//Rectangle(hdc, 2, 1, 640, 400);
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tHere are some rectangles\n");
	//printf("\n\n\n\t\t\tYes they are\n");

	//for(int i = 50; i < 52; i++)//menuµÄ·½¿ò
	//	Rectangle(hdc, i+120, i+8, 320-i, 135-i);

	ReleaseDC(hwnd, hdc);
	//while(1);
	// return 0;
}
