class Solution
{
    public:
    bool isRotated(string str1, string str2)
    {
        string check = str1.substr(2) + str1.substr(0,2);
        if(check == str2) return true;
        int n = str1.length();
        check = str1.substr(n - 2,2) + str1.substr(0,n - 2);
        if(check == str2) return true;
        return false;
    }
};