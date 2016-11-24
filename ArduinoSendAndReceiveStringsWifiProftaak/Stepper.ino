void stepper()
{
  switch(_step){ 
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
  if(totalSteps == 2)
  {
    totalSteps = 0;
    attack = false;
  }
  (_dir){ 
    _step++;
    stepsRemain--;
    if(stepsRemain <= 0){
      stepsRemain = totalsteps;
      _dir = false;
      totalSteps++;
    }
  }
  else{ 
    _step--;
    stepsRemain--;
    if(stepsRemain <= 0){
      stepsRemain = totalsteps;
      _dir = true;
      totalSteps++;
    }
  } 
  if(_step>3){ 
    _step=0; 
  } 
  if(_step<0){ 
    _step=3; 
  }

}

void initStepper(){
  while(!initDone){

    switch(_step){ 
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
    _step++;
    stepsRemain--;
    if(stepsRemain <= 0){
      stepsRemain = totalsteps;
      initDone = true;
    }
    if(_step>3){ 
      _step=0; 
    } 
    if(_step<0){ 
      _step=3; 
    }
  }


}


