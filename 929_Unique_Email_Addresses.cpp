class Solution {
public:

    string formatEmail(string emailAddress) {
        string email = "";
        bool found = false;
        int len = emailAddress.length();
        for(int i = 0; i < len; i++) {
            if (emailAddress[i] == '@') {
                email += emailAddress.substr(i);
                return email;
            } else if (!found){
                if (emailAddress[i] == '.') continue;
                else if(emailAddress[i] == '+') {
                    found = true;
                } else {
                    email += emailAddress[i];
                }
            }
        }
        assert(0);
    }

    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> visited;
        for(auto email : emails) {
            string formatedEmail = formatEmail(email);
            if (visited.find(formatedEmail) == visited.end()) {
                visited.insert(formatedEmail);
            }
        }
        return visited.size();
    }
};
