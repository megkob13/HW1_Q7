#include <iostream>
#include <vector>


using namespace std;

// AERSP 424 Homework 1: Question 7
// Goal: Write functions named gradient_weights and update_weights that
// computes equations.

double z = 0;//initialize variable z
double sigma = 0; //initialize variable sigma
double sigmaprime = 0; //initialize variable sigmaprime
double y_predict = 0; //initialize variable y_predict
double y = 1; //assign given value
double dC = 0; //initialize variable
double alpha = .001; //assign given value

vector<double> gradient_weights(vector<double>&, vector<double>&);//function prototype for gradient_weights
vector<double> update_weights(vector <double>&, vector <double>&, double); //function prototype for update_weights

int main()
{

	vector<double> w = { 0.0001, 0.0001, 0.0001 }; //given values for w
	vector<double> x = { 124, 31.89, 20.945 }; //given values of x
	vector<double> dw = { 0, 0, 0 }; //initialize vector


	dw = gradient_weights(w, x); //passes variables to functions
	w = update_weights(dw, w, alpha);

	for (int i = 0; i < dw.size(); i++)
	{
		cout << "dw[" << i << "] = " << dw[i] << endl; //prints individual elements of vector
	}
	for (int i = 0; i < w.size(); i++)
	{
		cout << "updated w[" << i << "] = " << w[i] << endl; //prints individual elements of vector
	}

}