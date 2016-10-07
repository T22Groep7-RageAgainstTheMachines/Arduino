void processMessage(String message) {
  Serial.println("processMessage()");
  if (message == "F")
  {
    changeDir(fwd);
    Rp6.moveAtSpeed(50, 50);
  }
  if (message == "B")
  {
    changeDir(bck);
    Rp6.moveAtSpeed(-50, -50);
  }
  if (message == "L")
  {
    if (dir == RP6_BACKWARD){
      Rp6.moveAtSpeed(60, 40);
    }
    else {
      Rp6.moveAtSpeed(40, 60);
    }
  }
  if (message == "R")
  {
    if (dir == RP6_BACKWARD){
      Rp6.moveAtSpeed(40, 60);
    }
    else {
      Rp6.moveAtSpeed(60, 40);

    }
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

void changeDir(newDir)
{

  if (newDir == fwd) {
    dir = RP6_FORWARD;
  }
  else if(newDir == bck){
    dir = RP6_BACKWARD;
  }
}



