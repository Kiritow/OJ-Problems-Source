#include<iostream>
#include<stdio.h>
#include<list>
using namespace std;
class Bookshelf; 
class Book{
public:
    Book(int _id,int _width):id(_id),width(_width){}
    int id,width;
    friend class Bookshelf;
};
class Bookshelf{
public:
    Bookshelf(int w):width(w){
        occupied_width=0;
    }
    void add(const Book &book){
        shelf.push_front(book);
        occupied_width += book.width;
        while(occupied_width>width){
            occupied_width -= (shelf.back()).width;
            shelf.pop_back();
        } 
    }
    void remove(const int &id){
        list<Book>::iterator i;
        for(i=shelf.begin();i!=shelf.end();i++){
            if(i->id == id) break;
        }
        if(i==shelf.end()) return;
        occupied_width -= i->width;
        shelf.erase(i);
    }
    friend ostream& operator<<(ostream &out,Bookshelf &bookshelf);
private:
    list<Book> shelf;
    int width;
    int occupied_width;
};
ostream& operator<<(ostream &out, Bookshelf &bookshelf)
{
    list<Book>::iterator i;
    for(i=(bookshelf.shelf).begin();i!=(bookshelf.shelf).end();i++)
        out<<" "<<i->id;
    return out;
}
int main()
{
    int width;
    int p=1;
    char cmd;
    while(cin>>width,width!=-1)
    {
        Bookshelf bookshelf(width);
        int id,w;
        while(cin>>cmd)
        {
            if(cmd=='E') break;
            else if(cmd=='R')
            {
                cin>>id;
                bookshelf.remove(id);
            }else
            {
                cin>>id>>w;
                bookshelf.add(Book(id,w));
            }
        }
        cout<<"PROBLEM "<<p++<<":"<<bookshelf<<endl;
    }
    return 0;
}
