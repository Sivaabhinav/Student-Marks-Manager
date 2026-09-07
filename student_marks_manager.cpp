#include <iostream>
using namespace std;

class Student {
    int id[10], mark[10], n=0;
    string name[10];

public:
    void add(int a,string b,int c) {
        id[n]=a; name[n]=b; mark[n++]=c;
    }

    void insert(int p,int a,string b,int c) {
        if(p<1 || p>n+1) { cout<<"Invalid position\n"; return; }
        for(int i=n;i>=p;i--) {
            id[i]=id[i-1]; name[i]=name[i-1]; mark[i]=mark[i-1];
        }
        id[p-1]=a; name[p-1]=b; mark[p-1]=c; n++;
    }

    void del(int p) {
        if(p<1 || p>n) { cout<<"Invalid position\n"; return; }
        for(int i=p-1;i<n-1;i++) {
            id[i]=id[i+1]; name[i]=name[i+1]; mark[i]=mark[i+1];
        }
        n--;
    }

    void search(int a) {
        for(int i=0;i<n;i++)
            if(id[i]==a) {
                cout<<id[i]<<" "<<name[i]<<" "<<mark[i]<<endl;
                return;
            }
        cout<<"Not found\n";
    }

    void display() {
        for(int i=0;i<n;i++)
            cout<<id[i]<<" "<<name[i]<<" "<<mark[i]<<endl;
    }

    void highest() {
        int m=mark[0];
        for(int i=1;i<n;i++)
            if(mark[i]>m) m=mark[i];
        cout<<"Highest = "<<m<<endl;
    }

    void average() {
        int sum=0;
        for(int i=0;i<n;i++) sum+=mark[i];
        cout<<"Average = "<<(float)sum/n<<endl;
    }
};

int main() {
    Student s;

    s.add(101,"Sadie",75);
    s.add(102,"Billie",85);
    s.add(103,"Maddison",90);

    s.insert(2,104,"Olivia",80);
    s.del(3);
    s.search(103);
    s.display();
    s.highest();
    s.average();

    return 0;
}
