#include <iostream>
#include <cmath>

using namespace std;

class DefInt {
    private:
        double a;
        double b;
        double (*function)(double);

    public:
        DefInt();
        DefInt(double x, double y, double (*func)(double));
        bool Validate();
        DefInt(const DefInt &obj); // Copy constructor 
        ~DefInt(); // Destructor to free allocated memory
        double ByTrapezoid(double N);
};

bool DefInt::Validate() {
    if(a > b) {
        cerr << "Invalid limits of integration: a should be less than or equal to b." << endl;
        return false;
    }
    if(!function) {
        cerr << "Function pointer is NULL!" << endl;
        return false;
    }
    return true;
}

DefInt::DefInt(): a(0.0), b(0.0), function(NULL) {};
DefInt::DefInt(double x, double y, double (*func)(double)): a(x), b(y), function(func) {
    Validate();
};
DefInt::DefInt(const DefInt &obj): a(obj.a), b(obj.b), function(obj.function) {};
DefInt::~DefInt() {
    // No dynamic memory to free since function pointer is not owning
};

double DefInt::ByTrapezoid(double N) {
    if(!Validate()) {
        return NAN; // Return NaN if validation fails
    }
    if(N <= 0) {
        cerr << "Number of intervals N must be positive!" << endl;
        return NAN;
    }
    double sum = 0.0;
    sum += 0.5 * (function(a) + function(b));
    double h = (b - a) / N;
    for(int i=1;i<N;i++){
        double x = a + (double)i*h;
        sum += function(x);
    }
    return h * sum;
};

double function1(double x) {
    return x*x*x - x*x + 1;
}

int main() {
    DefInt MyInt(1.0,2.0,function1);
    int N;
    cout << "Enter the number of intervals: ";
    cin >> N;
    cout<< endl;
    cout<<"value of interval is: "<<N<<endl;

    double ans = MyInt.ByTrapezoid(N);
    if(!isnan(ans)) 
        cout << "The value of the area under the curve x^3 - x^2 + 1 from 1.0 to 2.0 is: " << ans << endl;
    else
        cout << "Failed to compute area." << endl;

    DefInt MyInt2 = MyInt; // Using copy constructor
    ans = MyInt2.ByTrapezoid(N);
    if(!isnan(ans))
        cout << "The value of the area under the curve x^3 - x^2 + 1 from 1.0 to 2.0 (using copy constructor) is: " << ans << endl;
    else
        cout << "Failed to compute area using copy constructor." << endl;

    DefInt MyInt3; // Default constructor
    MyInt3 = MyInt; // Using assignment operator
    ans = MyInt3.ByTrapezoid(N);
    if(!isnan(ans))
        cout << "The value of the area under the curve x^3 - x^2 + 1 from 1.0 to 2.0 (using assignment operator) is: " << ans << endl;
    else
        cout << "Failed to compute area using assignment operator." << endl;

    DefInt MyInt4(2.0,1.0,function1); // Invalid limits
    ans = MyInt4.ByTrapezoid(N);
    if(!isnan(ans))
        cout << "The value of the area under the curve x^3 - x^2 + 1 from 2.0 to 1.0 is: " << ans << endl; // Should handle error
    else
        cout << "Failed to compute area with invalid limits." << endl;

    DefInt MyInt5(1.0,2.0,NULL); // NULL function pointer
    ans = MyInt5.ByTrapezoid(N);
    if(!isnan(ans))
        cout << "The value of the area under the curve with NULL function pointer from 1.0 to 2.0 is: " << ans << endl; // Should handle error 
    else
        cout << "Failed to compute area with NULL function pointer." << endl;

    DefInt MyInt6(1.0,2.0,function1);
    cout<< "Enter a negative number of intervals: ";
    cin>> N;
    cout<< endl;
    cout<<"value of interval is: "<<N<<endl;
    ans = MyInt6.ByTrapezoid(N); // Invalid N
    if(!isnan(ans))
        cout << "The value of the area under the curve x^3 - x^2 + 1 from 1.0 to 2.0 with negative N is: " << ans << endl; // Should handle error
    else
        cout << "Failed to compute area with negative N." << endl;

    return 0;
}

/*
Enter the number of intervals: 100

value of interval is: 100
The value of the area under the curve x^3 - x^2 + 1 from 1.0 to 2.0 is: 2.41673
The value of the area under the curve x^3 - x^2 + 1 from 1.0 to 2.0 (using copy constructor) is: 2.41673
The value of the area under the curve x^3 - x^2 + 1 from 1.0 to 2.0 (using assignment operator) is: 2.41673
Invalid limits of integration: a should be less than or equal to b.
Invalid limits of integration: a should be less than or equal to b.
Failed to compute area with invalid limits.
Function pointer is NULL!
Function pointer is NULL!
Failed to compute area with NULL function pointer.
Enter a negative number of intervals: -10

value of interval is: -10
Number of intervals N must be positive!
Failed to compute area with negative N.
*/
