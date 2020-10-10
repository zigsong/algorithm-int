// 8.6 와일드카드 문제를 해결하는 완전탐색 알고리즘

// input 
// 케이스의 수
// 패턴 (ex. he?p  he*p) w
// 파일 개수
// 파일명 s

// 와일드카드 패턴 w가 문자열 s에 대응되는지 여부를 반환한다.
bool match(const string& w, const string& s) {
    int pos = 0;
    // 문자열의 끝까지 탐색, 하나라도 거짓이면 안된다. 별 문제 없으면 pos 를 하나씩 올려간다.
    // ? 는 어느 문자가 와도 상관 없으니 그냥 ++pos 해도 된다. * 가 문제!
    while(pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) 
        ++pos;
    if(pos == w.size()) 
        return pos == s.size(); 
        // true of false 반환, w는 s와 길이가 같거나 더 짧다
        // w 가 끝났을 때 s 도 끝나면 길이가 같으므로 true 반환(일치한다!)

    // * 가 나왔을 때
    if(w[pos] == '*')
        // pos 는 그대로 두고 skip 을 0 부터 (s길이 - pos)까지 올려간다
        for(int skip = 0; pos+skip <= s.size(); ++skip)
            // 재귀 호출, skip 을 올려가며 
            // he*p
            // heaaap
            if(match(w.substr(pos+1), s.substr(pos+skip)))  // match 가 false 를 반환하면 다음 루프로
                return true;
    return false;
}