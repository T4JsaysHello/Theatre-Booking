#include <string>

#include <iostream>

#include <vector>

#ifndef EVENTS_H
#define EVENTS_H
class Events {
  public:
  // variables
    std::string typeOfEvent;
    std::string artistName;
    int spaceAvailable;
  // methods
  Events(std::string typeOfEvent, std::string artistName, int spaceAvailable);
  virtual~Events();
  virtual void addBooking();
  virtual void addBooking(int seatPosition);
  virtual void cancelBooking();
  virtual void cancelBooking(int seatPosition);
  virtual void listdetail();
};

class MusicEvents: public Events {
  public:
    // methods
    MusicEvents(std::string artistName);
};

class Film: public Events {
  public:
  // variables 
    std::string filmTitle;
    int runtimeMinutes;
    std::string filmType;
    std::string viewRating;
  // methods
  Film(std::string artistName, std::string filmTitle, int runtimeMinutes, std::string filmType, std::string viewRating);
  void listdetail();
};

class StandUpComedy: public Events {
  public:
  // variables
    std::vector < bool > seatPlan;
  // methods
  StandUpComedy(std::string artistName);
  void addBooking(int seatPosition);
  void cancelBooking(int seatPosition);
  void listdetail();
};

#endif
