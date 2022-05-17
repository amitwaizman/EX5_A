
#ifndef ORGCHART_A_ORGCHART_H
#define ORGCHART_A_ORGCHART_H
#include <string>
#include<vector>
#include <iostream>
using namespace std;
namespace ariel {
    class OrgChart {
    private:
        struct Node {
            char m_value;
            vector<Node *> vec;
        };
        Node *tree;
    public:
        OrgChart& add_root(string root);
        OrgChart& add_sub(string a, string b);
        friend ostream& operator<<(ostream &out, const OrgChart& it);

        class iterator_OC {
        private:
            Node *n;
        public:
            iterator_OC() {
                this->n= nullptr;
            }

            bool operator!=(const iterator_OC &it) const {
                return false;
            }

            bool operator==(const iterator_OC &it) const {
                return false;
            }

            iterator_OC operator++(int) {
                iterator_OC iter = *this;
                return iter;
            }

            iterator_OC &operator++() {
                return *this;
            }

            friend ostream& operator<<(ostream &out, const iterator_OC& it){
                return out;
            }



            string *operator->() const {
                return nullptr;
            }

            string operator*() const {
                return "";
            }

        };
        iterator_OC begin_level_order();

        iterator_OC end_level_order();

        iterator_OC begin_reverse_order();

        iterator_OC reverse_order();

        iterator_OC begin_preorder();

        iterator_OC end_preorder();

            string *begin();

            string *end();
    };
}
#endif //ORGCHART_A_ORGCHART_H
