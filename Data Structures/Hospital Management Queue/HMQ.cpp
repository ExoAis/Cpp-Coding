#include "HMQ.h"

HMQ::HMQ() {
	cout << "Everyone welcome to the Medical Hospital" << endl;
	cout << "We can serve at maximum 10 patients per shift" << endl;
	string n;
	for (int i = 0; i < 10; i++) {
		cout << "Please enter your name" << endl;
		getline(cin, n);
		registerPatient(n);
	}
	servePatient();
	servePatient();
	servePatient();
	servePatient();
	servePatient();
	servePatient();
	servePatient();
	servePatient();
	showAllPatients();
	cancelAll();
	if (canDoctorGoHome()) {
		cout << "The doctor is going home" << endl;
	}
	else {
		cout << "The waiting list is not empty" << endl;
	}
}
void HMQ::registerPatient(string name) {
	Node patient;
	patient.ID = count;
	patient.Name = name;
	queue.Enqueue(patient);
	count += 1;
}
void HMQ::servePatient() {
	Node patient = queue.Dequeue();
	cout << "Patien with ID " << patient.ID << " and Name " << patient.Name << " has been served" << endl;
}
void HMQ::cancelAll() {
	cout << "It is the time for Doctor's lunch break. Therefore all appointments will be cancelled" << endl;
	queue.emptyQueue();
}
bool HMQ::canDoctorGoHome() {
	if (queue.isEmpty()) {
		return true;
	}
	return false;
}
void HMQ::showAllPatients() {
	if (queue.isEmpty()) {
		return;
	}
	else {
		queue.print();
	}
}