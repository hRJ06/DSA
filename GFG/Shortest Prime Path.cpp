class Solution{   
public:
    int solve(int num1,int num2)
    {   
      //code here
      vector<bool> prime(10000,true);
      prime[0] = prime[1] = false;
      for(int i = 2; i<10000; i++) {
        if(prime[i]) {
            for(int j = 2 * i; j<10000; j = j + i) {
                prime[j] = 0;
            }
        }
      }
      unordered_set<int> s;
      for(int i = 1000; i<10000; i++) {
        if(prime[i]) s.insert(i);
      }
      queue<pair<int,int>> q;
      q.push({0,num1});
      while(!q.empty()) {
          auto top = q.front();
          q.pop();
          int step = top.first, n = top.second;
          if(n != num2) {
            string no = to_string(n);
            for(int i = 0; i<4; i++) {
                for(int j = 0; j<=9; j++) {
                    char c = no[i];
                    no[i] = (j + '0');
                    int newNo = stoi(no);
                    if(s.find(newNo) != s.end()) {
                        s.erase(newNo);
                        if(newNo != num2) {
                            q.push({step + 1,newNo});
                        }
                        else {
                            return step + 1;
                        }
                    }
                    no[i] = c;
                }
            }
          }
          else {
            return step;
          }
      }
      return -1;
    }
};