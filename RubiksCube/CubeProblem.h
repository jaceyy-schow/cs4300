#ifndef _CUBEPROBLEM_H_
#define _CUBEPROBLEM_H_

#include "ai_search.h"
#include "CubeModel.h"
#include <vector>
#include <map>

namespace ai {
    namespace rubiks{
        class Problem : public ai::Search::Problem {

        public:

         Problem ( ai::Search::State *initial_state_in, const std::vector< Cube >& goal_cube_in);
         virtual ~Problem( );

         virtual bool GoalTest( const ai::Search::State * const state_in ) const;
         virtual std::vector<ai::Search::Action *> Actions(const ai::Search::State * const state_in );
         virtual ai::Search::State *Result( const ai::Search::State  * const state_in,const ai::Search::Action * const action_in );

         virtual double StepCost( const ai::Search::State * const state1_in,
                                  const ai::Search::Action * const action_in,
                                  const ai::Search::State * const state2_in ) const;
         void setAllowedMoves( const std::map< std::string, Move >& allowed_moves );

         virtual double Heuristic(const ai::Search::State * const state_in )const;

        private:
         std::vector< Cube > goals;
         std::map<std::string,Move> mAllowed;
         std::vector< Facelet > currentFacelets;

                
        };

    
    }
}

#endif /* _RECTANGLEPROBLEM_H_ */
/* Local Variables : */
/* F:c++          */
/* End:              */