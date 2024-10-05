#include <iostream>
#include <string> 
#include <cmath> 

using namespace std;

void PrintTable(double Table[4][5]) {
    string TableColNames = "             | Gross Income | Taxable Income | Tax BREAKDOWN | Nation Insurance | 2024 Take Home |";
    //string TableTopBottomLine = "             ";
    //string TableTopBottomLineV2 = "             ";

    //for (int i = 0; i < TableColNames.length(); i++) {
    //    TableTopBottomLine += "_";
    //    TableTopBottomLineV2 += "-";
    //}
    //cout << TableTopBottomLine << endl << TableColNames << endl;
    //cout << TableTopBottomLineV2 << endl;

    cout << TableColNames << endl;



}

void print(string message) { // this print with a newline
    cout << message << endl;
}

void printNoNewLine(string message) { // this function print with out a new line
    cout << message;
}

string input(string message) { // this function takes an input an returns it
    printNoNewLine(message);
    string thisInput;
    getline(cin, thisInput);
    return thisInput;
}

int RangeIntInput(int Min, int Max, string message) { // this input function will only return number when it meets the requirement
    int thisIntInput;

    while (true) {
        try {
            string thisStringInput = input(message);
            thisIntInput = stoi(thisStringInput);
            if (thisIntInput >= Min && thisIntInput <= Max) {
                return thisIntInput;
            }
            else {
                print("Please enter a valid number bewteen " + to_string(Min) + " - " + to_string(Max));
            }
        }
        catch (exception e) {
            print("Invalid input. Please enter a valid number.");
        }
    }


}

int FindThisCharIndex(char ThisChar, string ThisString) {
    const int Length = ThisString.length();
    char* ThisCharArray = new char[Length + 1];

    strcpy_s(ThisCharArray, Length + 1, ThisString.c_str());

    for (int i = 0; Length - 1; i++) {
        if (ThisChar == ThisCharArray[i]) {
            delete[] ThisCharArray;
            return i;
        }
    }

    delete[] ThisCharArray;
    return 0;
}

double getValidMoneyInput(string message) {
    double ThisIsMoneyFromUser = 0;

    bool d_isVaild = false;

    while (!d_isVaild) {
        try {
            string ThisStringInput = input(message);
            ThisIsMoneyFromUser = stod(ThisStringInput.substr(0, FindThisCharIndex('.', ThisStringInput) + 3));
            d_isVaild = true;
        }
        catch (exception e) {
            print("Please enter valid money amount.");
        }
    }

    return ThisIsMoneyFromUser;

}


double DoTheTaxBands(double AfterPersonalAllowance) {
    int Basic[3] = {12571, 50270};
    int High[3] = { 50271, 125140};
    int Max = 124140;
    double AfterTheTaxBand;
    if (AfterPersonalAllowance >= Basic[0] && AfterPersonalAllowance <= Basic[1]) {
        AfterTheTaxBand = AfterPersonalAllowance * (20 / 100.00);
    }
    else if (AfterPersonalAllowance >= High[0] && AfterPersonalAllowance <= High[1]) {
        AfterTheTaxBand = AfterPersonalAllowance * (40 / 100.00);
    }
    else if (AfterPersonalAllowance > Max) {
        AfterTheTaxBand = AfterPersonalAllowance * (45 / 100.00);
    }

    return AfterTheTaxBand;
}

double DoTaxBREAKDOWN(double MoneyAfterPeronalAllowance) {
    double DoneTheTax = DoTheTaxBands(MoneyAfterPeronalAllowance);
    return DoneTheTax;
}

int FindThisCharInThisCharArray(char arrayOfChar[16], char findThisChar) {
    for (int row = 0; row < 16; row++) {
        if (findThisChar == arrayOfChar[row]) {
            return row;
        }
    }

    return -10; // to show that it couldnt find that char
}

char StringToChar(string TheString) {
    return TheString[0];
}

double DoNationalInsurance(double TaxableIncome) {
    char Letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 's', 'v', 'z' };
    double CatePer[16][3] = { 
        {0.0, 8.0, 2.0},
        {0.0, 1.85, 2.0},
        {0.0, 0.0, 0.0},
        {0.0, 2.0, 2.0},
        {0.0, 1.85, 2.0},
        {0.0, 8.0, 2.0},
        {0.0, 8.0, 2.0},
        {0.0, 1.85, 2.0},
        {0.0, 2.0, 2.0},
        {0.0, 0.0, 0.0},
        {0.0, 2.0, 2.0},
        {0.0, 8.0, 2.0},
        {0.0, 8.0, 2.0},
        {0.0, 0.0, 0.0},
        {0.0, 8.0, 2.0},
        {0.0, 2.0, 2.0}
    };

    int IndexCatePer = -10;
    while (!(IndexCatePer >= 0)) { 
        string LetterInput = input("Enter your Category Letter: ");
        if (LetterInput.length() == 1) {
            char FindThisChar = StringToChar(LetterInput);
            IndexCatePer = FindThisCharInThisCharArray(Letters, FindThisChar);
            if (IndexCatePer != -10) {
                break;
            }
            
        }
    }
    double CategorysFromIndexRow[4];

    CategorysFromIndexRow[0] = CatePer[IndexCatePer][0];
    CategorysFromIndexRow[1] = CatePer[IndexCatePer][1];
    CategorysFromIndexRow[2] = CatePer[IndexCatePer][2];

    double ThisIsWhatYouPay = 0;
    if (TaxableIncome >= 123.00 && TaxableIncome <= 242.00) {
        double percentage;
        if (CategorysFromIndexRow[0] == 0) {
            percentage = 0;
        }
        else {
            percentage = CategorysFromIndexRow[0] / 100.0;
        }
        ThisIsWhatYouPay = TaxableIncome * percentage;
    } else if (TaxableIncome >= 242.01 && TaxableIncome <= 967.00) {
        double percentage;
        if (CategorysFromIndexRow[1] == 0) {
            percentage = 0;
        }
        else {
            percentage = CategorysFromIndexRow[1] / 100.0;
        }
        ThisIsWhatYouPay = TaxableIncome * percentage;
    }
    else if (TaxableIncome > 967.00) {
        double percentage;
        if (CategorysFromIndexRow[2] == 0) {
            percentage = 0;
        }
        else {
            percentage = CategorysFromIndexRow[2] / 100.0;
        }
        ThisIsWhatYouPay = TaxableIncome * percentage;
    }

    return ThisIsWhatYouPay;
}

double NIclassOne(double TaxableIncome) {
    double PayThis = 0;

    if (TaxableIncome > 12570 && TaxableIncome < 50270) {
        PayThis = TaxableIncome * (12 / 100.00);
    }
    else if (TaxableIncome > 50270) {
        PayThis = TaxableIncome * (2 / 100.00);
    }
    return PayThis;
}

double NIclassTwo(double TaxableIncome) {
    if (TaxableIncome > 12570) {
        return 3.45 * 52;// this will give the what you need to pay in a year 
    }
    else {
        return 0;
    }
}

double NIclassThree(double TaxableIncome, bool FillInTheGap) {
    if (TaxableIncome > 12570 && FillInTheGap) {
        return 17.45 * 52; // this will give the what you need to pay in a year 
    }
    else {
        return 0;
    }
}

double NIclassFour(double TaxableIncome) {
    double PatThis = 0;
    if (TaxableIncome > 12570 && TaxableIncome < 50270) {
        PatThis = (TaxableIncome - 12570) * (9 / 100.00);
    }
    if (TaxableIncome > 50270) {
        PatThis += (TaxableIncome - 50270) * (2 / 100.00);
    }
    return PatThis;
}


double DoNationalInsuranceV2(int Class, double TaxableIncome) {
    double total = 0.00;
    switch (Class)
    {
    case 1:
        total = NIclassOne(TaxableIncome);
        break;
    case 2:
    case 4:
        total = NIclassTwo(TaxableIncome) + NIclassFour(TaxableIncome);
        break;
    case 3:
        total = NIclassThree(TaxableIncome, false);
        break;
    default:
        throw std::invalid_argument("Invalid NI Class");
    }
    return total;
}


int main()
{
    double personalAllowance = 12570.00;
    double GrossIncome = getValidMoneyInput("Enter the amount of money that you make in a year: ");

    double TaxableIncome = GrossIncome - personalAllowance;
    if (GrossIncome <= personalAllowance) {
        cout << "You dont have to pay tax or National Insurance." << endl;
    }
    else {
        int Class = RangeIntInput(1, 4, "Which class do you fall in (class 2 and class 4 are the same): ");
        double NationalInsurancePay = DoNationalInsuranceV2(Class, TaxableIncome);

        double TaxBREAKDOWN = DoTaxBREAKDOWN(TaxableIncome);

        cout << "Taxable Income Per Year: " << TaxableIncome << endl;
        cout << "Tax Breakdown Per Year: " << TaxBREAKDOWN << endl;
        cout << "National Insurance Per Year: " << NationalInsurancePay << endl;

        double x = TaxableIncome - TaxBREAKDOWN;
        x -= NationalInsurancePay;
        x += personalAllowance;

        cout << "2023 - 2024 Take Home: " << x << endl;
    }
    
}
