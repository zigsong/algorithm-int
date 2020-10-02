#include <iostream>
#include <string>
#include <vector>

bool match(const string& w, const string& s) {
    int pos = 0;
    while(pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) 
        ++pos;
    if(pos == w.size()) 
        return pos == s.size(); //true of false 반환
    
    if(w[pos] == '*')
        for(int skip = 0; pos+skip <= s.size(); ++skip)
            if(match(w.substr(pos+1), s.substr(pos+skip)))
                return true;
    return false;
}