//minimum sum of 2 digit numbers formed using the given array

class Solution{   
public:
    string solve(int arr[], int n) {
        priority_queue<int,vector<int>,greater<int>> q1;
        // string str1="",str2="";
        long long num1=0,num2=0;
        // int x,y;
        for(int i=0;i<n;i++)
        {
            q1.push(arr[i]);
        }
        while(!q1.empty())
        {
            if(!q1.empty())
            {
                num1= (num1*10)+q1.top();
                q1.pop();
            }
            if(!q1.empty())
            {
                num2= (num2*10)+q1.top();
                q1.pop();
            }
        }
        long long sum=num1+num2; 
        return to_string(sum);
    }
};
