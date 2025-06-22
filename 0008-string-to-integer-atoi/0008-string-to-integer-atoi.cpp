class Solution {
public:
    int myAtoi(string s) {
        
        //check for empty string
        if(s == "")
        {
           return 0; 
        }

        int i = 0;
        int n = s.size();
        int result = 0;
        int sign = 1; //default positive
        int digit = 0;

        // const int round1 = pow(2,31);
        // const int round2 = pow(2,31)-1;

        //check for leading whitespaces
        while( i < n && s[i] == ' ')
        {
            i++;
        }

        //check for signedness '+' or '-'
        if(s[i] == '-')
        {
            printf("I am here [%c]\n",s[i]);
            sign = (-1);
            i++;
        }
        else if(s[i] == '+')
        {
            i++;
        }

        //process integer charector
        while( i< n && isdigit(s[i]))
        {
            printf("digit is [%d]\n",s[i]);
            digit = s[i]-'0';
            
            //rounding-off //overflow check //imp
            if((result > ((INT_MAX - digit)/10)))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result*10 + digit;          
            i++;
        }

        return (sign*result);
        
    }
};

/*
//NOTE:: You could have used long for storing the results so that no overflow occurs at firstplace,
//secondly, you can check for overflow cases after calculating the result
//Although this wrong technically "Handling OVERFLOW, by Doing an OVERFLOW" :)
         {
            long res = res * 10 + (s[i] - '0');

            // Handle overflow check as per "int" storage rules
            if (sign * res > INT_MAX) return INT_MAX;
            if (sign * res < INT_MIN) return INT_MIN;
         }   
            
*/

//StudyNotes:
/**

The problem requires converting a given string into an integer while following specific rules. Key challenges include handling whitespace, signs (+ and -), non-numeric characters, and integer overflow.

A simple string parsing approach can be used:

Ignore leading whitespace.
Determine the sign (+ or -).
Convert valid numeric characters to an integer.
Stop conversion when a non-numeric character appears.
Handle integer overflow by capping the value at INT_MAX or INT_MIN.

#Approach:

Trim leading spaces using trim().
Check for sign at the beginning (+ or -).
Iterate through characters while they are numeric:
Convert each character to a digit.
Multiply the existing result by 10 and add the new digit.
Check for integer overflow conditions.
Return the final computed integer with the correct sign.
This approach ensures we efficiently extract and convert the number in O(n) time complexity.

#Complexity:

Time Complexity: O(n) (where n is the length of the string)
Space Complexity: O(1) (constant extra space used)


**/