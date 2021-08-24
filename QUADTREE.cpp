#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& it) {
    char head = *(it++);

    if (head == 'b' || head == 'w')
        return string(1, head);

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void)
{
    int C;
    cin >> C;

    while(C--)
    {
        string picture;
        cin >> picture;

        string::iterator it = picture.begin();
        cout << reverse(it) << endl;
    }
    return 0;
}