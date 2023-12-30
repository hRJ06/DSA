class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string,int> mp;
        for(int i = 0; i<n; i++) {
            mp[arr[i]]++;
        }
        string person = "";
        int vote = 0;
        for(auto &i : mp) {
            if(i.second > vote) {
                person = i.first;
                vote = i.second;
            }
            else if(i.second == vote and i.first < person) {
                person = i.first;
            }
        }
        return {person,to_string(vote)};
    }
};