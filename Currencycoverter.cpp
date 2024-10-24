#include <iostream>
using namespace std;

class CurrencyConvertor {
private:
    double usdToEuroRate;
    double euroToUsdRate;
    double usdToPakRupeeRate;
    double usdToIndRupeeRate;

public:
    CurrencyConvertor(double usdToEuro, double euroToUsd, double usdToPak, double usdToInd) {
        usdToEuroRate = usdToEuro;
        euroToUsdRate = euroToUsd;
        usdToPakRupeeRate = usdToPak;
        usdToIndRupeeRate = usdToInd;
    }

    // Convert USD to Euro
    double usdToEuro(double usdAmount) {
        return usdAmount * usdToEuroRate;
    }

    // Convert Euro to USD
    double euroToUsd(double euroAmount) {
        return euroAmount * euroToUsdRate;
    }

    // Convert USD to Pakistani Rupee
    double usdToPakRupee(double usdAmount) {
        return usdAmount * usdToPakRupeeRate;
    }

    // Convert USD to Indian Rupee
    double usdToIndRupee(double usdAmount) {
        return usdAmount * usdToIndRupeeRate;
    }

    // Display Exchange Rate
    void displayExchangeRate() const {
        cout << "\n\t--------Current Exchange Rate -----------\n";
        cout << "1 USD to Euro: " << usdToEuroRate << endl;
        cout << "1 Euro to USD: " << euroToUsdRate << endl;
        cout << "1 USD to Pakistani Rupee: " << usdToPakRupeeRate << endl;
        cout << "1 USD to Indian Rupee: " << usdToIndRupeeRate << endl;
    }
};

void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get(); // Waits for user input
}

int main() {
    const double initialUsdToEuroRate = 0.85;
    const double initialEuroToUsdRate = 1.18;
    const double initialUsdToPakRate = 277.50;
    const double initialUsdToIndRate = 75.00;

    CurrencyConvertor convertor(initialUsdToEuroRate, initialEuroToUsdRate, initialUsdToPakRate, initialUsdToIndRate);

    int choice;
    double amount;

    do {
        system("clear"); // Clear the terminal on macOS
        convertor.displayExchangeRate();

        cout << "\n\t******* Currency Converter Main Menu ********\n";
        cout << "1. Convert USD to Euro\n";
        cout << "2. Convert Euro to USD\n";
        cout << "3. Convert USD to Pakistani Rupee\n";
        cout << "4. Convert USD to Indian Rupee\n";
        cout << "0. Exit\n";
        cout << "Please Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the Amount of USD: ";
            cin >> amount;
            cout << amount << " USD is equivalent to " << convertor.usdToEuro(amount) << " Euro\n";
            pause();
            break;

        case 2:
            cout << "Enter the Amount of Euro: ";
            cin >> amount;
            cout << amount << " Euro is equivalent to " << convertor.euroToUsd(amount) << " USD\n";
            pause();
            break;

        case 3:
            cout << "Enter the Amount of USD: ";
            cin >> amount;
            cout << amount << " USD is equivalent to " << convertor.usdToPakRupee(amount) << " Pakistani Rupee\n";
            pause();
            break;

        case 4:
            cout << "Enter the Amount of USD: ";
            cin >> amount;
            cout << amount << " USD is equivalent to " << convertor.usdToIndRupee(amount) << " Indian Rupee\n";
            pause();
            break;

        case 0:
            cout << "Program Ended\n";
            break;

        default:
            cout << "Please Enter a Valid Number\n";
            pause();
        }
    } while (choice != 0);

    return 0;
}
