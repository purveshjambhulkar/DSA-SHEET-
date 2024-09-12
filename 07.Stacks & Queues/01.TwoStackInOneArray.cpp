class twoStacks {
  public:
  
    int *arr;
    int n ; 
    int top1 , top2;

    twoStacks() {
        n = 100;
        arr = new int[n];
        top1 = -1;
        top2 = n/2;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        //check if stack is full
        if(top1 >=n/2){
            cout<<"Stack Overflow"<<endl;
            return;
        }else{
            top1++;
            arr[top1] = x;
        }
        
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        //check if stack is full
        if(top2 >= n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }else{
            top2++;
            arr[top2] = x;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        //check if stack is empty
        if(top1 == -1 ){
            // cout<<"Stack Underflow"<<endl;
            return -1;
        }else{
            int ans = arr[top1--];
            return ans;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        //check if the stack is empty
        if(top2 == n/2){
            return -1;
        }else{
            int ans = arr[top2--];
            return ans;
        }
    }
};