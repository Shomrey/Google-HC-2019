#include <iostream>
#include <vector>
#include <string>
#include "Components.hpp"

using namespace std;

vector<Photo> load_photos(int no_of_photos){
    vector<Photo> loaded_photos;
    int it = 0, no_of_tags = 0;
    char orient;
    vector<string> tags;
    string tag;
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
    return loaded_photos;
}

int main(int argc, char* argv[]) {
    
    int no_of_photos = 0, it = 0, no_of_tags = 0;
    
    cin >> no_of_photos;
    vector<Photo> loaded_photos = load_photos(no_of_photos);
    for(auto photo : loaded_photos) photo.show_photo();
    return 0;
}