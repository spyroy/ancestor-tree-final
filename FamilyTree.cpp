#include "FamilyTree.hpp"

using namespace family;

Tree::Tree(string name){
    this->data = name;
    this->father = this->mother = NULL;
    gender = "";
}

Tree* Tree::search(string child){   
    if(this == NULL){
        return NULL;
    }
    if(this->data == child){
        return this;
    }    
    Tree* go_mother = this->mother->search(child);
    Tree* go_father = this->father->search(child);
    if (go_mother != NULL)
        return go_mother;
    if (go_father != NULL)
        return go_father;
    return NULL;   
}

Tree& Tree::addFather(string child,string father){
    if(this->data == child)
    {
        if(this->father == NULL)
        {
            this->father = new Tree(father);
            this->father->gender = "male";
            this->father->child = this->data;
            return *this;
        }
        else
            throw exception("cant add father to: " + child);
    }
    Tree* found = search(child);
    if(found == NULL)
        throw ("no name "+child);
    if(found->father == NULL)
    {
        found->father = new Tree(father);
        found->father->gender = "male";
        found->father->child = found->data;
        return *this;
    }
    else
        throw exception("cant add father to: " + child);
}


Tree& Tree::addMother(string child,string mother){
    if(this->data == child)
    {
        if(this->mother == nullptr)
        {
            this->mother = new Tree(mother);
            this->mother->gender = "female";
            this->mother->child = this->data;
            return *this;
        }
        else
            throw ("cant add mother to: " + child);
    }
    else if(this->data != child)
    {
        Tree* found = search(child);
        if(found == nullptr)
            throw ("no name "+child);
        if(found->mother == nullptr)
        {
            found->mother = new Tree(mother);
            found->mother->gender = "female";
            found->mother->child = found->data;
            return *this;
        }
        else
            throw ("cant add mother to: " + child);
    }
    return *this;
}

//source: GeeksForGeeks
int Tree::level(Tree* root,string data, int level)
{
    if (root == NULL)
        return 0;

    if (root -> data == data)
        return level;

    int down = Tree::level(root->mother, data, (level + 1));
    if (down != 0)
        return down;

    down = Tree::level(root->father,data, level + 1);
    return down;
}

string Tree::relation(string name){
    if(search(name) == NULL){
        return "unrelated";
    }
    if(this == NULL){
        return NULL;
    }
    else{
        int level = Tree::level(this,name,1);
        Tree* found = search(name);
        if (level == 1 && found!= NULL) {
            return "me";
        }
        if(found->gender == "male"){
            if(level == 2)
                return "father";
            if(level == 3)
                return "grandfather";
            else{
                string ans = "grandfather";
                for (int i = 0; i < level-3; i++) {
                    ans.insert(0,"great-");
                }
                return ans;
            }        
        }
        else if(found->gender == "female"){
            if(level == 2)
                return "mother";
            if(level == 3)
                return "grandmother";
            else{
                string ans = "grandmother";
                for (int i = 0; i < level-3; i++) {
                    ans.insert(0,"great-");;
                }
                return ans;
            }      
        }
    }
    return "unrelated";
}

Tree* Tree::findRelate(Tree* root,string relate){
    if(root == NULL){
        return NULL;
    }
    if(Tree::relation(root->data) == relate){
        return root;
    } 
    Tree* go_mother = findRelate(root->mother,relate);
    Tree* go_father = findRelate(root->father,relate);
    if (go_mother != NULL)
        return go_mother;
    if (go_father != NULL)
        return go_father;
    return NULL; 
}

string Tree::find(string relate){
    if(this == NULL){
        return NULL;
    }
    Tree* found = findRelate(this, relate);
    if(found == NULL)
        throw("there is no relation: " + relate);
    return found->data;
}

//source: stackoverflow
void Tree::displayTree(const std::string& prefix, Tree* node, bool isLeft)
{
    if( node != nullptr )
    {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        cout << node->data << endl;
        displayTree( prefix + (isLeft ? "│   " : "    "), node->mother, true);
        displayTree( prefix + (isLeft ? "│   " : "    "), node->father, false);
    }
}

void Tree::display(){
    displayTree("", this, false);
}

void Tree::my_delete(Tree* root){   
    if(root == NULL)
        return;
    my_delete(root->mother);  
    my_delete(root->father);
    if(root->father != NULL)
        root->father = NULL;
    if(root->mother != NULL)
        root->mother = NULL;
}

string Tree::remove(string name){
    if(this == NULL)
        return NULL;
    if(relation(name) == "unrelated")
        throw(name + "not found\n");    
    Tree* found; 
    Tree* found2; 
    string ans;  
    found = search(name);
    found2 = search(found->child);
    if(found == this)
        throw("cannot remove root");
    ans = found->data;   
    my_delete(found);
    if(found->gender == "male")
        found2->father = NULL;
    if(found->gender == "female")
        found2->mother = NULL;    
    return ans;
}



// int main(){
//     Tree T("matan");
//     T.addFather("matan", "uri");
//     T.addFather("uri", "haim");
//     T.addFather("haim", "leiv");
//     T.addFather("leiv", "avraham");
//     T.addFather("avraham", "adam");
//     T.addMother("matan", "orli");
//     T.addMother("orli", "tirzza");
//     T.addMother("tirzza", "bella");
//     T.addMother("bella", "sarah");
//     T.addMother("sarah", "eve");

//     cout << T.relation("matan")<<endl;
//     cout << T.relation("uri")<<endl;
//     cout << T.relation("haim")<<endl;
//     cout << T.relation("leiv")<<endl;
//     cout << T.relation("avraham")<<endl;
//     cout << T.relation("adam")<<endl;
//     cout << T.relation("orli")<<endl;
//     cout << T.relation("tirzza")<<endl;
//     cout << T.relation("bella")<<endl;
//     cout << T.relation("sarah")<<endl;
//     cout << T.relation("eve")<<endl;

//     Tree H("matan");
//     H.addFather("matan", "uri");
//     H.addFather("uri", "haim");
//     H.addMother("uri", "ora");
//     H.addMother("matan", "orli");
//     H.addMother("orli", "tirzza");
//     H.addFather("orli", "moshe");
//     H.addMother("tirzza","bella");
//     H.addFather("tirzza","eliezer");

//     H.display();
//     T.remove("avraham");
//     cout<<T.relation("adam")<<endl;
//     T.remove("me");
//     cout<<T.relation("orli");
// }
