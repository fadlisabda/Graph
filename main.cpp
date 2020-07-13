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
    public://diakses secara public.
        vertex** addvertex;//variabel ini akan menjadi objek untuk tiap vertex yang dibuat didalam graph.
        int **add_jacent;//menghubungkan dua vertex yang saling terhubung.
        void Addvertex(char a);//tiap vertex yang dibuat akan diinputkan difungsi main().
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
            int nvert;//untuk mengetahui jumlah vertex yang akan dibuat.
            void DFS_search(vertex *v,int j);
};

void graph::Addvertex(char a){//membuat vertex yang diinginkan.
    addvertex[nvert++]=new vertex(a);//menginputkan vertex char a kedalam array vertex **Addvertex.
    //int nvert++ akan menunjukkan indeks dari array tersebut.
}

void graph::addedge(int st,int end){//menghubungkan vertex-vertex yang ada berdasarkan indeksnya.
    //nilai array dibuat sama antara vertex asal dan vertex tujuan.
    //hal ini dikarenakan graph yang dibuat adalah blind search.
    add_jacent[st][end]=1;
    add_jacent[end][st]=1;
}

void graph::display(int v){//menampilkan vertex dari hasil penelusuran algoritma DFS yang dibuat.
    //menampilkan vertex yang diinginkan dengan memanggil variabel addvertex
    //dengan menggunakan nilai integer dari argument inputan
    cout<<addvertex[v]->lab<<" ";
}

void graph::DFS(){//untuk menjalankan algoritma DFS
    //mengondisikan semua vertex ke dalam keadaan awal(belum ditelusuri)
    cout<<"Pencarian jalur dengan metode DFS :"<<endl;
    for (int i = 0; i < nvert; i++)
    {
        addvertex[i]->condition=false;//kondisi
        addvertex[i]->parent=NULL;//keadaan awal
    }
    for (int j = 0; j < nvert; j++)//pemanggilan ini dilakukan secara terus-menerus mulai dari vertex awal sampai vertex terakhir
    {
        if (addvertex[j]->condition == false)//jika vertex belum ditelusuri
        {
            DFS_search(addvertex[j],j);//proses penelusuran dimulai dengan memanggil method 
        }
    }
}

void graph::DFS_search(vertex*vert,int index){//melakukan penelusuran terhadap seluruh vertex yang berdekatan dengannya
    //untuk menelusuri seluruh rangkaian vertex yang ada
    vert->condition=true;
    display(index);
    for (int i = 0; i < nvert; i++)//sampai variabel boolean condition pada seluruh vertex bernilai true artinya vertex tersebut telah dilewati atau ditelusuri
    {
        if((add_jacent[index][i]==1)&&(addvertex[i]->condition == false))
        {
            addvertex[i]->parent=vert;
            DFS_search(addvertex[i],i);//melakukan rekursif
        }
    }
}

int main(){
    graph *a=new graph();
    a->Addvertex('A');//0
    a->Addvertex('B');//1
    a->Addvertex('C');//2
    a->Addvertex('D');//3
    a->Addvertex('E');//4
    a->Addvertex('F');//5
    a->Addvertex('G');//6
    a->Addvertex('H');//7
    a->Addvertex('I');//8
    a->Addvertex('J');//9
    a->Addvertex('K');//10
    
    a->addedge(0,1);//AB
    a->addedge(0,2);//AC    
    a->addedge(1,3);//BD
    a->addedge(1,4);//BE
    a->addedge(2,5);//CF
    a->addedge(2,6);//CG
    a->addedge(3,7);//DH
    a->addedge(3,8);//DI
    a->addedge(4,9);//EJ
    a->addedge(5,10);//FK

    a->DFS();
    cout<<endl;
    cout<<endl;
    cout<<"Hasil Pencarian DFS"<<endl;
    return 0;
}