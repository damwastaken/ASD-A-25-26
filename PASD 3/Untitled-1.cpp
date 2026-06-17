#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:

    Stack()
    {
        top = NULL;
    }

    bool kosong()
    {
        return top == NULL;
    }

    void push(char x)
    {
        Node *baru = new Node;

        baru->data = x;
        baru->next = top;

        top = baru;
    }

    char pop()
    {
        if(kosong())
        {
            return '-';
        }

        Node *hapus = top;

        char ambil = hapus->data;

        top = top->next;

        delete hapus;

        return ambil;
    }

    void tampil()
    {
        Node *bantu = top;

        cout << "\nTOP\n";
        cout << " |\n";
        cout << " V\n";

        while(bantu != NULL)
        {
            cout << "| " << bantu->data << " |\n";

            bantu = bantu->next;
        }

        cout << "--------\n";
    }

    void resetABC()
    {
        while(!kosong())
        {
            pop();
        }

        // TOP -> C -> B -> A

        push('A');
        push('B');
        push('C');
    }
};

int main()
{
    Stack s, bantu;

    // ===============================
    // A. Masukkan D setelah A
    // ===============================

    s.resetABC();

    cout << "====================================\n";
    cout << "A. Memasukkan D setelah A\n";
    cout << "====================================\n";

    cout << "\nKeadaan awal:\n";
    s.tampil();

    cin.get();

    while(!s.kosong())
    {
        bantu.push(s.pop());
    }

    s.push('D');

    while(!bantu.kosong())
    {
        s.push(bantu.pop());
    }

    cout << "\nHasil:\n";
    s.tampil();

    cout << "\nTekan ENTER untuk lanjut...";
    cin.get();



    // ===============================
    // B. Masukkan E setelah B
    // ===============================

    s.resetABC();

    cout << "\n====================================\n";
    cout << "B. Memasukkan E setelah B\n";
    cout << "====================================\n";

    cout << "\nKeadaan awal:\n";
    s.tampil();

    // Ambil C
    bantu.push(s.pop());

    // Ambil B
    bantu.push(s.pop());

    s.push('E');

    while(!bantu.kosong())
    {
        s.push(bantu.pop());
    }

    cout << "\nHasil:\n";
    s.tampil();

    cout << "\nTekan ENTER untuk lanjut...";
    cin.get();



    // ===============================
    // C. Masukkan F paling bawah
    //    A,B,C hilang
    // ===============================

    s.resetABC();

    cout << "\n====================================\n";
    cout << "C. Memasukkan F paling bawah\n";
    cout << "   (A,B,C hilang)\n";
    cout << "====================================\n";

    cout << "\nKeadaan awal:\n";
    s.tampil();

    while(!s.kosong())
    {
        s.pop();
    }

    s.push('F');

    cout << "\nHasil:\n";
    s.tampil();

    cout << "\nTekan ENTER untuk lanjut...";
    cin.get();



    // ===============================
    // D. Masukkan F paling bawah
    //    A,B,C tetap ada
    // ===============================

    s.resetABC();

    cout << "\n====================================\n";
    cout << "D. Memasukkan F paling bawah\n";
    cout << "   (A,B,C tetap ada)\n";
    cout << "====================================\n";

    cout << "\nKeadaan awal:\n";
    s.tampil();

    while(!s.kosong())
    {
        bantu.push(s.pop());
    }

    s.push('F');

    while(!bantu.kosong())
    {
        s.push(bantu.pop());
    }

    cout << "\nHasil:\n";
    s.tampil();

    cout << "\nProgram selesai\n";

    return 0;
}