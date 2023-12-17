class FoodRatings {
private:
    unordered_map<string,set<pair<int,string>>> cuisineRating;
    unordered_map<string,string> foodToCuisine;
    unordered_map<string,int> foodRating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i<n; i++) {
            cuisineRating[cuisines[i]].insert({-ratings[i],foods[i]});
            foodToCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        cuisineRating[cuisine].erase({-foodRating[food],food});
        foodRating[food] = newRating;
        cuisineRating[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return (*cuisineRating[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */