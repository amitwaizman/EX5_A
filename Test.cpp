#include "sources/OrgChart.hpp"
#include "doctest.h"
#include <string>
#include <algorithm>
using namespace ariel;
using namespace std;

string nospaces(string input) {
        std::erase(input, ' ');
        std::erase(input, '\t');
        std::erase(input, '\n');
        std::erase(input, '\r');
        return input;
    }

TEST_CASE("Good input") {
    OrgChart organization;
   CHECK_NOTHROW( organization.add_root("CEO").add_sub("CEO", "CTO").add_sub("CEO", "CFO").add_sub("CEO", "COO").add_sub("CTO", "VP_SW").add_sub("COO", "VP_BI"));
    SUBCASE("level_order"){
    string ans="";
    string ans2="CEO CTO CFO COO VP_SW VP_BI";
      for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
      ans+= (*it);
  }
CHECK((nospaces(ans)==nospaces(ans2))==true);
  }

SUBCASE("level_order-reverse_order"){
string ans="";
string ans2="VP_SW VP_BI CTO CFO COO CEO";
for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
  {
ans+= (*it) ;
 }
CHECK((nospaces(ans)==nospaces(ans2))==true);
}

SUBCASE("begin_preorder-end_preorder"){
string ans="";
string ans2="CEO CTO VP_SW CFO COO VP_BI";
  for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
ans+= (*it);
  }
CHECK((nospaces(ans)==nospaces(ans2))==true);
}

SUBCASE("organization"){
string ans="";
string ans2="CEO CTO CFO COO VP_SW VP_BI";
  for (auto element : organization)
  {
    ans+= element ;
  }
CHECK((nospaces(ans)==nospaces(ans2))==true);
}

SUBCASE("size"){
string ans="";
string ans2=" 3 3 3 3 5 5";
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
ans+=  it->size();
  }
CHECK((nospaces(ans)==nospaces(ans2))==true);
}


}

TEST_CASE("Bad input") {
    OrgChart organization;
    OrgChart organization1;
    OrgChart organization2;
    OrgChart organization3;
    CHECK_NOTHROW( organization.add_root("CEO").add_sub("CEO", "CTO").add_sub("CEO", "CFO").add_sub("CEO", "COO").add_sub("CTO", "VP_SW").add_sub("COO", "VP_BI"));
SUBCASE("not exit root"){
CHECK_THROWS(organization1.add_sub("CEO", "CTO"));
CHECK_THROWS(organization2.add_sub("CEO", "CTO"));
CHECK_THROWS(organization3.add_sub("CEO", "CTO"));
    }

SUBCASE("Not GoodL-Level_order") {
        string ans = "";
        string ans2 = "VP_SW CTO CFO COO VP_SW VP_BI CEO";
        for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {
            ans += (*it);
        }
                CHECK_FALSE((nospaces(ans) == nospaces(ans2)) == true);

// ans="";
 ans2="CTO  VP_BI CEO";
for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
ans+= (*it);
}
                CHECK_FALSE((nospaces(ans)==nospaces(ans2))==true);

ans="";
ans2="CEO";
for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
ans+= (*it);
}
                CHECK_FALSE((nospaces(ans)==nospaces(ans2))==true);
}


SUBCASE("Not Good-level_order-reverse_order"){
string ans="";
string ans2="VP_BI CTO CFO COO CEO";
for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
{
ans+= (*it) ;
}
                CHECK_FALSE((nospaces(ans)==nospaces(ans2))==true);

 ans="";
 ans2="CTO VP_BI CFO COO CEO";
for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
{
ans+= (*it) ;
}
                CHECK_FALSE((nospaces(ans)==nospaces(ans2))==true);
}

SUBCASE("not good-begin_preorder()-end_preorder()"){
string ans="";
string ans2="CEO CTO VP_SW CFO COO VP_BI";
for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
ans+= (*it);
}
                CHECK_FALSE((nospaces(ans)==nospaces(ans2))==true);

 ans="";
 ans2="CEO CTO  CFO COO VP_BI";
for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
ans+= (*it);
}
                CHECK_FALSE((nospaces(ans)==nospaces(ans2))==true);

ans="";
ans2="CEO CTO";
for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
ans+= (*it);
}
                CHECK_FALSE((nospaces(ans)==nospaces(ans2))==true);


ans="";
ans2="amit CTO";
for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
ans+= (*it);
}
                CHECK_FALSE((nospaces(ans)==nospaces(ans2))==true);
}

SUBCASE("Not Good- size"){
string ans="";
string ans2=" 85 44 3 3 5 5";
for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
{
ans+=  it->size();
}
CHECK_FALSE((nospaces(ans)==nospaces(ans2))==true);

 ans="";
 ans2=" 8 5 5";
for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
{
    ans+=  it->size();
}
CHECK_FALSE((nospaces(ans) == nospaces(ans2)) == true);
}
SUBCASE("not god"){
        string ans;
        string ans2="CEO CTO";
        for (auto element : organization)
        { // this should work like level order
            ans+=element;
        }
                CHECK_FALSE((nospaces(ans)==nospaces(ans2))==true);

    }

}