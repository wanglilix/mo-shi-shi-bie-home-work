#include "StdAfx.h"
#include "ActivationFuntion.h"

double ActivationFuntion(double in)
{
	
   double y = (double)1 / (double)(1 + exp(-in));

	return y;
}
