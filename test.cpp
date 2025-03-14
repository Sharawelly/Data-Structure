#include <bits/stdc++.h>
#include <string>
using namespace std;


int main() {
    string str1, str2;
    getline(cin, str1);
    stringstream stringStream  (str1);
    stack<string >st;
    while (stringStream >> str2) {
        double res1 = 0, res2 = 0;
        int counter = 0;
        if (str2 >= "A" && str2 <= "z" && str2 != "s" && str2 != "S" && str2 != "p" && str2 != "P" && str2 != "e"){
            cout << "Wrong Description";
            return 0;
        }
        if (str2 == "e"){
            while (st.top() != "s" && st.top() != "S" && st.top() != "p" && st.top() != "P"){
                counter++;
                res1 += stod(st.top());
                res2 += 1 / stod(st.top());
                st.pop();
            }
            if (st.top() == "s" || st.top() == "S"){
                if (counter < 1){
                    cout << "Incorrect Input";
                    return 0;
                }
                st.pop();
                st.push(to_string(res1));
            }
            else if (st.top() == "p" || st.top() == "P"){
                if (counter < 2){
                    cout << "Incorrect Input";
                    return 0;
                }
                st.pop();
                st.push(to_string(1 / res2));
            }
        }
        else
            st.push(str2);
    }

    int num1 = stoi(st.top());
    double num2 = stod(st.top());
    cout << "The total resistance = " << ((num2 - num1 == 0)?  num1 : num2);


}