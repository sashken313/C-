#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    int count = 0;
    int key_count = 0;
    string key;
    cout << "введите ключ: ";
    cin >> key;
    int co = 0;
    int m = 0; int y = 0;
    ofstream out("translate.txt");
    ifstream file("cppstudio.txt");
    char Words[33] = { 'а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я' };
    while (!file.eof())
    {
        char c;
        file.get(c);
        cout << c <<'-';
        if (c != ' ') {

            if (key_count >= key.length())
                key_count = 0;
            for (int j = 0; j < 33; j++)
            {
                if (c == Words[j])
                {
                    m = j;
                    cout << m<<"--";
                }
            }

            for (int j = key_count; j < key.length(); j++)
            {
                for (int j2 = 0; j2 < 33; j2++)
                {
                    if (key[j] == Words[j2])
                    {
                        y = j2;
                        cout << y << "---";
                        break;
                    }
                }
                break;
            }

            co = ((m+y+1) % abs(33));
            out << Words[co];
            cout << Words[co]<<"\n";
            key_count++;
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