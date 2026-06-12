class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;
        for(int i=0; i<operations.size(); i++) {
            if(operations[i] != "C" && operations[i] != "D" && operations[i] != "+") {
                st.push(stoi(operations[i]));
                sum += st.top();
            } else if(operations[i] == "+") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                sum += num1 + num2;
                st.push(num2);
                st.push(num1);
                st.push(num1 + num2);
            } else if(operations[i] == "C") {
                int rem = st.top();
                st.pop();
                sum -= rem;
            } else if(operations[i] == "D") {
                int num = st.top();
                st.push(2 * num);
                sum += 2 * num;
            } 
        }

        return sum;
    }
};