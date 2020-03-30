#include "CubeProblem.h"
#include "CubeState.h"
#include "CubeAction.h"
#include "CubeAppData.h"
#include "CubeModel.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <map>

namespace ai {
    namespace rubiks {
        static const std::map< std::string, Move > g_predefined = {
      { "I", Move( Move::M_IDENTITY ) },
      { "U", Move( Move::M_U ) }, { "U'", Move( Move::M_UP ) },
      { "L", Move( Move::M_L ) }, { "L'", Move( Move::M_LP ) },
      { "F", Move( Move::M_F ) }, { "F'", Move( Move::M_FP ) },
      { "R", Move( Move::M_R ) }, { "R'", Move( Move::M_RP ) },
      { "B", Move( Move::M_B ) }, { "B'", Move( Move::M_BP ) },
      { "D", Move( Move::M_D ) }, { "D'", Move( Move::M_DP ) },
      { "E", Move( Move::M_EQ) }, { "E'", Move( Move::M_EP ) },
      { "M", Move( Move::M_M ) }, { "M'", Move( Move::M_MP ) },
      { "S", Move( Move::M_S ) }, { "S'", Move( Move::M_SP ) },
      { "U2", Move( Move::M_U ) * Move( Move::M_U ) },
      { "L2", Move( Move::M_L ) * Move( Move::M_L ) },
      { "F2", Move( Move::M_F ) * Move( Move::M_F ) },
      { "R2", Move( Move::M_R ) * Move( Move::M_R ) },
      { "B2", Move( Move::M_B ) * Move( Move::M_B ) },
      { "D2", Move( Move::M_D ) * Move( Move::M_D ) },
      { "E2", Move( Move::M_EQ) * Move( Move::M_EQ) },
      { "M2", Move( Move::M_M ) * Move( Move::M_M ) },
      { "S2", Move( Move::M_S ) * Move( Move::M_S ) },
      { "x", Move( Move::M_X ) }, { "x'", Move( Move::M_XP ) },
      { "y", Move( Move::M_Y ) }, { "y'", Move( Move::M_YP ) },
      { "z", Move( Move::M_Z ) }, { "z'", Move( Move::M_ZP ) },

    };

        Problem::Problem( ai::Search::State *initial_state_in, const std::vector< Cube >& goal_cube_in)
            : ai::Search::Problem( initial_state_in ), goals(goal_cube_in), mAllowed(g_predefined){
        
            }

        Problem::~Problem(){
            //empty
        }

        bool Problem::GoalTest( const ai::Search::State * const state_in) const{
            const State * const state = dynamic_cast< const State * const >( state_in );
            unsigned int i;
            for( i = 0; i < goals.size(); i++ ){
                if (state->getModel() == goals[i]){
                    return true;
                }
            }
            return false;
        }
        

        std::vector<ai::Search::Action *> Problem::Actions(const ai::Search::State * const state_in ){
            std::vector<ai::Search::Action *> actions;

            for ( auto const& x : mAllowed){
                actions.push_back(new Action (x.second));
               
            }
        
           /*  actions.push_back( new Action( Move::M_U) );

            actions.push_back( new Action( Move::M_UP) );

            actions.push_back( new Action( Move::M_L) );

            actions.push_back( new Action( Move::M_LP) );

            actions.push_back( new Action( Move::M_F) );

            actions.push_back( new Action( Move::M_FP) );

            actions.push_back( new Action( Move::M_R) );

            actions.push_back( new Action( Move::M_RP ) );

            actions.push_back( new Action( Move::M_B ) );

            actions.push_back( new Action( Move::M_BP ) );

            actions.push_back( new Action( Move::M_D ) );

            actions.push_back( new Action( Move::M_DP ) ); */

            return actions;
            
        }
        
        ai::Search::State *Problem::Result( const ai::Search::State * const state_in, const ai::Search::Action * const action_in ) {
            const State * const state = dynamic_cast< const State * const >( state_in );
            const Action * const action = dynamic_cast< const Action * const>(action_in);

            Cube cube = state->getModel();
            
            return new State( cube.applyMove(action->getMove(), state->getModel()));
        }

        double Problem::StepCost( const ai::Search::State  * const state1_in,
                                  const ai::Search::Action * const action_in,
                                  const ai::Search::State  * const state2_in ) const {
            const Action * const action = dynamic_cast< const Action * const >( action_in );
            return action->getMove( ).getCost( );
        }

        void Problem::setAllowedMoves( const std::map< std::string, Move >& allowed_moves ){
            mAllowed = allowed_moves;

        }
          
        /*double Problem::Heuristic(const ai::Search::State * const state_in )const {
            const State * const state = dynamic_cast< const State * const >( state_in );

            std::vector <double> Heuristics;
            std::vector< Facelet > currentFacelets = state->getModel().getFacelets();

            for( unsigned int i = 0; i < goals.size(); i++){
                std::vector<Facelet> goalFacelets = goals[i].getFacelets();
                double total = 0;
                for(int j = 0; j < (int)currentFacelets.size(); j++){
                    if( (currentFacelets[j] == goalFacelets[j]) || ( goalFacelets[j] == (char)'*')){

                    }else{
                        total++;

                    }
                }
                Heuristics.push_back(total);
            }
            double smallest = Heuristics[0];
            for (unsigned int i = 0; i< Heuristics.size(); i++){
                if (i == 0){
                    smallest = Heuristics[i];
                }
                else if( Heuristics[i] < smallest){
                    smallest = Heuristics[i];
                }
            }
            return smallest / 20;
        }
        */

        double Problem::Heuristic(const ai::Search::State *const state_in) const {
            const State * const state = dynamic_cast< const State * const >( state_in );
            double least = 0;
            std::vector<Facelet> state_facelets = state->getModel().getFacelets();
            for( unsigned int i = 0; i < goals.size(); i++) {
                std::vector<Facelet> goal_facelets = goals[i].getFacelets();
                double out_of_place = 0;
                for( int j = 0; j < 54; j++) {
                    if (state_facelets[j] != '*') {
                        if (state_facelets[j] != goal_facelets[j]) {
                        out_of_place += 1;
                        }
                    }
                }
                if (i == 0) {
                    least = out_of_place;
                }
                if (out_of_place < least) {
                    least = out_of_place;
                }
            }
            double facelets = (double)(least/20);
            double least2 = 0;
            unsigned int goal;
            for (goal = 0; goal < goals.size(); goal++){
                std::vector<Facelet> goal_facelets = goals[goal].getFacelets();
                double OOP = 0.0;
                if (state_facelets[0] != goal_facelets[0] || state_facelets[9] != goal_facelets[9] || state_facelets[38]!= goal_facelets[38]){OOP += 1.0;} 
                if (state_facelets[6] != goal_facelets[6] || state_facelets[11] != goal_facelets[11] || state_facelets[18]!= goal_facelets[18]){OOP += 1.0;} 
                if (state_facelets[8] != goal_facelets[8] || state_facelets[20] != goal_facelets[20] || state_facelets[27]!= goal_facelets[27]){OOP += 1.0;} 
                if (state_facelets[2] != goal_facelets[2] || state_facelets[29] != goal_facelets[29] || state_facelets[36]!= goal_facelets[36]){OOP += 1.0;} 
                if (state_facelets[15] != goal_facelets[15] || state_facelets[44] != goal_facelets[44] || state_facelets[51]!= goal_facelets[51]){OOP += 1.0;} 
                if (state_facelets[17] != goal_facelets[17] || state_facelets[24] != goal_facelets[24] || state_facelets[45]!= goal_facelets[45]){OOP += 1.0;} 
                if (state_facelets[47] != goal_facelets[47] || state_facelets[26] != goal_facelets[26] || state_facelets[33]!= goal_facelets[33]){OOP += 1.0;} 
                if (state_facelets[53] != goal_facelets[53] || state_facelets[35] != goal_facelets[35] || state_facelets[42]!= goal_facelets[42]){OOP += 1.0;} 
            
                if (goal == 0){
                    least2 = OOP;
                }
                if (OOP < least2){
                    least2 = OOP;
                }
            }            
            double corners = (double)(least2/8);

            double least3 = 0;
            unsigned int g;
            for (g = 0; g < goals.size(); g++){
                double OP = 0.0;
                std::vector<Facelet> goal_facelets = goals[g].getFacelets();

                if (state_facelets[1] != goal_facelets[1] || state_facelets[37] != goal_facelets[37]){OP += 1.0;} 
                if (state_facelets[3] != goal_facelets[3] || state_facelets[10] != goal_facelets[10]){OP += 1.0;} 
                if (state_facelets[7] != goal_facelets[8] || state_facelets[19] != goal_facelets[19]){OP += 1.0;} 
                if (state_facelets[5] != goal_facelets[2] || state_facelets[28] != goal_facelets[28]){OP += 1.0;} 
                
                if (state_facelets[14] != goal_facelets[14] || state_facelets[21] != goal_facelets[21]){OP += 1.0;} 
                if (state_facelets[23] != goal_facelets[23] || state_facelets[30] != goal_facelets[30]){OP += 1.0;} 
                if (state_facelets[32] != goal_facelets[32] || state_facelets[39] != goal_facelets[39]){OP += 1.0;} 
                if (state_facelets[41] != goal_facelets[41] || state_facelets[12] != goal_facelets[12]){OP += 1.0;}

                if (state_facelets[46] != goal_facelets[46] || state_facelets[25] != goal_facelets[25]){OP += 1.0;} 
                if (state_facelets[50] != goal_facelets[50] || state_facelets[34] != goal_facelets[34]){OP += 1.0;} 
                if (state_facelets[52] != goal_facelets[52] || state_facelets[43] != goal_facelets[43]){OP += 1.0;} 
                if (state_facelets[16] != goal_facelets[16] || state_facelets[48] != goal_facelets[48]){OP += 1.0;} 

                if (g == 0){
                    least3 = OP;
                }
                if (OP < least3){
                   least3 = OP;
            
                }
            
            }

            double edges = (double)(least3/12);
            double greatest = facelets;
            if (corners > facelets && corners > edges  ){
                greatest = corners;
            }
            else if (facelets > corners && facelets > edges) {
                greatest = facelets;
            }
            else{
                greatest = edges;
            }
            return greatest;
        }
    }
}