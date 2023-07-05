#include <iostream>

#include <string>

#include <vector>

#include "Events.h"

// functions needed to be declared before using them inside of menuLoop.

void bookTx();
void Refund();
void checkEvent();
void listAllEvents();

std::vector < Events * > eventList;
// creates a event by using objects in vectors
void SetEvents() {
  eventList.push_back(new MusicEvents("yoste"));
  eventList.push_back(new Film("matt reeves", "The Batman", 180, "2D", "12A"));
  eventList.push_back(new StandUpComedy("lee evans"));
}

// Loops through the menu screen to check for user inputs

void menuLoop() {
  int x;
  std::cout << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Enter (1) To Book Tickets" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter (2) To Cancel/Refund Tickets" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter (3) To View Certain Event" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter (4) To Get Listing Of All Events" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter (5) Exit The Programm" << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << std::endl;
  std::cin >> x;
  switch (x) {
  case 1:
    bookTx();
    break;
  case 2:
    Refund();
    break;
  case 3:
    checkEvent();
    break;
  case 4:
    listAllEvents();
    break;
  case 5:
    std::cout << "-----------------------------" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "System Ending" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    break;
  default:
    std::cout << "Incorrect Input try again" << std::endl;
  }
}

// List all the event type and their artist names

void listAllEvents() {
  std::cout << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "ALL EVENTS" << std::endl;
  for (int i = 0; i < eventList.size(); i++) {
    std::cout << std::endl;
    std::cout << "-x--x--x--x--x--x--x--x--x--x--x--x--x--x--" << std::endl;
    std::cout << "Type of Event: " << eventList[i] -> typeOfEvent << std::endl;
    std::cout << "Artist Name: " << eventList[i] -> artistName << std::endl;
    std::cout << "-x--x--x--x--x--x--x--x--x--x--x--x--x--x--" << std::endl;
    std::cout << std::endl;
  }
  std::cout << "-----------------------------" << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << std::endl;
  menuLoop();
}

// Refunds any tickets that want to be canceled

void Refund() {
  std::string x;
  std::cout << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "What type of event did you book?" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter MUSIC for music events" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter FILM for film events" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter STANDUP for stand up events" << std::endl;
  std::cout << std::endl;
  std::cin >> x;
  if (x == "MUSIC") {
    for (int i = 0; i < eventList.size(); i++) {
      if (eventList[i] -> typeOfEvent == "Music Event") {
        eventList[i] -> cancelBooking();
      }
    }
    menuLoop();
  } else if (x == "FILM") {
    for (int i = 0; i < eventList.size(); i++) {
      if (eventList[i] -> typeOfEvent == "Film Event") {
        eventList[i] -> cancelBooking();
      }

    }
    menuLoop();
  } else if (x == "STANDUP") {
    for (int i = 0; i < eventList.size(); i++) {
      if (eventList[i] -> typeOfEvent == "StandUp Event") {
        int typ;
        std::cout << "Enter Seat Postion: " << std::endl;
        std::cin >> typ;
        eventList[i] -> cancelBooking(typ);
      }
    }
    menuLoop();
  } else if (x == "EXIT") {
    menuLoop();
  } else {
    std::cout << "Incorrect Input, please try again" << std::endl;
    Refund();
  }
}

// Books a ticket method

void bookTx() {
  std::string x;
  std::cout << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "What type of event do you want to book?" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter MUSIC for music events" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter FILM for film events" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter STANDUP for stand up events" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter EXIT to return to menu" << std::endl;
  std::cout << std::endl;
  std::cin >> x;
  if (x == "MUSIC") {
    for (int i = 0; i < eventList.size(); i++) {
      if (eventList[i] -> typeOfEvent == "Music Event") {
        eventList[i] -> addBooking();
      }
    }
    menuLoop();
  } else if (x == "FILM") {
    for (int i = 0; i < eventList.size(); i++) {
      if (eventList[i] -> typeOfEvent == "Film Event") {
        eventList[i] -> addBooking();
      }

    }
  } else if (x == "STANDUP") {
    for (int i = 0; i < eventList.size(); i++) {
      if (eventList[i] -> typeOfEvent == "StandUp Event") {
        int typ;
        std::cout << "Enter Seat Postion: " << std::endl;
        std::cin >> typ;
        eventList[i] -> addBooking(typ);
      }
    }
    menuLoop();
  } else if (x == "EXIT") {
    menuLoop();
  } else {
    std::cout << "Incorrect Input, please try again" << std::endl;
    bookTx();
  }
}

// Checks for certain events

void checkEvent() {
  std::string x;
  std::cout << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "What type of event do you want to Check" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter MUSIC for music events" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter FILM for film events" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter STANDUP for stand up events" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter EXIT to return to menu" << std::endl;
  std::cout << std::endl;
  std::cin >> x;
  if (x == "MUSIC") {

    for (int i = 0; i < eventList.size(); i++) {
      if (eventList[i] -> typeOfEvent == "Music Event") {
        std::cout << std::endl;
        std::cout << "-----------------------------" << std::endl;
        eventList[i] -> listdetail();
      }
    }
    menuLoop();
  } else if (x == "FILM") {
    for (int i = 0; i < eventList.size(); i++) {
      if (eventList[i] -> typeOfEvent == "Film Event") {
        std::cout << std::endl;
        std::cout << "-----------------------------" << std::endl;
        eventList[i] -> listdetail();
      }

    }
    menuLoop();
  } else if (x == "STANDUP") {
    for (int i = 0; i < eventList.size(); i++) {
      if (eventList[i] -> typeOfEvent == "StandUp Event") {
        std::cout << std::endl;
        std::cout << "-----------------------------" << std::endl;
        eventList[i] -> listdetail();
      }
    }
    menuLoop();
  } else if (x == "EXIT") {
    menuLoop();
  } else {
    std::cout << "Incorrect Input, please try again" << std::endl;
    checkEvent();
  }
}
// Main
int main() {
  SetEvents();
  menuLoop();
  return 0;
}

