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

vector<double> gradient_weights(vector <double>& w, vector <double>& x)
{

	double result = 0; //start the result at zero, then values will be added 
	//to it zero the for loop.
	for (int i = 0; i < w.size(); i++) //both vectors will be same size, so run
		//loop for number of elements within vectors
	{
		result += w[i] * x[i]; //new result is equal to the original result 
		//plus the product of w*x (dot product is multiplying respective terms
		//and adding the products of the terms together
	}

	z = result;

	sigma = 1 / (1 + exp(-z)); //function given in doc
	sigmaprime = sigma * (1 - sigma); //function given in doc

	y_predict = sigma;

	dC = 2 * (y_predict - y); //function given in doc

	vector<double> dw = { 1, 1, 1 };

	for (int i = 0; i < dw.size(); i++)
	{
		dw[i] = dC * sigmaprime * x[i]; // multiplies every element of vector x and creates
		//new vector dw for gradient weights
	}
	return dw;
}

vector<double> update_weights(vector <double>& dw, vector <double>& w, double alpha)
{

	for (int i = 0; i < w.size(); i++)
	{
		w[i] = w[i] - alpha * dw[i]; //each element of dw is multiplied by alpha
		//then subtracted from the respective element in w to create new vector of updated
		//w values
	}
	return w;

}