/** Generated by YAKINDU Statechart Tools code generator. */

#include "Statechart.h"

/*! \file
Implementation of the state machine 'Statechart'
*/




Statechart::Statechart() :
	viMyCounter(0),
	timerService(sc_null),
	isExecuting(false)
{
	for (sc_ushort state_vec_pos = 0; state_vec_pos < maxOrthogonalStates; ++state_vec_pos)
		stateConfVector[state_vec_pos] = Statechart_last_state;
	
	clearInEvents();
}

Statechart::~Statechart()
{
}


using namespace statechart_events;

SctEvent* Statechart::getNextEvent()
{
	SctEvent* nextEvent = 0;
	
	if(!inEventQueue.empty()) {
		nextEvent = inEventQueue.front();
		inEventQueue.pop_front();
	}
	
	return nextEvent;
}

void Statechart::dispatch_event(SctEvent * event)
{
	if(event == 0) {
		return;
	}
	switch(event->name)
	{
		case Statechart_Blink_Turn_ON_time_event_0:
		{
			timeEvents[0] = true;
			break;
		}
		case Statechart_Blink_Turn_OFF_time_event_0:
		{
			timeEvents[1] = true;
			break;
		}
		default:
			/* do nothing */
			break;
	}
	delete event;
}

void Statechart::iface_dispatch_event(SctEvent * event)
{
	switch(event->name)
	{
		default:
			/* do nothing */
			break;
	}
}
void Statechart::internal_dispatch_event(SctEvent * event)
{
	switch(event->name)
	{
		default:
			/* do nothing */
			break;
	}
}

StatechartEventName Statechart::getTimedEventName(sc_eventid evid)
{
	if (evid == (sc_eventid)(&timeEvents[0])) {
		return Statechart_Blink_Turn_ON_time_event_0;
	}
	if (evid == (sc_eventid)(&timeEvents[1])) {
		return Statechart_Blink_Turn_OFF_time_event_0;
	}
	return invalid_event;
}



sc_boolean Statechart::isActive() const
{
	return stateConfVector[0] != Statechart_last_state;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean Statechart::isFinal() const
{
   return false;}

sc_boolean Statechart::check() {
	if(timerService == sc_null) {
		return false;
	}
	return true;
}


void Statechart::setTimerService(sc::timer::TimerServiceInterface* timerService_)
{
	this->timerService = timerService_;
}

sc::timer::TimerServiceInterface* Statechart::getTimerService()
{
	return timerService;
}

sc_integer Statechart::getNumberOfParallelTimeEvents() {
	return parallelTimeEventsCount;
}

void Statechart::raiseTimeEvent(sc_eventid evid)
{
	if ((evid >= (sc_eventid)timeEvents) && (evid < (sc_eventid)(&timeEvents[timeEventsCount])))
	{
		inEventQueue.push_back(new TimedSctEvent(getTimedEventName(evid)));
		runCycle();
	}
}


sc_boolean Statechart::isStateActive(StatechartStates state) const
{
	switch (state)
	{
		case Blink_Turn_ON :
		{
			return (sc_boolean) (stateConfVector[SCVI_BLINK_TURN_ON] == Blink_Turn_ON);
			break;
		}
		case Blink_Turn_OFF :
		{
			return (sc_boolean) (stateConfVector[SCVI_BLINK_TURN_OFF] == Blink_Turn_OFF);
			break;
		}
		default:
		{
			/* State is not active*/
			return false;
			break;
		}
	}
}


// implementations of all internal functions
/* Entry action for state 'Turn_ON'. */
void Statechart::enact_Blink_Turn_ON()
{
	/* Entry action for state 'Turn_ON'. */
	timerService->setTimer(this, (sc_eventid)(&timeEvents[0]), 500, false);
	opLedWrite(ON);
	viMyCounter++;
}

/* Entry action for state 'Turn_OFF'. */
void Statechart::enact_Blink_Turn_OFF()
{
	/* Entry action for state 'Turn_OFF'. */
	timerService->setTimer(this, (sc_eventid)(&timeEvents[1]), (1 * 1000), false);
	opLedWrite(OFF);
	viMyCounter--;
}

/* Exit action for state 'Turn_ON'. */
void Statechart::exact_Blink_Turn_ON()
{
	/* Exit action for state 'Turn_ON'. */
	timerService->unsetTimer(this, (sc_eventid)(&timeEvents[0]));
}

/* Exit action for state 'Turn_OFF'. */
void Statechart::exact_Blink_Turn_OFF()
{
	/* Exit action for state 'Turn_OFF'. */
	timerService->unsetTimer(this, (sc_eventid)(&timeEvents[1]));
}

/* 'default' enter sequence for state Turn_ON */
void Statechart::enseq_Blink_Turn_ON_default()
{
	/* 'default' enter sequence for state Turn_ON */
	enact_Blink_Turn_ON();
	stateConfVector[0] = Blink_Turn_ON;
}

/* 'default' enter sequence for state Turn_OFF */
void Statechart::enseq_Blink_Turn_OFF_default()
{
	/* 'default' enter sequence for state Turn_OFF */
	enact_Blink_Turn_OFF();
	stateConfVector[0] = Blink_Turn_OFF;
}

/* 'default' enter sequence for region Blink */
void Statechart::enseq_Blink_default()
{
	/* 'default' enter sequence for region Blink */
	react_Blink__entry_Default();
}

/* Default exit sequence for state Turn_ON */
void Statechart::exseq_Blink_Turn_ON()
{
	/* Default exit sequence for state Turn_ON */
	stateConfVector[0] = Statechart_last_state;
	exact_Blink_Turn_ON();
}

/* Default exit sequence for state Turn_OFF */
void Statechart::exseq_Blink_Turn_OFF()
{
	/* Default exit sequence for state Turn_OFF */
	stateConfVector[0] = Statechart_last_state;
	exact_Blink_Turn_OFF();
}

/* Default exit sequence for region Blink */
void Statechart::exseq_Blink()
{
	/* Default exit sequence for region Blink */
	/* Handle exit of all possible states (of Statechart.Blink) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case Blink_Turn_ON :
		{
			exseq_Blink_Turn_ON();
			break;
		}
		case Blink_Turn_OFF :
		{
			exseq_Blink_Turn_OFF();
			break;
		}
		default:
			/* do nothing */
			break;
	}
}

/* Default react sequence for initial entry  */
void Statechart::react_Blink__entry_Default()
{
	/* Default react sequence for initial entry  */
	opLedInit();
	viMyCounter = 0;
	enseq_Blink_Turn_ON_default();
}

sc_integer Statechart::react(const sc_integer transitioned_before) {
	/* State machine reactions. */
	return transitioned_before;
}

sc_integer Statechart::Blink_Turn_ON_react(const sc_integer transitioned_before) {
	/* The reactions of state Turn_ON. */
	sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (timeEvents[0])
		{ 
			exseq_Blink_Turn_ON();
			timeEvents[0] = false;
			enseq_Blink_Turn_OFF_default();
			react(0);
			transitioned_after = 0;
		} 
	} 
	/* If no transition was taken then execute local reactions */
	if ((transitioned_after) == (transitioned_before))
	{ 
		transitioned_after = react(transitioned_before);
	} 
	return transitioned_after;
}

sc_integer Statechart::Blink_Turn_OFF_react(const sc_integer transitioned_before) {
	/* The reactions of state Turn_OFF. */
	sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (timeEvents[1])
		{ 
			exseq_Blink_Turn_OFF();
			timeEvents[1] = false;
			enseq_Blink_Turn_ON_default();
			react(0);
			transitioned_after = 0;
		} 
	} 
	/* If no transition was taken then execute local reactions */
	if ((transitioned_after) == (transitioned_before))
	{ 
		transitioned_after = react(transitioned_before);
	} 
	return transitioned_after;
}

void Statechart::clearInEvents() {
	timeEvents[0] = false;
	timeEvents[1] = false;
}

void Statechart::microStep() {
	switch(stateConfVector[ 0 ])
	{
		case Blink_Turn_ON :
		{
			Blink_Turn_ON_react(-1);
			break;
		}
		case Blink_Turn_OFF :
		{
			Blink_Turn_OFF_react(-1);
			break;
		}
		default:
			/* do nothing */
			break;
	}
}

void Statechart::runCycle() {
	/* Performs a 'run to completion' step. */
	if (isExecuting)
	{ 
		return;
	} 
	isExecuting = true;
	dispatch_event(getNextEvent());
	do
	{ 
		microStep();
		clearInEvents();
		dispatch_event(getNextEvent());
	} while ((timeEvents[0]) || (timeEvents[1]));
	isExecuting = false;
}

void Statechart::enter() {
	/* Activates the state machine. */
	if (isExecuting)
	{ 
		return;
	} 
	isExecuting = true;
	/* Default enter sequence for statechart Statechart */
	enseq_Blink_default();
	isExecuting = false;
}

void Statechart::exit() {
	/* Deactivates the state machine. */
	if (isExecuting)
	{ 
		return;
	} 
	isExecuting = true;
	/* Default exit sequence for statechart Statechart */
	exseq_Blink();
	isExecuting = false;
}

/* Can be used by the client code to trigger a run to completion step without raising an event. */
void Statechart::triggerWithoutEvent() {
	runCycle();
}

