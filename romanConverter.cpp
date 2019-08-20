#include "../std_lib_facilities.h"

// seokho han 201761541
// ass2_q2

/*
 convert roman number to a decimal number.
*/

int rToD(char c)// convert a roman numeral to an integer 
{
    int re = 0;
    switch (c)
    {
        case 'M':
            re =  1000;
            break;
        case 'D':
            re =  500;
            break;
        case 'C':
            re =  100;
            break;
        case 'L':
            re =  50;
            break;
        case 'X':
            re =  10;
            break;
        case 'V':
            re =  5;
            break;
        case 'I':
            re =  1;
            break;
        default:
            error ("Invalid Roman numeral!");
            return -1;
    }
    return re;
}

int main()
{
    int dNum = 0;
    string s;

    cout << "Enter a number in Roman numerals: ";
    cin >> s;

   for (int i = 0; i < s.size(); i++)// check if any letter is repeated more than 3 times except leading 'M'
   {
       if (i + 3 < s.size() && s[0] != 'M')
       {
           int d1 = rToD(s[i]);
           int d2 = rToD(s[i+1]);
           int d3 = rToD(s[i+2]);
           int d4 = rToD(s[i+3]);

           if (d1 == d2 && d2 == d3 && d3 == d4)
           {
               error("Not allowed!(A numeral cannot be repeated more than 3 times.)" );
           }
       }
   }
   
    for (int i = 0; i < s.size(); i++)// convert roman to decimal value
    {
      int c1 = rToD(s[i]);
      if (i + 1 < s.size())
      {
          int c2 = rToD(s[i+1]);
          if (c1 >= c2)
          {    
              dNum += c1;
          }
          else
          {
              dNum = dNum + c2 - c1;
              i++;
          }
      }
      else
      {
          dNum += c1;
          i++;
      }
    }

    cout << "The converted number is: " << dNum << endl;

    return 0;
}
