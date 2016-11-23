void processMessage(String message) {
  Serial.println(message);
  if (message == "%MF#")
  {
    dir = RP6_FORWARD;
    Rp6.changeDirection(dir);
    Rp6.moveAtSpeed(255, 255);
    //Rp6.move(200,  RP6_FORWARD, 1000);

  }
  else if (message == "%MB#")
  {
    dir = RP6_BACKWARD;
    Rp6.changeDirection(dir);
    Rp6.moveAtSpeed(255, 255);
    //Rp6.move(200,  RP6_BACKWARD, 1000);
  }
  else if (message == "%MR#")
  {
    dir = RP6_RIGHT;
    Rp6.changeDirection(dir);
    Rp6.moveAtSpeed(255, 200);
    //Rp6.move(200,  RP6_BACKWARD, 1000);
  }
  else if (message == "%ML#")
  {
    dir = RP6_LEFT;
    Rp6.changeDirection(dir);
    Rp6.moveAtSpeed(255, 200);
    //Rp6.move(200,  RP6_BACKWARD, 1000);
  }
  else if (message == "%CD#")
  {
    Rp6.stop();
    if (dir == RP6_BACKWARD)
    {
      dir = RP6_FORWARD;
      Rp6.changeDirection(dir);
    }
    else
    {
      dir = RP6_BACKWARD;
      Rp6.changeDirection(dir);
    }
  }
  else if (message == "%STOP#")
  {
    Rp6.stop();
  }
  else if (message == "%RR#")
  {
    Rp6.rotate(200, RP6_RIGHT, 180);
  }
  else  if (message == "%RL#")
  {
    Rp6.rotate(200, RP6_LEFT, 180);
  }
  else  if (message == "%ATTACK#")
  {
    attack = true;
  }
  else
  {
    return;
  }
}



