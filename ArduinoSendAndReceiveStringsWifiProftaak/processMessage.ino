void processMessage(String message) {
  Serial.println(message);
  if (message == "%MF#")
  {
    Rp6.move(200,  RP6_FORWARD, 1000);
  }
  if (message == "%MB#")
  {
    Rp6.move(200,  RP6_BACKWARD, 1000);
  }
  if (message == "%CD#")
  {
    Rp6.stop();
    if (dir == RP6_BACKWARD)
    {
      dir = RP6_FORWARD;
    }
    else
    {
      dir = RP6_BACKWARD;
    }
  }
  if (message == "%STOP#")
  {
    Rp6.stop();
  }
  if (message == "%RR#")
  {
    Rp6.rotate(200, RP6_RIGHT, 180);
  }
  if (message == "#RL%")
  {
    Rp6.rotate(200, RP6_LEFT, 180);
  }

  else
  {
    return;
  }
}



