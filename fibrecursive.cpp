#include <iostream>
#include <vector>
using namespace std;

void fibonacciIterative(int n) {
    if (n < 1) return; // If n is less than 1, there's nothing to print

    int a = 0, b = 1;
    cout << "Fibonacci Sequence (Iterative): " << a << " " << b << " ";

    for (int i = 2; i < n; ++i) {
        int c = a + b;
        cout << c << " "; // Print the next Fibonacci number
        a = b; // Update for next iteration
        b = c; // Update for next iteration
    }
    cout << endl; // End of the sequence
}


void fibonacciRecursive(int n, int a = 0, int b = 1) {
        if (n == 0) {
        cout  << a << " "; // Print the first Fibonacci number
        return;
    }    if (n == 1) {
        cout  <<  b<< " "; // Print the first Fibonacci number
        return;
    }
    cout << a << " "; // Print the current Fibonacci number
    fibonacciRecursive(n - 1, b, a + b); // Recur with updated values
}


void fibonacciDP(int n) {
    if (n < 1) return; // If n is less than 1, there's nothing to print

    vector<int> fib(n);
    fib[0] = 0; // F(0)
    if (n > 1) fib[1] = 1; // F(1)

    cout << "Fibonacci Sequence (DP): " << fib[0] << " " << fib[1] << " ";

    for (int i = 2; i < n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2]; // Calculate Fibonacci number
        cout << fib[i] << " "; // Print the Fibonacci number
    }
    cout << endl; // End of the sequence
}

int main() {
    int n;
    int a = 0, b = 1;
    cout << "Enter the number of Fibonacci numbers to compute: ";
    cin >> n;
    int ch;
    cout<<"\nEnter Your Choice\n1\n2\n3:-";
    cin>>ch;
    switch(ch)
    {
        case 1:
            fibonacciIterative(n);
            break;
        case 2:
            fibonacciRecursive(n, a,b);
            break;
        case 3:
            fibonacciDP(n);
            break;
        default:
            cout << "Invalid choice!" << endl;
        
    }
    
    return 0;
}
