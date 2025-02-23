#include <iostream>
using namespace std;

class PaymentProcessor {
private:
    static int fraudulentTransactionsCount; // Tracks fraud cases

public:
    // Check if transaction amount exceeds $5000
    int checkAmountLimit(double amount) {
        if (amount > 5000) {
            return 1; // Fraud detected
        }
        return 0;
    }

    // Check if transaction comes from a flagged location
    int checkLocationMismatch(string location) {
        if (location == "Russia" || location == "North Korea" || location == "Iran") {
            return 1; // Fraud detected
        }
        return 0;
    }

    // Process a payment and check for fraud
    int processPayment(double amount, string location) {
        int fraud = checkAmountLimit(amount) + checkLocationMismatch(location);
        if (fraud > 0) {
            fraudulentTransactionsCount++; // Increase fraud count
            cout << "Fraud Detected! Transaction Blocked.\n";
        } else {
            cout << "Payment Processed Successfully.\n";
        }
        return fraud;
    }

    // Get total number of fraudulent transactions
    static int getFraudulentTransactionsCount() {
        return fraudulentTransactionsCount;
    }
};

// Initialize static variable
int PaymentProcessor::fraudulentTransactionsCount = 0;

int main() {
    PaymentProcessor processor;

    processor.processPayment(6000, "USA");   // Exceeds limit -> Fraud
    processor.processPayment(100, "Russia"); // Suspicious location -> Fraud
    processor.processPayment(500, "USA");    // Safe transaction

    cout << "Total fraudulent transactions: " 
         << PaymentProcessor::getFraudulentTransactionsCount() << endl;

    return 0;
}
