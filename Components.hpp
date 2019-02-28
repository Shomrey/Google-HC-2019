#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <iostream>
#include <string>
#include <vector>

class Photo{
public:

    Photo(int id, char orient, int no_of_tags, std::vector<std::string> tags): photo_id(id), orientation(orient), no_of_tags(no_of_tags), tags(tags){};
    int get_id()    {return photo_id;};
    char get_orientation() {return orientation;};
    void show_photo() {std::cout<<"id: "<<photo_id<<", no_of_tags: "<<no_of_tags<<std::endl<<"tags: "; for(auto tag : tags) std::cout<<tag<<", ";std::cout<<std::endl;};
    int get_num_of_tags(){ return no_of_tags;}
    std::vector<std::string> get_tags(){ return tags;}
    
private:

    int photo_id;
    std::vector<std::string> tags;
    int no_of_tags;
    char orientation;


};

class Slide {
public:
    void add_photo(Photo photo) {photos.push_back(photo);};
    std::vector<Photo> get_photos() {return photos;};
    void show_slide() {std::cout<<"Next slide"<<std::endl;for(auto photo: photos) photo.show_photo();}
private:
    std::vector<Photo> photos;
};

#endif//COMPONENTS_H

