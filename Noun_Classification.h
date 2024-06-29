#ifndef NOUN_CLASSIFICATION_H
#define NOUNT_CLASSIFICATION_H
#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<vector>
struct Node{
    int index;
    int weight;
    Node* prev=nullptr;
    std::vector<Node*> next;
    bool visited=true;
    Node(int i,int w):index(i),weight(w){}
};
class System{
    public:
    System(int all,int ask){
        std::string str1,str2;
        std::getline(std::cin,str1);
        std::getline(std::cin,str2);
        constructing(all,str1,str2);
        truecalculate(box[0],box[0]->weight);
        for(int i=0;i<ask;i++){
            int temp;
            std::cin>>temp;
            std::cin.ignore();
            temp--;
            dealing(temp);
            cleaning();
        }
        for(auto i:result)
        std::cout<<i<<std::endl;
    }
    private:
    std::vector<Node*> box;
    std::vector<std::string> result;
    int barriade;
    int publicuse;
    void cleaning(){
        for(auto i:box){
            i->visited=true;
        }
        return;
    }
    void constructing(int all,std::string&s1,std::string&s2){
        std::stringstream ss1(s1);
        std::stringstream ss2(s2);
        for(int i=0;i<all;i++){
            int temp;
            ss1>>temp;
            box.push_back(new Node(i,temp));
        }
        for(int i=1;i<all;i++){
            int temp;
            ss2>>temp;
            temp--;
            box[i]->prev=box[temp];
            box[temp]->next.push_back(box[i]);
        }
    }
    void dealing(int asker){
        Node* head=box[0];
        Node* temp=nullptr;
        std::string str="";
        while(head->next.size()!=0){
            temp=head;
            publicuse=truecalculate(head,head->weight);
            barriade=publicuse;
            int target=calculating(head,asker);
            if(target==asker&&target==head->index)
            break;
            head=box[target];
            str+=std::to_string(head->index+1)+" ";
            if(!teller(head,asker)){
                head->visited=false;
                head=temp;
            }
        }
        result.push_back(str);
        return;
    }
    int calculating(Node* head,int asker){
        for(auto it:head->next){
            if(it->visited==false)
            continue;
            if(numeric(it)<barriade){
                barriade=numeric(it);
                asker=it->index;
            }
            asker=calculating(it,asker);
        }
        return asker;
    }
    int truecalculate(Node* head,int sum){
        for(auto it:head->next){
           if(it->visited==false)
            continue;
           sum+=it->weight;
           sum =truecalculate(it,sum);
        }
        return sum;
    }
    int numeric(Node* head){
        int value1=truecalculate(head,head->weight);
        int value2=publicuse-value1;
        if(value2>value1)return value2-value1;
        return value1-value2;
    }
    bool teller(Node* head,int asker){
        bool stem=false;
        if(head->index==asker)
            return true;
        if(head->next.size()==0)
            return false;
        for(int i=0;i<head->next.size();i++){
            if(head->next[i]->visited){
                stem=stem||teller(head->next[i],asker);
            }
        }
        return stem;
    }
};
#endif
