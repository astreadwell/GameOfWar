#include "Player.h"



    // default constructor 
    Player::Player() {
        numCards = 0;
    }

    // alternative constructor 
    Player::Player(vector<Card> ini_cards) {
        for (int i = 0; i < ini_cards.size(); i++) {
            cards.push_back(ini_cards[i]);
        }
        numCards = cards.size();
    }

    // return how many cards player holds currently 
    int Player::getNumCards() const {
        return numCards;
    }

    // player plays one card at the front of cards at hand 
    Card Player::play_a_card() {
        list<Card> cards2 = cards;
        Card front = cards2.front();
        cards.pop_front();
        numCards = numCards - 1;
        return front;
        
    }

    // player wins and adds winning cards to the end of the pile at hand  
    void Player::addCards(vector<Card> winningCards) {
        for (int i = 0; i < winningCards.size(); i++) {
            cards.push_back(winningCards[i]);
        }
        numCards = numCards + winningCards.size();
    }

    // player drops THREE cards from the front of pile at hand 
   // when there is a tie 
    vector<Card> Player::dropCards() {
        vector<Card> droppedCards;
        list<Card> cards2 = cards;
        if (cards.size() < 3) {
            for (int i = 0; i < cards.size(); i++) {
                droppedCards.push_back(cards2.front());
                cards.pop_front();
            }
            numCards = numCards - droppedCards.size();
            return droppedCards;
        }
        
        for (int i = 0; i < 2; i++) {
            droppedCards.push_back(cards2.front());
            cards.pop_front();

        }
        
        numCards = numCards - droppedCards.size();
        return droppedCards;
    }

    // display cards at player's hand 
    void Player::print() const {
        for (list<Card>::const_iterator it = cards.begin(); it != cards.end(); it++) {
            it->print();
        }
    }

    // you are allowed to add other member functions if you want 


