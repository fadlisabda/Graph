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

class graph{//berfungsi untuk merepresentasikan fungsi-fungsi yang dibuat untuk membangun sebuah DFS graph.
    public://diakses secara public
        vertex** addvertex;//variabel ini akan menjadi objek untuk tiap vertex yang dibuat didalam graph
        int **add_jacent;//menghubungkan dua vertex yang saling terhubung
        void Addvertex(char a);
        void addedge(int st,int end);
        void DFS();

        graph(){//constructor graph yang akan aktif ketika objek graph nanti dipanggil didalam fungsi main().
            addvertex=new vertex*[20];
            add_jacent=new int*[20];
            for (int i = 0; i < 20; i++)
            {
                add_jacent[i]=new int[20];
                for (int j = 0; i < 20; i++)
                {
                    add_jacent[i][j]=0;
                }
            }
            nvert=0;
        }

        private:
            void display(int v);
            int nvert;//untuk mengetahui jumlah vertex yang akan dibuat
            void DFS_search(vertex *v,int j);
};

int main(){
       
    return 0;
}