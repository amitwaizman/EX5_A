#include "OrgChart.hpp"
 using namespace ariel;
 using namespace std;

     OrgChart& OrgChart::add_root(string root) {
         return *this;
     }

     OrgChart& OrgChart::add_sub( string str1,  string str2) {
         return *this;
     }


     ostream&  ariel::operator<<(ostream &out, const OrgChart &it) {
         return out;
     }


    OrgChart::iterator_OC OrgChart:: end_level_order() {
         return OrgChart::iterator_OC();

     }

   OrgChart::iterator_OC OrgChart:: begin_level_order() {
         return OrgChart::iterator_OC();

     }

OrgChart::iterator_OC OrgChart:: begin_reverse_order() {
         return OrgChart::iterator_OC();

     }

OrgChart::iterator_OC OrgChart:: reverse_order() {
         return OrgChart::iterator_OC();

     }


OrgChart::iterator_OC OrgChart:: begin_preorder() {
         return OrgChart::iterator_OC();

     }

OrgChart::iterator_OC OrgChart:: end_preorder() {
         return OrgChart::iterator_OC();
     }

string* OrgChart::begin() {
    string *index;
    return index;

}
string* OrgChart::end() {
    string *index;
    return index;

}

