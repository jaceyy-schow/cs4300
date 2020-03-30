#include <cstdio>
#include <cstring>
#include "starterGimliKnowledgeBase.h"
#include <sstream>

namespace starter
{

  GimliKnowledgeBase::GimliKnowledgeBase()
    : ai::PL::KnowledgeBase(),
    width(4),
    height(4)
  {
    // nothing here
  }
  GimliKnowledgeBase::~GimliKnowledgeBase()
  {
    // nothing here
  }

  void GimliKnowledgeBase::SetSize(int width_in, int height_in) 
  {
    width = width_in;
    height = height_in;
  }

  bool GimliKnowledgeBase::AskNirvana(int x_in, int y_in){
    bool rval, rval2;
    rval = AskNoPit(x_in,y_in);
    rval2 = AskWumpus(x_in,y_in);
    if (rval && rval2){
      return true;
    }
    else{
      return false;
    }

  }

  bool GimliKnowledgeBase::AskGold(int x_in, int y_in)
  {
    ai::PL::KnowledgeBase question;
    std::stringstream ss;
    bool rval;
    ss << "Gold_"<< x_in << "_" << y_in;
    question.AddSentence(ss.str());
    rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
    if(rval){
      return true;
    }
    else{
      return false;
    }
  }

  bool GimliKnowledgeBase::AskNoPit(int x_in, int y_in)
  {
    ai::PL::KnowledgeBase question;
    std::stringstream ss;
    bool rval;
    ss << "!Pit_"<< x_in << "_" << y_in;
    question.AddSentence(ss.str());
    rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
    if(rval){
      return true;
    }
    else{
      return false;
    }
  }

  bool GimliKnowledgeBase::AskPit(int x_in, int y_in)
  {
    ai::PL::KnowledgeBase question;
    std::stringstream ss;
    bool rval;
    ss << "Pit_"<< x_in << "_" << y_in;
    question.AddSentence(ss.str());
    rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
    if(rval){
      return true;
    }
    else{
      return false;
    }
  }

  bool GimliKnowledgeBase::AskNoWumpus(int x_in, int y_in)
  {
    ai::PL::KnowledgeBase question;
    std::stringstream ss;
    bool rval;
    ss << "!Wumpus_"<<x_in << "_" << y_in;
    question.AddSentence(ss.str());
    rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
    if(rval){
      return true;
    }
    else{
      return false;
    }
  }

  bool GimliKnowledgeBase::AskWumpus(int x_in, int y_in)
  {
    ai::PL::KnowledgeBase question;
    std::stringstream ss;
    bool rval;
    ss << "Wumpus_"<<x_in << "_" << y_in;
    question.AddSentence(ss.str());
    rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
    if(rval){
      return true;
    }
    else{
      return false;
    }
  }

  bool GimliKnowledgeBase::AskNotSafe(int x_in, int y_in)
  {
    ai::PL::KnowledgeBase question;
    std::stringstream ss;
    bool rval;
    ss << "!Safe_"<<x_in << "_" << y_in;
    question.AddSentence(ss.str());
    rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
    if(rval){
      return true;
    }
    else{
      return false;
    }
  }

  bool GimliKnowledgeBase::AskSafe(int x_in, int y_in)
  {
    ai::PL::KnowledgeBase question;
    std::stringstream ss;
    bool rval;
    ss << "Safe_"<< x_in << "_" << y_in;
    question.AddSentence(ss.str());
    rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
    if(rval){
      return true;
    }
    else{
      return false;
    }
  }

  bool GimliKnowledgeBase::AskVisited(int x_in, int y_in)
  {
    ai::PL::KnowledgeBase question;
    std::stringstream ss;
    bool rval;
    ss << "Visited_"<<x_in << "_" << y_in;
    question.AddSentence(ss.str());
    rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
    if(rval){
      return true;
    }
    else{
      return false;
    }
  }
  
  bool GimliKnowledgeBase::AskAimedAtWumpus(int x_in, int y_in, int direction_in)
  {
    int x, y;
    bool wumpLoc;
    for (x = 1; x <=width; x++){
      for (y = 1; y <= height; y++){
         wumpLoc = AskWumpus(x, y);
         if ((wumpLoc == true) && (x == x_in)){
           if ((y > y_in) && (direction_in == 90)){
             return true;
           }
           else if ((y< y_in) && (direction_in == 270)){
             return true;
           }
           else{return false;}
         }
         else if ((wumpLoc == true)&&(y==y_in)){
           if( (x > x_in) && (direction_in == 0)){
             return true;
           }
           else if ( (x < x_in) && (direction_in == 180) ){
             return true;
           }
           else{return false;}
         }
      }
    }
    return false;
  }
  
  void GimliKnowledgeBase::TellNoGlitter(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "!Glitter_"<<x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellGlitter(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "Glitter_"<<x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellNoBreeze(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "!Breeze_"<<x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellBreeze(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "Breeze_"<<x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellNoStench(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "!Stench_"<<x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellStench(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "Stench_"<<x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellNoPit(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "!Pit_"<<x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellWumpusDead()
  {
    std::stringstream ss;
    ss << "WD";
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellNoWumpus(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "!Wumpus_"<<x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellWumpus(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "Wumpus_"<<x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  
  void GimliKnowledgeBase::TellVisited(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "Visited_"<< x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellGlitterRules() 
  {
    int x, y;
    for (x = 1; x <= width; x++){
      for (y = 1; y <= height; y++){
        std::stringstream ss;
        ss <<"Glitter_"<< x << "_" << y << "<=> (Gold_" << x << "_" << y << ")";  
        AddSentence(ss.str());
      }
    }
  }
  void GimliKnowledgeBase::TellBreezeRules()
  {
    int x, y;
    for (x = 1; x <= width ; x++){
      for (y = 1; y <= height; y++){
        std::stringstream jj;
        if (x+1 > width){
          jj << "Breeze_"<< x << "_" << y << "<=> ((Pit_" << x << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << ") |(Pit_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
        else if (x-1 < 1){
          jj << "Breeze_"<< x << "_" << y << "<=> ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << ") | (Pit_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
        else if (y+1 >height){
          jj << "Breeze_"<< x << "_" << y << "<=> ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
        else if (y-1 < 1){
          jj << "Breeze_"<< x << "_" << y << "<=> ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
        else{
          jj << "Breeze_"<< x << "_" << y << "<=> ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << ") | (Pit_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
      }
    }
  }
  void GimliKnowledgeBase::TellStenchRules()
  {
    int x, y;
    for (x = 1; x <= width; x++){
      for (y = 1; y <= height; y++){
        std::stringstream ss, jj;
        ss << "Wumpus_" << x << "_" << y << "=> (!Pit_" << x << "_" << y <<")";
        if (x+1 > width){
          jj << "Stench_"<< x << "_" << y << "<=> ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << ") |(Wumpus_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
        else if (x-1 < 1){
          jj << "Stench_"<< x << "_" << y << "<=> ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << ") | (Wumpus_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
        else if (y+1 >height){
          jj << "Stench_"<< x << "_" << y << "<=> ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");

        }
        else if (y-1 < 1){
          jj << "Stench_"<< x << "_" << y << "<=> ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
        else{
          jj << "Stench_"<< x << "_" << y << "<=> ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << ") | (Wumpus_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");

        }
      }
    }
  }
  void GimliKnowledgeBase::TellSafeRules()
  {
    int x, y;
    std::stringstream ss, jj;
    for( x = 1; x <= width; x++){
      for( y = 1; y <= height; y++ ){
        ss << "Safe_"<< x <<"_"<< y <<" <=> ((!Pit_" << x << "_" << y << ") & ((!Wumpus_" << x << "_" << y << ") | WD))";
        AddSentence(ss.str());
        ss.str("");
      }
    }
    jj << "Wumpus_1_2 => Safe_2_1";
    AddSentence(jj.str());
    jj.str("");
  }
};
