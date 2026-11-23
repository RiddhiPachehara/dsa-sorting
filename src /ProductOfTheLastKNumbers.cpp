class ProductOfNumbers {
private:
    vector<int> prefixProducts;

public:
    ProductOfNumbers() {
        prefixProducts.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProducts = {1};
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProducts.size();
        if (k >= n) {
            return 0;
        }
        return prefixProducts[n - 1] / prefixProducts[n - 1 - k];
    }
};
