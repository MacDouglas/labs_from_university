#include "method's.h"

using namespace std;

namespace maths_methods {

	double dihotomy(char* str, double a, double b, double eps, double& value, double& result)
	{
		double c;
		do {
			c = (a + b) / 2;
			if (EvalPolStr(str, a) * EvalPolStr(str, c) < 0) {
				b = c;
			}
			else {
				a = c;
			}
			result = fabs(EvalPolStr(str, (a + b) / 2));	//абс-ая погрешность по функции
			value = fabs((b - a) / 2);						//абс-ая погрешность по аргументу
		} while (result >= eps || value >= eps);
		return c;
	}

	double chord(char* str, double a, double b, double eps, double& value, double& result) {
		cout << "Chord method: " << endl;

		double c, cx;
		do
		{
			c = a - (EvalPolStr(str, a) / (EvalPolStr(str, b) - EvalPolStr(str, a))) * (b - a);
			if (EvalPolStr(str, a) * EvalPolStr(str, c) <= 0)
			{
				cx = b;
				b = c;
			}
			else
			{
				cx = a;
				a = c;
			}
			result = fabs(EvalPolStr(str, c));
			value = fabs(c - cx);
		} while (result >= eps || value >= eps);

		return c;
	}
	double newton(char* str, double a, double b, double eps, double& value, double& result) {
		
		cout << "Newton method : \n";
		
		double x,x1;
		
		if (EvalPolStr(str, a, 0) * EvalPolStr(str, a, 2) > 0)
			x = a;
		else if (EvalPolStr(str, b, 0) * EvalPolStr(str, b, 2) > 0)
			x = b;
		else
			x = (a + b) / 2;
		
		do {

			double dx = EvalPolStr(str, x, 1);

			if (dx == 0)
				throw invalid_argument("0 devision");
			result = EvalPolStr(str, x, 0);

			x1 = x - result / dx;

			result = fabs(result);
			value = fabs(x1 - x);

			x = x1;
		} while (result >= eps && value >= eps);
		return x1;
	}

	double golden(char* str, double a, double b, double eps, double& value, double& result) {
		
		cout << "Golden Ratio method : \n";
		
		double acur = a, bcur = b;
		const double ratio = (sqrt(5) + 1) / 2;
		
		do{
			
			double dcur = acur + (bcur - acur) / ratio;
			double ccur = bcur + acur - dcur;
			
			if (EvalPolStr(str, acur, 0) * EvalPolStr(str, dcur, 0) <= 0)
				bcur = dcur;
			else
				acur = ccur;
			
			result = fabs(EvalPolStr(str, (acur + bcur) / 2, 0));
			value = fabs(bcur - acur / 2);
			
		} while(result >= eps && value >= eps);
		return (acur + bcur) / 2;
	}

	double iteration(char* str, double a, double b, double eps, double& value, double& result) {
		cout << "Iteration method : \n";
		
		double fx, x = -1,x1;
		
		for (double i = a; i < b; i += 0.0001) 
		{
			if (fabs(EvalPolStr(str, i, 1)) > x)
				x = i;
		}
		
		fx = EvalPolStr(str, x, 1);
		
		do{
			result = EvalPolStr(str, x, 0);
			
			x1 = x - result / fx;
			result = fabs(result);
			
			value = fabs(x1 - x);
	
			x = x1;
		} while (result >= eps && value >= eps);

		return x1;
	}

	double combined(char* str, double a, double b, double eps, double& value, double& result) {
		
		cout << "Combined method : \n";
		
		double acur = a, bcur = b,ax,bx, derivative;
		do 
		{
			double difference = EvalPolStr(str, bcur, 0) - EvalPolStr(str, acur, 0); //(f(bk) - f(ak))
			
			if (difference == 0) 
				throw invalid_argument("0 devision by difference");
			
			double ccur = acur - EvalPolStr(str, acur, 0) / difference * (bcur - acur);
			if (EvalPolStr(str, acur, 0) * EvalPolStr(str, acur, 2) > 0) 
			{
				derivative = EvalPolStr(str, acur, 1);
				
				if (derivative == 0) 
					throw invalid_argument("0 devision by derivative");
				
				ax = acur - EvalPolStr(str, acur, 0) / derivative;
				
				acur = ax;
				bcur = ccur;
			}
			else {
				acur = ccur;
				derivative = EvalPolStr(str, bcur, 1);
				
				if (derivative == 0) 
					throw invalid_argument("0 devision by derivative");
				bx = bcur - EvalPolStr(str, bcur, 0) / derivative;
				bcur = bx;
			}
			result = fabs(EvalPolStr(str, (acur + bcur) / 2, 0));
			value = fabs(bcur - acur) / 2;
		
		} while (value > eps && result > eps);
		return (acur + bcur) / 2;
	}

}