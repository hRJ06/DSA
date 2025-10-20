class ProductOfNumbers {
    private:
        vector<long long> prefix;
    public:
        ProductOfNumbers() {
            prefix = {1};
        }
        
        void add(int num) {
            if(!num) prefix = {1};
            else prefix.push_back(prefix.back() * num);
        }
        
        int getProduct(int k) {
            if(prefix.size() <= k) return 0;
            return prefix.back() / prefix[prefix.size() - k - 1];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */