#include <bits/stdc++.h>
using namespace std;
/*
Nim game is a type of impartial game, that means that you can determine the winner based on the positions that remain for a game position.  It does not depend on whose turn it is.  Impartial games are are two player and turn based games. 
For impartial games there are two possible ways to win, "normal play" the last player who can make a move wins, or "misere play" the first player who can't make a move wins.  

If we consider "normal play" for the game of nim, which is something like this.  In one form you have 3 nim heaps or 3 piles of stones.  There are some amount of stones in each pile.  player A goes first always.  Every turn a player must remove from a single nim heap 1 or more stones.  The player who removes the last stones is the winner.  

This is a solved game, you can determine who will be the winner at the very beginning of the game.  Compute the nim sum (nim addition).  This is shown in nim arithmetic in the math section.  But it's just xor of all the nim heaps. 
The player who can make the nim sum 0 on there turn is guaranteed to win if they play optimally.  So if nim sum is not zero on first turn, player A can always make the nim sum 0 by choosing appropriate number. And player B will always force nim sum to not be 0 because 0^x=x, a property of removing any stones with xor of 0.   

imagine [100,100,100],
nim-sum = 100
player A removes 100 stones from pile 0.
nim-sum = 0
player B removes 100 stones from pile 1 (doesn't matter however many stones he removes nim sum will not be 0)
nim-sum=100
player A removes the last 100 stones to win.  

Player A goes makes the first move
returns true if player A wins, false if player B wins
*/
bool nimGame(vector<int>& stones) {
  int nimSum = accumulate(stones.begin(), stones.end(), 0, [](const int a, const int b) {
    return a^b;
  });
  // Since Player A goes first he will win if the nim sum is not 0.
  return nimSum!=0;
}
/*
TODO: Can I add graphics to represent case when player A wins and player B wins, can I draw graphically the stones in the nim heaps or piles. 
*/
int main() {
  vector<int> stones = {3,3,3,3};
  bool playerAWins = nimGame(stones);
  if (playerAWins) {
    cout<<"Player A wins"<<endl;
  } else {
    cout<<"Player B wins"<<endl;
  }
}