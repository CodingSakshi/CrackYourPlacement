// Problem Link: https://www.hackerrank.com/challenges/one-week-preparation-kit-time-conversion

string timeConversion(string s) {
    string z = s.substr(8,2);
    string h = s.substr(0,2);
    string ans = "";
    
    if(z == "AM" && h == "12") {
        ans += "00";
    }
    else if(z == "PM" && h == "12") {
        ans += "12";
    }
    else if(z == "PM") {
        int x = stoi(h)+12;
        string nh = to_string(x);
        ans += nh;
    }
    else {
        ans += h;
    }
    
    string rem = s.substr(2, 6);
    ans += rem;
    return ans;
}