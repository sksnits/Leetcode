class Solution {
public:
    int myAtoi(string s) {
        
        //check for empty charector
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
            sign *= (-1);
            i++;
        }


        while(isdigit(s[i]))
        {
            printf("digit is [%d]\n",s[i]);
            digit = s[i]-'0';
            
            //rounding-off //overflow check
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