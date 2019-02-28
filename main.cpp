#include <iostream>
#include <vector>
#include <string>

using namespace std;
class zdjecie{

    int id_zdj;
    vector<string> tags;
    int ilosc_tagow;
    char orientacja;

    int pobierz_id()
    {
        return id_zdj;
    }
};

class slajd {

    vector<zdjecie> zdjecia;


};
int main() {
    std::cout << "Hello, World!" <<f()<< std::endl;
    return 0;
}