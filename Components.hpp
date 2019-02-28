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
    private:
    
    int photo_id;
    std::vector<std::string> tags;
    int no_of_tags;
    char orientation;

    
};

class Slide {
    public:
    void add_photo(Photo photo) {zdjecia.push_back(photo);};
    private:
    std::vector<Photo> zdjecia;
};

#endif//COMPONENTS_H