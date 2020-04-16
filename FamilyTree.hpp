#pragma once
#include <iostream>
#include <string>
#include<exception>
#include<vector>
using std::string;
using namespace std;

namespace family
{
    class Tree
    {
        private:
            string data;
            Tree* father;
            Tree* mother;
            string gender;
            string child;
            Tree* search(string child);
            int level(Tree *node,string data, int level);
            Tree* findRelate(Tree* t,string relate);
            void displayTree(const std::string& prefix, Tree* node, bool isLeft);
            void my_delete(Tree*);
        public:
            Tree(string s);
            Tree& addFather(string child, string father);
            Tree& addMother(string child, string mother);
            string relation(string relate);
            string find(string name);
            void display();
            string remove(string name);
    };
};