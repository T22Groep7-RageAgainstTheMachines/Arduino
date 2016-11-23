



void stepper() {
  switch (steps)
  {
    case 0:
      digitalWrite(AOut, LOW);
      digitalWrite(BOut, LOW);
      digitalWrite(COut, HIGH);
      digitalWrite(DOut, HIGH);
      break;
    case 1:
      digitalWrite(AOut, LOW);
      digitalWrite(BOut, HIGH);
      digitalWrite(COut, HIGH);
      digitalWrite(DOut, LOW);
      break;
    case 2:
      digitalWrite(AOut, HIGH);
      digitalWrite(BOut, HIGH);
      digitalWrite(COut, LOW);
      digitalWrite(DOut, LOW);
      break;
    case 3:
      digitalWrite(AOut, HIGH);
      digitalWrite(BOut, LOW);
      digitalWrite(COut, LOW);
      digitalWrite(DOut, HIGH);
      break;
    default:
      digitalWrite(AOut, LOW);
      digitalWrite(BOut, LOW);
      digitalWrite(COut, LOW);
      digitalWrite(DOut, LOW);
      break;
  }
}
