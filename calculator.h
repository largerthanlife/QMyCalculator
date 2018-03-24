/*
* Copyright(c): 2017 - 2018
* File name: calculator.h
* Description: include some statements, macro definitions, functions that used in main.cpp
* Author: Liu Zechao
* Version: 1.1
* Date: 2017/6/11
*/


#ifndef _CALCULATOR
#define _CALCULATOR

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#include<float.h>
#include<windows.h>
#include"stack.h"

#define OprandType  Element1
#define OpcharType  Element

/* Length of input string */
#define MAXSTRING   100

/* Length of some strings */
/* Used to store some part of input string */
#define MAXNUM      20

/* The number of times of add */
/* Used in the formula of definite integral */
#define MAX         100000

/* Length of line that show in the screen */
#define LINELENGTG  80

/* Label of functions */
#define CALCULATE   1
#define VARIANCE    2
#define INTEGRAL    3
#define EQUATION    4
#define INFORMATION 5
#define SAMPLE      6

#define VERSION     4.1
#define PI          3.1415926535897932384626433832795028841971
#define E           2.7182818284590452353602874713526624977572 

#endif