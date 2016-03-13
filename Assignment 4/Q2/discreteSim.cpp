#include <iostream>
#include <vector>
#include <unordered_map>
#include "MinMaxHeap.hpp"
using namespace std;
class Microbe {
	private:
		int identity;
		int strength;
		int n;
		bool infected;
		bool dead;
	public:
		Microbe() {
			identity = 0;
			strength = 0;
			n = 0;
			infected = true;
			dead = true;
		}

		Microbe(int id, int str) {
			identity = id;
			strength = str;
			n = (((identity + strength) * 29) % 37) + 7;
			infected = false;
			dead = false;
		}

		int getIdentity() {
			return identity;
		}

		int getStrength() {
			return strength;
		}

		int getN() {
			return n;
		}

		void reduceStrength() {
			strength = strength - 1;
		}

		void infect() {
			infected = true;
		}

		void kill() {
			dead = true;
		}

		bool isInfected() {
			return infected;
		}

		bool isDead() {
			return dead;
		}
};

class Event {
	private:
		int step;
		char type; // death, infection, cell division
		Microbe* subject;
	public:
		Event() {
			step = 0;
			type = 'd';
			subject = NULL;
		}

		Event(int s, int t, Microbe* sub) {
			step = s;
			type = t;
			sub = subject;
		}

		bool operator <(const Event& e) {
			return step < e.step ? true : false;
		}

		int getStep() {
			return step;
		}

		char getType() {
			return type;
		}

		Microbe* getSubject() {
			return subject;
		}
};

int main() {
	int M, N, T;
	cin >> N;
	unordered_map<int, Microbe*> culture;
	MinMaxHeap<Event> sim;
	for (int i = 0; i < N; i++) {
		int str;
		cin >> str;
		Microbe* m1 = new Microbe(i, str);
		culture.insert(pair<int, Microbe*>(i, m1));
		// Create events for first cell division.
		// Subsequent divisions scheduled after the first division takes place.
		Event *e1 = new Event(m1->getN(), 'c', m1);
		sim.insert(*e1);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int mic, step;
		cin >> mic >> step;
		Microbe* m1 = culture.find(mic)->second;
		Event *e1 = new Event(step, 'i', m1);
		sim.insert(*e1);
	}
	int timestep = 0, global_identity = N, population = N;
	cin >> T;
	while(timestep <= T) {
		// Change data structure values, update output
		Event nextEvent = sim.getMin();
		while(timestep == nextEvent.getStep()) {
			Microbe* subject = nextEvent.getSubject();
			if (nextEvent.getType() == 'c') {
				// Always check whether microbe is infected / dead!
				if (!(subject->isInfected() || subject->isDead())) {
					Microbe* m1 = new Microbe(global_identity, subject->getStrength());
					cout << "b " << global_identity << " " << timestep << endl;
					global_identity++;
					population++;
					subject->reduceStrength();
					// Schedule events for m1's division and subject's next division
					Event *e1 = new Event(timestep + m1->getN(), 'c', m1);
					sim.insert(*e1);
					Event *e2 = new Event(timestep + subject->getN(), 'c', subject);
					sim.insert(*e2);
				}
			} else if (nextEvent.getType() == 'i') {
				subject->infect();
				// Schedule subject's death
				Event *e1 = new Event(timestep + subject->getStrength(), 'd', subject);
				sim.insert(*e1);
			} else if (nextEvent.getType() == 'd') {
				subject->kill();
				cout << "d " << subject->getIdentity() << " " << timestep << endl;
				population--;
			}
			sim.deleteMin();
			nextEvent = sim.getMin();
		}
		// Get to next event time instant
		timestep = nextEvent.getStep();
	}
}