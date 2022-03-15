 #include <iostream>
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int x;
    char a[33] = { 'а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я' };
   for (int key = 0; key < 33; key++) {
        cout << "--- " << key << " ---";
        ifstream file("translate.txt");
        while (!file.eof())
        {
            char c;
            file.get(c);
            if (c != ' ') {
                for (int i = 0; i < 33; i++) {
                    if (a[i] == c) {
                        x = i + key;
                        if (x > 32) {
                            x -= 33;
                        }
                        cout << a[x];
                    }
                }
            }
            else {
                cout << ' ';
            }
        }
        file.close();
        cout << "\n";
    }
    ifstream file("translate.txt");
    int key = 0;
   cout << "введите ключ: ";
    cin >> key;
    ofstream out("orig.txt");
    while (!file.eof())
    {
        char c;
        file.get(c);
    
        if (c != ' ') {
            for (int i = 0; i < 33; i++) {
                if (a[i] == c) {        
                    out << a[i - key];              
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

