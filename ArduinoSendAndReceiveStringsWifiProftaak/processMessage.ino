void processMessage(String message) {
  Serial.println("processMessage()");
  if (message == "F")
  {
    dir = RP6_FORWARD;
    Rp6.moveAtSpeed(50, 50);
  }
  if (message == "B")
  {
    dir == RP6_BACKWARD;
    Rp6.moveAtSpeed(50, 50);
  }
  if (message == "L")
  {
    if (dir == RP6_BACKWARD){
    Rp6.moveAtSpeed(40, 60);
    }
    else {
          Rp6.moveAtSpeed(60, 40);s
    }
  }
  if (message == "R")
  {
    if (dir == RP6_BACKWARD){
    Rp6.moveAtSpeed(60, 40);
    }
    else {
          Rp6.moveAtSpeed(40, 60);

    }
  }
  if (message == "C")
  {
    if (dir == RP6_BACKWARD) {
      dir = RP6_FORWARD;
    }
    else {
      dir = RP6_BACKWARD;
    }
    Rp6.changeDirection(dir);
  }
  if (message == "Stop")
  {
    Rp6.stop();
  }
  else
  {
    return;
  }
}
