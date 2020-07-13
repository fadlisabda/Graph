#include <iostream>
using namespace std;

class vertex{//akan digunakan sebagai representasi objek vertex atau node didalam sebuah graph.
    public:
        char lab;//karakter nama dari vertex yang bersangkutan.
        bool condition;//berfungsi untuk mengetahui apakah vertex tersebut telah di telusuri ataukah tidak.
        vertex *parent;//digunakan untuk menelusuri alamat vertex yang belum dilewati.

        vertex(char l){//nantinya akan digunakan ketika tiap vertex dibuat di dalam class graph.
            lab=l;
        }

};

int main(){
    
    return 0;
}