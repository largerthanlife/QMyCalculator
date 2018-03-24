/*
 * File name: main.cpp
 * Description: control the functions and show the result.
 * Author: Liu Zechao
 * Version: 3.1
 * Date: 2017/6/10
 * Function List:	int main();
 */

#include"calculator.h"
#include"stack.h"

#include "mainwindow.h"
#include <QApplication>
#include <QObject>

int Menu();
void ShowLine();
void ShowInformation();
void ShowHelp();
void ShowSample();
void ConversionOfBODH(OpcharType *s);
void StringHandle(OpcharType * const s, bool *error);
OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *myflag);
OprandType Variance(int varianceNum, bool *error);
OprandType StringToOprand(OpcharType * const s);
bool SolvingEquations(OpcharType *s, OprandType *answer);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


//	OpcharType s[MAXSTRING];					//the input string
//	OprandType lwrlim = 0, uprlim = 0;			//lower and upper limit of definite integral
//	OprandType ans = 0;							//the value of last operation
//	OprandType sum = 0;							//used in the formula of seeking the value of definite integral
//	OprandType xvalue = 0;						//the value of 'x'
//	int varianceNum = 0;						//the amount of input to seek the variance
//	int functionIndex = 1;						//the label of functions
//	unsigned int operationTimes = 0;			//record the number of times of operation
//	bool flag = 1;								//record the number of times of operation, company with operationTimes
//	bool isfound = 1;							//whether the solution of equation is founded
//	bool error = 0;								//the number of times of error-happening

//	system("title MyCalculator");
//	system("color F9");

//	functionIndex = Menu();
//	while (1)
//	{
//		switch (functionIndex)
//		{
//		case CALCULATE:
//		{
//			if (!flag)
//			{
//				operationTimes = 0;
//				flag = 1;
//			}
//			ShowInformation();
//			ShowLine();

//			if (operationTimes++ > 0)
//			{
//				printf("\t\tLast ans: %g\n\n", ans);
//				printf("\t\tYour expression:\n\n\t\t");
//			}
//			else
//			{
//				printf("\t\tEnter a mathematical expression:\n\n\t\t");
//			}
//			if (operationTimes <= 1)
//                gets(s);
//			else
//				puts(s);

//			StringHandle(s, &error);
//			ConversionOfBODH(s);
//			ans = EvaluateExpression(s, ans, xvalue, &error);
//			if (!error)
//				printf("\n\t\tAnswer: %g\n\n", ans);
//			ShowLine();
//			printf("\t\tPress \"enter\" to return to the menu\n\n");
//			if (!error)
//			{
//				printf("\t\tLast ans: %g\n\n", ans);
//				printf("\t\tContinue:\n\n\t\t");
//			}
//			else
//			{
//				printf("\t\tInput error, try again:\n\n\t\t");
//				error = 0;
//			}
//            gets(s);
//			if (strlen(s) == 0)
//			{
//				flag = 0;
//				system("cls");
//				functionIndex = Menu();
//			}
//			else
//				system("cls");
//			break;
//		}

//		case VARIANCE:
//		{
//			if (!flag)
//			{
//				operationTimes = 0;
//				flag = 1;
//			}
//			ShowInformation();
//			ShowLine();
//			if (operationTimes++ > 0)
//			{
//				if (!error)
//				{
//					printf("\tLast variance: %g\n\n", ans);
//					printf("\tLast standard deviation: %g\n\n", sqrt(ans));
//					printf("\tYour inputs are : %d\n\n", varianceNum);
//				}
//				else
//				{
//					error = 0;
//					printf("\tYour inputs are : %d\n\n", varianceNum);
//					printf("Input error,try again:\n\n");
//				}
//			}
//			if (operationTimes <= 1)
//			{
//				printf("\tplease enter the number that need to input:_\b");
//                scanf("%d", &varianceNum);
//				getchar();
//				putchar('\n');
//			}

//			ans = Variance(varianceNum, &error);
//			if (ans == -1)
//			{
//				flag = 0;
//				getchar();
//				system("cls");
//				functionIndex = Menu();
//				break;
//			}
//			printf("\n\tvariance = %lf\n\n", ans);
//			printf("\tstandard deviation = %lf\n\n", sqrt(ans));
//			ShowLine();

//			printf("\tPress \"enter\" to return to the menu\n\n");
//			if (!error && (ans != -1))
//			{
//				printf("\tLast variance: %g\n\n", ans);
//				printf("\tLast standard deviation: %g\n\n", sqrt(ans));
//			}
//			else
//			{
//				printf("Input error, try again\n\n");
//				error = 0;
//			}
//			printf("\tPlease enter the number that need to input:_\b");
//            gets(s);
//			if (strlen(s) == 0)
//			{
//				flag = 0;
//				system("cls");
//				functionIndex = Menu();
//			}
//			else
//			{
//				varianceNum = (int) StringToOprand(s);
//				system("cls");
//			}
//			break;
//		}

//		case INTEGRAL:
//		{
//			srand((unsigned)time(NULL));
//			if (!flag)
//			{
//				operationTimes = 0;
//				flag = 1;
//			}
//			ShowInformation();
//			ShowLine();
//			if (operationTimes++ > 0)
//			{
//				if (!error)
//					printf("\tLast ans: %g\n", ans);
//				else
//				{
//					printf("\tInput error, try again\n");
//					error = 0;
//				}
//			}
//			if (operationTimes <= 1)
//			{
//				printf("\n\tEnter a continuous function :\n\n\t");
//                gets(s);

//				printf("\n\tEnter lower and upper limit :_ _\b\b\b");
//                scanf("%lf %lf", &lwrlim, &uprlim);
//				getchar();					//������ʽ�Ļس���
//			}

//			else
//			{
//				//printf("\tlower and upper limit:%g %g\n\n", lwrlim, uprlim);
//				printf("\tcontinuous function :%s\n", s);
//			}

//			StringHandle(s, &error);
//			for (functionIndex = 0, sum = 0; functionIndex < MAX; functionIndex++)				//����ͬ���������Ϊ x ��ֵ�����㺯��ֵ�� ����ۼӵ� sum ������
//			{
//				xvalue = ((double)rand() / (RAND_MAX)) * (uprlim - lwrlim) + lwrlim;	//ÿ�β���һ����(lwrlim, uprlim)�ڵ������
//				sum += EvaluateExpression(s, ans, xvalue, &error);
//			}

//			if (!error)
//				printf("\n\tAnswer :%g\n", ans = sum * (uprlim - lwrlim) / MAX);
//			ShowLine();
//			printf("\tPress \"enter\" to return to the menu\n\n");
//			if (!error)
//			{
//				printf("\tLast ans: %g\n", ans);
//				printf("\tContinue:\n\n");
//			}
//			else
//			{
//				printf("\tInput error, try again:\n\n");
//				error = 0;
//			}
//			printf("\tEnter a continuous function :\n\n\t");
//            gets(s);
//			if (strlen(s) == 0)
//			{
//				flag = 0;
//				system("cls");
//				functionIndex = Menu();
//			}
//			else
//			{
//				printf("\n\tEnter lower and upper limit :_ _\b\b\b");
//                scanf("%lf %lf", &lwrlim, &uprlim);
//				getchar();
//				system("cls");
//				functionIndex = 3;
//			}
//			break;
//		}

//		case EQUATION:
//		{
//			if (!flag)
//			{
//				operationTimes = 0;
//				flag = 1;
//			}
//			ShowInformation();
//			ShowLine();
//			if (operationTimes++ > 0)
//			{
//				if (!error)
//					printf("\t\tLast ans: %.2lf\n", ans);
//				else
//				{
//					printf("\t\tInput error, try again:\n");
//					error = 0;
//				}
//			}
//			printf("\t\tEnter a one-dollar-equation:\n\n\t\t");

//			if (operationTimes <= 1)
//                gets(s);
//			else
//				puts(s);

//			StringHandle(s, &error);
//			ConversionOfBODH(s);
//			if (isfound = SolvingEquations(s, &ans))
//				printf("\n\t\tSorry, the answer can not be calculated\n\n");
//			else
//				printf("\n\t\tAnswer: x = %.2lf\n\n", ans);
//			ShowLine();
//			printf("\t\tPress \"enter\" to return to the menu\n\n");
//			if (!isfound)
//			{
//				printf("\t\tLast ans: x = %.2lf\n", ans);
//			}

//			printf("\t\tContinue:\n\n\t\t");
//            gets(s);
//			if (strlen(s) == 0)
//			{
//				flag = 0;
//				system("cls");
//				functionIndex = Menu();
//			}
//			else
//				system("cls");
//			break;
//		}

//		case INFORMATION:
//		{
//			ShowInformation();
//			ShowLine();
//			ShowHelp();
//			ShowLine();
//			getchar();
//			system("cls");
//			functionIndex = Menu();
//			break;
//		}

//		case SAMPLE:
//		{
//			ShowInformation();
//			ShowLine();
//			ShowSample();
//			ShowLine();
//			getchar();
//			system("cls");
//			functionIndex = Menu();
//			break;
//		}

//		default :
//		{
//			//if(functionIndex == 99) operationTimes++;
//			ShowInformation();
//			ShowLine();
//			printf("\t\tInput error!\n");
//			printf("\t\tPress any key to continue\n\n");
//			ShowLine();
//			getchar();
//			system("cls");
//			//if(operationTimes == 9) Myshow();
//			functionIndex = Menu();
//		}
//		}
//	}

//	//system("pause");
//    //return EXIT_SUCCESS;

    return a.exec();
}

//#include "mainwindow.h"
//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
//}
