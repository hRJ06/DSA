class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int a = 0,b = 0;
        for(int i = 0; i<n; i++) {
            char ch = colors[i];
            int j = i + 1;
            while(j < n and colors[j] == ch) j++;
            if(ch == 'A')  
                a += max(0,j - i - 2);
            else
                b += max(0,j - i - 2);
            i = j - 1;
        }
        return a > b;
    }
};