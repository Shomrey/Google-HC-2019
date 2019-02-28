#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Zdjecie{
    public:
    Zdjecie(char orient, int no_of_tags);
    int pobierz_id()    {return id_zdj;}
    private:
    int id_zdj;
    vector<string> tags;
    int ilosc_tagow;
    char orientacja;

    
};

Zdjecie::Zdjecie(char orient, int no_of_tags): orientacja(orient), ilosc_tagow(no_of_tags){}

class Slajd {
    public:
    Slajd();
    private:
    vector<Zdjecie> zdjecia;


};
int main(int argc, char* argv[]) {
    vector<Zdjecie> wczytane_zdjecia;
    int ilosc_zdjec = 0, it = 0, no_of_tags = 0;
    char orient;
    vector<string> tagi;
    string tag;
    cin >> ilosc_zdjec;
    while(it<ilosc_zdjec){
        tagi.clear();
        cin >> orient;
        cin >> no_of_tags;
        Zdjecie zdj(orient,no_of_tags);
        
        it++;
    }
    return 0;
}