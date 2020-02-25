//Ty Rozell

#include <iostream>
#include <vector>
#include "porter_stem.h"

using namespace std;

int main()
{
    string words = "an experimental study of a wing in a propeller slipstream was made in order ";
           words += "to determine the spanwise distribution of the lift increase due to slipstream at different angles of attack of the wing ";
           words += "and at different free stream to slipstream velocity ratios the results were intended in part as an evaluation basis ";
           words += "for different theoretical treatments of this problem";

    string temp;
    vector<string> stringVector;

    //split the string into a vector of strings
    for (int i=0; i <= words.length(); i++)
    {
        if (words[i] != ' ' && i < words.length() - 1)
            temp += words[i];
        else
        {
            stringVector.push_back(temp);
            temp = "";
        }
    }

    //call porter stemming function
    stringVector = porterStem(stringVector);

    //output results
    for (const auto word : stringVector)
        cout << word << ' ';
    cout << endl;
}