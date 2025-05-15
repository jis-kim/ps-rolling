#include <iostream>
using namespace std;

int main(void) {
    int A, B, C;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> A >> B >> C;
    cout << (A+B)%C << '\n' << ((A%C)+(B%C))%C << '\n' << (A*B)%C << '\n' << ((A%C)*(B%C))%C;
}