#include <memory>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

/// Question 4: This is an extension task. Look at the interface class Observer. This class's responsibility 
/// is to observe and react any changes happening to the EventEmitter class, which emits an event via calling `emitEvent`. 
/// 
/// Your Task: You are to write a mock implementation using Google Tests of Observer to test that EventEmitter actually calls all its
/// attached Observers. This is called Mock testing, which essentially tests the external APIs of classes, and 
/// their relationship, rather than being concerned with the correctness of the overall application. You are to modify the CMakeLists.txt
/// file at the root of this repository, to make Question-4 utilise Google Tests. You also need to modify this file, to implement the mock, and
/// fix the test to utilise the mock and pass the test. 
/// 
/// More information about integrating Google Tests can be found here https://google.github.io/googletest/quickstart-cmake.html
/// You can learn about Mock Testing here: https://google.github.io/googletest/gmock_for_dummies.html


// Forward declaration. Don't worry about this.
class Actor;

class Observer {
public:
	virtual void ReactToEvent(Actor* actor) = 0;
};

class Actor {
	using ObserverPtr = std::shared_ptr<Observer>;

	std::vector<ObserverPtr> mObservers;
	int mCounter = 0;

public:
	Actor(std::initializer_list<ObserverPtr> observers)
		: mObservers(observers) {}


	int GetCounter() const {
		return mCounter;
	}

	void EmitEvent() {
		mCounter++;

		for(auto & observer: mObservers) {
			observer->ReactToEvent(this);
		}
	}

};

// This will not compile until you implement MockObserver.

TEST(ActorTest, ObserversAreCalled) {
	auto observer = std::make_shared<MockObserver>();
	Actor actor = { observer };

	constexpr auto numCalls = 5;

	EXPECT_CALL(*observer, ReactToEvent(&actor))
		.Times(numCalls);

	for (int i = 0; i < numCalls; i++) {
		actor.EmitEvent();
	}
}
