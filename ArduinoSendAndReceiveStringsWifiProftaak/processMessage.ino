void processMessage(String message) {
  Serial.println("processMessage()");
  if (message == "F")
  {
    Rp6.moveAtSpeed(50, 50);
  }
  if (message == "B")
  {
    Rp6.moveAtSpeed(-50, -50);
  }
  if (message == "L")
  {
    Rp6.moveAtSpeed(40, 60);
  }
  if (message == "R")
  {
    Rp6.moveAtSpeed(60, 40);
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

