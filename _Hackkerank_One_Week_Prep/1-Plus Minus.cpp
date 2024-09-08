// Problem Link: https://www.hackerrank.com/challenges/one-week-preparation-kit-plus-minus

void plusMinus(vector<int> arr) {
    int size = arr.size();
    int pos = 0;
    int neg = 0;
    int zer = 0;
    
    for(auto i : arr) {
        if(i == 0) zer++;
        else if(i > 0) pos++;
        else neg++;
    }
    
    cout << fixed << setprecision(6) << static_cast<double>(pos)/size << endl << static_cast<double>(neg)/size << endl << static_cast<double>(zer)/size;
}