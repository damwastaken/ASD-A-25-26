#include <iostream>
using namespace std;

class Stack
{
    public:
        int data[10];
        int top;

        Stack()
        {
            top = -1;
        }

        // PUSH
        void push(int nilai)
        {
            top++;
            data[top] = nilai;
        }

        // POP
        int pop()
        {
            int ambil = data[top];
            top--;

            return ambil;
        }

        // Menampilkan isi stack
        void tampil(string nama)
        {
            cout << "\n" << nama << endl;
            cout << "-----------------" << endl;

            if(top == -1)
            {
                cout << "(Kosong)" << endl;
            }
            else
            {
                for(int i = top; i >= 0; i--)
                {
                    cout << "|  " << data[i] << "  |" << endl;
                }
            }

            cout << "-----------------" << endl;
        }
};

int main()
{
    Stack tumpukan1;
    Stack tumpukan2;
    Stack tumpukan3;

    // Isi awal sesuai gambar
    tumpukan1.push(3);
    tumpukan1.push(2);
    tumpukan1.push(1);

    int pilihan;
    int pindah;

    do
    {
        cout << "\n===================================" << endl;
        cout << "         PROGRAM STACK             " << endl;
        cout << "===================================" << endl;

        tumpukan1.tampil("TUMPUKAN 1");
        tumpukan2.tampil("TUMPUKAN 2");
        tumpukan3.tampil("TUMPUKAN 3");

        cout << "\nMenu :" << endl;
        cout << "1. Pindah Tumpukan 1 -> 2" << endl;
        cout << "2. Pindah Tumpukan 1 -> 3" << endl;
        cout << "3. Pindah Tumpukan 2 -> 1" << endl;
        cout << "4. Pindah Tumpukan 2 -> 3" << endl;
        cout << "5. Pindah Tumpukan 3 -> 1" << endl;
        cout << "6. Pindah Tumpukan 3 -> 2" << endl;
        cout << "7. Exit" << endl;

        cout << "Pilihan : ";
        cin >> pilihan;

        switch(pilihan)
        {
            case 1:

                if(tumpukan1.top != -1)
                {
                    pindah = tumpukan1.pop();
                    tumpukan2.push(pindah);
                }
                else
                {
                    cout << "Tumpukan 1 kosong!" << endl;
                }

                break;

            case 2:

                if(tumpukan1.top != -1)
                {
                    pindah = tumpukan1.pop();
                    tumpukan3.push(pindah);
                }
                else
                {
                    cout << "Tumpukan 1 kosong!" << endl;
                }

                break;

            case 3:

                if(tumpukan2.top != -1)
                {
                    pindah = tumpukan2.pop();
                    tumpukan1.push(pindah);
                }
                else
                {
                    cout << "Tumpukan 2 kosong!" << endl;
                }

                break;

            case 4:

                if(tumpukan2.top != -1)
                {
                    pindah = tumpukan2.pop();
                    tumpukan3.push(pindah);
                }
                else
                {
                    cout << "Tumpukan 2 kosong!" << endl;
                }

                break;

            case 5:

                if(tumpukan3.top != -1)
                {
                    pindah = tumpukan3.pop();
                    tumpukan1.push(pindah);
                }
                else
                {
                    cout << "Tumpukan 3 kosong!" << endl;
                }

                break;

            case 6:

                if(tumpukan3.top != -1)
                {
                    pindah = tumpukan3.pop();
                    tumpukan2.push(pindah);
                }
                else
                {
                    cout << "Tumpukan 3 kosong!" << endl;
                }

                break;

            case 7:
                cout << "Program Selesai" << endl;
                break;

            default:
                cout << "Pilihan Salah!" << endl;
        }

    } while(pilihan != 7);

    return 0;
}