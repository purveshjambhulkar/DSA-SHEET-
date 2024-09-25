class MyStack {
public:
    queue<int> one;
    queue<int> two;

    MyStack() {
        
    }
    
    void push(int x) {
        one.push(x);
    }
    
    int pop() {
        while (one.size() > 1) {
            two.push(one.front());
            one.pop();
        }
        int topElement = one.front();
        one.pop();

        while (!two.empty()) {
            one.push(two.front());
            two.pop();
        }

        return topElement;
    }
    
    int top() {
        while (one.size() > 1) {
            two.push(one.front());
            one.pop();
        }
        int topElement = one.front();
        one.pop();
        two.push(topElement);

        while (!two.empty()) {
            one.push(two.front());
            two.pop();
        }

        return topElement;
    }
    
    bool empty() {
        return one.empty();
    }
};
