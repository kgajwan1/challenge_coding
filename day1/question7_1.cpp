#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include<chrono>
 
using namespace std;
 
namespace SUIT
{
    enum Enum
    {
        SPADE,
        HEART,
        CLUB,
        DIAMOND
    };
};
 
class Card
{
private:
    SUIT::Enum s;
    int v;
     
public:
    virtual SUIT::Enum suit() const
    {
        return s;
    };
     
    virtual int val() const
    {
        return v;
    };
     
    Card(int val, SUIT::Enum suit):s(suit), v(val){};
};
 
/*
Just remember and practise the paradigm of inheritance
*/
class BlackJackCard : public Card
{
public:
    virtual int val()
    {
        int v = Card::val();
        if (v < 10) return v;
        return 10;
    }
     
    BlackJackCard(int val, SUIT::Enum suit):Card(val, suit){};
};
 
class player
{
private:
    int id;
    int bet;
    set<int> points;
    vector<BlackJackCard *> bjcs;
    bool addPoint(set<int>& points, BlackJackCard* card)
    {
        if (points.empty())
        {
            points.insert(card->val());
            if (card->val() == 1)
                points.insert(11);
        }
        else
        {
            /*
            set elements are ALWAYS CONST, they can't be modified once inserted.
            */
            set<int> tmp;
            for (set<int>::iterator it = points.begin(); it != points.end(); ++ it)
            {
                tmp.insert(*it + card->val());
                if (card->val() == 1)
                    tmp.insert(*it + 11);
            }
            points = tmp;
        }
        
    }
      
    void getPoints()
    {
        cout << "You All Possible Points : " << endl;
        for (set<int>::iterator it = points.begin(); it != points.end(); ++ it)
        {
            cout << *it << endl;
        }
    };
     
    int getMinPoints()
    {
        /*
        set is implemented by commonly BST, so eles are in order!!!
        learn to use lower_bound() and upper_bound()
         
        "they allow the direct iteration on subsets based on their order."
        which gives us another option to find min. preferable
        */
         
        //return *(points.lower_bound(0));
        return *(points.begin());
    };
     
    void printCards()
    {
        cout << "You Cards : " << endl;
        for (vector<BlackJackCard *>::iterator it = bjcs.begin(); it != bjcs.end(); ++ it)
        {
            cout << (*it)->val() << endl;
        }
         
    }
public:
    player(int i, int j):id(i),bet(j)
    {
        bjcs.push_back(new BlackJackCard(rand() % 13 + 1, SUIT::SPADE));
        bjcs.push_back(new BlackJackCard(rand() % 13 + 1, SUIT::SPADE));
        addPoint(points, bjcs[0]);
        addPoint(points, bjcs[1]);
    };
     
    void getAnotherCard()
    {
        for (set<int>::iterator it = points.begin(); it != points.end(); ++ it)
        {
            /*
            predefined strategy for the player
            */
            if (*it <= 21 && 21 - *it <= 4)
            {
                printCards();
                getPoints();
                cout << "Stand" << endl; 
                exit(1);
            }
        }
        bjcs.push_back(new BlackJackCard(rand() % 13 + 1, SUIT::SPADE));
        addPoint(points, bjcs.back());
        if (getMinPoints() > 21)
        {
            printCards();
            getPoints();
            cout << "Busted" << endl;
            exit(2);
        }
    };
     
    virtual ~player()
    {
        for (vector<BlackJackCard *>::iterator it = bjcs.begin(); it != bjcs.end(); ++it)
        {
            delete *it;
        }
    };
     
};
 
int main()
{
    srand(time(0));
    player p(1, 1000);
    p.getAnotherCard();
    p.getAnotherCard();
    p.getAnotherCard();
     
    return 0;
}