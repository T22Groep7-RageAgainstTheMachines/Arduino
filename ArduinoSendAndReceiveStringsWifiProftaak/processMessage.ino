void processMessage(String message) {
  Serial.println(message);
  if (message == "CD")
  {
    if (dir == RP6_BACKWARD)
    {
      dir = RP6_FORWARD;
    }
    else
    {
      dir = RP6_BACKWARD;
    }
    Rp6.changeDirection(dir);
  }
  if (message == "STOP")
  {
    Rp6.stop();
  }
  if (message == "RR")
  {
    Rp6.rotate(50, dir, 180);
  }
  if (message == "RL")
  {
    Rp6.rotate(50, dir, 180);
  }
  
  else
  {
    return;
  }
}

