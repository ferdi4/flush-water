class ToiletState
{
  private:
    int _sensorPin1 = 0;
    int _sensorPin2 = 0;
    int _state = 0;

  public:
    ToiletState();
    ~ToiletState();
    void setup(int sensorPin1, int sensorPin2);
    void updateState();
    void init();
    int getState();
};

void ToiletState::setup(int sensorPin1, int sensorPin2) {
  _sensorPin1 = sensorPin1;
  _sensorPin2 = sensorPin2;
}

ToiletState::~ToiletState() {}
ToiletState::ToiletState() {}

void ToiletState::init() {
  pinMode(_sensorPin1, INPUT_PULLDOWN);
  pinMode(_sensorPin2, INPUT_PULLDOWN);
}

void ToiletState::updateState() {
  _state = digitalRead(_sensorPin1) + digitalRead(_sensorPin2);
}

int ToiletState::getState() {
  return _state;
}

ToiletState state;


void setup() {
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(5, OUTPUT);
  
  state.setup(23, 22);
  state.init();

  Serial.begin(115200);
}

void loop() {
  state.updateState();
  writeState(state.getState());
  delay(1000);
}

// TODO: 
void writeState(int state) {
  if (state == 0) { // empty
    digitalWrite(19, LOW);
    digitalWrite(18, LOW);
    digitalWrite(5, HIGH);
  } else if(state == 1) {// half
    digitalWrite(19, LOW);
    digitalWrite(18, HIGH);
    digitalWrite(5, HIGH);
  } else { // full
    digitalWrite(19, HIGH);
    digitalWrite(18, HIGH);
    digitalWrite(5, HIGH);
  }
}
