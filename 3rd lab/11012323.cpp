#include<cmath>
#include<vector>
#include<iostream>

using namespace std;

class Stack {
    public:
        Stack *next;
        int x;
        Stack();
        Stack(int a, Stack *n=0) {
            x = a;
            next = n;
        }
};

void pop(Stack *n, int& length) {
    if(n == 0)
        return;
    Stack *temp = n;
    n = n->next;
    length--;
}

void push(Stack *n, int x) {
    if(n == 0) {
        Stack *temp = new Stack(x);
        n = temp;
        return;
    }
    Stack *temp = new Stack(x);
    temp = n->next;
    n = temp;
}

void print(Stack *n) {
    Stack *temp = n;
    while(temp) {
        cout << temp->x << "->";
        temp = temp->next;
    }
    cout << "???" << endl;
}

void resize_stack(vector<Stack *> &st, int& length, int check) {
    int prev = st.size();
    if(check == 1) {
        st.resize((st.size() * 2));
        length *= 2;
    }
    else if(check == 2) {
        st.resize((st.size() / 2));
        length /= 2;
    }
}

bool power(int a) {
    double x = log10(a)/log10(2);
    if(x - floor(x) != 0)
        return false;
    else
        return true;
}

int main() {
    int length = 2, n, i = 0, ch = 5;
    vector<Stack *>st(length);
    st[0] = 0;

    while(ch) {
        cout << "\npress 1 for Push, ";
        cout << "press 2 for Pop,";
        cout << "press 0 for exit,";
        cout << "Enter choice:- ";
        cin >> ch;

        if(ch == 1) {
            if(i >= length-1) {
                resize_stack(st, length, 1);
                cout << "\n New stack size:- " << length << "\n\n";
            }
            cout << "Enter number:- ";
            cin >> n;
            st[i+1] = new Stack(n, st[i]);
            i++;
            print(st[i]);
        }
        else if(ch == 2) {
            if(i == 0) {
                cout << "UNDERFLOW\n";
            }
            else {
                if(power(i)) {
                    pop(st[i], i);
                    resize_stack(st, length, 2);
                    cout << "\n New stack size: " << length << "\n\n";
                }
                else {
                    pop(st[i], i);
                }
                print(st[i]);
            }
        }
    }

    print(st[i]);
    return 0;
}