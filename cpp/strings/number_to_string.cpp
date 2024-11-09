#include<bits/stdc++.h>
using namespace std;
// 1200
string numberToWords(int num, vector<string>& below_twenty, vector<string>& tens) {
    if(num < 20){
        return below_twenty[num];
    }
    else if(num < 100){
        return tens[num/10] + " " + below_twenty[num%10];
    }
    else if(num < 1000){
        return below_twenty[num/100] + " Hundred " + 
        numberToWords(num%100, below_twenty, tens);
    }
    else if(num < 1000000){
        return numberToWords(num/1000, below_twenty, tens) + " Thousand " + 
        numberToWords(num%1000,below_twenty,tens);
    }
    else if(num < 1000000000){
        return numberToWords(num/1000000, below_twenty, tens) + " Million " + 
        numberToWords(num%1000000, below_twenty, tens);
    }
}

int main()
{
    vector<string> below_twenty = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
        "Eighteen", "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    int num = 1200100;
    string output = numberToWords(num, below_twenty, tens);
    output.erase(0, output.find_first_not_of(' '));
    output.erase(output.find_last_not_of(' ') + 1);
    cout<<num<<": "<<output<<"|";
    
    return 0;
}
