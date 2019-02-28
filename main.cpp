#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Components.hpp"

using namespace std;
int min_value(Photo from, Photo to);

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
        if(photo.get_orientation() == 'H') horizontal.push_back(photo);
        else vertical.push_back(photo);
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

int get_tag_number(vector<string> p1,vector<string> p2)
{
    int number =0;
    for(auto tag1: p1)
    {
        for(auto tag2:p2)
        {
            if(tag1.compare(tag2))
            {
                number++;
                break;
            }
        }
    }
    return number;
}

vector<Slide> merge_veritical(vector<Photo> vertical_photos)
{
    vector<Slide> mearged;
    cout<<"Here"<<endl;
    Photo photo_pom(-1,0,0,vector<string>());
    int no_of_tags_pom=0;
    cout<<"Here"<<endl;
    for(auto main_photo: vertical_photos)
    {
        cout<<"Here"<<endl;
        no_of_tags_pom =0;
        for(auto photo: vertical_photos)
        {
            if(main_photo.get_id() != photo.get_id())
            {
                if(no_of_tags_pom<get_tag_number(main_photo.get_tags(),photo.get_tags()))
                {
                    no_of_tags_pom = get_tag_number(main_photo.get_tags(),photo.get_tags());
                    photo_pom = photo;
                }
            }
        }
        if(photo_pom.get_id()!=-1)
        {
            cout<<"Here get id"<<endl;
            Slide slide;
            slide.add_photo(main_photo);
            slide.add_photo(photo_pom);
            mearged.push_back(slide);
        }
    }
}

int main(int argc, char* argv[]) {

    int no_of_photos = 0, it = 0, no_of_tags = 0;
    vector<Photo> horizontal_photos;
    vector<Photo> vertical_photos;
    vector<Slide> slides;
    cin >> no_of_photos;
    load_photos(no_of_photos, horizontal_photos, vertical_photos);

    // for(auto photo : horizontal_photos) photo.show_photo();

    // for(auto photo : vertical_photos) photo.show_photo();
    cout<<min_value(horizontal_photos[0], horizontal_photos[1]);
    for(auto photo : horizontal_photos){
        Slide new_slide;
        new_slide.add_photo(photo);
        slides.push_back(new_slide);
    }
    print_to_file(slides);
    return 0;
}
//returns value of edge from 'from' to 'to'
int min_value(Photo from, Photo to)
{
    int uniqueFrom = from.get_num_of_tags();
    int uniqueTo = to.get_num_of_tags();
    int similar = 0;
    vector<string> fromTags = from.get_tags();
    vector<string> toTags = to.get_tags();
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