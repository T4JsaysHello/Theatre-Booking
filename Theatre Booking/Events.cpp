#include "Events.h"

// method for event base class

Events::Events(std::string typeOfEvent, std::string artistName, int spaceAvailable) {
  this -> typeOfEvent = typeOfEvent;
  this -> artistName = artistName;
  this -> spaceAvailable = spaceAvailable;
}

Events::~Events() {}

void Events::addBooking() {
  if (this -> spaceAvailable > 0) {
    this -> spaceAvailable--;
    std::cout << "Ticket Booked" << std::endl;
  } else {
    std::cout << "No Space available, Check Event details for available events" << std::endl;
  }
}

void Events::addBooking(int seatPosition) {}

void Events::cancelBooking() {
  this -> spaceAvailable++;
  std::cout << "Ticket Refunded" << std::endl;
}

void Events::cancelBooking(int seatPosition) {}

void Events::listdetail() {
  std::cout << "Type of Event: " << this -> typeOfEvent << std::endl;
  std::cout << "Artist Name: " << this -> artistName << std::endl;
  std::cout << "Space Available: " << this -> spaceAvailable << std::endl;
}

// music events methods

MusicEvents::MusicEvents(std::string artistName): Events("Music Event", artistName, 300) {}

// film events methods 

Film::Film(std::string artistName, std::string filmTitle, int runtimeMinutes, std::string filmType, std::string viewRating): Events("Film Event", artistName, 200) {
  this -> filmTitle = filmTitle;
  this -> runtimeMinutes = runtimeMinutes;
  this -> filmType = filmType;
  this -> viewRating = viewRating;
}

void Film::listdetail() {
  std::cout << "Type of Event: " << this -> typeOfEvent << std::endl;
  std::cout << "Artist Name: " << this -> artistName << std::endl;
  std::cout << "Space Available: " << this -> spaceAvailable << std::endl;
  std::cout << "Title: " << this -> filmTitle << std::endl;
  std::cout << "This movie is in: " << this -> filmType << std::endl;
  std::cout << "This movie is: " << this -> runtimeMinutes << " minutes long" << std::endl;
  std::cout << "This movie is rated: " << this -> viewRating << std::endl;
}

// stand up comedy events methods

StandUpComedy::StandUpComedy(std::string artistName): Events("StandUp Event", artistName, 200) {
  this -> seatPlan.assign(200, false);
}

void StandUpComedy::addBooking(int seatPosition) {
  seatPosition--;
  if (this -> seatPlan[seatPosition] == true) {
    std::cout << "Seat Unavailable, Please find another" << std::endl;
  } else {
    this -> seatPlan[seatPosition] = true;
    std::cout << "Ticket Booked" << std::endl;
    this -> spaceAvailable--;
  }
}

void StandUpComedy::cancelBooking(int seatPosition) {
  seatPosition--;
  if (this -> seatPlan[seatPosition] == false) {
    std::cout << "Seat not booked" << std::endl;
  } else {
    this -> seatPlan[seatPosition] = false;
    std::cout << "Ticket Refunded" << std::endl;
    this -> spaceAvailable++;
  }
}

void StandUpComedy::listdetail() {
  std::cout << "Type of Event: " << this -> typeOfEvent << std::endl;
  std::cout << "Artist Name: " << this -> artistName << std::endl;
  std::cout << "Space Available: " << this -> spaceAvailable << std::endl;
  std::cout << "Seat Plan" << std::endl;
  int loopNum = 1;
  for (int i = 0; i < this -> seatPlan.size(); i++) {
    if (this -> seatPlan[i] == false) {
      std::cout << i + 1 << "   ";
      if (loopNum == 10) {
        std::cout << std::endl;
        loopNum = 1;
      }
    }
  }
}
