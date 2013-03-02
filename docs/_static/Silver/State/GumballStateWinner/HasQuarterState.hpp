#ifndef	_HFDP_CPP_STATE_GUMBALL_STATE_WINNER_HAS_QUARTER_STATE_HPP_
#define _HFDP_CPP_STATE_GUMBALL_STATE_WINNER_HAS_QUARTER_STATE_HPP_

#include "Hum_Log_Manager.h"
#include "Hum_Trace.h"

#ifdef WIN32
#include <process.h>
#else
#include <sys/types.h>
#include <unistd.h>
#endif

namespace HeadFirstDesignPatterns {
  namespace State {
    namespace GumballStateWinner {

      class HasQuarterState : public State {

        int _random;
        GumballMachine* _gumballMachine;

        HasQuarterState( const HasQuarterState& ); // Disable copy constructor
        void operator=( const HasQuarterState& ); // Disable assignment operator

      public:
        explicit HasQuarterState( GumballMachine* gumballMachine ) :
          _gumballMachine( gumballMachine ), _random( 0 )
        {
          assert( gumballMachine );
          HUM_TRACE(ACE_TEXT("HasQuarterState::HasQuarterState"));
#ifdef WIN32
          srand( _getpid() );
#else
          srand( getpid() );
#endif
        }
        void insertQuarter() const
        {
          HUM_TRACE(ACE_TEXT("HasQuarterState::insertQuarter"));
          std::cout << "You can't insert another quarter" << std::endl;
        }
        void ejectQuarter() const
        {
          HUM_TRACE(ACE_TEXT("HasQuarterState::ejectQuarter"));
          std::cout << "Quarter returned" << std::endl;
          _gumballMachine->setState( _gumballMachine->getNoQuarterState() );
        }
        void turnCrank() const
        {
          HUM_TRACE(ACE_TEXT("HasQuarterState::turnCrank"));
          std::cout << "You turned..." << std::endl;
          int winner = rand() % 5;
          if( ( winner == 0 ) && ( _gumballMachine->getCount() > 0 ) ) {
            _gumballMachine->setState( _gumballMachine->getWinnerState() );
          } else {
            _gumballMachine->setState( _gumballMachine->getSoldState() );
          }
        }
        void dispense()
        {
          HUM_TRACE(ACE_TEXT("HasQuarterState::dispense"));
          std::cout << "No gumball dispensed" << std::endl;
        }
        std::string toString() const
        {
          HUM_TRACE(ACE_TEXT("HasQuarterState::toString"));
          return "waiting for turn of crank";
        }
      };

    } // namespace GumballStateWinner
  } // namespace State
} // namespace HeadFirstDesignPatterns

#endif
