#ifndef INTERVIEWREVIEW_H
#define INTERVIEWREVIEW_H
	class Furniture {
	public:
		Furniture() { }
		virtual void TestForce() { cout << "Calling the Furniture class testForce function" << endl; }
	};
	class Steel : Furniture {
	public:
		Steel() { }
		virtual void TestForce() { cout << "Calling the Steel class testForce function" << endl; }
	};

	class Chair : Furniture {
	public:
		Chair() { }
		virtual void TestForce() { cout << "Calling the Chair class testForce function" << endl; }
	};

	class SteelChair : Chair, Steel {
	public:
		SteelChair() { }
		virtual void TestForce() {
			//Call the chair TestForce
			Steel::TestForce();
			//Call the steel TestForce
			Chair::TestForce();
			//Call the steelChair TestForce
			cout << "Calling the SteelChair class testForce function" << endl;
		}
	};
#endif