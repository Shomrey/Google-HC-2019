#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Photo{
public:

    Photo(int id, char orient, int no_of_tags, std::vector<std::string> tags): photo_id(id), orientation(orient), no_of_tags(no_of_tags), tags(tags){};
    Photo(const Photo& source); //cc-tor
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
Photo::Photo(const Photo& source){
    photo_id = source.photo_id;
    orientation = source.orientation;
    no_of_tags = source.no_of_tags;
    tags = source.tags;
}

int min_value(Slide from, Slide to)
{
    vector<string> fromTags = from.get_tags();
    vector<string> toTags = to.get_tags();
    int uniqueFrom = fromTags.size();
    int uniqueTo = toTags.size();
    int similar = 0;

    for(int i = 0; i < fromTags.size(); i++)
    {
        for(int j = 0; j < toTags.size(); j++)
        {
            if(fromTags[i] == toTags[j])
            {
                uniqueFrom--;
                uniqueTo--;
                similar++;
            }
        }
    }
    int result = min(min(uniqueFrom, uniqueTo),similar);
    return result;
}

class Slide {
public:
    void add_photo(Photo photo);
    std::vector<Photo> get_photos() {return photos;};
    std::vector<std::string> get_tags() {return tags_of_photos;};
    bool is_visited() {return visited;};
    void visit() {visited = true;};
private:
    bool visited = false;
    std::vector<Photo> photos;
    std::vector<std::string> tags_of_photos;
};

void Slide::add_photo(Photo photo){
    photos.push_back(photo);
    if(tags_of_photos.empty()){
        for(auto tag : photo.get_tags()) tags_of_photos.push_back(tag);
    }
    else{
        for(auto tag : photo.get_tags()) if(std::find(tags_of_photos.begin(),tags_of_photos.end(),tag)==tags_of_photos.end()) tags_of_photos.push_back(tag);
    }
}

class Graf{
public:
    Graf(){};
    std::vector<std::vector<int>> graphik;
    void make_graf(std::vector<Slide> & slides);
};

void Graf::make_graf(std::vector<Slide> & slides){
    for(int i = 0; i < slides.size()-1 ; i++)
    {
        for(int j = i + 1; j < slides.size(); j++)
        {
            int val = min_value(slides(i), slides(j));
            if(val != 0)
            {
                graphik[i].push_back(i);
                graphik[i].push_back(j);
                graphik[i].push_back(val);
                graphik[j].push_back(j);
                graphik[j].push_back(i);
                graphik[j].push_back(val);
            }
        }
    }
}


#endif//COMPONENTS_H