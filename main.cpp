#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Components.hpp"

using namespace std;

void load_photos(int no_of_photos, vector<Photo>& horizontal, vector<Photo>& vertical){
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
        if(photo.get_orientation() == 'H'){
            cout<<"Pushed h"<<endl;
            horizontal.push_back(photo);
        }
        else{
            cout<<"Pushed v"<<endl;
            vertical.push_back(photo);
        }
        it++;
    }
}

void print_to_file(vector<Slide> slides){
    fstream fs;
    fs.open("output.txt",fstream::out);
    fs << slides.size() << "\n";
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
    // for(auto photo : vertical_photos) photo.show_photo();
    // for(auto photo : horizontal_photos) photo.show_photo();
    // vector<Slide> slides;
    // Slide slide1, slide2;
    // slide1.add_photo(horizontal_photos[0]);
    // slide2.add_photo(vertical_photos[0]);
    // slide2.add_photo(vertical_photos[1]);
    // slides.push_back(slide1);
    // slides.push_back(slide2);
    // print_to_file(slides);
    return 0;
}