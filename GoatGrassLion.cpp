#include<iostream>
using namespace std;
#include<string>
#include<unordered_set>
class State{
public:

    bool O;//owner
    bool G;//goat
    bool g;//grass
    bool L;//lion


    //future paths
    State * _p;
    State * Gp;
    State * gp;
    State * Lp;

    //constructor
    State(bool O,bool G,bool g,bool L)
    {
        this->O=O;
        this->G=G;
        this->g=g;
        this->L=L;


        this->_p=NULL;
        this->Gp=NULL;
        this->gp=NULL;
        this->Lp=NULL;
    }
};
//generalizable
string findPath(string path,int people){//people are excluding owner(owner -  entities-0,1,... )
    //strategy 
    //For even no. of entities, take odd, then take even. 
    //For odd no. of entities, take even, come back, take all odd but one, bring back all even, take the remaining odd, come back, take all even.

    int boatsize;
    if(people%2==0)
    {
        boatsize=(people)/2+1;
        
    }
    else{
        boatsize=(people-1)/2+1;
        //pushing even people
        for(int i=0;i<people;i+=2)
        {
            path.push_back('0' + i);
        }
        path.push_back(' ');
        //come back
        path.push_back('0');
        path.push_back(' ');
        //taking all odd but 1
        path.push_back('0');
        for(int i=1;i<people;i+=2)
        {
            path.push_back('0' + i);
        }
        path.push_back(' ');
        //bringing back the even
        for(int i=0;i<people;i+=2)
        {
            path.push_back('0' + i);
        }
        path.push_back(' ');
        //take the remaining odd
        path.push_back('0' + (people - 1));
        path.push_back(' ');
        //come back
        path.push_back('0');
        //take all even
        path.push_back(' ');
        for(int i=0;i<people;i+=2)
        {
            path.push_back('0' + i);
        }
        path.push_back(' ');
    }
    return path;
}

//recursive function
bool PathCreator(State * start,string &ans,unordered_set<vector<bool>> &visited)
{
    //base cases

    //path found base case
    if(start->O==false && start->G==false && start->g==false && start->L==false)
        return true;
    
    //Lion will eat goat
    if(start->G==start->L && start->G!=start->O) 
        return false;

    //Goat will eat grass
    if(start->g==start->G && start->G!=start->O)
        return false;
    
    start->_p=new State(!start->O,start->G,start->g,start->L);
    ans.push_back('_');
    //checking if state is already visited before
    if(visited.count({(start->_p)->O,(start->_p)->G,(start->_p)->g,(start->_p)->L})==0)
    {
        visited.insert({(start->_p)->O,(start->_p)->G,(start->_p)->g,(start->_p)->L});
        bool b1=PathCreator(start->_p,ans,visited);
        if(b1)
            return true;
    }
    
    ans.pop_back();
    
    // the if handles the infeasible cases
    if(start->G==start->O)
    {
        ans.push_back('G');
        start->Gp=new State(!start->O,!start->G,start->g,start->L);
        if(visited.count({(start->Gp)->O,(start->Gp)->G,(start->Gp)->g,(start->Gp)->L})==0)
        {
            visited.insert({(start->Gp)->O,(start->Gp)->G,(start->Gp)->g,(start->Gp)->L});
            bool b2=PathCreator(start->Gp,ans,visited);
            if(b2)
                return true;
        }
        
        ans.pop_back();
        
        
    }
    if(start->g==start->O)
    {
        ans.push_back('g');
        start->gp=new State(!start->O,start->G,!start->g,start->L);
        if(visited.count({(start->gp)->O,(start->gp)->G,(start->gp)->g,(start->gp)->L})==0)
        {
            visited.insert({(start->gp)->O,(start->gp)->G,(start->gp)->g,(start->gp)->L});
            bool b3=PathCreator(start->gp,ans,visited);
            if(b3)
                return true;
        }
        ans.pop_back();
        
        
    }
    if(start->L==start->O)
    {
        ans.push_back('L');
        start->Lp=new State(!start->O,start->G,start->g,!start->L);
        if(visited.count({(start->Lp)->O,(start->Lp)->G,(start->Lp)->g,(start->Lp)->L})==0)
        {
            visited.insert({(start->Lp)->O,(start->Lp)->G,(start->Lp)->g,(start->Lp)->L});
            bool b4=PathCreator(start->Lp,ans,visited);
            if(b4)
                return true;
        }
        ans.pop_back();
        
        

    }
    

    return false;
    
}
int main()
{
    unordered_set<vector<bool>> visit;
    State * start= new State(true, true, true, true);
    string ans="";
    if(PathCreator(start,ans,visit))
    {
        cout<<ans<<endl;
    }
    string path="";
    int people;//excluding owner
    cin>>people;
    cout<<findPath(path,people);

}

bool validPath(string path){
    
    vector<bool>states(4,true);//true implies thing is on start land
    //Owner,Goat,Grass,Lion
    //steps=0(only owner),1(goat),2(grass),3(Lion)
    if(path.length()%2==0){
        return false;
    }
    if(path[0]!='1' || path[path.length()-1]!='1')
        return false;
    //as 1st move is compulsury goat and owner
    states[0]=false;
    states[1]=false;
    for(int i=1;i<=path.length()-1;i++){
        bool owner=states[0];//where owner is
        if(owner != states[path[i]-'0'])//not a valid path(owner and thing are not on same side to go together)
        {
            return false;
        }
        states[path[i]-'0']=!states[path[i]-'0'];
        if((path[i]-'0')!=0)//if owner moved with someone else we have to change owners position too
            states[0]=!states[0];
        if((states[1]==states[2] && states[1]!=states[0] ) || (states[3]==states[1] && states[1]!=states[0]))//goat eats grass or lion eats goat(owner is not present)
        {
            return false;
        }
    }
    //checks if everyone is on the other side
    for(bool b:states){
        if (b==true)
            return false;
    }
    return true;
    
    
}

