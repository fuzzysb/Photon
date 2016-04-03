const int pinTVUP       = D0;
const int pinTVDOWN     = D3;
const uint32_t timeTVUP   = 10000;
const uint32_t timeTVDOWN = 10000;

uint32_t timeToMove;
uint32_t timeMoveStarted;

void setup()
{
  pinMode(pinTVUP  , OUTPUT);
  pinMode(pinTVDOWN, OUTPUT);

  Particle.function("UP"  , startTVUp); 
  Particle.function("DOWN", startTVDown);
}

void loop()
{
  if (timeToMove > 0 && millis() - timeMoveStarted > timeToMove)
  { digitalWrite(pinTVUP  , LOW);
    digitalWrite(pinTVDOWN, LOW);
    timeToMove =                          
    timeMoveStarted = 0;
  }
}

int startTVUp(String param)
{
  digitalWrite(pinTVDOWN, LOW);            
  digitalWrite(pinTVUP  , HIGH);           
  timeToMove = timeTVUP;                       
  timeMoveStarted = millis();             
  return timeToMove;
}

int startTVDown(String param)
{
  digitalWrite(pinTVUP  , LOW);
  digitalWrite(pinTVDOWN, HIGH);
  timeToMove = timeTVDOWN;
  timeMoveStarted = millis();
  return timeToMove;
}