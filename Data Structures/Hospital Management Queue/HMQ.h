#ifndef HMQ_H
#define HMQ_H
#include "ABQ.h"

class HMQ {
	private:
		ABQ queue;
		int count = 1;
	public:
		HMQ();
		void registerPatient(string name);
		void servePatient();
		void cancelAll();
		bool canDoctorGoHome();
		void showAllPatients();
};

#endif
