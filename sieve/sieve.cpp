/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Daniel Partika
 * Date        : 9.10.2021
 * Description : Sieve of Eratosthenes, computes prime numbers and displays them
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit); // constructor

    ~PrimesSieve() { //
        delete [] is_prime_;
    }

    int num_primes() const {
        return num_primes_;
    }

    void display_primes() const;

private:
    // Instance variables
    bool * const is_prime_;
    const int limit_; // number given from user
    int num_primes_, max_prime_;

    // Method declarations
    int count_num_primes() const;
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) : //code for constructor
        is_prime_{new bool[limit + 1]}, limit_{limit} {
    sieve();
}

void PrimesSieve::display_primes() const {
    // TODO: write code to display the primes in the format specified in the
    // requirements document.
    const int max_prime_width = num_digits(max_prime_), primes_per_row = 80 / (max_prime_width + 1);
    //cout << "max_prime_width: " << max_prime_width;
    //cout << "primes_per_row: " << primes_per_row;
    cout << "\nNumber of primes found: " << count_num_primes() << endl;
    cout << "Primes up to " << limit_ << ":" << endl;
    
    //cout << "Primes per row: " << primes_per_row; 
    //cout << "numdigits: " << num_digits(max_prime_) << endl;
    //cout << "max prime: " << max_prime_;
    int primes_printed = 0;
    if (count_num_primes() <= primes_per_row) { // one row output
        for (int i = 2; i <= limit_; i++){
            if(max_prime_ == i){
                //cout  << setw(max_prime_width) << i;
                cout << i;
                primes_printed = 0;
                
            } else if (is_prime_[i]) {
                //cout << setw(max_prime_width) << i << " ";
                cout << i << " ";
                primes_printed ++;
            } 
        }
    } else { //multiline output
        primes_printed = 0;
        for (int i = 2; i <= limit_; i++) {
            //int modprint = primes_printed+1;
            //primes_printed++;
            
            if (max_prime_ == i || (primes_printed +1 == primes_per_row && is_prime_[i]) ) { 
                cout << setw(max_prime_width) << i;
                primes_printed += 1;
            } else if (is_prime_[i] && limit_ != primes_printed) {
                cout << setw(max_prime_width) << i << " ";
                primes_printed += 1;
            } 
            if (primes_printed == primes_per_row) { 
                cout << endl;
                //cout << "i is: " << i << " primes per row is: " << primes_per_row << endl;
                primes_printed = 0;
            }
        }
    }  
}
    

int PrimesSieve::count_num_primes() const {
    // TODO: write code to count the number of primes found
    int n = 0;
    for (int i = limit_; i >= 2; i--) {
        if (is_prime_[i]){
            n++;
        }
    }
    return n;
}

void PrimesSieve::sieve() {
    // TODO: write sieve algorithm
    //initalize is_prime_
    for (int i = 0; i <= limit_; i++){
        is_prime_[i] = true;
    }
    //sieve algorithm
    for (int i = 2; i <= sqrt(limit_); i++) {
        if (is_prime_[i]){
            for (int j = i * i; j <= limit_; j+=i) {
                is_prime_[j] = false; 
            }
        }
    }
    //get max prime
    //bool cond = false;
    //while (cond != true){
        for (int i = limit_; i >= 2; i--) {
            if (is_prime_[i]){
                max_prime_ = i;
                //cond = true;
                break;
            }
        }
    //}
    //cout << "MAX_PRIME" << max_prime_ << endl;

}

int PrimesSieve::num_digits(int num) {
    // TODO: write code to determine how many digits are in an integer
    // Hint: No strings are needed. Keep dividing by 10.
    int n = 1;
    while ((num / 10) >= 10){
        num /= 10;
        n += 1;
    }
    n++;
    return n;
}

int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    // TODO: write code that uses your class to produce the desired output.
    PrimesSieve(limit).display_primes();
    return 0;
}
