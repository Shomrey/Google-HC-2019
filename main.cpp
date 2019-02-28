#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Photo{
    public:
    Photo(int id, char orient, int no_of_tags, vector<string> tagi): photo_id(id), orientation(orient), no_of_tags(no_of_tags), tags(tagi){};
    int get_id()    {return photo_id;}
    void show_photo() {std::cout<<"id: "<<photo_id<<", no_of_tags: "<<no_of_tags<<std::endl<<"tags: "; for(auto tag : tags) std::cout<<tag<<", ";std::cout<<std::endl;};
    private:
    int photo_id;
    vector<string> tags;
    int no_of_tags;
    char orientation;

    
};

class Slide {
    public:
    void add_photo(Photo photo) {zdjecia.push_back(photo);};
    private:
    vector<Photo> zdjecia;
};

int main(int argc, char* argv[]) {
    vector<Photo> loaded_photos;
    int no_of_photos = 0, it = 0, no_of_tags = 0;
    char orient;
    vector<string> tags;
    string tag;
    cin >> no_of_photos;
    while(it<no_of_photos){
        tags.clear();
        cin >> orient;
        cin >> no_of_tags;
        for(int i = 0; i < no_of_tags; i++){
            cin >> tag;
            tags.push_back(tag);
        }
        Photo photo(it,orient,no_of_tags,tags);
        loaded_photos.push_back(photo);
        it++;
    }
    for(auto photo: loaded_photos) photo.show_photo();
    return 0;
}