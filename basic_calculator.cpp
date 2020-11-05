class Solution {
public:

    int stringToInt(string str) {

        stringstream ss;
        ss << str;
        int ret = 0;
        ss >> ret;
        return ret;
    }

    string intToString(int num) {

        stringstream ss;
        ss << num;
        string ret;
        ss >> ret;
        return ret;
    }

    int calculate(string s) {

        string str;
        str.resize(5*s.length(), ' ');
        int ind = 0;
        str[ind++] = '(';
        str[ind++] = ' ';

        for(int i = 0; i < s.length(); i++) {
            if (!isdigit(s[i])) {
                // str = str + " " + s[i] + " ";
                str[ind++] = ' ';
                str[ind++] = s[i];
                str[ind++] = ' ';
            } else {
                // str = str + s[i];
                str[ind++] = s[i];
            }
        }
        str[ind++] = ' ';
        str[ind++] = ')';

        // str = str + " )";
        cout << str << endl;
        stringstream ss;
        ss << str;
        string tmp;
        stack<string> container;




        while(ss >> tmp) {
            // cout << tmp << " dfg" <<endl;
            if (tmp == "(") {
                container.push(tmp);
            } else if (tmp == ")") {
                if(container.size()) {
                    int ans = 0;
                    string pre = "";
                    while(container.top() != "(") {
                        string top = container.top();
                        // cout << top << endl;
                        container.pop();
                        if (top == "+") {
                            ans += stringToInt(pre);
                            pre = "";
                        } else if(top == "-") {
                            ans -= stringToInt(pre);
                            pre = "";
                        } else {
                            pre = top;
                        }
                    }
                    if (pre.length() > 0) {
                        ans += stringToInt(pre);
                        pre = "";
                    }
                    container.pop();
                    if (ans < 0) {
                        if (container.size() && container.top() == "+") {
                            container.pop();
                            container.push("-");
                        } else if (container.size() && container.top() == "-") {
                            container.pop();
                            container.push("+");
                        } else {
                            container.push("-");
                        }
                    }

                    container.push(intToString(abs(ans)));
                }
            } else {
                container.push(tmp);
            }
        }
        int ans = stringToInt(container.top());
        if (container.size() > 1) {
            return -ans;
        }

        return ans;
    }
};
