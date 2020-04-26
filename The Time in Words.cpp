#include <bits/stdc++.h>

using namespace std;

string hourName(int h)
{
    char hour[100];
    if(h == 1)
    {
        return "one";        
    }
    else if(h == 2)
    {
        return "two";
    }
    else if(h == 3)
    {
        return "three";
    }
    else if(h == 4)
    {
        return "four";
    }
    else if(h == 5)
    {
        return "five";
    }
    else if(h == 6)
    {
        return "six";
    }
    else if(h == 7)
    {
        return "seven";
    }
    else if(h == 8)
    {
        return "eight";
    }
    else if(h == 9)
    {
        return "nine";
    }
    else if(h == 10)
    {
        return "ten";
    }
    else if(h == 11)
    {
        return "eleven";
    }
   
        return "twelve";

}
string minName(int m)
{
    if(m == 2)
    {
        return "two";
    }
    else if(m == 3)
    {
        return "three";
    }
    else if(m == 4)
    {
        return "four";
    }
    else if(m == 5)
    {
        return "five";
    }
    else if(m == 6)
    {
        return "six";
    }
    else if(m == 7)
    {
        return "seven";
    }
    else if(m == 8)
    {
        return "eight";
    }
    else if(m == 9)
    {
        return "nine";
    }
    else if(m == 10)
    {
        return "ten";
    }
    else if(m == 11)
    {
        return "eleven";
    }
    else if(m == 12)
    {
        return "twelve";
    }
    else if(m == 13)
    {
        return "thirteen";
    }
    else if(m == 14)
    {
        return "fourteen";
    }
    
    else if(m == 16)
    {
        return "sixteen";
    }
    else if(m == 17)
    {
        return "seventeen";
    }
    else if(m == 18)
    {
        return "eighteen";
    }
    else if(m == 19)
    {
        return "nineteen";
    }
    else if(m == 20)
    {
        return "twenty";
    }
    else if(m == 21)
    {
        return "twenty one";
    }
    else if(m == 22)
    {
        return "twenty two";
    }
    else if(m == 23)
    {
        return "twenty three";
    }
    else if(m == 24)
    {
        return "twenty four";
    }
    else if(m == 25)
    {
        return "twenty five";
    }
    else if(m == 26)
    {
        return "twenty six";
    }
    else if(m == 27)
    {
        return "twenty seven";
    }
    else if(m == 28)
    {
        return "twenty eight";
    }
     return "twenty nine";
    
        
}

// Complete the timeInWords function below.
string timeInWords(int h, int m) {

    if(m == 0)
    {
       return(hourName(h) + " o' clock");
    }
    else if(m >= 1 && m <= 30)
    {
        if(m == 1)
        {
            return ("one minute past "+ hourName(h));
        }
        else if(m == 30)
        {
            return ("half past "+ hourName(h));
        }
        else if(m == 15)
        {
            return ("quarter past " + hourName(h));
        }
        else
        {

           return (minName(m) + " minutes past " + hourName(h));
        }
        
    }
    else if (m >30 && m < 60)
    {
        if(m == 45)
        {
            return ("quarter to " + hourName(h + 1));
        }
        else
        {
            return (minName(60 - m)+ " minutes to " + hourName(h+1));            
        }        
    }
    return "Not Valid";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
