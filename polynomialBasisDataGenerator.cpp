/*Program to perform polynomial basis linear model (y = WTPhi(x)+e ; e ~ N(0, a)) data generator*/
/*Author: Siffi Singh */
/*Dated: 27/10/2017 */

/* standard Header */
#include <bits/stdc++.h>
using namespace std;
# define two_pi 2.0*3.14159265358979323846
/*Generating guassian distributed data*/
double guassianerror(double mu, double sigma) {
    double z0 = 0, z1 = 0;
    double epsilon = std::numeric_limits < double > ::min();
    bool generate;
    generate = !generate;
    if (!generate)
        return z1 * sigma + mu;
    double u1, u2;
    do {
        u1 = rand() * (1.0 / RAND_MAX);
        u2 = rand() * (1.0 / RAND_MAX);
    } while (u1 <= epsilon);
    z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
    z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
    return z0 * sigma + mu;
}
/*Generating uniform data*/
double uniform(double min, double max) {
    return (min + (rand() % static_cast < int > (max - min + 1)));
}
/*matrix multiply for row and column vector*/
double matrixmul(int n, double X[1000][1], double W[1][1000]) {
    double ans = 0;
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < n; k++) {
                ans = ans + W[i][k] * X[k][j];
            }
        }
    }
    return ans;
}
/*Driver Function*/
int main() {
    int n, a;
    cout << "Enter basis number: ";
    cin >> n;
    cout << "Enter variance of error function: ";
    cin >> a;
    double min = -10;
    double max = 10;
    double e, x;
    /*Variable Declarations*/
    double X[1000][1], E[1000], Y[1000], W[1][1000];
    cout << "Enter the weights: ";
    for (int i = 0; i < n + 1; i++) {
        cin >> W[0][i]; 	//vector W, for calculating W(transpose)*X
    }
    int data;
    /*Inputing number of data to be generated.*/
    cout << "Enter the number of data you want to generate: ";
    cin >> data;
    for (int i = 0; i < data; i++) {
        e = guassianerror(0, a);	//e, error function is guassian distributed
        x = uniform(min, max);		//'x' is a uniform distribution in the range [-10,10]
        for (int j = n; j >= 0; j--) {
            X[j][0] = pow(x, j);		//vector X, for calculating W(transpose)*X
        }
        E[i] = e;
        Y[i] = matrixmul(n + 1, X, W) + e;
        cout << Y[i] << " || " << x << " || " << e << endl;
    }
    return 0;
}



