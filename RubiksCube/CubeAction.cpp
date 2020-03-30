#include "CubeAction.h"
#include <iostream>

namespace ai {
  namespace rubiks {

    Action::Action( const Move& move ) 
      : mMove( move ) {
    }

    Action::~Action( ) {
    }
    const Move& Action::getMove( ) const {
      return mMove;
    }

  }
}

std::ostream& operator<<( std::ostream& os, const ai::rubiks::Action&action){
  os << action.getMove().getName();
  return os;
}
