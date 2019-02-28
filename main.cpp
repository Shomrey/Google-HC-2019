#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Components.hpp"

using namespace std;

void load_photos(int no_of_photos, vector<Photo> horizontal, vector<Photo> vertical){
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
        if(photo.get_orientation() == 'H') horizontal.push_back(photo);
        else vertical.push_back(photo);
        it++;
    }
}

void print_to_file(vector<Slide> slides){
    fstream fs;
    fs.open("output.txt",fstream::app);
    fs << slides.size();
    for(auto slide: slides){
        for(auto photo : slide.get_photos()) fs << photo.get_id() << " ";
        fs << "\n";
    }
    fs.close();
}

int main(int argc, char* argv[]) {

    int no_of_photos = 0, it = 0, no_of_tags = 0;
    vector<Photo> horizontal_photos;
    vector<Photo> vertical_photos;

    cin >> no_of_photos;
    load_photos(no_of_photos, horizontal_photos, vertical_photos);

    for(auto photo : horizontal_photos) photo.show_photo();

    for(auto photo : vertical_photos) photo.show_photo();

    return 0;
}