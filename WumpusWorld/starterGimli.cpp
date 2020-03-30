#include "starterGimli.h"
#include "starterGimliWumpusSearch.h"
#include <sstream>
#include <chrono>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <iomanip>

namespace starter
{
  Gimli::Gimli(ai::Agent::Options *opts)
  {
    SetName("Gimli");
    width  = -1;
    height = -1;
  
    x = 1;
    y = 1;
    direction = 0;
    last_action = ai::Wumpus::Action::NOOP;
    gold   = 0;
    arrows = 1;
  }

  Gimli::~Gimli()
  {
  }

  ai::Agent::Action * Gimli::Program(const ai::Agent::Percept * percept)
  {
    ManagePercepts(percept);
    return ChooseAction();
  }

  void Gimli::ManagePercepts(const ai::Agent::Percept * percept)
  {
    /* update state variables and knowledge base from current percepts */
    ManageWidthHeight(percept); // Dimensions must come first
    ManageLocation(percept); // Location must come next
    ManageGlitter(percept);
    ManageBreeze(percept);
    ManageStench(percept);
    ManageScream(percept);
  }

  void Gimli::ManageWidthHeight(const ai::Agent::Percept * percept) {
    if( width < 1 || height < 1 ) {
      std::stringstream ss(percept->GetAtom("WIDTH").GetValue());
      ss >> width;
      ss.clear();
      ss.str(percept->GetAtom("HEIGHT").GetValue());
      ss >> height;
      //not setting the correct width and height.. had to manually enter
      
      kb.SetSize(width,height);

      ss.clear();
      ss.str(percept->GetAtom("PIT-PROBABILITY").GetValue());
      ss >> pit_probability;

      kb.TellGlitterRules();
      kb.TellBreezeRules();
      kb.TellStenchRules();
      kb.TellSafeRules();
      kb.TellNoPit(1, 1);
      kb.TellNoWumpus(1, 1);
      kb.TellVisited(1, 1);

      std::ofstream fout("Gimli.kb");
      fout << kb;
      fout.close();
    }
  }

  void Gimli::ManageLocation(const ai::Agent::Percept * percept)
  {
    /* If we moved forward, and did not bump, then update position
     * Otherwise, if we turned, update direction */
    if((last_action == ai::Wumpus::Action::FORWARD) &&
       (percept->GetAtom("BUMP").GetName() == ""))
      {
        if     (direction == 0)    { x += 1; }
        else if(direction == 90)   { y += 1; }
        else if(direction == 180)  { x -= 1; }
        else if(direction == 270)  { y -= 1; }
        else                       { std::cerr << "BAD DIRECTION" << std::endl;}

        if(!kb.AskVisited(x, y))   { kb.TellVisited(x,y); }
      }
    else if(last_action == ai::Wumpus::Action::TURN_LEFT)
      {
        direction += 90;
        direction %= 360;
      }
    else if(last_action == ai::Wumpus::Action::TURN_RIGHT)
      {
        direction += 270;
        direction %= 360;
      }
  }

  
  void Gimli::ManageGlitter(const ai::Agent::Percept * percept)
  {
    /* If we see glitter, mark it in the knowledge base.
     * Update state variables for gold and arrow counts. */
    if(percept->GetAtom("GLITTER").GetName() != "")
      {
        kb.TellGlitter(x, y);
      }
    else
      {
        kb.TellNoGlitter(x, y);
      }
    std::stringstream ss(percept->GetAtom("GOLD").GetValue());
    ss >> gold;
    ss.clear();
    ss.str(percept->GetAtom("ARROWS").GetValue());
    ss >> arrows;
  }

  void Gimli::ManageBreeze(const ai::Agent::Percept * percept)
  {
    /* Tell the knowledge base whether we feel a breeze or not. */
    if(percept->GetAtom("BREEZE").GetName() != "")
      {
        kb.TellBreeze(x, y);
      }
    else
      {
        kb.TellNoBreeze(x, y);
      }
  }

  void Gimli::ManageStench(const ai::Agent::Percept * percept)
  {
    /* Tell the knowledge base whether we smell a stench or not. */
    if(percept->GetAtom("STENCH").GetName() != "")
      {
        kb.TellStench(x, y);
      }
    else
      {
        kb.TellNoStench(x, y);
      }
  }

  void Gimli::ManageScream(const ai::Agent::Percept * percept)
  {
    /* Tell the knowledge base if we hear a scream.
     * Or, if we shot last turn but don't hear a scream. */
    if(percept->GetAtom("SCREAM").GetName() != "")
      {
        kb.TellWumpusDead();
      }
    else if(last_action == ai::Wumpus::Action::SHOOT)
      { // we missed the wumpus.  this should only occur
        // in the starting cell, facing east.
        // this means the wumpus is to the north
        kb.TellWumpus(1, 2);
      }
  }

  ai::Agent::Action * Gimli::ChooseAction()
  {
    /* Choose an action to execute with the following state machine:
     * If we have the gold -> QUIT
     * If we see the gold -> GRAB the gold
     * If we have an action in the plan -> pop the action from the plan and execute it.
     * If the room in front of us is safe and unvisited -> FORWARD
     * If we can find a safe, unvisited room -> save the plan to get there, and execute the first action in the plan.
     * If we can shoot the wumpus -> save the plan to do it, and execute the first action in the plan.
     * If we are cornered at the start by the wumpus, and not by a pit -> SHOOT
     * Otherwise, we don't have a safe course of action -> QUIT
     */
    int action_code;

    if(gold > 0)
      {
        action_code = ai::Wumpus::Action::QUIT;
      }
\
    else if(kb.AskGold(x, y))
      {
        action_code = ai::Wumpus::Action::GRAB;
      }
    else if(!plan.empty())
      { // do next action
        action_code = plan.front();
        plan.pop();
      }
    else if(kb.AskNirvana(x,y)){
      action_code = ai::Wumpus::Action::YELL;
      action_code = ai::Wumpus::Action::FORWARD;
      plan.pop();
      
    }
    else if(ForwardIsSafe())
      {
        action_code = ai::Wumpus::Action::FORWARD;
      }
    else if(FindNearestUnvisitedSafe())
      {
        action_code = plan.front();
        plan.pop();
      }
    else if(ShootWumpus())
      {
        action_code = plan.front();
        plan.pop();
      }
    else if(WumpusNearStart())
      { // we are in the start cell, facing east
        // we smell a stench, but don't feel a breeze
        // we will shoot, and see if we can kill the wumpus,
        //   or at least know where he is.
        action_code = ai::Wumpus::Action::SHOOT;

      }
    // else do something else
    // else quit
    else
      {
        action_code = ai::Wumpus::Action::QUIT;
      }
  
    ai::Agent::Action *action = new ai::Wumpus::Action();
    action->SetCode(action_code);
    last_action = action_code; // remember our last action for next turn.
    return action;
  }

  bool Gimli::ForwardIsSafe()
  {
    /* Ask the knowledge base if the next room is safe and unvisited. */
    int x_next, y_next;
    switch(direction)
      {
      case 0:   x_next = x + 1;  y_next = y;     break;
      case 90:  x_next = x;      y_next = y + 1; break;
      case 180: x_next = x - 1;  y_next = y;     break;
      case 270: x_next = x;      y_next = y - 1; break;
      default:
        std::cerr << "BAD DIRECTION" << std::endl;
        return false;
        break;
      }
    bool canMove = (kb.AskSafe(x_next, y_next) && !kb.AskVisited(x_next, y_next));
    return (canMove);
  }

  bool Gimli::SearchForAction(bool shoot_wumpus)
  {
    /* Use an A* graph search strategy to find the shortest path to an action.
     * shoot_wumpus == false -> find the nearest safe, unvisited room, if one exists.
     * shoot_wumpus == true -> find the nearest safe path to shoot the wumpus, if one exists. */
    ai::Search::Frontier  *frontier      = new ai::Search::AStarFrontier;
    GimliWumpusState      *initial_state = new GimliWumpusState;
    initial_state->x         = x;
    initial_state->y         = y;
    initial_state->direction = direction;
    initial_state->shot      = 0;
    GimliWumpusProblem *problem = new GimliWumpusProblem(initial_state, &kb, width, height, shoot_wumpus);
  
    ai::Search::Graph searcher(problem, frontier);
    if(searcher.Search())
      { // found a solution, put it into the plan
        std::list<ai::Search::Node *> *l = searcher.GetSolution().GetList();
        std::list<ai::Search::Node *>::const_iterator i;
        for(i = l->begin(); i != l->end(); i++)
          {
            GimliWumpusAction *a = (GimliWumpusAction *)((*i)->GetAction());
            if(a)
              {
                plan.push(a->GetActionCode());
              }
            else
              { // the last action is always empty, not a problem.
              }
          }
        return true;
      }
    else
      { // no solution found
        return false;
      }
  }
  
  bool Gimli::FindNearestUnvisitedSafe()
  {
    /* Use an A* graph search strategy to find the shortest path to
     * the nearest safe, unvisited room, if one exists. */
    return SearchForAction(false);
  }

  bool Gimli::ShootWumpus()
  {
    /* If we still have our arrow,
     * Use an A* graph search strategy to find the shortest path to
     * the shoot the wumpus, if one exists. */
    if(arrows <= 0) { return false; }
    return SearchForAction(true);
  }

  bool Gimli::WumpusNearStart()
  {
    if (x ==1 && y == 1 && direction == 0){
      if (kb.AskNoPit(1,2) && kb.AskNoPit(2,1)){
        if (kb.AskSafe(1,2) && kb.AskSafe(2,1)){
          return false;
        }
        return true;
      }
    }
    return false;
    /* If we are in the starting room, still facing east,
     * ask the knowledge base if there is no pit nearby, and the wumpus is nearby. */
  }
  void Gimli::DoNirvana(){
      while(!plan.empty()) plan.pop();
  }
};

  



