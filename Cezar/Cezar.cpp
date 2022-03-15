

#include <iostream>
#include <fstream>

#include <cstdio>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int key = 0;
    char a[33] = { 'а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я'};
    ifstream file("cppstudio.txt");
  /* while (!file.eof())
    {
        char c;
        file.get(c);
        cout << c << "\n";
        if (c != ' ') count++;
    }
    cout << count-1 <<"\n";*/

    cout << "введите ключ: ";
    cin >> key;
    int x;
    ofstream out("translate.txt");
    while (!file.eof())
    {
        char c;
        file.get(c);
        cout << c << "-";
        if (c != ' ') {
            for (int i = 0; i < 33; i++) {
                if (a[i] == c) {
                    x = i + key;
                    if (x > 33) {
                        x -= 33;
                    }
                    out << a[x];
                    cout << a[x] << "\n";
                }
            }
        }
        else {
            out << ' ';
        }
    }
        file.close();
        out.close();
    system("pause");
    return 0;

}

