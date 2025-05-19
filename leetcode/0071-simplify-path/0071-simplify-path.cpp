class Solution {
public:
    string simplifyPath(string path) {
        // canonical - 표준적인
        // . -> current, .. -> prev.
        // path 는 valid absolute unix path 임.(1로시작함.)
        
        int start = 0, end = 0;
        stack<string> can; //candidates
        while (start != string::npos) {
            end = path.find("/", start + 1); // 없음.
            int len = end == string::npos? end : end - start - 1;
            string cur = path.substr(start + 1, len);
            if (cur == "..") {
                if (!can.empty()){
                    can.pop();
                }
            } else if (cur != "." && cur != ""){
                can.push(cur);
            }
            start = end;
        }

        string res = "";
        if (can.empty()) return "/";
        while (!can.empty()) {
            string s = can.top();
            can.pop();
            res = ("/" + s + res);
        }
        return res;
    }
};